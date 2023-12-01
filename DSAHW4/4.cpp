/*
Problem 4 : How many elements are in a CircularQueue Q1(n) ?

    elements in Q1 :
        if r>=f --> (r-f)
        if r<f  --> (r-f) + size

*/

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int r, f;
    int size;
    int *arr;

public:
    CircularQueue(int s);
    ~CircularQueue();
    void enCircularQueue(int value);
    int deCircularQueue();
    void displayCircularQueue();
    int elements();
};

CircularQueue::CircularQueue(int s)
{
    f = r = -1;
    size = s;
    arr = new int[s];
}
CircularQueue::~CircularQueue()
{
    delete[] arr;
}
void CircularQueue::enCircularQueue(int value)
{
    if ((f == 0 && r == size - 1) ||
        ((r + 1) % size == f))
    {
        printf("\nCircularQueue is Full");
        return;
    }

    else if (f == -1)
    {
        f = r = 0;
        arr[r] = value;
    }

    else if (r == size - 1 && f != 0)
    {
        r = 0;
        arr[r] = value;
    }

    else
    {
        r++;
        arr[r] = value;
    }
}
int CircularQueue::deCircularQueue()
{
    if (f == -1)
    {
        printf("\nCircularQueue is Empty");
        return INT_MIN;
    }

    int data = arr[f];
    arr[f] = -1;
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else if (f == size - 1)
        f = 0;
    else
        f++;

    return data;
}
void CircularQueue::displayCircularQueue()
{
    if (f == -1)
    {
        printf("\nCircularQueue is Empty");
        return;
    }
    printf("\nElements in Circular CircularQueue are: ");
    if (r >= f)
    {
        for (int i = f; i <= r; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = f; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= r; i++)
            printf("%d ", arr[i]);
    }
}
int CircularQueue::elements()
{
    if (r >= f)
        return r - f + 1;
    else
        return (size - f) + r + 1;
}

int main()
{
    CircularQueue q(5);

    q.enCircularQueue(14);
    q.enCircularQueue(22);
    q.enCircularQueue(13);
    q.enCircularQueue(-6);

    q.displayCircularQueue();
    cout << "__" << q.elements() << "__";

    printf("\nDeleted value = %d", q.deCircularQueue());
    printf("\nDeleted value = %d", q.deCircularQueue());

    q.displayCircularQueue();
    cout << "__" << q.elements() << "__";

    q.enCircularQueue(9);
    q.enCircularQueue(20);
    q.enCircularQueue(5);

    q.displayCircularQueue();
    cout << "__" << q.elements() << "__";

    q.enCircularQueue(20);
    return 0;
}
