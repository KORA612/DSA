#include <iostream>

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(){data = 0; next = NULL; prev = NULL;}
		Node(int data){this->data = data; next = NULL; prev = NULL;}
	
};
class doublyList
{
	public:
		Node* head;
		doublyList(){head = NULL;}
		~doublyList()
		{
			Node* temp = head;
			if(head!=NULL)
				while(head)
				{
					head = head->next;
					delete temp;
					temp = head;
				}
		}
		void insert( int data )
		{
				
			Node* node = new Node( data );
			if(head == NULL){
				head = node;
			}
			else
			{
				Node* temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = node;
				node->prev = temp;

			}
		}
		int deleteLast()
		{
			if(head == NULL)
				throw("List is Empty");
			else if(head->next == NULL)
			{
				int tempData = head->data;
				delete head;
				head = NULL;
				return tempData;
			}
			else{
				Node* temp = head;
				while(temp->next != NULL)
					temp = temp->next;
				int tempData = temp->data;
				temp->prev->next = NULL;
				delete temp;

				return tempData;
			}
		}
};

void convert_to_circular(Node* head)
{
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
	head->prev = temp;

}
int main()
{
	doublyList d;
	d.insert(1);
	d.insert(2);
	d.insert(3);
	convert_to_circular(d.head);
	return 0;
}
