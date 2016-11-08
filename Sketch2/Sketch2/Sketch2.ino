#include <Map.h>
/*
Use the buzzer to play a song!
The buzzer in your Inventor's Kit is an electromechanical
component you can use to make noise. Inside the buzzer is a
coil of wire and a small magnet. When current flows through
the coil, it becomes magnetized and pulls towards the magnet,
creating a tiny "click". When you do this thousands of times
per second, you create tones.

The Arduino has a built-in command called tone() which clicks
the buzzer at a certain frequency. This sketch knows the
frequencies of the common notes, allowing you to create songs.
We're never going to let you down!
Hardware connections:
The buzzer has two pins. One is positive and one is negative.
The postitive pin is marked by a "+" symbol on both the top
and bottom of the buzzer.

Connect the positive pin to Arduino digital pin 9.
(Note that this must be a PWM pin.)
Connect the negative pin to GND.
*/

/*
This sketch uses the buzzer to play songs.
The Arduino's tone() command will play notes of a given frequency.
We'll provide a function that takes in note characters (a-g),
and returns the corresponding frequency from this table:
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
const int switchPin = 10;
const int buzzerPin = 9;
const int aPin = 8;
const int bPin = 2;
const int cPin = 3;
const int dPin = 4;
const int ePin = 5;
const int fPin = 6;
const int gPin = 7;

// We'll set up an array with the notes we want to play
// change these values to make different songs!

// Length must equal the total number of notes and spaces 

//const int songLength = 18;

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)

//sky city
char notes[] = "abCbCEbeeagaCg"; // a space represents a rest"abCbCEb"

// Beats is an array values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.
//sky city
int beats[] = { 1, 1, 3, 1, 2, 2, 4, 1, 1, 3, 1, 2, 2, 4};

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 150;


void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(switchPin, INPUT);
}


void loop() {
	int i, duration;
	int songLength = strlen(notes);
	int one_read;
	one_read = digitalRead(switchPin);
	Serial.print(one_read);
	if (one_read == HIGH)
	{
		

		for (i = 0; i < songLength; i++) // step through the song arrays
		{
			duration = beats[i] * tempo;  // length of note/rest in ms

			if (notes[i] == ' ')          // is this a rest? 
			{
				delay(duration);            // then pause for a moment
			}
			else                          // otherwise, play the note
			{
				tone(buzzerPin, frequency(notes[i], duration), duration);
				delay(duration);            // wait for tone to finish
				lightDown();
			}
			delay(tempo / 10);              // brief pause between notes
		}
	}
	// We only want to play the song once, so we'll pause forever:
	// If you'd like your song to play over and over,
	// remove the above statement
}




int frequency(char note, int duration) {
	// This function takes a note character (a-g), and returns the
	// corresponding frequency in Hz for the tone() function.

	int i;
	const int numNotes = 14;  // number of notes we're storing

	// The following arrays hold the note characters and their
	// corresponding frequencies. The last "C" note is uppercase
	// to separate it from the first lowercase "c". If you want to
	// add more notes, you'll need to use unique characters.

	// For the "char" (character) type, we put single characters
	// in single quotes.

	char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C',
						'D', 'E', 'F', 'G', 'A', 'B'};
	//char names[] = { '1', '2', '3', '4', '5', '6', '7', '8' };
	int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523,
						587, 659, 699, 784, 800, 988};


	Map<char, int> *name_to_freq = new Map<char, int>();
	// Now we'll search through the letters in the array, and if
	// we find it, we'll return the frequency for that note.

	for (i = 0; i < numNotes; i++)  // Step through the notes
	{
		if (names[i] == note)         // Is this the one?
		{
			if (names[i] == 'c' || names[i] == 'C')
			{
				lightUp(cPin);
			}
			else if (names[i] == 'd' || names[i] == 'D')
			{
				lightUp(dPin);
			}
			else if (names[i] == 'e' || names[i] == 'E')
			{
				lightUp(ePin);
			}
			else if (names[i] == 'f' || names[i] == 'F')
			{
				lightUp(fPin);
			}
			else if (names[i] == 'g' || names[i] == 'G')
			{
				lightUp(gPin);
			}
			else if (names[i] == 'a' || names[i] == 'A')
			{
				lightUp(aPin);
			}
			else if (names[i] == 'b' || names[i] == 'B')
			{
				lightUp(bPin);
			}
				
			return(frequencies[i]);     // Yes! Return the frequency
		}

	}

	name_to_freq->add('c', 262);
	//name_to_freq.add('d', 294);
	//name_to_freq.add('e', 330);
	//name_to_freq.add('f', 349);
	//name_to_freq.add('g', 392);
	//name_to_freq.add('a', 440);
	//name_to_freq.add('b', 494);
	//name_to_freq.add('C', 523);
	//name_to_freq.add('D', 587);
	//name_to_freq.add('E', 659);
	//name_to_freq.add('F', 699);
	//name_to_freq.add('G', 784);
	//name_to_freq.add('A', 800);
	//name_to_freq.add('B', 988);
	//return name_to_freq.find(note);

	
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

}