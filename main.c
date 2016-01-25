#include "LinkedList.h"

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
