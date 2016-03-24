/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/


#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int count1 = 0, count2 = 0, count3 = 0;
	struct node *temp;
	temp = head;
	while (temp)
	{
		if (temp->data == 0)
		{
			count1++;
		}
		else if (temp->data == 1)
		{
			count2++;
		}
		else
		{
			count3++;
		}
		temp = temp->next;
	}
	while (head)
	{
		if (count1 != 0)
		{
			head->data = 0;
			count1--;
		}
		else if (count2 != 0)
		{
			head->data = 1;
			count2--;
		}
		else
		{
			head->data = 2;
			count3--;
		}
		head = head->next;;
	}

}