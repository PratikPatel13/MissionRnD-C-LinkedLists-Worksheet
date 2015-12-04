/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
void swap(struct node *p1, struct node *p2);
struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *p1 = head, *p2;
	if (head == NULL)
		return NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->num > p2->num)
			{
				swap(p1, p2);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return head;
}

void swap(struct node *p1, struct node *p2)
{
	int temp;
	temp = p1->num;
	p1->num = p2->num;
	p2->num = temp;

}