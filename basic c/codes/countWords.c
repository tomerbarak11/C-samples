#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word{
	char m_theword[20];
	int m_count;
	struct word* m_next;
}word;

typedef struct words{
	word* m_head;	
}wordsList;

void countWords();
word* createWord(char _word[]);
word* createHead(word* _head,word* _w);
word* ListInsertByKey(word* _head,char _word[],word* _w);
void PrintList(word* _head);

int main()
{
	countWords();
}

void countWords()
{
	FILE* f;
	int cmp;
	wordsList *words;
	char oneWord[20];
	word* w;
	if((f=fopen("countWords.txt","r"))==NULL)
	{
		printf("open error\n");
	}
	
	words=(wordsList*)malloc(1*sizeof(wordsList));
	if(NULL==words)
	{
		printf("allocation fail\n");
		return;
	}
	words->m_head=NULL;
	
	while((cmp=fscanf(f,"%s",oneWord))!=EOF)
	{
		w=createWord(oneWord);
		if(NULL==(words->m_head))
		{
			words->m_head=createHead(words->m_head,w);
		}
		else if(strcmp(words->m_head->m_theword,oneWord)==0)
		{
			words->m_head->m_count++;
		}
		else if(strcmp(words->m_head->m_theword,oneWord)<0)
		{
			words->m_head=ListInsertByKey(words->m_head,oneWord,w);
		}	
		else
		{
			words->m_head=ListInsertByKey(words->m_head,oneWord,w);
		}
		
	}
	PrintList(words->m_head);
	fclose(f);
}

word* createWord(char _word[])
{
	word* w;
	w=(word*)malloc(1*sizeof(word));
	if(NULL==w)
	{
		printf("allocation failed");
		return NULL;
	}
	strcpy(w->m_theword,_word);
	w->m_count=0;
	return w;
}

word* createHead(word* _head,word* _w)
{	
	printf("head\n");
	_head=_w;
	_w->m_count++;
	return _head;
}

word* ListInsertHead(word* _head,word* _w)
{	
	_w->m_next=_head;
	_w->m_count++;		
	return _w;
}


word* ListInsertByKey(word* _head,char _word[],word* _w)
{
	int i=1;
	word* temp=_head;
	while(NULL!=temp)
	{	
		if(strcmp(temp->m_theword,_word)==0)
		{
			_w->m_count++;	
			printf("%d	a	word = %s number = %d\n",i,
			_w->m_theword,_w->m_count);
			return _head;
		}
		
		else if(strcmp(temp->m_theword,_word)<0)
		{
			_head=ListInsertHead(_head,_w);
			_w->m_count++;
			printf("%d	b	word = %s number = %d\n",i,
			_w->m_theword,_w->m_count);		
			return _head;
		}
		
		else
		{
			_w->m_next=_head;
			_head=_w;
			 if(NULL!=temp->m_next)
			{	
				temp->m_next=_w;
				_w->m_count++;
				printf("%d	c	word = %s number = %d\n",i,
			_w->m_theword,_w->m_count);
				return _head;
			}
		}
		temp=temp->m_next;
	}
	_w->m_count++;
	printf("%d	d	word = %s number = %d\n",i,
	_w->m_theword,_w->m_count);
	return _head;
}

void PrintList(word* _head)
{
	while(NULL!=_head)
		{
			printf("%s appears %d times\n",
			_head->m_theword,
			_head->m_count);
			_head=_head->m_next;
		}
}
