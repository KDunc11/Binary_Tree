#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Node.cpp"
#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	//Constructor
	List<T>();
	//Destructor
	~List();

	//Public Member Functions
	bool insert(const T& new_Data); //Used to insert a node into the list
	bool isEmpty(); //Checks if a list is empty
	bool pop_back(); //Removes last element in the list
	void clearList(); //Removes all nodes from the list
	T* back(); //Returns the value stored in the tail of the list
	T* front(); //Returns the value stored in the head of the list
	void printList(ostream& ostrm)const;
	
	//Friend Functions
	template<typename T2>
	friend ostream& operator <<(ostream& ostrm, const List<T2>& list); //Operator overloading for out stream <<
private:
	//Private Member Variables
	Node<T>* head;
	Node<T>* tail;
	Node<T>* iterator;
};
#endif