// 
// 
// 

#include "Linkedlist.h"

/*==========Linkedlist==============
constructor of the linked list
*/
Linkedlist::Linkedlist()
{
	size = 0; 
	first = new Node();
	last = new Node();
	first->next = last;
	first->prev = NULL;
	last->next = NULL;
	last->prev = first;
}

/*==========~Linkedlist==============
disstructor of the linked list
*/
Linkedlist::~Linkedlist()
{
	while (first->next != NULL && first->next != last)
	{
		Node *current = first->next;
		first->next->next->prev = first;
		first = first->next->next;
		delete current;
	}
	delete first;
	if (last != NULL)
		delete last;
}

/*==========Linkedlist==============
disstructor of the linked list, init by array of char and int
Input: char notes[], int beats[]
*/
Linkedlist::Linkedlist(char notes[], int beats[])
{
	size = 0;
	first = new Node();
	last = new Node();
	first->next = last;
	first->prev = NULL;
	last->next = NULL;
	last->prev = first;
	int songLength = strlen(notes);

	for (int i = 0; i < songLength; i++)
	{
		addNode(beats[i], notes[i]);
	}
}

/*==========addNode==============
Add a new node into linkedlist
Input: char notes, int beats
*/
void Linkedlist::addNode(int beat, char note)
{
	Node *newNode = new Node(beat, note);

	last->prev->next = newNode;
	newNode->prev = last->prev;
	last->prev = newNode;
	newNode->next = last;
	size += 1;
}

/*==========deleteFirst==============
Delete a first node of linkedlist
*/
void Linkedlist::deleteFirst()
{
	Node *current = first->next;
	if (current != last)
	{
		first = current->next;
		current->next->prev = first;
		delete current;
	}
}

/*==========linkedlistTraverse==============
This function tones the notes and beats stored in linked list.
It get pin number of buzzer and two functions, one is turn off the light and 
one is frequency.
Input: const int buzzerPin, int tempo, void (*lightDown)(),int (*frequency)(char)
*/
void Linkedlist::linkedlistTraverse(const int buzzerPin, int tempo, 
									void (*lightDown)(),int (*frequency)(char))
{
	Node *current = first->next;
	int n = 0;
	while (current != last)
	{	
		if (current->note != NULL && current->beat != NULL)
		{
			int duration = current->beat * tempo;  // length of note/rest in ms
			if (current->note == ' ')
			{
				delay(duration);            // then pause for a moment
			}
			else
			{
				tone(buzzerPin, frequency(current->note), duration);
				delay(duration);              // brief pause between notes
				lightDown();
			}
			delay(tempo / 10);              // brief pause between notes

		}
		n++;
		current = current->next;
	}
}

