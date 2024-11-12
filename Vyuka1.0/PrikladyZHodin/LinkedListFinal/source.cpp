#include <iostream>

using namespace std;


template <typename T>
struct Node
{
	T val;
	Node* next;

    //vytiskne prvek linked listu
    void print_node();
    //vytiskne prvek a všechny navazující
    void print_LL();
    //pridá na konec listu jeden prvek
    void push_back_val(T val);
    //na daný index vloží prvek a všechny ostatní posune
    void insert_val(int idx, T val);
    //vrátí pointer na prvek, který se nachází na daném indexu
    Node* operator[](int idx);
    //odstraní prvek na daném indexu
    void delete_node(int idx);

};


int main()
{
    Node <int> LL;
    LL.val = 0;
    LL.next = NULL;

    LL.push_back_val(1);
    LL.push_back_val(2);
    LL.push_back_val(3);

    LL.print_LL();
    LL[1]->print_node();

    LL.insert_val(2,4);
    LL.delete_node(3);
    LL.print_LL();	
}
template<typename T>
void Node<T>::print_node(){
    cout << "[Add: " << this << ", val: " << val << ", next: " << next << "]" << endl;
}
template<typename T>
void Node<T>::print_LL(){
    print_node();
    if (next != NULL) next->print_LL();
}
template<typename T>
void Node<T>::push_back_val(T val){
    Node* newNode = new Node();
    Node* cur_node = this;
    while(cur_node->next!=NULL){
        cur_node = cur_node->next;
    }
    cur_node->next = newNode;
    newNode->val = val;
    newNode->next = NULL;
}
template<typename T>
void Node<T>::insert_val(int idx, T val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = (*this)[idx-1]->next;
    (*this)[idx-1]->next = newNode;
}
template<typename T>
Node<T>* Node<T>::operator[](int idx){
    Node* cur_node = this;
    for (int i = 0; i < idx; i++)
    {
        if(cur_node->next!=NULL) cur_node=cur_node->next;
        else throw out_of_range("Index out of range of LL");
    }
    return cur_node;
} 
template<typename T>
void Node<T>::delete_node(int idx){
    Node* node_to_erase = (*this)[idx];
    (*this)[idx-1]->next = node_to_erase->next;
    node_to_erase->val= NULL;
    node_to_erase->next=NULL;
    delete node_to_erase;
}