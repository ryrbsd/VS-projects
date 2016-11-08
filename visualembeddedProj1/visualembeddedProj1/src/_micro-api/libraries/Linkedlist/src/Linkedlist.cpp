// 
// 
// 

#include "Linkedlist.h"

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
void Linkedlist::addNode(int beat, char note)
{
	Node *newNode = new Node(beat, note);

	last->prev->next = newNode;
	newNode->prev = last->prev;
	last->prev = newNode;
	newNode->next = last;
	size += 1;
}

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
				//Serial.println("tone:");
				//Serial.println(current->note);
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

