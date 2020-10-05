#include "Tree.h"

//Constructor
template<typename T>
Tree<T>::Tree()
{
	root = nullptr; //Creates an empty binary tree
}

//Destructor
template<typename T>
Tree<T>::~Tree()
{
}

//Public Member Functions
template<typename T>
void Tree<T>::insert(const T& el, const int &num) //Inserts a word and verse number into the tree
{
	TreeNode<T>* p = root, *prev = nullptr;

	while (p != nullptr)
	{
		prev = p;
		if (el < p->data)
			p = p->left;
		else if (el == p->data)
			break;
		else
			p = p->right;
	}

	if (root == nullptr) //If the tree is empty then create a new node
	{
		root = new TreeNode<T>(el);
		root->verses->insert(num);
	}
	else if (el == prev->data) //If the list has one or more nodes and the word equals the word found just insert the verse number into the list
		prev->verses->insert(num);
	else if (el < prev->data) //If the data is less than the node's data then insert a new node as the current's node left child and the verse number into the list
	{
		prev->left = new TreeNode<T>(el); 
		prev->left->verses->insert(num);
	}
	else //If the data is greater than the node's data then insert a new node as the current's node right child and the verse number into the list
	{
		prev->right = new TreeNode<T>(el);
		prev->right->verses->insert(num);
	}
}

template<typename T>
void Tree<T>::print(ostream& ostrm)const
{
	this->printTree(ostrm, root);
}

template<typename T>
int Tree<T>::leafNodeCount()
{
	return getLeafCount(this->root);
}

template<typename T>
int Tree<T>::depth()
{
	return getMaxDepth(root);
}

//Private Member Functions
template<typename T>
void Tree<T>::printTree(ostream& ostrm, TreeNode<T>* node)const
{
	if (node != nullptr)
	{
		if (node->left)
			printTree(ostrm, node->left);

		ostrm << node->data << ": " << *node->verses << endl;

		if (node->right)
			printTree(ostrm, node->right);
	}
}

template<typename T>
TreeNode<T>* Tree<T>::getRoot()
{
	return root;
}

template<typename T>
int Tree<T>::getLeafCount(TreeNode<T>* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getLeafCount(node->left) +
		getLeafCount(node->right);
}

template<typename T>
int Tree<T>::getMaxDepth(TreeNode<T>* node)
{
	if (node == nullptr) //Check if the tree is empty 
		return 0;
	else
	{
		int leftDepth = getMaxDepth(node->left); //Checks the left subtree
		int rightDepth = getMaxDepth(node->right); //Checks the right subtree

		if (leftDepth > rightDepth)
			return (leftDepth++); //Increments the left value
		else
			return (rightDepth++); //Increments the right value
	}
}

//Friend Functions
template<class T2>
ostream& operator << (ostream& ostrm, const Tree<T2>& tree)
{
	tree.print(ostrm);
	return ostrm << endl;
}