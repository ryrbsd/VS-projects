// BST.h

#ifndef _BST_h
#define _BST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//generic data type <Key, Value>
template <typename Key, typename Value> class BST
{
public:
    /*============Node(BST)================
    The tree node has 2 pointer 2 variables
    */
	class Node
	{
		public:
			Node *left; // left child of the node
			Node *right; // right child of the node
			Key key; // the key of the node
			Value value; // the value of the code storing
			
			/*==========Node============
			The constructor of Node(BST)
			Input: Key key, Value value
			return: Node
			*/
			Node(Key key, Value value)
			{
				left = NULL;
				right = NULL;
				this->key = key;
				this->value = value;
			}
			
			/*==========~Node============
			The disconstructor of Node(BST)
			Set all thing to none
			*/
			~Node()
			{
				left = NULL;
				right = NULL;
				key = NULL;
				value = NULL;
			}
	};
	int size; // size of BST
	Node *head; // the head node of BST
	
	/*==========BST============
	The constructor of BST
	*/
	BST()
	{
		size = 0;
		head = NULL;
	}
	
	/*==========~BST============
	The disstructor of BST
	*/
	~BST()
	{
		if (head != NULL)
		{
			deleteTree(head);
		}
	}
	
	/*==============deleteTree============
	This fucntion is to delete whole tree starting from the node
	Input: Node *node
	return: void
	*/
	void deleteTree(Node *node)
	{
		if (node->left != NULL)
			deleteNode(node->left);
		if (node->right != NULL)
			deleteNode(node->right);
		delete node;
		size--;
		node = NULL;
		return;
	}

	/*===========insert=============
	This function insert new node in to BST by key
	Input: Key key, Value value
	return void
	*/
	void insert(Key key, Value value)
	{
		head = insert(key, value, head);
		size = countsize(head);
	}

	/*===========get=============
	This function get value from bst by key
	Input: Key key
	return Value value
	*/
	Value get(Key key)
	{
		return find(key, head);
	}

	/*===========deleteByKey=============
	This function delete value from bst by key
	Input: Key key
	return void
	*/
	void deleteByKey(Key key)
	{
		deleteNode(head, key);
		size = countsize(head);
	}

	/*===========findMinValue=============
	This function find minimum key's value from bst 
	return Value
	*/
	Value findMinValue()
	{
		Node *min = findMin(head);
		if (min != NULL)
			return findMin(head)->value;
		else
			return NULL;
	}

	/*===========deleteMin=============
	This function delete minimum key's value from bst 
	return void
	*/
	void deleteMin()
	{
		head = deleteMin(head);
		size = countsize(head);
	}
	
	//private functions
	private: 
		/*===========find=============
		This function find value from key in bst start from head
		Input: Key key, Node *head
		return Value value
		*/
		Value find(Key key, Node *head)
		{
			if (head == NULL || head->key == NULL)
			{
				return NULL;
			}
			else if (key > head->key)
			{
				return find(key, head->right);
			}
			else if (key < head->key)
			{
				return find(key, head->left);
			}
			else
			{
				return head->value;
			}
		}
		
		/*===========insert=============
		This function insert value by key in bst start from head
		Input: Key key, Node *head, Value value
		return Node *current
		*/
		Node *insert(Key key, Value value, Node *current)
		{
			if (current == NULL)
			{
				current = new Node(key, value);
				size++;
			}
			else if (key < current->key)
			{
				current->left = insert(key, value, current->left);
			}
			else if (key > current->key)
			{
				current->right = insert(key, value, current->right);
			}
			else
			{
				current->value = value;
			}
			return current;
		}

		/*===========countsize=============
		This function count number of Nodes of bst starting from head
		Input:  Node *head
		return int size
		*/
		int countsize(Node *head)
		{
			if (head == NULL)
				return 0;
			return countsize(head->left) + countsize(head->right) + 1;
		}
		
		/*===========deleteNode=============
		This function delete value by key in bst start from head and return the 
		new tree after delete
		Input: Key key, Node *head
		return Node *head(New tree)
		*/
		Node deleteNode(Node *head, Key key)
		{
			if (head == NULL) 
				return NULL;
			if (key < head->key)
				head->left = deleteNode(head->left, key);
			else if (key > head->key)
				head->right = deleteNode(head->right, key);
			else
			{
				if (head->right == NULL)
					return head->left;
				if (head->left == NULL)
					return head->right;
				Node *temp = head;
				head = findMin(head->right);
				head->right = deleteMin(temp->right);
				head->left = temp->left;

			}
			return head;
		}
		
		/*===========findMin=============
		This function find the value which key is minimum in bst start from head and return the 
		value
		Input: Node *head
		return Value *value(New tree)
		*/
		Value *findMin(Node *head)
		{
			if (head->left != NULL)
				return findMin(head->left);
			return head->value;
		}

		/*===========deleteMin=============
		This function delete value by min key in bst start from head and return the 
		new tree after delete
		Input: Node *head
		return Node *head(New tree)
		*/
		Node *deleteMin(Node *head)
		{
			if (head->left == NULL)
			{
				Node *right = head->right;
				delete head;
				return right;
			}

			head->left = deleteMin(head->left);
			return head;
		}

};


#endif

