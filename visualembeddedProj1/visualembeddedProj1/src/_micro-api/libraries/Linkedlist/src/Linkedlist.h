// Linkedlist.h
#include "Node.h"
#ifndef _LINKEDLIST_h
#define _LINKEDLIST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"

#else
	#include "WProgram.h"
#endif
class Linkedlist {
	public:
		Node *first;
		Node *last;
		int size;
		Linkedlist();
		Linkedlist(char notes[], int beats[]);
		~Linkedlist();
		void linkedlistTraverse(const int buzzerPin, int tempo,
								void(*lightDown)(), int(*frequency)(char));
		void addNode(int beat, char note);
		void deleteFirst();
};


#endif

