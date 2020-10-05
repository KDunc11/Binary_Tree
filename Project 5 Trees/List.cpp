#include "List.h"

//Constructor
template<typename T>
List<T>::List()
{
	head = tail = iterator = nullptr;
}

//Destructor
template<typename T>
List<T>::~List()
{
}

//Public Member Functions
template<typename T>
bool List<T>::insert(const T& new_Data)
{
	if (head == nullptr) //Inserting into an empty list
	{
		Node<T>* node = new Node<T>(new_Data);

		head = node; //Sets and and tail equal to the node being inserted, creating the first node in the list
		tail = node;
		return true;
	}
	else if (head->next == nullptr) //Inserting into a list with one node
	{
		Node<T>* node = new Node<T>(new_Data);

		head->next = node; //Inserts a node after the first node in the list
		tail = node; //Updates tail to the newly inserted node
		return true;
	}
	else //Inserting with more than two nodes in the list
	{
		Node<T>* node = new Node<T>(new_Data);
		Node<T>* temp = head;

		while (temp->next != nullptr) //Traverses through the list till reaching the tail
			temp = temp->next;

		temp->next = node; //Inserts node at the end of the list
		tail = node; //Updates tail to the newly inserted node
		return true;
	}
	return false;
}

template<typename T>
bool List<T>::isEmpty()
{
	if (head == nullptr) //If head is equal to nullptr then the list is empty
		return true;
	else
		return false; //Otherwise the list contains at list one node
}

template<typename T>
bool List<T>::pop_back() //Removes the last node in the list
{
	if (isEmpty()) //Checks if there are any nodes in the list
		return false;
	else if (head->next == nullptr) //If there is one node in the list
	{
		head = tail = nullptr; //Removes the node from the list
		return true;
	}
	else //If there are two or more nodes in the list
	{
		Node<T>* temp = head;
		Node<T>* storePrev = temp;

		while (temp->next != nullptr) //Traverses to the end of the list
		{
			storePrev = temp;
			temp = temp->next;
		}

		tail = storePrev; //Moves tail to the node before the last node in the list
		tail->next = nullptr; //Removes the last node in the list
		return true;
	}
}

template<typename T>
void List<T>::clearList() //Used to remove all the nodes from a list
{
	while (isEmpty() == false) //Removes nodes from the back of the list until there aren't any nodes left
		pop_back();
}

template<typename T>
T* List<T>::back() //Returns the value stored at the end of the list
{
	if (isEmpty())
		return NULL;
	else
		return &(tail->data);
}

template<typename T>
T* List<T>::front()
{
	if (isEmpty())
		return NULL;
	else
		return &(head->data);
}

template<typename T>
void List<T>::printList(ostream& ostrm)const
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		ostrm << temp->data << " ";
		temp = temp->next;
	}
}

//Friend Functions
template<class T2>
ostream& operator <<(ostream& ostrm, const List<T2>& list)
{
	list.printList(ostrm);
	return ostrm;
}
