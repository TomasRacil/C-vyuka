#include <iostream>

using namespace std;


struct Node
{
	int val;
	Node* next;

    Node* operator[](int index){
      Node* cur_node = this;
        for (int i = 0; i < index; i++)
        {
            cur_node=cur_node->next;
        }
        return cur_node;
   } 
};

Node* getNode(Node* LL, int idx);
void printLL(Node* node);
void printNode(Node* node);
Node* newNode(int val);
Node* addNextNode(int val, Node* node1);
void delNode(Node* previous);


int main()
{

    Node* LL = newNode(1);
    cout<<"Node1:"<<endl;
    printNode(LL);

    Node* node2 = newNode(2);
    cout<<endl<<"Node2:"<<endl;
    printNode(node2);

    LL->next=node2;
    cout<<endl<<"Node1&2:"<<endl;
    printLL(LL);

    Node* node3 = addNextNode(3, LL);
    cout<<endl<<"Node1&2&3:"<<endl;
    printLL(LL);
    
    cout<<endl<<"Node0:"<<endl;
    printNode(getNode(LL, 0));
    printNode((*LL)[0]);

    delNode(LL);
    cout<<endl<<"Node1&3:"<<endl;
    printLL(LL);
    


	return 0;
	
}



void delNode(Node* previous){
    Node* erased = previous->next;
    previous->next = erased->next;
    delete erased;
}

Node* addNextNode(int val, Node* previous){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = previous->next;
    previous->next = newNode;
    return newNode;
}

void printLL(Node* node)
{
	cout << "[Add: " << node << ", val: " << node->val << ", next: " << node->next << "]" << endl;
	if (node->next != NULL) printLL(node->next);
}
void printNode(Node* node)
{
	cout << "[Add: " << node << ", val: " << node->val << ", next: " << node->next << "]" << endl;
}



Node* newNode(int val)
{
	Node* newNode = new Node();
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

Node* getNode(Node* LL, int idx){
    Node* cur_node = LL;
    for (int i = 0; i < idx; i++)
    {
        cur_node=cur_node->next;
    }
    
    return cur_node;
}

