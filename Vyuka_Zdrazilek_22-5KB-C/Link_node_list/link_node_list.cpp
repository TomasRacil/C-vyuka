#include <iostream>

using namespace std;


struct Node
{
    int val;
    Node* next;
    void print_node()
    {
        cout << "[ ADD: " << this << ", val: " << val << ", next: " << next << " ]" << endl;
    }

    void print_LL() 
    {
        Node* current = this;
        while (current != nullptr)
        {
            current->print_node();
            current = current -> next;
        }
    }
    
    //pridá na konec listu jeden prvek
    void push_back_val(int val) 
    {
        Node* new_node = new Node;
        new_node -> val = val;
        new_node -> next = nullptr;

        if (this == nullptr)
        {
            *this = *new_node;
            return;
        }

        Node* current = this;
        while (current -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = new_node;
    }
    
    //na daný index vloží prvek a všechny ostatní posune
    void insert_val(int idx, int val) 
    {
        Node* new_node = new Node;
        new_node -> val = val;

        if (idx == 0)
        {
            new_node -> next = this;
            *this = *new_node;
            return;
        }

        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == idx - 1)
            {
                new_node -> next = current->next;
                current -> next = new_node;
                return;
            }
            current = current -> next;
            count++;
        }
    }
    
    //vrátí pointer na prvek, který se nachází na daném indexu
    Node* operator[](int index) 
    {
        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                return current;
            }
            current = current -> next;
            count++;
        }
        return nullptr;
    }

    //odstraní prvek na daném indexu
    void delete_node(int idx) 
    {
        if (idx == 0)
        {
            Node* next_node = next;
            delete this;
            *this = *next_node;
            return;
        }

        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == idx - 1)
            {
                Node* node_to_delete = current -> next;
                current -> next = node_to_delete -> next;
                delete node_to_delete;
                return;
            }
            current = current -> next;
            count++;
        }
    }

};


int main()
{
    char lel;
    Node LL;
    LL.val = 0;
    LL.next = NULL;

    LL.push_back_val(1);
    LL.push_back_val(2);
    LL.push_back_val(3);

    LL.print_LL();
    LL[1]->print_node();

    

    LL.insert_val(2, 4);
    LL.delete_node(3);
    LL.print_LL();
}