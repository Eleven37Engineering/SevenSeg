#include <stdint.h>


class SevenSeg
{
	public:
		SevenSeg();
		SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4);


	private:
		setup();
		setSegments(int number, int digit, int time);
}