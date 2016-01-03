#ifndef SEVENSEG_H
#define SEVENSEG_H

#include <stdint.h>


class SevenSeg
{
	public:
		SevenSeg();
		void SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4, uint32_t time);


	private:
		void setup();
		void setSegments(int number, int digit, int time);
};

#endif