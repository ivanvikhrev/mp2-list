#include "list.h"

List::List(const List& list2)// проверитть позже
{
	if (list2.head)
	{ 
		Node *TempPtr = list2.head;
		head = nullptr;
		while (TempPtr)
		{
			
			InsertToTail(TempPtr->data);
			TempPtr = TempPtr->next;
		}
	}
	else
	{
		head = list2.head;
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
			Node *TempPtr = list2.head;
			head = nullptr;
			while (TempPtr)
			{    
				InsertToTail(TempPtr->data);
				TempPtr = TempPtr->next;
			}
		}
	    else
			head = nullptr;
	}
	return *this;
}
//................................................................
List::~List()
{
	while (head) 
	{
		Node *TempPtr = head->next; 
		delete head; 
		head = TempPtr; 
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
	Node* TempPtr = head;
	if (TempPtr)
	{
		while (TempPtr->next)
			TempPtr = TempPtr->next;
		TempPtr->next = new Node(d);
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
		if (!head)
			throw "ListIsEmpty";
}
//................................................................
void List::Delete(const DataType & d)
{   
	Node* TempPtr = head;
	Node* TempPtr1 = head;

	if (TempPtr)
	{
		while (TempPtr->next && TempPtr->data != d)
		{
			TempPtr1 = TempPtr;
			TempPtr  =  TempPtr->next; 
		}

		if (TempPtr->data == d)
		{
			TempPtr1->next = TempPtr->next;
			if (TempPtr == head)
			{
				head = head->next;
			}
			delete TempPtr;
		}
	}

  
}
//................................................................
Node* List::Search(const DataType& d) 
{
	Node* TempPtr = head;

	while (TempPtr)
	{
		if (TempPtr->data == d)
			return TempPtr;
		TempPtr = TempPtr->next;
	}
	return nullptr;
}
//................................................................
void List::Clean()
{
	Node* TempPtr = head;
	Node* TempPtr1;

	if (TempPtr)
	{
		while (TempPtr->next)
		{
			TempPtr1 = TempPtr->next;
			delete TempPtr;
			TempPtr = TempPtr1;
		}
		delete TempPtr;
		head = nullptr;
	}
}
//................................................................
int List::GetSize()
{
	Node* TempPtr = head;
	int Size = 0;
	while (TempPtr)
	{
		Size++;
		TempPtr = TempPtr->next;
	}
	return Size;
}

//................................................................
Node* List::GetHead()
{
	return head;
}
//................................................................
void List::Inverse()
{
	if (head)
	{
		Node* TempPtr = head->next;
		head->next = nullptr;
		Node* TempPtr1 = head;
		Node* Ptr;
		while (TempPtr)
		{
			Ptr = TempPtr->next;
			TempPtr->next = TempPtr1;
			TempPtr1 = TempPtr;
			TempPtr = Ptr;
		}
		head = TempPtr1;
	}
}
//................................................................
List List::Merge(Node* node, const List& list2)
{   
	List MergeList;
	Node* TempPtr = head;
	if (head)
	{
		MergeList.head = new Node(head->data);
		Node* temp = MergeList.head;
		while (TempPtr->next && TempPtr != node)
		{
			temp->next = new Node(TempPtr->next->data);
			TempPtr = TempPtr->next;
			temp = temp->next;
		}
		if (TempPtr == node)
		{
			if (list2.head)
			{
				Node* TempPtr2 = list2.head;
				while (TempPtr2)
				{
					temp->next = new Node(TempPtr2->data);
					TempPtr2 = TempPtr2->next;
					temp = temp->next;
				}
			}
			while (TempPtr->next)
			{
				temp->next = new Node(TempPtr->next->data);
				TempPtr = TempPtr->next;
				temp = temp->next;
			}
		}
		temp->next = nullptr;
	}

	return MergeList;
}
//................................................................
List List::Merge(const List& list2)
{
	List MergeList(*this);
	if (MergeList.head && list2.head)
	{
		Node* TempPtr = MergeList.head;
		while (TempPtr->next)
			TempPtr = TempPtr->next;


		Node* TempPtr1 = list2.head;
		while (TempPtr1)
		{
			TempPtr->next = new Node(TempPtr1->data);
			TempPtr = TempPtr->next;
			TempPtr1 = TempPtr1->next;
		}
		TempPtr->next = nullptr;
	}
	else 
		if (MergeList.head == nullptr) 
			MergeList = List(list2);
	return MergeList;
}
//................................................................
bool List::operator==(const List& list2) const
{

	bool flag = true;
	if (head != list2.head)
	{
		Node* TempPtr1 = head;
		Node* TempPtr2 = list2.head;
		if (TempPtr1 != TempPtr2 && TempPtr1 && TempPtr2)
		{
			while (TempPtr1->next && TempPtr2->next && flag)
			{
				if (TempPtr1->data != TempPtr2->data)
					flag = false;
				else
				{
					TempPtr1 = TempPtr1->next;
					TempPtr2 = TempPtr2->next;
				}
			}
			if (TempPtr1->next || TempPtr2->next)
				flag = false;
		}
		else
			if (TempPtr1 != TempPtr2)
				flag = false;
	}
	return flag;
}
//................................................................
ostream& operator<<(ostream& os, const List& l)
{
	Node *TempPtr = l.head;  
	if (l.head)
	{   
		int i = 0;
		while (TempPtr)
		{
			
			os << i << ") " << TempPtr->data << " --- ";
			i++;
			TempPtr = TempPtr->next;
		}
		os << "end";
	}
	else
	{
		os << "Empty";
	}
	return os;
}
