#include<stdlib.h>
#include <stdio.h>

typedef struct Queue
{
	int value;
	struct Queue *next;
}*Queue;

typedef enum{false,true}Bool;

Queue new()
{
	return NULL;
}

Bool is_empty(Queue qu)
{
	if(qu == NULL)
		return true;
	return false;
}

Queue enqueue(Queue qu,int x)
{
	Queue e;
	e = malloc(sizeof(*e));
	if(e == NULL)
	{
		exit(0);
	}

	e->value = x;
	e->next = NULL;
	if(is_empty(qu))
	{
		return e;
	}
	else
	{
		e->next = qu;
		return e;
	}
}

Queue dequeue(Queue qu)
{
	if(is_empty(qu))
	{
		printf("The List Is Empty\n");
		return NULL;
	}
	Queue tmp,tmp1;
	tmp = qu;
	tmp1 = qu;
	while(tmp ->next != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
	}
	tmp1->next = NULL;
	free(tmp);
	return qu;
}

int lenght(Queue qu)
{
	if(is_empty(qu))
		return 0;
	int len=0;
	while(qu != NULL)
	{
		len +=1;
		qu = qu->next;
	}
	return len;
}

void display(Queue qu)
{
	if(is_empty(qu))
	{
		printf("The Queue Is Empty\n");
		return;
	}

	else
	{
		while(qu != NULL)
		{
			printf("[%d] ", qu->value);
			qu = qu->next;
		}
		printf("\n");
	}
}

Queue Clear(Queue qu)
{
	if(is_empty(qu))
		return NULL;
	Queue tmp = qu;

	qu = tmp->next;
	free(tmp);
	tmp = NULL;
	Clear(qu);

	return qu;
}

int main(int argc, char const *argv[])
{
	Queue qu;
	qu = new();
	qu = enqueue(qu,5);
	qu = enqueue(qu,4);
	qu = enqueue(qu,3);
	qu = enqueue(qu,2);
	qu = enqueue(qu,1);
	display(qu);
	printf("Lenght = %d\n", lenght(qu));
	qu = dequeue(qu);
	display(qu);
	printf("Lenght = %d\n", lenght(qu));
	qu = dequeue(qu);
	display(qu);
	printf("Lenght = %d\n", lenght(qu));
	qu = dequeue(qu);
	display(qu);
	printf("Lenght = %d\n", lenght(qu));
	qu = dequeue(qu);
	display(qu);
	printf("Lenght = %d\n", lenght(qu));
	qu = Clear(qu);
	display(qu);
	return 0;
}