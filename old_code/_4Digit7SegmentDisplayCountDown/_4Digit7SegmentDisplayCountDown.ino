/*********************************************
    Eleven37 Engineering
 *********************************************/

void loop()
{
for(int digit1 = 2; digit1 >= 0; digit1--)
  {
    for(int digit2 = 9; digit2 >= 0; digit2--)
    {
      for(int digit3 = 9; digit3 >= 0; digit3--)
      {
        for(int digit4 = 9; digit4 >= 0; digit4--)
        {
          setDisplay(digit1, digit2, digit3, digit4);
        }  
      }  
    }
  }
}






