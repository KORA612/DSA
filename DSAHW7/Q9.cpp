#include <iostream>
class Node
{
	public:
		int data;
		Node* next;
		Node(){data = 0; next = NULL;}
		Node(int data){this->data = data; next = NULL;}
		Node(const Node& n)
		{
			data = n.data;
			next = new Node;
			*next = *(n.next);
		}
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
		void add_last( int data )
		{
			Node* node = new Node( data );
			if(head == NULL)
			{
				head = node;
				return;
			}
			Node* temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node;
			
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
void duplicate(Node* head)
{
	if(head == NULL)
		return;
	duplicate(head->next);
	Node* newNode = new Node(head->data);
	newNode->next = head->next;
	head->next = newNode;

}
int main()
{
	singlyLinkedList L;
	L.add_last(4);
	L.add_last(3);
	L.add_last(2);
	L.add_last(1);
	L.print();
	std::cout << std::endl;
	duplicate(L.head);
	L.print();

	return 0;
}
