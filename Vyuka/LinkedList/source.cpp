#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void printNode(Node* node);
Node* newNode(int val);


int main()
{

    Node* node1 = newNode(10);
    printNode(node1);
    Node* node2 = newNode(10);
    printNode(node2);
    node1->next=node2;
    printNode(node1);

	return 0;
	
}


void printNode(Node* node)
{
	cout << "[Add: " << node << ", val: " << node->val << ", next: " << node->next << "]" << endl;
	if (node->next != NULL) printNode(node->next);
}



Node* newNode(int val)
{
	Node* newNode = new Node();
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}


