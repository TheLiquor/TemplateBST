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
	void deleteNode(T);

	// Max | Find maximum value in the BST
	int maxNode(myNode*);
	int callMax();

	// Traverse | Traverse the tree and return the data in the order of traversal. (inorder, preorder, or postorder)
	void traverseTree(myNode*);
	void callTraversal();

	// Check to see if empty
	bool checkTree() const { return root == NULL; }
};

template <class T>
void MyBST<T>::insert(T input)
{
	myNode* temp = new myNode;
	myNode* parent;
	temp->data = input;
	temp->left = NULL;
	temp->right = NULL;
	parent = NULL;

	if (checkTree()) root = temp;
	else
	{
		myNode* current;
		current = root;
		while (current)
		{
			parent = current;
			if (temp->data > current->data)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}

		if (temp->data < parent->data) {
			parent->left = temp;
		}
		else
		{
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
	if (ptr != NULL)
	{
		if (ptr->left) traverseTree(ptr->left);
		cout << " " << ptr->data << endl;
		if (ptr->right) traverseTree(ptr->right);
	}
	else return;
}

template <class T>
void MyBST<T>::deleteNode(T input)
{
	bool present = false;
	if (checkTree())
	{
		cout << "Empty" << endl;
		return;
	}
	myNode* current;
	myNode* parent;
	current = root;
	parent = (myNode*)NULL;

	while (current != NULL)
	{
		if (current->data == input)
		{
			present = true;
			break;
		}
		else
		{
			parent = current;
			if (input > current->data)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
	}

	if (!present)
	{
		cout << input << " was not found!" << endl;
		return;
	}

	if ((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL)) // Check to see if either sides are both NULL
	{
		if (current->left == NULL && current->right != NULL) // finding out which side is NULL
		{
			if (parent->left == current)
			{
				parent->left = current->right;
				delete current;
			}
			else
			{
				parent->right = current->right;
				delete current;
			}
		}
		else
		{
			if (parent->left == current)
			{
				parent->left = current->left;
				delete current;
			}
			else
			{
				parent->right = current->left;
				delete current;
			}
		}
	}

	else if (current->left == NULL && current->right == NULL)
	{
		if (parent == NULL)
		{
			delete current;

		}
		else
			if (parent->left == current) parent->left = NULL;
			else parent->right = NULL;
			delete current;
			return;
	}

	else if (current->left != NULL && current->right != NULL)
	{
		myNode* hold;
		hold = current->right;
		if ((hold->left == NULL) && (hold->right == NULL))
		{
			current = hold;
			delete hold;
			current->right = NULL;
		}
		else
		{
			if ((current->right)->left != NULL)
			{
				myNode* leftCurrent;
				myNode* leftPtr;
				leftPtr = current->right;
				leftCurrent = (current->right)->left;

				while (leftCurrent->left != NULL)
				{
					leftPtr = leftCurrent;
					leftCurrent = leftCurrent->left;
				}
				current->data = leftCurrent->data;
				delete leftCurrent;
				leftPtr->left = NULL;
			}
			else
			{
				myNode* temp;
				temp = current->right;
				current->data = temp->data;
				current->right = temp->right;
				delete temp;
			}
		}
		return;
	}


}

template <class T>
int MyBST<T>::callMax()
{
	int val = 0;
	val = maxNode(root);
	return val;
}

template <class T>
int MyBST<T>::maxNode(myNode* ptr)
{
	int max = ptr->data;

	if (ptr->left != nullptr) {
		int leftMax = maxNode(ptr->left);
		if (max < leftMax)
			max = leftMax;
	}

	if (ptr->right != nullptr) {
		int rightMax = maxNode(ptr->right);
		if (max < rightMax)
			max = rightMax;
	}

	return max;
}

int main()
{
	MyBST<int> tree;
	int max = 0;
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	cout << "New tree with inserts : " << endl;
	tree.callTraversal();

	cout << "Delete 7 out of tree : " << endl;
	tree.deleteNode(7);
	tree.callTraversal();

	max = tree.callMax();
	cout << "The maximum number found in the tree is : " << max << endl;


	system("pause");

	return 0;
}

