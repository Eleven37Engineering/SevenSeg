#include "SevenSeg.h"
#include "Arduino.h"

#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

#define CC1 10
#define CC2 11
#define CC3 12
#define CC4 13

SevenSeg::SevenSeg()
{
	setup();
}

byte numbers[36][7] = 
{ 
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}, // 9 
  {1, 1, 1, 0, 1, 1, 1}, // A
  {1, 1, 1, 1, 1, 1, 1}, // B
  {1, 0, 0, 1, 1, 1, 0}, // C
  {1, 1, 1, 1, 1, 1, 0}, // D
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1}, // F
  {1, 0, 1, 1, 1, 1, 1}, // G
  {0, 1, 1, 0 ,1, 1, 1}, // H
  {0, 1, 1, 0, 0, 0, 0}, // I
  {0, 1, 1, 1, 1, 0, 0}, // J
  {0, 1, 1, 0, 1, 1, 1}, // K
  {0, 0, 0, 1, 1, 1, 0}, // L
  {0, 1, 1, 0, 1, 1, 1}, // M
  {0, 1, 1, 0, 1, 1, 1}, // N
  {1, 1, 1, 1, 1, 1, 0}, // O
  {1, 1, 0, 0, 1, 1, 1}, // P
  {1, 1, 1, 1, 1, 1, 0}, // Q
  {1, 1, 1, 0, 1, 1, 1}, // R 
  {1, 0, 1, 1, 0, 1, 1}, // S
  {0, 1, 1, 0, 0, 0, 1}, // T
  {0, 1, 1, 1, 1, 1, 0}, // U
  {0, 1, 1, 1, 1, 1, 0}, // V
  {0, 1, 1, 1, 1, 1, 0}, // W
  {0, 1, 1, 0 ,1, 1, 1}, // X
  {0, 1, 1, 1, 0, 0, 1}, // Y
  {1, 1, 0, 1, 1, 0, 1}  // Z
};

const int segments[8] = {A, B, C, D, E, F, G};

void SevenSeg::setup()
{
	pinMode(A, OUTPUT);
  digitalWrite(A, LOW);
  pinMode(B, OUTPUT);
  digitalWrite(B, LOW);
  pinMode(C, OUTPUT);
  digitalWrite(C, LOW);
  pinMode(D, OUTPUT);
  digitalWrite(D, LOW);
  pinMode(E, OUTPUT);
  digitalWrite(E, LOW);
  pinMode(F, OUTPUT);
  digitalWrite(F, LOW);
  pinMode(G, OUTPUT);
  digitalWrite(G, LOW);

  // Set Common Cathodes to High to ensure all digits are off. 
  pinMode(CC1, OUTPUT);
  digitalWrite(CC1, HIGH);
  pinMode(CC2, OUTPUT);
  digitalWrite(CC2, HIGH);
  pinMode(CC3, OUTPUT);
  digitalWrite(CC3, HIGH);
  pinMode(CC4, OUTPUT);
  digitalWrite(CC4, HIGH);
}



void SevenSeg::setSegments(int number, int digit, int time)
{
	for(int seg = 0; seg < 8; seg++)
  {
    // Puts 5V to the anode of the segment if the numbers array shows a 1
    if(numbers[number][seg] == 1)
    {
		  digitalWrite(segments[seg], HIGH);
    }
    // Puts 0V to the anode of the segment if the numbers array shows a anything BUT 1, i.e. 0
    else
    {
		  digitalWrite(segments[seg], LOW);
    }
  }
  // Sets the voltage to the Common Cathode to 0V(LOW), ie the LEDs that have 5V at the anode, 
  // the number is diplayed
  digitalWrite(digit, LOW);
  // Set the on time, set in Microseconds. Or one millionth of a second. 0.000001
  delayMicroseconds(time);
  // Sets the Common Cathode to 5V(High), ie the LEDs are no longer visible.
  digitalWrite(digit, HIGH);
}

void SevenSeg::SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4, uint32_t time)
{
  setSegments(digit1, CC1, time); 
  setSegments(digit2, CC2, time); 
  setSegments(digit3, CC3, time); 
  setSegments(digit4, CC4, time); 
}

void SevenSeg::SetDisplay(char* value, uint32_t time)
{
  this->SetDisplay(value[0] - 55, value[1] - 55, value[2] - 55, value[3] - 55, time);
}



