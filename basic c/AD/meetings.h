#include <stdio.h>
#include <stdlib.h>
#ifndef _AD_h_
#define _AD_h_

typedef struct meeting meeting_t;

meeting_t* createMeeting(float _begin,float _end,int _roomNumber);
float getMeetingStart(meeting_t* meeting);
float getMeetingEnd(meeting_t* meeting);
unsigned int getMeetingRoom(meeting_t* meeting);

#endif

