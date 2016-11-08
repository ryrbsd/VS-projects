#include "Linkedlist.h"
#include "BST.h"
#include "Treemap.h"
#include "Node.h"
#include "Linkedlist.h"
#include "Map.h"
#include <Map.h>

#define DEFAULT_ARRAY_LEN 5

/*
This sketch uses the buzzer to play songs.
note 	frequency
c     262 Hz
d     294 Hz
e     330 Hz
f     349 Hz
g     392 Hz
a     440 Hz
b     494 Hz
C     523 Hz
For more information, see http://arduino.cc/en/Tutorial/Tone
*/

const int numNotes = 14;  // number of notes we're storing
const int switchPin = 10;
const int buzzerPin = 9;
const int aPin = 6;
const int bPin = 7;
const int cPin = 8;
const int dPin = 2;
const int ePin = 3;
const int fPin = 4;
const int gPin = 5;
const int recordPin = 12;
const int highPin = 13;
const int recordMarkPin = 11;
const int stopPin = A0;
const int resatPin = A1;

// We'll set up an array with the notes we want to play
// change these values to make different songs!

// Length must equal the total number of notes and spaces 

//const int songLength = 18;

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)

//sky city
char defaultnotes[] = "abCbCEbeeagaCg"; // a space represents a rest"abCbCEb"

// Beats is an array values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.
//sky city
int defaultbeats[] = { 1, 1, 3, 1, 2, 2, 4, 1, 1, 3, 1, 2, 2, 4 };

char lastPlay = 0;
int recordMode = 0;

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 150;
Treemap<char, int> *name_to_freq;
Linkedlist *defaultList;
Linkedlist *songList;
Linkedlist *recordList;

unsigned long recordTime = 0;
int currentArraySize = DEFAULT_ARRAY_LEN;
int currentArrayLength = 0;

void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(switchPin, INPUT);
	digitalWrite(stopPin, LOW);
	pinMode(stopPin, INPUT);
	defaultList = new Linkedlist(defaultnotes, defaultbeats);
	songList = defaultList;
	recordList = new Linkedlist();



	name_to_freq = new Treemap<char, int>();
	name_to_freq->add('c', 262);
	name_to_freq->add('d', 294);
	name_to_freq->add('e', 330);
	name_to_freq->add('f', 349);
	name_to_freq->add('g', 392);
	name_to_freq->add('a', 440);
	name_to_freq->add('b', 494);
	name_to_freq->add('C', 523);
	name_to_freq->add('D', 587);
	name_to_freq->add('E', 659);
	name_to_freq->add('F', 699);
	name_to_freq->add('G', 784);
	name_to_freq->add('A', 800);
	name_to_freq->add('B', 988);
	Serial.println(name_to_freq->size());

}


void loop() {
	int i, duration;
	int songLength = strlen(defaultnotes);
	int one_read;
	one_read = digitalRead(switchPin);


	if (digitalRead(resatPin) && recordMode == 0)
	{
		songList = defaultList;
		delete recordList;
		recordList = new Linkedlist();
	}
	if (recordList != NULL && recordList->size != 0)
	{
		songList = recordList;
	}

	if (one_read == HIGH)
	{

		songList->linkedlistTraverse(buzzerPin, tempo, lightDown, frequency);

	}
	else if (digitalRead(recordPin))
	{

		if (recordMode == 0)
		{
			recordMode = 1;
			digitalWrite(recordMarkPin, HIGH);
			delay(500);
		}
		else
		{
			recordMode = 0;
			digitalWrite(recordMarkPin, LOW);
			recordList = new Linkedlist();
			delay(500);
		}

	}
	else if (recordMode == 1)
	{
		record();
	}
	else
	{
		play();
	}

}

void record()
{

	if ((lastPlay == 'c' || lastPlay == 'C') && !digitalRead(cPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'd' || lastPlay == 'D') && !digitalRead(dPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'e' || lastPlay == 'E') && !digitalRead(ePin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'f' || lastPlay == 'F') && !digitalRead(fPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'g' || lastPlay == 'G') && !digitalRead(gPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'a' || lastPlay == 'A') && !digitalRead(aPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if ((lastPlay == 'b' || lastPlay == 'B') && !digitalRead(bPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}

	else if (lastPlay == ' ' && !digitalRead(stopPin))
	{
		saveBeatAndNote();
		lastPlay = 0;
	}




	if (digitalRead(cPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('C'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'C')
			{
				lastPlay = 'C';
				recordTime = millis();
			}
			//else if (lastPlay != 'C')
			//{
			//	lastPlay = 'C';
			//	recordTime = millis();
			//}
		}

		else
		{
			tone(buzzerPin, frequency('c'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'c')
			{
				lastPlay = 'c';
				recordTime = millis();
			}
			//else if (lastPlay != 'c')
			//{
			//	lastPlay = 'c';
			//	recordTime = millis();
			//}
		}
	}
	else if (digitalRead(dPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('D'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'D')
			{
				lastPlay = 'D';
				recordTime = millis();
			}
			//else if (lastPlay != 'D')
			//{
			//	lastPlay = 'D';
			//	recordTime = millis();
			//}
		}

		else
		{
			tone(buzzerPin, frequency('d'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'd')
			{
				lastPlay = 'd';
				recordTime = millis();
			}
			//else if (lastPlay != 'd')
			//{
			//	lastPlay = 'd';
			//	recordTime = millis();
			//}
		}

	}
	else if (digitalRead(ePin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('E'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'E')
			{
				lastPlay = 'E';
				recordTime = millis();
			}
		}
		else
		{
			tone(buzzerPin, frequency('e'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'e')
			{
				lastPlay = 'e';
				recordTime = millis();
			}
		}
	}
	else if (digitalRead(fPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('F'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'F')
			{
				lastPlay = 'F';
				recordTime = millis();
			}
		}
		else
		{
			tone(buzzerPin, frequency('f'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'f')
			{
				lastPlay = 'f';
				recordTime = millis();
			}
		}

	}
	else if (digitalRead(gPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('G'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'G')
			{
				lastPlay = 'G';
				recordTime = millis();
			}
		}
		else
		{
			tone(buzzerPin, frequency('g'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'g')
			{
				lastPlay = 'g';
				recordTime = millis();
			}
		}
	}
	else if (digitalRead(aPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('A'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'A')
			{
				lastPlay = 'A';
				recordTime = millis();
			}
		}
		else
		{
			tone(buzzerPin, frequency('a'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'a')
			{
				lastPlay = 'a';
				recordTime = millis();
			}
		}
	}
	else if (digitalRead(bPin))
	{
		if (digitalRead(highPin))
		{
			tone(buzzerPin, frequency('B'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'B')
			{
				lastPlay = 'B';
				recordTime = millis();
			}
		}
		else
		{
			tone(buzzerPin, frequency('b'), tempo / 10);
			if (lastPlay == 0 || lastPlay != 'b')
			{
				lastPlay = 'b';
				recordTime = millis();
			}
		}
	}
	else if (digitalRead(stopPin))
	{
		if (lastPlay == 0 || lastPlay != ' ')
		{
			lastPlay = ' ';
			recordTime = millis();
		}
	}
	else
	{
		digitalWrite(buzzerPin, LOW);
		lightDown();
	}

}

void saveBeatAndNote()
{
	unsigned long curTime = millis();
	unsigned long timeDiff = curTime - recordTime;
	int beat = timeDiff / tempo;
	if (songList == defaultList || recordList == NULL)
	{
		if (recordList != NULL)
			delete recordList;
		recordList = new Linkedlist();
	}
	recordList->addNode(beat, lastPlay);

}

void play()
{
	if (digitalRead(cPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('C'), tempo / 10);
		else
			tone(buzzerPin, frequency('c'), tempo / 10);

	}
	else if (digitalRead(dPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('D'), tempo / 10);
		else
			tone(buzzerPin, frequency('d'), tempo / 10);

	}
	else if (digitalRead(ePin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('E'), tempo / 10);
		else
			tone(buzzerPin, frequency('e'), tempo / 10);
	}
	else if (digitalRead(fPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('F'), tempo / 10);
		else
			tone(buzzerPin, frequency('f'), tempo / 10);

	}
	else if (digitalRead(gPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('G'), tempo / 10);
		else
			tone(buzzerPin, frequency('g'), tempo / 10);

	}
	else if (digitalRead(aPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('A'), tempo / 10);
		else
			tone(buzzerPin, frequency('a'), tempo / 10);

	}
	else if (digitalRead(bPin))
	{
		if (digitalRead(highPin))
			tone(buzzerPin, frequency('B'), tempo / 10);
		else
			tone(buzzerPin, frequency('b'), tempo / 10);

	}
	else
	{
		digitalWrite(buzzerPin, LOW);
		lightDown();
	}
}



int frequency(char note) {
	// This function takes a note character (a-g), and returns the
	// corresponding frequency in Hz for the tone() function.

	int i;


	// The following arrays hold the note characters and their
	// corresponding frequencies. The last "C" note is uppercase
	// to separate it from the first lowercase "c". If you want to
	// add more notes, you'll need to use unique characters.

	// For the "char" (character) type, we put single characters
	// in single quotes.

	//char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C',
	//	'D', 'E', 'F', 'G', 'A', 'B' };
	//char names[] = { '1', '2', '3', '4', '5', '6', '7', '8' };
	//int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523,
	//	587, 659, 699, 784, 800, 988 };



	// Now we'll search through the letters in the array, and if
	// we find it, we'll return the frequency for that note.

	for (i = 0; i < numNotes; i++)  // Step through the notes
	{
		//Serial.println(name_to_freq->find(note));
		if (name_to_freq->find(note))         // Is this the one?
		{
			if (note == 'c' || note == 'C')
			{
				lightUp(cPin);
			}
			else if (note == 'd' || note == 'D')
			{
				lightUp(dPin);
			}
			else if (note == 'e' || note == 'E')
			{
				lightUp(ePin);
			}
			else if (note == 'f' || note == 'F')
			{
				lightUp(fPin);
			}
			else if (note == 'g' || note == 'G')
			{
				lightUp(gPin);
			}
			else if (note == 'a' || note == 'A')
			{
				lightUp(aPin);
			}
			else if (note == 'b' || note == 'B')
			{
				lightUp(bPin);
			}

			return name_to_freq->find(note);    // Yes! Return the frequency
		}

	}

	/*return name_to_freq->find(note);*/


	return(0);  // We looked through everything and didn't find it,
	// but we still need to return a value, so return 0.
}

void lightUp(int ledPin)
{
	digitalWrite(ledPin, HIGH);     // Turn the LED on
}

void lightDown()
{
	digitalWrite(aPin, LOW);      // Turn the LED off
	digitalWrite(bPin, LOW);
	digitalWrite(cPin, LOW);
	digitalWrite(dPin, LOW);
	digitalWrite(ePin, LOW);
	digitalWrite(fPin, LOW);
	digitalWrite(gPin, LOW);
	digitalWrite(stopPin, LOW);
}