#pragma once
#include "List.h"
#include"List.cpp"

template<typename T>
class TreeNode
{
public:
	//Default Constructor
	TreeNode<T>()
	{
		left = right = nullptr;
		verses = new List<int>();
	}

	//Constructor
	TreeNode<T>(const T& el)
	{
		data = el;
		left = right = nullptr;
		verses = new List<int>();
	}

	//Destructor
	~TreeNode() {}

	//Public Member Variables
	T data;
	List<int>* verses;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

