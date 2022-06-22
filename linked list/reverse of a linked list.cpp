#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
};


void printReverse(Node* head){
	if (head == NULL)
	return;
	printReverse(head->next)
	cout << head->data << " ";
}
void push(Node** head_ref, char new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Driver code*/
int main()
{
	// Let us create linked list 1->2->3->4
	Node* head = NULL;
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	printReverse(head);
	return 0;
}

