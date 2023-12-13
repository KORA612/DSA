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

class Queue
{
private:
    int f, r;
    int size;
    int *arr;

public:
    Queue(int s);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enQueue(int num);
    int deQueue();
    void printQueue();
};

Queue::Queue(int s)
{
    f = 0;
    r = -1;
    size = s - 1;
    arr = new int[size];
}
Queue::~Queue()
{
    delete[] arr;
}
bool Queue::isFull()
{
    return r == size;
}
bool Queue::isEmpty()
{
    return f > r;
}
void Queue::enQueue(int num)
{
    if (isFull())
    {
        cout << "it's Full.\n";
        return;
    }
    r++;
    arr[r] = num;
}
int Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "it's Empty.\n";
    }
    else
    {
        f++;
        return arr[f - 1];
    }
}
void Queue::printQueue()
{
    if (isEmpty())
    {
        cout << "it's Empty.\n";
        return;
    }
    int i = f;
    for (i; i <= r; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

Stack reverse(Stack s, int ns)
{
    Queue q(ns);
    Stack res(ns);
    for (int i = 0; i < ns; i++)
    {
        q.enQueue(s.pop());
        res.push(q.deQueue());
    }
    return res;
}

int main()
{
    Stack s(5);
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    
    s = reverse(s,5);
    for (int i = 0; i < 5; i++)
    {
        cout << s.pop();
    }
    
}