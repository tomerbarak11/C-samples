#include <stdio.h>
#include <string.h>
#ifndef _meetings_h_
#define _meetings_h_
#include "meetings.h"

typedef struct AD AD_t;

AD_t* createAD(int _NumOfMeetings);
void insertMeeting(meeting_t* _Pmeet,AD_t* _PAD);
meeting_t* findMeeting(AD_t* _PAD,float _begin);
void printDay(AD_t* _PAD);
void destroyCalendar(AD_t* _PAD);
void store(AD_t* _PAD);
void restore(AD_t* _PAD);
#endif	
