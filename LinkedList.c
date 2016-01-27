#include "LinkedList.h"

/*
 * This function is to add a node to linked list.
 * It takes newValue as input and doesn't return a value as output.
 * At the same time it changes the value of head.
 */
void AddNode(int newNodeValue)
{
	struct Node *newNode;

	/* to allocate memory for new node */
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->value = newNodeValue;

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
void  displayNodes()
{
	struct Node *currentNode = head;

	/* if there is not any node in the linked list */
	if(currentNode == NULL)
	{
		printf("Linked list is empty.");
	}

	/* if linked list has any node , all value of nodes print on screen */
	while(currentNode != NULL)
	{
		printf("%d ",currentNode->value);
		currentNode = currentNode->next;
	}

	printf("\n");
}


/*
 * This function is to remove a value from linked list.
 * A variable is taken as an input and will be removed.
 * If remove variable is head , value of head changes as a global variable.
 */
void removeNode(int removeNodeValue)
{
	struct Node *previousNode = NULL;
	struct Node *currentNode = head;
	int isMatchRemoveNodeValue = false;

	/* if the linked list is not empty , search remove value in the linked list */
	while(currentNode != NULL)
	{
		/*
		 * If remove value is found in the linked list
		 * else go to the next node in the linked list.
		 */
		if(currentNode->value == removeNodeValue)
		{
			isMatchRemoveNodeValue = true;

			/*
			 * If previous node is null , value to be removed on head of
			 * linked list. Else value to be removed is out of head.
			 */
			if(previousNode == NULL)
			{
				currentNode = currentNode->next;
				free(head);
				head = currentNode;
			}
			else
			{
				previousNode->next = currentNode->next;
				free(currentNode);
				currentNode = previousNode->next;
			}

		}
		else
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

	}

	/* remove value does not find in the linked list */
	if(isMatchRemoveNodeValue == false)
	{
		printf("'%d' didn't find in the linked list. \n",removeNodeValue);
	}
}
