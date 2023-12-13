#include <iostream>
class Node
{
	public:
		int data;
		Node* next;
		Node(){data = 0; next = NULL;}
		Node(int data){this->data = data; next = NULL;}
	
};
class singlyLinkedList
{
	public:
		Node* head;
		singlyLinkedList(){head = NULL;}
		~singlyLinkedList()
		{
			while( head->next )
			{
				del_first();
			}
		}
		void add_first( int data )
		{
			Node* node = new Node( data );
			node->next = head;
			head = node;
		}
		int del_first()
		{
			if(head == NULL)
				throw("list is empty");
			
			int tempData = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;

			return tempData;
		}
		void print()
		{
			Node* iterator = head;
			while(iterator != NULL)
			{
				std::cout << iterator->data << std::endl;
				iterator = iterator->next;
			}
		}
};
void del_max(Node* head)
{
	if(head == NULL)
		return;
	Node* max = head;
	Node* iterator = head;
	Node* temp = head;
	while(iterator->next)
	{
		if(max->data < iterator->data)
		{
			max = iterator;
		}
		iterator = iterator->next;
	}
	iterator = head;
	while(iterator != max)
	{
		temp = iterator;
		iterator = iterator->next;
	}
	if(max == head && max->next == NULL)
		head = NULL;
	else if(max == head)
		head = head->next;
	else if(max->next == NULL)
		temp->next = NULL;
	else
		temp->next = max->next;
	delete max;
	
}
int main()
{
	singlyLinkedList list;
	list.add_first(12);
	list.add_first(1515);
	list.add_first(7959);
	list.add_first(124);
	list.add_first(142);
	list.print();
	del_max(list.head);
	list.print();
	return 0;
}
