#pragma once

#include "SimpleNode.h"

template <typename T>
class SimpleLinkedList
{
private:
    SimpleNode<T> head;
    int lenght;

public:
    SimpleLinkedList(/* args */);
    void print_LL();
    void push_back_val(T val);
    void insert_val(int idx, T val);
    Node* operator[](int idx);
    void delete_node(int idx);
    int size();
    ~SimpleLinkedList();
};
