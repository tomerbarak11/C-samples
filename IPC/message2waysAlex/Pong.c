#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <time.h>

#include "PingPong.h"

const char USAGE[]		= "Usage: %s [-v] [-f name] [-s msec]\n";
const char ERR_FTOK[]	= "ERROR getting key for %s!\n";
const char ERR_MSGGET[]	= "ERROR getting queue %s = 0x%08x!\n";
const char ERR_MSGSND[]	= "ERROR sending message [%d, %d, %s]!\n";
const char ERR_MSGRCV[]	= "ERROR receiving message [%d]!\n";

const char ECHO_SEND[]	= "SENT message [%2d, %d, %s]\n";
const char ECHO_RECV[]	= "RECV message [%2d, %d, %d, %s]\n";

const char ECHO_DONE[]	= "%s DONE after %d messages - exiting...\n";

int main(int argc, char **argv)
{
	key_t  msgKey;
	int  mQ;
	msgbuf snd;
	msgbuf rcv;
	int	noBytes;
/*	int	msgTypeRcv	= - MSG_TYPE_EOF;
 * 		In this particular case, we can use ANY for msgTypeRcv
*/	int	msgTypeRcv	= 0;
	int noMsgs = 0;

	char msqName[256]	= MSGQUE_NAME_DEFAULT;
	int  sleepTime		= 0;
	int	 verbose		= 0;
	int  opt;

	pid_t pid = getpid();

/*	Parse the options */
    while (-1 != (opt = getopt(argc, argv, "vf:s:"))) {
        switch (opt) {
		case 'v':	/* verbose (echo) */
			verbose = 1;
			break;
        case 'f':	/* MsgQue name */
            strcpy(msqName,optarg);
            break;
		case 's':	/* millisecond to sleep between messages */
			sleepTime = atoi(optarg) * 1000;
			break;
        default: /* '?' */
            fprintf(stderr, USAGE, argv[0]);
            return EXIT_FAILURE;
        }
    }


/*  make the key */
	if (-1 == (msgKey = ftok(msqName, 1))) {
		fprintf(stderr, ERR_FTOK, msqName);
		return errno;
	}

/*  create or open message queue */
	if (-1 == (mQ = msgget(msgKey, PERMIS))) {
		fprintf(stderr, ERR_MSGGET, msqName, msgKey);
		return errno;
	}

/*	read the message and echo it back */
	/* setup the message data */
	snd.m_type	= MSG_TYPE_PONG;
	snd.m_procID= pid;

	while (1) {
		if (-1 == (noBytes = msgrcv(mQ, &rcv, sizeof(msgbuf) - sizeof(rcv.m_type), msgTypeRcv, MSG_NOERROR))) {
			fprintf(stderr, ERR_MSGRCV, MSG_TYPE_PING);
			return errno;
		}
		/* make sure the message is null-terminated, provide for m_procID */
		rcv.m_message[noBytes - sizeof rcv.m_procID] = '\0';

		if (verbose)
			fprintf(stdout, ECHO_RECV, (int)rcv.m_type, rcv.m_procID, noBytes, rcv.m_message);

		/* check for end of file message */
		if (MSG_TYPE_EOF == rcv.m_type) {
				break;
		} else {
			if (0 == strcmp(rcv.m_message, MSGQUE_EOF))
			break;
		}

		if (sleepTime)
			usleep(sleepTime);

		/* make the response */
		strcpy(snd.m_message, rcv.m_message);

		/* message size is without the message type */
		if (-1 == msgsnd(mQ, &snd, strlen(rcv.m_message) + sizeof rcv.m_procID, IPC_NOWAIT)) {
			fprintf(stderr, ERR_MSGSND, (int) snd.m_type, snd.m_procID, snd.m_message);
			return errno;
		}

		/* echo the message to stdout and sleep a while */
		if (verbose)
			fprintf(stdout, ECHO_SEND, (int)snd.m_type, snd.m_procID, snd.m_message);

		noMsgs++;
	}

/*	no cleanup needed */
	printf(ECHO_DONE, argv[0], noMsgs);

	return errno;
}
