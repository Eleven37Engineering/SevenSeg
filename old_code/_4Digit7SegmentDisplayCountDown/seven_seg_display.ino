/***********************************************************************
    Brody Ricketts
    Makecourse.com
    University of South Florida
***********************************************************************/

/*
 * Define segments on the 7-Segment Display
 * Defined as the Segment address to the Arduino Address. ie Segment A on the 7-Segment Display
 * is assisgned to digital pin 2 on the Arduino.
 */
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP 9 // Decimal Point is not used in this sketch.

//    ---A--- 
//   |       |
// F |       | B
//   |---G---|
// E |       | C
//   |       |
//    ---D---


// Define the common Cathode pins. 
// The common cathode pins control the whole digits. 
#define CC1 10
#define CC2 11
#define CC3 12
#define CC4 13

// Define numberSegments
// numberSegments is an array to control the number displayed on the 7-Segment display

//byte numberSegments[10]
//{ 
//  /* 
//   *  {A, B, C, D, E, F, G, DP}
//   */
//  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
//  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
//  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
//  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
//  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
//  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
//  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
//  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
//  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
//  {1, 1, 1, 0, 0, 1, 1, 0}  // 9
//}

// Numbers array
// An array is defined and filled with the 'numberSegments' array defined above.
// Rows and columns are assigned as follows: numbers[number][segments]
byte numbers[10][8] = 
{ 
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 0, 0, 1, 1, 0}  // 9 
 };

const int segments[8] = {A, B, C, D, E, F, G, DP};

// Create a function to control the segments of the display
// Parameter digit is the digit of the display, ie 1-4
// the parameter time controls how long the segments are turned OFF
void setSegments(int number, int digit, int time)
{
  for(int seg = 0; seg < 8; seg++)
  {
    // Puts 5V to the anode of the segment if the numbers array shows a 1
    if(numbers[number][seg] == 1)
    {
      digitalWrite(segments[seg], HIGH);
    }
    // puts 0V to the anode of the segment if the numbers array shows a 0
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

void setup()
{
  // Set Anodes to Low to ensure segments are off.
  //Serial.begin(9600);
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
  pinMode(DP, OUTPUT);
  digitalWrite(DP, LOW);

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

void setDisplay(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4)
{
  for(int t = 0; t < 20; t++)
  {
    setSegments(dig1, CC1, 50);
    setSegments(dig2, CC2, 50);
    setSegments(dig3, CC3, 50);
    setSegments(dig4, CC4, 50);
  }  
}
