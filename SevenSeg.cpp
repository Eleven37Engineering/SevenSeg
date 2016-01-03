#include <SevenSeg.hpp>

SevenSeg::SevenSeg()
{
	setup();
}

void SevenSeg::SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4)
{
	
}

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