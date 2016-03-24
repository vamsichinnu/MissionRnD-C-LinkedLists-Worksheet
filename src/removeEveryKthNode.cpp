/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int count = 1, p;
	struct node *res;
	res = head;
	p = K;
	if (head&&K>1)
	{
		while (head&&head->next)
		{
			count++;
			if (p == count)
			{
				head->next = (head->next)->next;
				p = p + K;
			}
			else
			{
				head = head->next;
			}
		}
		return res;
	}
	else
	{
		return NULL;
	}
}