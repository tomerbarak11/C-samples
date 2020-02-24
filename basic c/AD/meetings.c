#include "meetings.h"

struct meeting{
	float m_begin;
	float m_end;
	unsigned int m_room;
};

meeting_t* createMeeting(float _begin,float _end,int _roomNumber)
{
	meeting_t* Pmeet;
	Pmeet= (meeting_t*) malloc(sizeof(meeting_t));
	if (NULL==Pmeet)
	{
		printf("memory allocation failed");
		return NULL;
	}
	Pmeet->m_begin=_begin;
	Pmeet->m_end=_end;
	Pmeet->m_room=_roomNumber;
	return Pmeet;
}

float getMeetingStart(meeting_t* meeting)
{
	if(NULL==meeting)
	{
		printf("start=null\n");
	}
	return meeting->m_begin;
}

float getMeetingEnd(meeting_t* meeting)
{
	if(NULL==meeting)
	{
		printf("end=null\n");
	}
	return meeting->m_end;
}

unsigned int getMeetingRoom(meeting_t* meeting)
{
	return meeting->m_room;
}
