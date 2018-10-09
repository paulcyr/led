#ifndef RGB_H
#define RGB_H

#include <cstdint>

class RGB {

	static const int MAX_VALUE = 255;

	public:
	
		uint8_t r, g, b;

		RGB(uint8_t r, uint8_t g, uint8_t b);

		float getHue();
		float* getHSL();
		float* getHSB();
};

#endif