#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int value;
	struct Stack *next;
}*Stack;

typedef enum {false,true} Bool;

Stack new()
{
	return NULL;
}

Stack append(Stack st,int x)
{
	Stack e;
	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(0);
	e->value = x;
	e->next = new();
	if(st == NULL)
		return e;
	e->next = st;
	return e;
}

Stack pop(Stack st)
{
	if(st == NULL)
		return NULL;
	Stack e;
	e = st;
	st = e->next;
	free(e);
	return st;
}

int lenght(Stack st)
{
	if(st == NULL)
		return 0;
	int len=0;
	while(st != NULL)
	{
		len +=1;
		st = st->next;
	}
	return len;
}

void display(Stack st)
{
	if(st == NULL)
	{
		printf("The Stack is Empty!\n");
		return;
	}
	while(st != NULL)
	{
		printf("[%d] ", st->value);
		st =st->next;
	}
	printf("\n");
}

Stack Clear(Stack st)
{
	while(st != NULL)
	{
		st = pop(st);
	}
	return st;
}

int main(int argc, char const *argv[])
{
	Stack st = new();
	st = append(st,10);
	st = append(st,9);
	st = append(st,8);
	st = append(st,7);
	st = append(st,6);
	st = append(st,5);
	st = append(st,4);
	st = append(st,3);
	st = append(st,2);
	st = append(st,1);
	st = append(st,0);
	display(st);
	printf("lenght = %d\n",lenght(st));
	st = Clear(st);
	display(st);
	return 0;
}