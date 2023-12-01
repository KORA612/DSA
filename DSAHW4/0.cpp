#include <iostream>
using namespace std;

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
        return arr[f-1];
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
    cout<<endl;
}

int main()
{
    Queue q1(5);
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.printQueue();
    q1.enQueue(4);
    q1.enQueue(5);
    q1.enQueue(6);
    q1.printQueue();
    cout << q1.deQueue();
    cout << q1.deQueue();
    cout << q1.deQueue();
    q1.printQueue();
    q1.deQueue();
    q1.deQueue();
    q1.printQueue();
}
