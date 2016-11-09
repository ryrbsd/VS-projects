// Node.h

#ifndef _NODE_h
#define _NODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
//This Node class is only for Linkedlist, BST has it's own 
//subclass BST:Node
class Node {
public:
	char note; // the note stroe in Linkedlist Node
	int beat; // the beat stroe in Linkedlist Node
	Node *prev; // the pointer of prev node
	Node *next; // the pointer of next node
	Node();
	Node(int inbeat, char innote);
	~Node();
};

#endif

