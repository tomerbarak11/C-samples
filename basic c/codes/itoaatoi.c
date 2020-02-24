#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* myItoa(int x);
int myAtoi(char* str);
int checkPlusMinusString(char x);
int numOfDigits(int num);
int buildNum(char *s,int len);

int main()
{
	int x=-123;
	char str[]="-456";
	char *xstr;
	xstr=myItoa(x);
	printf("myItoa = %s\n",xstr);
	printf("myAtoi = %d\n",myAtoi(str));
}

char* myItoa(int x)
{
	int temp,i,count=0,flagMinus=0;
	char *new,*newMinus;
	char minus[256]="-";
	if(x<0)
	{
		x=x*(-1);
		flagMinus=1;
	}
	temp=x;
	count=numOfDigits(x);
	new=(char*)malloc((count+1)*sizeof(char));
	new[count+1]='\0';
	for(i=count-1;i>=0;i--)
	{
		new[i]=temp%10+'0';
		temp=temp/10;
	}
	if(1==flagMinus)
	{
		strcat(minus,new);
		newMinus=(char*)malloc(strlen(new)*sizeof(char));
		if(NULL==newMinus)
		{
			printf("overflaw\n");
		}
		strcpy(newMinus,minus);
		return newMinus;
	}
	return new;
}

int numOfDigits(int num)
{
	int count=0;
	while(num)
	{
		num=num/10;
		count++;
	}
	return count;
}

int myAtoi(char* str)
{
	int num=0,j,len,tens=1;
	char *plus,*minus;
	int flagPlus=0,flagMinus=0;
	char minusStr[256]="-";
	len=strlen(str);
	
	if(str[0]=='+')
	{
		plus=(char*)malloc((len-1)*sizeof(char));
		for(j=0;j<len;j++)
		{
			plus[j]=str[j+1];
		}
		printf("plus = %s\n",plus);
		flagPlus=1;
	}
	
	else if (str[0]=='-')
	{
		minus=(char*)malloc((len-1)*sizeof(char));
		for(j=0;j<len;j++)
		{
			minus[j]=str[j+1];
		}
		flagMinus=1;
	}
	
	if(!flagPlus&&!flagMinus)
	{
		num=buildNum(str,len);
		return num;
	}

	else if(flagPlus==1)
	{
		len--;
		num=buildNum(plus,len);
		return num;
	}
	
	else if(flagMinus==1)
	{	
		len--;
		num=buildNum(minus,len);
		return num*(-1);
	}
}

int buildNum(char *s,int len)
{
	int tens=1,i=1,num=0;
			while(len)
		{
			num=num+((s[len-1])-'0')*tens;
			len--;
			i++;			
			tens=tens*10;
		}
		return num;
}
