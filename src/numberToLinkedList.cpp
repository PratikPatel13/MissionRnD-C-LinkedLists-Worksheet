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
	int data;
	struct node *newNode = NULL, *last = NULL;

	// If the number is zero then allocate only one node and set the pointer field to NULL
	if (N == 0)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = N;
		newNode->next = NULL;
	}

	//If number is negative, make it positive
	if (N < 0)
		N = N * -1;

	/* Make node for each digit from reverse and when new digit is added make that digit point to last digit.
		Example : N = 345 , then first make node for 5 and set its pointer to NULL, and then make node for 4,
		set the pointer field point to 3 and continue
	*/
	while (N != 0)
	{
		data = N % 10;
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = data;
		if (last == NULL)        //If it is first number then make it point to NULL
		{
			newNode->next = NULL;
			last = newNode;
		}
		else     
		{
			newNode->next = last;
			last = newNode;
		}
		N /= 10;
	}
	return newNode;
}
