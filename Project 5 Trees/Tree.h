#ifndef TREE_H
#define TREE_H

#include"TreeNode.h"
#include"TreeNode.cpp"

template<typename T>
class Tree
{
public:
	//Constructor
	Tree<T>();
	//Destructor
	~Tree();
	
	//Public Member Functions
	void insert(const T& el, const int& num);
	void print(ostream& ostrm)const;
	int leafNodeCount();
	int depth();
	
	//Friend Functions
	template< typename T2>
	friend ostream& operator << (ostream& ostrm, const Tree<T2>& tree); //Operator overloading for out stream <<
private:
	//Private Member Variables
	TreeNode<T>* root;
	
	//Private Member Functions
	void printTree(ostream& ostrm, TreeNode<T>* node)const;
	TreeNode<T>* getRoot();
	int getLeafCount(TreeNode<T>* node);
	int getMaxDepth(TreeNode<T>* node);
};
#endif