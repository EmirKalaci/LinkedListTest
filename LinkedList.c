#include "LinkedList.h"

/*
 * This function is to add a node to linked list.
 * It takes newValue as input and doesn't return a value as output.
 * At the same time it changes the value of head.
 */
void AddNodes(int newValue)
{
	struct Node *newNode;

	/* to allocate memory for new node */
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->value = newValue;

	/*
	 * If there is not any value in the linked list
	 * newNode assigns as head of linked list
	 * and null assigns to next of head.
	 * else there is any value in the linked list
	 * newNode assigns as head of linked list.
	 */
	if(head == NULL)
	{
		head = newNode;
		head->next = NULL;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

}


/*
 * This function is to show values in the Linked List.
 * It doesn't take an input and doesn't return an output.
 * At the same time it doesn't change any global variable.
 */
void  display()
{
	struct Node *current = head;

    if(current == NULL)
    {
    	printf("Linked list is empty.");
    }

    /* all of values show in the linked list */
    while(current != NULL)
    {
    	printf("%d ",current->value);
    	current = current->next;
    }

    printf("\n");
}


/*
 * This function is to remove a value from linked list.
 * A variable is taken as an input and will be removed.
 * If remove variable is head , value of head changes as a global variable.
 */
void removeNode(int remove)
{
	struct Node *previous = NULL;
	struct Node *current = head;
	int bool = false;

	/* if the linked list is empty , to search remove value in the linked list */
	while(current != NULL)
	{
		/*
		 * If remove value is found in the linked list
		 * else go to the next value in the linked list.
		 */
		if(current->value == remove)
		{
			bool = true;

			/*
			 * If previous is null , value to be removed on head of
			 * linked list. Else value to be removed is out of head.
			 */
			if(previous == NULL)
			{
				current = current->next;
				free(head);
				head = current;
			}
			else
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
			}

		}
		else
		{
			previous = current;
			current = current->next;
		}

	}

	/* remove value doesn't find in the linked list */
	if(bool == false)
	{
		printf("'%d' didn't find in the linked list. \n",remove);
	}
}
