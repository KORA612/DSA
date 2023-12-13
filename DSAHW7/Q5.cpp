
#include <iostream>
class Node
{
	public:
		int data;
		Node* next;
		Node(){data = 0; next = NULL;}
		Node(int data){this->data = data; next = NULL;}
	
};
class stack
{
	public:
		Node* top;
		stack(){top = NULL;}
		~stack()
		{
			Node* temp = top;
			while(top)
			{
				top = top->next;
				delete temp;
				temp = top;
			}
				
		}
		void push( int data )
		{
				
			Node* node = new Node( data );
			if(top == NULL)
			{
				top = node;
			}
			else
			{
				node->next = top;
				top = node;
			}
		}
		int pop()
		{
			if(top == NULL)
				throw("list is empty");
			int tempData = top->data;
			Node* temp = top;
			top = top->next;
			delete temp;

			return tempData;
		}
};
int main()
{
	stack s;
	s.push(2);
	s.push(3);
	s.push(4);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	return 0;
}
