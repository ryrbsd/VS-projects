// BST.h

#ifndef _BST_h
#define _BST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

template <typename Key, typename Value> class BST
{
public:
	class Node
	{
		public:
			Node *left;
			Node *right;
			Key key;
			Value value;
		
			Node(Key key, Value value)
			{
				left = NULL;
				right = NULL;
				this->key = key;
				//Serial.println("node");
				//Serial.println(this->key);
				this->value = value;
			}
			~Node()
			{
				left = NULL;
				right = NULL;
				key = NULL;
				value = NULL;
			}
	};
	int size;
	Node *head;
	BST()
	{
		size = 0;
		head = NULL;
	}
	~BST()
	{
		if (head != NULL)
		{
			deleteTree(head);
		}
	}

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

	void insert(Key key, Value value)
	{
		//Serial.println(key);
		head = insert(key, value, head);
		size = countsize(head);
	}

	Value get(Key key)
	{
		return find(key, head);
	}

	void deleteByKey(Key key)
	{
		deleteNode(head, key);
		size = countsize(head);
	}

	Value findMinValue()
	{
		Node *min = findMin(head);
		if (min != NULL)
			return findMin(head)->value;
		else
			return NULL;
	}

	void deleteMin()
	{
		head = deleteMin(head);
		size = countsize(head);
	}

	private:
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

		int countsize(Node *head)
		{
			if (head == NULL)
				return 0;
			return countsize(head->left) + countsize(head->right) + 1;
		}
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

		Node *findMin(Node *head)
		{
			if (head->left != NULL)
				return findMin(head->left);
			return head->value;
		}

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

