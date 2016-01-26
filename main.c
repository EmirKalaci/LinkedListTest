#include "LinkedList.h"

int main()
{
	struct Node *head = NULL;

	AddNode(5);
	AddNode(8);
	AddNode(9);

	displayNodes();

	removeNode(9);
	removeNode(5);
	removeNode(2);
	removeNode(20);

	displayNodes();

	removeNode(8);

	displayNodes();

	return 0;
}
