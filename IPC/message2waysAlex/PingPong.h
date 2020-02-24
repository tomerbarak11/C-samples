#ifndef __PINGPONG_H__
#define __PINGPONG_H__

#include <sys/types.h>
#include <sys/stat.h>

#define MSGQUE_NAME_DEFAULT "ping-pong-MSQ"
#define MSGQUE_EOF			"!DONE!"
#define PERMIS	(S_IRUSR | S_IWUSR)

#define MSG_LEN 		248
#define MSG_TYPE_PING	  5
#define MSG_TYPE_EOF	  6
#define MSG_TYPE_PONG	  8

typedef struct msgbuf
{
	long  m_type;
	pid_t m_procID;
	char  m_message[MSG_LEN];
} msgbuf;

#endif /* __PINGPONG_H__ */
