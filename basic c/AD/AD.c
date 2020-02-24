#include <stdio.h>
#include <stdlib.h>
#include "AD.h"
#define SUCCESS !0
#define FAIL 0 

struct AD{
	unsigned int m_NumOfMeetings;
	meeting_t** m_meetingArr;
	unsigned int m_currNumOfMeetings;
};

AD_t* createAD(int _NumOfMeetings)
{
	AD_t* PAD;
	PAD= (AD_t*) malloc(1*sizeof(AD_t));
	PAD->m_currNumOfMeetings=0;
	if (NULL==PAD)
	{
		printf("memory allocation failed");
	}
	PAD->m_meetingArr=(meeting_t**) calloc(_NumOfMeetings,sizeof(meeting_t*));
	if (NULL==PAD->m_meetingArr)
	{
		free(PAD);
		printf("memory allocation failed");
		return NULL;
	}
	(PAD)->m_NumOfMeetings=_NumOfMeetings;
	return PAD;
}

void insertMeeting(meeting_t* _Pmeet,AD_t* _PAD)
{
	int i;
	if ((_PAD)->m_currNumOfMeetings>=(_PAD)-> m_NumOfMeetings)
	{
		_PAD= (AD_t*) realloc(_PAD,((_PAD)-> m_NumOfMeetings+1)*sizeof(meeting_t*));	
		if(NULL==_PAD)
		{
			printf("memory allocation failed");
			return;
		}
	}
	
	*(_PAD->m_meetingArr+_PAD->m_currNumOfMeetings)=_Pmeet;
	_PAD->m_NumOfMeetings++;
	_PAD->m_currNumOfMeetings++;

	
	for(i=0;i<_PAD->m_currNumOfMeetings;i++)
	{
			if(_PAD->m_meetingArr[i]!=NULL)
		printf("\nmeeting number %d begin = %.2f end = %.2f room = %u\n\n",i+1, getMeetingStart(_PAD->m_meetingArr[i]),
		getMeetingEnd(_PAD->m_meetingArr[i]),
		getMeetingRoom(_PAD->m_meetingArr[i]));
	}
	printf("\n");
	return;	
}

meeting_t* findMeeting(AD_t* _PAD,float _begin)
{
	int i;
	if(NULL==_PAD)
	{
		printf("no meetins exist\n");
		return NULL;
	}	
	for(i=0;i<_PAD->m_currNumOfMeetings;i++)
	{
		if((_begin=getMeetingStart(_PAD->m_meetingArr[i])))
		{
			printf("meeting found\n");
			return _PAD->m_meetingArr[i];
		}
	}
	printf("meeting not found\n");
	return NULL;
}

void printDay(AD_t* _PAD)
{
	int i;
	if(NULL==_PAD)
	{
		printf("day is empty\n");
	}
	for(i=0;i<_PAD->m_currNumOfMeetings;i++)
	{
		if(_PAD->m_meetingArr[i]!=NULL)
		{
			printf("\nmeeting number %d begin = %.2f end = %.2f room = %u\n\n",i+1, getMeetingStart(_PAD->m_meetingArr[i]),
			getMeetingEnd(_PAD->m_meetingArr[i]),
			getMeetingRoom(_PAD->m_meetingArr[i]));
		}
	}
	return;
}

void destroyCalendar(AD_t* _PAD)
{
	int i;
	if(NULL==_PAD)
	{
		printf("already empty\n");
		return;
	}
	for(i=0;i<_PAD->m_currNumOfMeetings;i++)
	{
		free(_PAD->m_meetingArr[i]);
	}
	free(_PAD->m_meetingArr);
	free(_PAD);
	return;
}

void store(AD_t* _PAD)
{
	FILE* f;
	int i;
	if(NULL==_PAD)
	{
		printf("empty list");
		return;
	}
	f=fopen("meetings.txt","w+");
	if(NULL==f)
	{
		printf("error opening file");
		return;
	}
	for(i=0;i<_PAD->m_currNumOfMeetings;i++)
	{
		fprintf(f,"meeting number %d begin = %.2f end = %.2f room = %u\n",i,
		getMeetingStart(_PAD->m_meetingArr[i]),
		getMeetingEnd(_PAD->m_meetingArr[i]),
		getMeetingRoom(_PAD->m_meetingArr[i]));
	}	
	fclose(f);
}

void restore(AD_t* _PAD)
{
	char c;
	FILE* f;
	f=fopen("meetings.txt","r");
	if(NULL==f)
	{
		printf("error opening file");
		return;
	}
	while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(f); 
    } 
}
