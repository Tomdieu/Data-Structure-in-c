#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	int value;
	struct Tree *parent;
	struct Tree *left;
	struct Tree *right;
}*Tree;

Tree Node(int x)
{
	Tree tr;
	tr = malloc(sizeof(*tr));
	if(tr == NULL)
	{
		exit(0);
	}
	tr->value = x;
	tr->parent = NULL;
	tr->left = NULL;
	tr->right = NULL;

	return tr;
}

Tree join_tree(Tree left,Tree right,int node)
{
	Tree tr;
	tr = Node(node);
	tr->left = left;
	tr->right = right;

	if(left != NULL)
		left->parent = tr;
	if(right != NULL)
		right->parent = tr;
	return tr;
}

void display_tree(Tree tr)
{
	if(tr == NULL)
	{
		printf("The Tree Is Empty\n");
		return;
	}

	if(tr->parent != NULL)
	{
		printf("(%d) -> (%d)\n", tr->parent->value,tr->value);
	}
	else
	{
		printf("(%d)\n",tr->value);
	}

	if(tr->left != NULL)
		display_tree(tr->left);
	if(tr->right != NULL)
		display_tree(tr->right);	
}

void clear_tree(Tree tr)
{
	if(tr == NULL)
		return;
	
	clear_tree(tr->left);
	clear_tree(tr->right);
	printf("clearing -> %d\n", tr->value);
	free(tr);
	tr=NULL;
}

int Count_Node(Tree tr)
{
	if(tr == NULL)
		return 0;
	return (Count_Node(tr->left)+Count_Node(tr->right)+1);
}

int main(int argc, char const *argv[])
{
	Tree tr,tr1,tr3;
	tr = Node(9);
	tr1 = Node(10);
	tr3 = join_tree(tr,join_tree(Node(4),Node(5),20),11);
	display_tree(tr3);
	printf("Lenght = %d\n", Count_Node(tr3));
	clear_tree(tr3);
	return 0;
}
