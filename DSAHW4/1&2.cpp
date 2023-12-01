#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int f, r;
    int size;
    int *arr;

public:
    PriorityQueue(int s);
    ~PriorityQueue();
    bool isFull();
    bool isEmpty();
    void enPriorityQueue(int num);
    int dePriorityQueue();
    void printPriorityQueue();
    void shift(int ind);
};

PriorityQueue::PriorityQueue(int s)
{
    f = 0;
    r = -1;
    size = s - 1;
    arr = new int[size];
}
PriorityQueue::~PriorityQueue()
{
    delete[] arr;
}
bool PriorityQueue::isFull()
{
    return r == size;
}
bool PriorityQueue::isEmpty()
{
    return f > r;
}
void PriorityQueue::enPriorityQueue(int num)
{
    if (isFull())
    {
        cout << "it's Full.\n";
        return;
    }
    r++;
    arr[r] = num;
}
int PriorityQueue::dePriorityQueue()
{
    if (isEmpty())
    {
        cout << "it's Empty.\n";
    }
    else
    {
        int maxAmount = arr[f];
        int maxIndex = f;
        for (int i = f; i <= r; i++) // O(n)
        {
            if (arr[i] > maxAmount)
            {
                maxAmount = arr[i];
                maxIndex = i;
            }
        }
        // cout << maxAmount <<" "<< maxIndex<<endl ;
        shift(maxIndex);
        f++;
        return maxAmount;
    }
}
void PriorityQueue::printPriorityQueue()
{
    if (isEmpty())
    {
        cout << "it's Empty.\n";
        return;
    }
    for (int i = f; i <= r; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void PriorityQueue::shift(int ind)
{
    for (int i = ind; i > f; i--) // O(n)
    {
        arr[i] = arr[i - 1];
    }
}

int main()
{
    PriorityQueue q1(5);
    q1.enPriorityQueue(8);
    q1.enPriorityQueue(12);
    q1.enPriorityQueue(3);
    q1.enPriorityQueue(7);
    q1.enPriorityQueue(0);
    q1.printPriorityQueue();

    cout << q1.dePriorityQueue() << " ";
    cout << q1.dePriorityQueue() << " ";
    cout << q1.dePriorityQueue() << " ";
    cout << q1.dePriorityQueue() << " ";
    cout << q1.dePriorityQueue() << " ";
}

// O(2n) = O (n);