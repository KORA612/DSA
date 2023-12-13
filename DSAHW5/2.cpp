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

void inCommon(Stack s, int ns, Queue q, int nq)
{
    int clonedQueue[nq];
    int clonedStack[ns];
    for (int i = 0; i < nq; i++)
    {
        clonedQueue[i] = q.deQueue();
    }
    for (int i = 0; i < ns; i++)
    {
        clonedStack[i] = s.pop();
    }
    for (int i = 0; i < nq; i++)
    {
        for (int j = 0; j < ns; j++)
        {
            if (clonedQueue[i] == clonedStack[j])
            {
                cout << clonedQueue[i];
            }
        }
    }
    return;
}

int main()
{
    Stack s(5);
    Queue q(5);
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    q.enQueue(1);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(5);

    inCommon(s,5,q,5);
}