#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
//struct node *root = NULL;

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
struct node *add_begin(struct node *root)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter data at begin:\n");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	new_node->prev = NULL;
	if(root==NULL)
	{
		root = new_node;
	}
	else
	{
		//FIRST RIGHT CONECTIONS
		new_node->next = root;
		root->prev = new_node;
		root = new_node;
	}
	return root;
}
int main (void)
{
	struct node *root=NULL;
	int option;
	do
	{
		printf("\n\n****MAIN MENU****\n");
		printf("1: Create a double linked list\n");
		printf("2: Display the double linked list\n");
		printf("3: Add node at begin of the list\n");
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
			case 3: root = add_begin(root);
				break;
		}
	}while(option!=12);

	return 0;

}
