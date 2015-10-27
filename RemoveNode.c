#include<stdio.h>
#include<stdlib.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef int bool;
#define true 1
#define false 0

struct Node
{
    int value;
    struct Node *next;
}*head;

void AddNodes(int newValue);
void display();
void removeNode(int remove);

int main()
{
	struct Node *head = NULL;

    AddNodes(2);
	AddNodes(5);
	AddNodes(8);
	AddNodes(9);

	display();

	removeNode(9);
	removeNode(5);
	removeNode(2);
	removeNode(20);

	display();

	removeNode(8);

	display();

	return 0;
}


/*
 *AddNodes function is to add a node to Linked List.
 *AddNodes function takes 'newValue' as input.
 *AddNodes function doesn't return a value as output.
 *AddNodes function changes the value of 'head'.
 */
void AddNodes(int newValue)
{
	struct Node *newNode;

	/*to allocate memory for new node*/
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> value = newValue;

	/*if there is not any value in the Linked List , 'newValue' assigns as head of Linked List'*/
	if(head == NULL)
	{
		head = newNode;
		head -> next = NULL;
	}
	/*if there is any value in the Linked List , 'newValue' assigns as head of Linked List'*/
	else
	{
		newNode -> next = head;
		head = newNode;
	}

}


/*
 *display function is to show values in the Linked List.
 *display function doesn't take an input.
 *display function doesn't return an output.
 *display function doesn't change any global variable.
 */
void  display()
{
	struct Node *current = head;

    if(current == NULL)
    {
    	printf("Linked List is empty.");
    }

    /*all of values show in the Linked List*/
    while(current != NULL)
    {
    	printf("%d ",current -> value);
    	current = current->next;
    }

    	printf("\n");
}


/*
 *removeNode function is to remove a value from Linked List.
 *removeNode function takes 'remove' variable as an input.
 *'remove' variable will be removed from Linked List'
 *if 'remove' variable is 'head' , value of 'head' changes as a global variable.
 */
void removeNode(int remove)
{
	struct Node *previous=NULL;
	struct Node *current=head;
	int bool = false;

	/*if the linked list is empty , to search 'remove' value in the Linked List */
	while(current != NULL)
	{
		/*'remove' value is found in the linked list*/
		if(current -> value == remove)
		{
			bool=true;
			/*if previous is null , value to be removed on head of Linked List*/
			if(previous == NULL)
			{
				current = current -> next;
				free(head);
				head = current;
			}
			/*value to be removed is out of head*/
			else
			{
				previous -> next = current -> next;
				free(current);
				current = previous -> next;
			}

		}
		/*go to the next value in the linked list*/
		else
		{
			previous=current;
			current=current->next;
		}

	}

	/*'remove' value doesn't find in the Linked List */
	if(bool == false)
	{
		printf("'%d' didn't find in the Linked List. \n",remove);
	}

}
