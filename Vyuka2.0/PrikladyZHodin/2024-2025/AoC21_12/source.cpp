#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
struct Node
{
    T *data;
    Node<T> *next;
};

struct Jeskyne
{
    string jmeno;
    bool mala;
    Node<Jeskyne> *dalsi;
};

bool operator==(const Jeskyne &j1, const Jeskyne &j2)
{
    return j1.jmeno == j2.jmeno;
}

template <typename T>
void add_to_list(Node<T> *head, T *data)
{
    Node<T> *new_node = new Node<T>();
    new_node->data = data;
    new_node->next = nullptr;

    if (head->data == nullptr)
    {
        head->data = data;
        return;
    }

    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

template <typename T>
void remove_last(Node<T> *head)
{
    Node<T> *temp = head;
    if (temp->data == nullptr)
    {
        return;
    }
    if (temp->next == nullptr)
    {
        delete temp;
        temp = nullptr;
        return;
    }
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

template <typename T>
T *find_in_list(Node<T> *head, T data)
{
    Node<T> *temp = head;
    if (temp->data == nullptr)
    {
        return nullptr;
    }
    while (temp != nullptr)
    {
        if (*temp->data == data)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void delete_list(Node<T> *head)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *next = temp->next;
        delete temp;
        temp = next;
    }
    head->next = nullptr;
}

template <typename T>
ostream &operator<<(ostream &os, Node<T> *head)
{
    Node<T> *temp = head;
    if (temp->data == nullptr)
    {
        return os;
    }
    while (temp != nullptr)
    {
        os << *(temp->data) << endl;
        temp = temp->next;
    }
    return os;
}

void rozdelRadek(const string &radek, string *prvni_cast, string *druha_cast)
{
    stringstream ss(radek);
    getline(ss, *prvni_cast, '-');
    getline(ss, *druha_cast, '-');
}

Jeskyne *vytvorJeskyni(string jmeno, bool mala)
{
    Jeskyne *j = new Jeskyne();
    j->jmeno = jmeno;
    j->mala = mala;
    j->dalsi = new Node<Jeskyne>();
    return j;
}

ostream &operator<<(ostream &os, Jeskyne &j)
{
    os << j.jmeno << " " << j.mala;
    return os;
}

void nactiSoubor(string soubor, Node<Jeskyne> *head)
{
    ifstream soubor_na_cteni;
    soubor_na_cteni.open(soubor);
    if (soubor_na_cteni.is_open())
    {
        string line;
        string *prvni_cast = new string();
        string *druha_cast = new string();
        Jeskyne pomocna_jeskyne;
        Jeskyne *pomocna_jeskyne_vychozi;
        Jeskyne *pomocna_jeskyne_cilova;
        while (getline(soubor_na_cteni, line))
        {
            rozdelRadek(line, prvni_cast, druha_cast);

            pomocna_jeskyne.jmeno = *prvni_cast;
            pomocna_jeskyne_vychozi = find_in_list(head, pomocna_jeskyne);
            if (pomocna_jeskyne_vychozi == nullptr)
            {
                pomocna_jeskyne_vychozi = vytvorJeskyni(*prvni_cast, islower((*prvni_cast)[0]));
                add_to_list(head, pomocna_jeskyne_vychozi);
            }
            pomocna_jeskyne.jmeno = *druha_cast;
            pomocna_jeskyne_cilova = find_in_list(head, pomocna_jeskyne);
            if (pomocna_jeskyne_cilova == nullptr)
            {
                pomocna_jeskyne_cilova = vytvorJeskyni(*druha_cast, islower((*druha_cast)[0]));
                add_to_list(head, pomocna_jeskyne_cilova);
            }
            add_to_list(pomocna_jeskyne_vychozi->dalsi, pomocna_jeskyne_cilova);
            add_to_list(pomocna_jeskyne_cilova->dalsi, pomocna_jeskyne_vychozi);
            pomocna_jeskyne_vychozi = nullptr;
            pomocna_jeskyne_cilova = nullptr;
        }
        delete prvni_cast;
        delete druha_cast;
    }
    soubor_na_cteni.close();
}

int najdiMozneCesty(Jeskyne *aktualni, Node<Jeskyne> *cesta)
{
    Node<Jeskyne> *temp = aktualni->dalsi;

    add_to_list(cesta, aktualni);

    int sum = 0;

    while (temp != nullptr)
    {
        if (temp->data->mala == true && find_in_list(cesta, *temp->data) != nullptr)
        {
            sum += 0;
        }
        else if (temp->data->jmeno == "end")
        {
            cout << cesta << endl;
            sum += 1;
        }
        else
        {
            sum += najdiMozneCesty(temp->data, cesta);
        }
        temp = temp->next;
    }
    remove_last(cesta);
    return sum;
}

int main()
{
    Node<Jeskyne> *jeskyne = new Node<Jeskyne>();

    nactiSoubor("AoC.txt", jeskyne);

    Jeskyne start = {"start", false, nullptr};

    cout << najdiMozneCesty(find_in_list(jeskyne, start), new Node<Jeskyne>());

    delete_list(jeskyne);

    return 0;
}