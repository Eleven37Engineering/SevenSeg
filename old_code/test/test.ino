#include "SevenSeg.h"

SevenSeg *sevenSeg;

void setup() 
{
  // put your setup code here, to run once:
  sevenSeg = new SevenSeg();
}

void loop() 
{ 
  sevenSeg->SetDisplay("abcd", 1000);
}
