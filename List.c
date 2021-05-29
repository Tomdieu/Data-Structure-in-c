//#include<stdlib.h>
//#include<stdio.h>
#include "functions.h"
/*typedef struct List
{
	int value;
	struct List *next;
}*List;

typedef enum{false,true}Bool;

List new()
{
	return NULL;
}

Bool is_empty(List li)
{
	if(li == NULL)
		return true;
	return false;
}

List insert_front(List li,int x)
{
	List e;
	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(0);
	e->value = x;
	e->next = NULL;
	if(li == NULL)
	{
		return e;
	}

	e->next = li;
	return e;
}

List insert_back(List li,int x)
{
	List e;
	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(0);
	e->value = x;
	e->next = NULL;
	if(li == NULL)
	{
		return e;
	}

	List tmp = li;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}	
	tmp->next = e;
	return li;
}

List pop_front(List li)
{
	if(is_empty(li))
	{
		printf("The List Is Empty\n");
		return NULL;
	}
	else
	{
		List tmp = li;
		li = tmp->next;
		free(tmp);
		tmp = NULL;
		return li; 
	}
}

List pop_back(List li)
{
	if(is_empty(li))
	{
		printf("The List Is Empty\n");
		return new();
	}
	else
	{
		List tmp,tmp1;
		tmp = li;
		tmp1 = li;
		while(tmp1->next != NULL)
		{
			tmp = tmp1;
			tmp1 = tmp1->next;
		}
		tmp->next = NULL;
		free(tmp1);
		tmp1 = NULL;
		return li;
	}
}

int lenght(List li)
{
	if(is_empty(li))
		return 0;
	return (lenght(li->next) +1);
}

List clrlist(List li)
{
	if(is_empty(li))
		return NULL;
	while(li != NULL)
	{
		li = pop_front(li);
	}
	return li;
}

void display(List li)
{
	if(is_empty(li))
	{
		printf("The List is Empty Nothing To Display\n");
		return;
	}
	while(li != NULL)
	{
		printf("[%d] ",li->value);
		li = li->next;
	}
	printf("\n");
}
*/
int main(int argc, char const *argv[])
{
	List li = new_list();

	li = insert_front(li,1);
	li = insert_front(li,0);
	display_list(li);
	li = insert_back(li,2);
	li = insert_back(li,3);
	display_list(li);
	printf("Lenght %d\n", lenght_list(li));
	li = clrlist(li);
	display_list(li);
	return 0;
}