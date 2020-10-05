#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
	//Constructors
	Node() //Default Constructor
	{
		next = nullptr;
	}
	Node(T inputData) //Constructor for creating a node based off existing data
	{
		data = inputData;
		next = nullptr;
	}
	//Destructor
	~Node()
	{
		next = nullptr;
	}

	//Member Variables
	T data;
	Node* next;
};
#endif