#include "list.h"

List::List(const List& list2)// проверитть позже
{
	if (list2.head)
	{
		Node Temp(list2.head->data, list2.head);
		Node* TempPtr1 = &Temp;
		Node* TempPtr2 = (*list2.head).next; // ?
 		while (TempPtr1)
		{   
			TempPtr2 = TempPtr2->next;
			TempPtr1->next = new Node(TempPtr2->data, TempPtr2->next);
			TempPtr1 = TempPtr1->next;
			//TempPtr2 = TempPtr2->next;
		}
	}
	else
	{
		head = nullptr;
	}
}
//................................................................
List& List::operator=(const List & list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head)
		{
			head = new Node(list2.head->data, list2.head);
			Node* Temp1 = head;
			Node* Temp2 = list2.head->next;
			while (Temp2)
			{   
                Temp1->next = new Node(Temp2->data);
				Temp1 = Temp1->next;
				Temp2 = Temp2->next; // ??
			}
		}
	    else
			head = NULL;
	}
	return *this;
}
//................................................................
List::~List()
{
	while (head != nullptr) 
	{
		Node *Temp = head->next; 
		delete head; 
		head = Temp; 
	}
}
//................................................................
void List::InsertToHead(const DataType& d)
{
	Node* Temp = new Node(d, head);
	head = Temp;
}
//................................................................
void List::InsertToTail(const DataType & d)
{
	Node* Temp = head;
	if (Temp)
	{
		while (Temp->next)
			Temp = Temp->next;
		Temp->next = new Node(d);
	}
	else
		head = new Node(d);
}
//................................................................
void List::InsertAfter(Node * node, const DataType & d)
{ 


	if (node && head)
	{
		Node* Temp = node->next;
		node->next = new Node(d, Temp);
	}
	else
		if (!head) //?
			throw "Error";
}
//................................................................
void List::Delete(const DataType & d)
{
	
}
//................................................................
Node* List::Search(const DataType& d)
{
	return nullptr;
}
//................................................................
void List::Clean()
{

}
//................................................................
int List::GetSize()
{
	return 0;
}

//................................................................
Node* List::GetHead()
{
	return nullptr;
}
//................................................................
void List::Inverse()
{

}
//................................................................
List List::Merge(Node* node, const List& list2)
{   
	List Nul;
	return Nul;
}
//................................................................
List List::Merge(const List& list2)
{
    List Nul;
	return Nul;
}
//................................................................
bool List::operator==(const List& list2) const
{
	return 0;
}
//................................................................
ostream& operator<<(ostream& os, const List& l)
{
	return os;
}
