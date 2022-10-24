
#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void printArr(int* arr, int len);
void printLL(Node* node);
void delLL(Node* node);

int* randArr(int len);

Node* newNode(int val);
Node* initLL(int* arr, int len);
Node* getNode(Node* node, int idx);
void rmNode(Node** node, int idx);
Node* addNode(Node* node, int idx, int val);



int main()
{
	int len, idx, val;

	cout << "Zadej velikost pole: ";
	cin >> len;
	int* arr = randArr(len);
	cout << "Pole: " << endl;
	printArr(arr, len);
	Node* head = initLL(arr, len);
	cout << "LL: " << endl;
	printLL(head);


	/*cout << "Zadej kolikaty prvek chces odebrat: ";
	cin >> idx;
	try {
		rmNode(&head, idx);
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
	printLL(head);*/

	cout << "Zadej kam chces pridat prvek: ";
	cin >> idx;
	cout << "Zadej jeho honotu: ";
	cin >> val;
	head = addNode(head, idx, val);
	printLL(head);

	/*
	cout << "Zadej kolikaty prvek chces zobrazit: ";
	cin >> idx;
	cout << getNode(head, idx)->val << endl;

	cout << "Zadej kolikaty prvek chces zmenit: ";
	cin >> idx;
	cout << "Zadej novou honotu: ";
	cin >> val;
	getNode(head, idx)->val = val;
	printLL(head);

	cout << "Zadej kolikaty prvek chces odebrat: ";
	cin >> idx;
	try {
		head = rmNode(head, idx);
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
	printLL(head);


	cout << "Zadej kam chces pridat prvek: ";
	cin >> idx;
	cout << "Zadej jeho honotu: ";
	cin >> val;
	head = addNode(head, idx, val);
	printLL(head);
	*/
	delLL(head);
}

void printArr(int* arr, int len)
{
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printLL(Node* node)
{
	cout << "[Add: " << node << ", val: " << node->val << ", next: " << node->next << "]" << endl;
	if (node->next != NULL) printLL(node->next);
}

void delLL(Node* node)
{
	if (node->next != NULL) delLL(node->next);
	delete node;

}

int* randArr(int len)
{
	srand(time(0));
	int* arr;
	arr = new int[len];
	for (int i = 0; i < len; ++i) {
		arr[i] = (int)rand() % 100;
	}
	return arr;
}

Node* newNode(int val)
{
	Node* newNode = new Node();
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

Node* initLL(int* arr, int len)
{
	Node* firstN = newNode(arr[0]);
	Node* lastN = firstN;
	for (int i = 1; i < len; ++i) {
		Node* newN = newNode(arr[i]);
		lastN->next = newN;
		lastN = newN;
	}
	return firstN;
}

Node* getNode(Node* node, int idx)
{
	if (idx <= 0 || node->next == NULL) return node;
	else return getNode(node->next, idx - 1);
}

void rmNode(Node** head, int idx)
{
	Node* erased = getNode(*head, idx);
	if (idx > 0) {
		Node* prev = getNode(*head, idx - 1);
		if (prev != erased) {
			if (erased->next != NULL) prev->next = erased->next;
			else prev->next = NULL;
		}
		else throw out_of_range("Outside of LL bounds");
	}
	else *head = getNode(*head, idx + 1);
	delete erased;

}

Node* addNode(Node* head, int idx, int val)
{
	Node* newN = newNode(val);
	Node* foll = getNode(head, idx);

	if (idx <= 0) {
		newN->next = foll;
		return newN;
	}
	else {
		Node* prev = getNode(head, idx - 1);
		if (prev != foll) {
			newN->next = foll;
			prev->next = newN;
			return head;
		}
		else {
			foll->next = newN;
			return head;
		}

	}
}
