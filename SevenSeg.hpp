#ifndef SEVENSEG_HPP
#define SEVENSEG_HPP

#include <stdint.h>


class SevenSeg
{
	public:
		SevenSeg();
		void SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4);


	private:
		void setup();
		void setSegments(int number, int digit, int time);
};

#endif