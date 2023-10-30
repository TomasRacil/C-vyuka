#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void printNode(Node* node);
Node* newNode(int val);
Node* addNextNode(int val, Node* node1);

int main()
{

    Node* node1 = newNode(1);
    cout<<"Node1:"<<endl;
    printNode(node1);

    Node* node2 = newNode(2);
    cout<<endl<<"Node2:"<<endl;
    printNode(node2);

    node1->next=node2;
    cout<<endl<<"Node1&2:"<<endl;
    printNode(node1);

    Node* node3 = addNextNode(3, node1);
    cout<<endl<<"Node1&2&3:"<<endl;
    printNode(node1);
    


	return 0;
	
}

Node* addNextNode(int val, Node* previous){
    Node* newNode = new Node();
    newNode->val;
    newNode->next = previous->next;
    previous->next = newNode;
    return newNode;
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


