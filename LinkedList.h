#include<stdio.h>
#include<stdlib.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif

struct Node
{
    int value;
    struct Node *next;
}*head;

typedef int bool;
#define true 1
#define false 0

void AddNodes(int newValue);
void display();
void removeNode(int remove);
