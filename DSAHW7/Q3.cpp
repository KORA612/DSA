#include<iostream>

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(){data = 0; next = NULL; prev = NULL;}
		Node(int data){this->data = data; next = NULL; prev = NULL;}
	
};
class priorityQueue
{
	public:
		Node* front;
		Node* rear;
		priorityQueue(){front = NULL; rear = NULL;}
		~priorityQueue()
		{
			Node* temp = front;
			if(front!=NULL)
				while(front)
				{
					front = front->next;
					delete temp;
					temp = front;
				}
		}
		void enQueue( int data )
		{
				
			Node* node = new Node( data );
			if(front == NULL){
				front = node;
				rear = node;
			}
			else{
				rear->next = node;
				node->prev = rear;
				rear = node;
			}
		}
		int deQueue()
		{
			if(front == NULL)
				throw("list is empty");

			Node* min = front;
			Node* iterator = front;
			
			while(iterator != rear->next)
			{
				if(min->data > iterator->data)
				{
					min = iterator;
				}
				iterator = iterator->next;
			}
			int tempData = min->data;
			if(min == front && min == rear)
			{
				front = NULL;
				rear = NULL;
			}
			else if(min == front)
			{
				front = front->next;

			}
			else if(min == rear)
			{
				rear = rear->prev;

			}
			else
			{
				min->prev->next = min->next;
				min->next->prev = min->prev;
			}
			delete min;
			min = NULL;
			return tempData;
		}
		
};

int main()
{
	priorityQueue pQ;
	int n;
	std::cout << "Enter the number of elements:\n";
	std::cin >> n;
	int num;
	std::cout << "Enter the elements:\n";
	for(int i = 0; i < n; ++i){
		std::cin >> num;
		pQ.enQueue(num);
	}
	std::cout << std::endl;
	for(int i = 0; i < n; ++i)
		std::cout << pQ.deQueue() << std::endl;
	
	return 0;
}
