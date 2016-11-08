// Node.h

#ifndef _NODE_h
#define _NODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Node {
public:
	char note;
	int beat;
	Node *prev;
	Node *next;
	Node();
	Node(int inbeat, char innote);
	~Node();
};

#endif

