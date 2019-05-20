#include<stdio.h>
#include<stdlib.h>

struct node
{

	char name[180];
	int num;
	struct node* link;
};

struct node* root = NULL;

void addatbegin()
{
	struct node *temp; 
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Insert new name at the begin\n");
	scanf("%s",temp->name);
	temp->link = NULL;
	if(root==NULL)
	{
		printf("The list is not empty\n");
	}
	else
	{
		temp->link = root; //Right connection FIRST!!!!
		root = temp; //Left connection 
	}

}

int lenght()
{
	int count; 
	count = 0; 
	struct node* temp;
	temp = root;

	while(temp != NULL)
	{
		count = count + 1;
		temp = temp->link;

	}

	return count;
}
void display()
{
	struct node* temp;
	temp = root;
	if(temp == NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%s-->", temp->name);
			temp = temp->link;
		}
		printf("\n\n");
	}
}
void append()
{
	struct node* temp; 
	temp = (struct node*)malloc(sizeof(struct node));

	printf("Enter node data\n");
	scanf("%s",temp->name);
	temp->link = NULL;
	if(root==NULL)//List is empty
	{
		root = temp;

	}
	else
	{
		struct node* p; 
		//p = (struct node*)malloc(sizeof(struct node));
		p = root;
		while(p->link != NULL)
		{
			p = p->link;

		}
		p->link = temp;  


	}	


}
int main ()
{
	int ch;
	int len;

	while(1)
	{
		printf("Single Linked List operations :\n");
		printf("1.Append\n");
		printf("2.Addatbeggin\n");
		printf("3.Addafter\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Quit");

		printf("Enter your choice\n");
		scanf("%d",&ch);
			
		switch(ch)
        	{
                	case 1:
                        	append();
                        	break;
                	case 2: addatbegin();
                        	break;
                	case 3: //addatafter();
                	        break;
                	case 4: len = lenght();
				printf("THE LENGTH IS %d\n",len);
                	        break;
                        case 5: display();
                       		 break;
                	case 6: //delete();
                        	break;
                	case 7: exit(1);
                
               		default: printf("Invalid!!!\n");
        	}       

	}

	return 0;
}

