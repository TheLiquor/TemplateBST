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
	struct node
	{
		T data;
		node* left, right;
	};
	node* root;
public:
	MyBST()
	{
		root = NULL;
	}

	// Insert specified value into BST
	template <class T>
	void MyBST<T>::insert(T data)
	{

	}
	// Delete given node, restructure tree accordingly
	// Max | Find maximum value in the BST
	// Traverse | Traverse the tree and return the data in the order of traversal. (inorder, preorder, or postorder)
};

int main()
{
    return 0;
}

