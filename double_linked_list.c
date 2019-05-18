#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *root = NULL;

struct node *create_dll(struct node *root)
{
	struct node *new_node,*p;
	int data;
	if(root==NULL)
	{
		new_node= (struct node *)malloc(sizeof(struct node));
		printf("INSERT INT DATA:\n");
		scanf("%d",&new_node->data);
		new_node->prev = NULL;
		new_node->next = NULL;
		root = new_node;
	}
	else
	{
		p = root;
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("INSERT INT DATA:\n");
		scanf("%d",&new_node->data);
		while(p->next!=NULL)
		{
			p = p->next;
		}
		p->next = new_node;
		new_node->prev = p;
		new_node->next = NULL;
	}
	return root;
}
void display(struct node *root)
{
	struct node *p;
	p = root;
	while(p!=NULL)
	{
		printf("\t->%d",p->data);
		p = p->next;
	}
}
int main (void)
{
	int option;
	do
	{
		printf("\n\n****MAIN MENU****\n");
		printf("1: Create a double linked list\n");
		printf("2: Display the double linked list\n");
		printf("12: EXIT\n");
		printf("Enter your option:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: root = create_dll(root);
				printf("DOUBLE LINKED LIST CREATED\n");
				break;
			case 2: display(root);
				break;
		}
	}while(option!=12);

	return 0;

}
