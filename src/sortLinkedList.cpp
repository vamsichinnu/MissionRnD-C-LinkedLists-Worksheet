/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void divide(struct node *res, struct node **front, struct node **back)
{
	struct node *fast, *slow;
	if (res == NULL || res->next == NULL)
	{
		*front = res;
	}
	else
	{
		slow = res;
		fast = (res->next);
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front = res;
		*back = slow->next;
		slow->next = NULL;

	}
}
struct node* merge(struct node *front, struct node *back)
{
	struct node *sort = NULL;
	if (front == NULL)
	{
		return back;
	}
	if (back == NULL)
	{
		return front;
	}
	if (front->num <= back->num)
	{
		sort = front;
		sort->next = (merge(front->next, back));
	}
	else
	{
		sort = back;
		sort->next = (merge(front, back->next));
	}

	return sort;
}
void mergesort(struct node **head)
{
	struct node *front, *back = NULL;
	if (*head == NULL || (*head)->next == NULL)
	{
	}
	else
	{
		divide(*head, &front, &back);
		mergesort(&front);
		mergesort(&back);
		*(head) = merge(front, back);
	}
}
struct node * sortLinkedList(struct node *head) {

	if (head)
	{
		mergesort(&head);
		return head;
	}
	else
	{
		return NULL;
	}
}