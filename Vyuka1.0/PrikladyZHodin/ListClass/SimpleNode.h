#pragma once

template <typename T>
class SimpleNode
{
private:
    T val;
	SimpleNode* next;
public:
    SimpleNode();
    SimpleNode(T val);
    SimpleNode(T val, SimpleNode* next);
    SimpleNode* getNext();
    void changeNext(SimpleNode* next);
    void print_node();
    ~SimpleNode();
};


