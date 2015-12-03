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

void sll_012_sort(struct node *head)
{
	int zeroCount = 0, oneCount = 0, twoCount = 0;  
	struct node *p;
	p = head;
	while (p != NULL)    // Count number of 0's 1's and 2's 
	{
		if (p->data == 0)
			zeroCount++;
		else if (p->data == 1)
			oneCount++;
		else
			twoCount++;
		p = p->next;
	}
	p = head;
	// Modify list such that all 0's are added first then 1's and then 2's
	while (p!=NULL) 
	{
		if (zeroCount > 0)
		{
			p->data = 0;
			zeroCount--;
		}
		else if (oneCount > 0)
		{
			p->data = 1;
			oneCount--;
		}
		else
		{
			p->data = 2;
			twoCount--;
		}
		p = p->next;
	}
}
