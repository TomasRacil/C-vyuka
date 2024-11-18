#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
public:
    void push(T val)
    {
        data.push_back(val);
    }
    T top()
    {
        if (data.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }
    T pop()
    {
        T temp = top();
        data.pop_back();
        return temp;
    }

private:
    vector<T> data;
};

int main()
{
    Stack<int> s;
    s.pop();
    cout << s.top() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    return 0;
}