//To evaluate this data structure, write your program to read from 
//an array of unsorted integers.You could also read from a data 
//file(with the filename passed as a command line parameter) and populates 
//the data structure.
//
//Rigorous testing is expected!Be sure to include tests for attempting to 
//remove a node from an empty BST, attempting to insert a duplicate node, 
//removing a node with no children, removing a node with one child, and removing 
//a node with two children.Be sure to verify the BST organization and structure are correct.

#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class MyBST
{
private:
	struct myNode
	{
		T data;
		myNode* left;
		myNode* right;
	};
	myNode* root;
public:
	MyBST()
	{
		root = NULL;
	}
	// Insert specified value into BST
	void insert(T);
	
	// Delete given node, restructure tree accordingly

	// Max | Find maximum value in the BST

	// Traverse | Traverse the tree and return the data in the order of traversal. (inorder)
	void traverseTree(myNode*);
	void callTraversal(); // called from main to trigger the actual traversal function to start at root

};


template <class T>
void MyBST<T>::insert(T input)
{
	myNode* temp = new myNode;
	myNode* parent;
	temp->data = input;
	temp->left = NULL;
	temp->right = NULL;

	if (isEmpty()) root = temp;
	else
	{
		myNode* current;
		current = root;
		while (current)
		{
			parent = current;
			if (temp->data > current->data) current = current->right;
		}

		if (temp->data < parent->data)
		{
			parent->left = temp;
		}
		else {
			parent->right = temp;
		}
	}
}

template <class T>
void MyBST<T>::callTraversal()
{
	traverseTree(root);
}

template <class T>
void MyBST<T>::traverseTree(myNode* ptr)
{
	if (ptr == NULL) return;
	else
	{
		if (ptr->left) traverseTree(ptr->left);
		cout << " " << ptr->data << " ";
		if (ptr->right) traverseTree(ptr->right);
	}
}



int main()
{
	MyBST<int> tree;
	
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	
	tree.callTraversal();

	system("pause");



    return 0;
};

