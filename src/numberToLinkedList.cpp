/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	node *start = NULL;
	node	*current = NULL;
	node *buff;
	int temp = 10;
	if (N < 0)
	{
		N = N*(-1);
	}
	while (N / temp != 0)
	{
		temp = temp * 10;
	}
	while (temp != 1)
	{
		buff = (struct node *)malloc(sizeof(struct node));
		buff->num = ((N * 10) / temp) % 10;
		temp = temp / 10;
		if (start == NULL)
		{
			buff->next = start;
			current = buff;
			start = buff;
		}
		else
		{
			current->next = buff;
			buff->next = NULL;
			current = buff;
		}

	}
	return start;
}