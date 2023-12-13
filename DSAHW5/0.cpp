#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top, len;

public:
    Stack(int);
    ~Stack();
    int peek();
    int 
    pop();
    void push(int);
    bool isFull();
    bool isEmpty();
};

Stack::Stack(int s)
{
    top = -1;
    len = s;
    arr = new int[len];
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "It's Empty!\n";
        return 0;
    }
    return arr[top];
}

int Stack::pop()
{
    int tmp = peek();
    top--;
    return tmp;
}

void Stack::push(int num)
{
    if (isFull())
    {
        cout << "It's Full!\n";
        return;
    }
    top++;
    arr[top] = num;
}

bool Stack::isFull()
{
    if (top == len - 1)
    {
        return true;
    }
    return false;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

Stack::~Stack()
{
    delete[] arr;
}

int main()
{
    Stack s(1);
    s.push(5);
    s.push(3);
    cout << s.pop();
    cout << s.pop();
}