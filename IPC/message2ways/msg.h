#ifndef _MSG_H_
#define _MSG_H_
#define SIZE 200
#include <unistd.h>
#include <stddef.h>
typedef struct my_msgbuf
{
	long m_type;
	char m_text[SIZE];
	pid_t pid;
}my_msgbuf;

enum MessageResult{
	MESSAGE_OK,
	MESSAGE_NOT_INITIALLIZED,
	MESSAGE_ALLOCATION_ERROR,
	MESSAGE_OVERFLAW,
	MESSAGE_UNDERFLAW,
	MESSAGE_MAX_RESULT
}

void MsgCreate(const char* _pathName,int _var);
void MsgConnect(const char* _pathName,int _var);
void MsgDestroy(my_msgbuf* _buf);
MessageResult MessagePut(my_msgbuf* _buf,long _msgType, const void* _msgBuf,size_t _msgSize);
MessageResult MessageGet(my_msgbuf* _buf,long _msgType, void* _msgBuf,size_t _msgBufSize,size_t* _pMsgLen);
MessageResult MessageTryGet(my_msgbuf* _buf,char* _msg);
int MessageSize(my_msgbuf* _buf);
void scanstring(my_msgbuf* _buf,char* _msg);

#endif
