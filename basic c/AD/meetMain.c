#include <stdio.h>
#include "AD.h"
#include "meetings.h"
#define SUCCESS !0
#define FAIL 0

int main ()
{
	int choice;
	unsigned int NumOfMeetings;
	meeting_t* Pmeet=NULL;
	AD_t* PAD=NULL;
	int roomNumber;
	float begin,end;

	while(1)
	{
		printf("please enter your choice\n1 create ad\n2 create meeting\n3 insert meeting\n4 find meeting\n5 print day\n6 destroy calendar\n7 store\n8 restore\n\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
			{		
				printf("please enter the number of meetings\n");
				scanf("%u",&NumOfMeetings);	
				PAD=createAD(NumOfMeetings);
				break;
			}
			
			case 2:
			{
				if(NULL!=Pmeet)
				{
					printf("you need to insert meeting\n\n");
					break;
				}
				printf("\nplease enter begin time\n");
				scanf("%f",&begin);
				printf("please enter end time\n");
				scanf("%f",&end);
				if(begin<end&&Pmeet==NULL)
				{
					printf("please enter room number\n");
					scanf("%d",&roomNumber);
					Pmeet=createMeeting(begin,end,roomNumber);
					break;
				}
				else if(begin>end)
				{
					printf("error, begin is later than end\n");
					break;
				}
			}
			
			case 3:
			{
				insertMeeting(Pmeet,PAD);
				Pmeet=NULL;
				break;
			}
			case 4:
			{
				findMeeting(PAD,1);
				break;
			}
			case 5:
			{
				printDay(PAD);
				break;
			}
			case 6:
			{
				destroyCalendar(PAD);
				break;
			}
			case 7:
			{
				store(PAD);
				break;
			}
			case 8:
			{
				restore(PAD);
				break;
			}
		}
	}
	return 0;
}

