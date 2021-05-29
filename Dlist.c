#include<stdio.h>
#include<stdlib.h>


typedef struct DListNode
{
	int value;
	struct DListNode *back;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	int lenght;
	struct DListNode *begin;
	struct DListNode *end;
}*DList;


typedef enum{false,true}Boolean;

DList new()
{
	return NULL;
}


Boolean is_empty(DList li)
{
	if(li == NULL)
		return true;
	return false;
}

int lenght(DList li)
{
	if(is_empty(li))
		return 0;
	return li->lenght;
}

DList append_back(DList li,int x)
{
	DListNode *e;
	e = malloc(sizeof(*e));
	if (e == NULL)
	{
		exit(0);
	}
	else
	{
		e->value = x;
		e->back = NULL;
		e->next = NULL;
		if(is_empty(li))
		{
			li = malloc(sizeof(*e));
			if(li == NULL)
			{
				exit(0);
			}
			else
			{
				li->begin = e;
				li->end = e;
				li->lenght = 1;
				return li;
			}
		}
		else
		{
			li->end->next = e;
			e->back = li->end;
			li->end = e;
		}

	}
	li->lenght+=1;
	return li;
}

DList append_front(DList li,int x)
{
	DListNode *e;
	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(0);
	e->value = x;
	e->next = NULL;
	e->back = NULL;
	if(is_empty(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			exit(0);
		}
		else
		{
			li->begin = e;
			li->end = e;
			li->lenght+=1;
		}
	}
	else
	{
		li->begin->back = e;
		e->next = li->begin;
		li->begin = e;
		li->lenght+=1;
	}
	return li;
}

void display(DList li)
{
	if(is_empty(li))
	{
		printf("Nothing to display the list is empty\n");
		return;
	}

	DListNode *e;

	e = li->begin;

	while(e != NULL)
	{
		printf("[%d] ", e->value);
		e = e->next;
	} 
	printf("\n");
}

void display_back(DList li)
{
	if(is_empty(li))
	{
		printf("Nothing to display the list is empty\n");
		return;
	}

	DListNode *e;

	e = li->end;

	while(e != NULL)
	{
		printf("[%d] ", e->value);
		e = e->back;
	} 
	printf("\n");	
}

DList pop(DList li)
{
	if(is_empty(li))
	{
		return new();
	}
	
	else
	{
		if(li->begin == li->end)
		{
			li->lenght = 0;
			li->begin = NULL;
			li->end=NULL;
			//printf("Lenght %d\n",li->lenght );
			return li;
		}
		DListNode *e;
		e = li->end->back;
		free(li->end);
		e->next = NULL;
		li->end = e;
		li->lenght-=1;
		//printf("Lenght %d\n",li->lenght );
		return li;
	}

}

DList popAll(DList li)
{
	for (int i = 0; i <= li->lenght; i++)
	{
		li = pop(li);
	}
	return li;
}

int main(int argc, char const *argv[])
{
	DList mylist;
	mylist = new();
	mylist = append_back(mylist,1);
	mylist = append_back(mylist,2);
	mylist = append_back(mylist,3);
	mylist = append_front(mylist,0);
	mylist = append_front(mylist,-1);
	mylist = append_front(mylist,-2);
	mylist = append_front(mylist,-3);
	display_back(mylist);
	printf("lenght %d\n",lenght(mylist));
	mylist=pop(mylist);
	display(mylist);
	mylist = pop(mylist);
	display(mylist);
	mylist=pop(mylist);
	display(mylist);
	mylist = popAll(mylist);
	display(mylist);
	printf("lenght %d\n",lenght(mylist));
	return 0;
}
