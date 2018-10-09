#include "RGB.h"
#include <cstdint>
#include <algorithm>


RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {};

float RGB::getHue() {

	float hue;

	uint8_t max_abs = std::max({r, g, b});
	uint8_t min_abs = std::min({r, g, b});
	
	if (max_abs == min_abs) {
		hue = 0;
	}
	else {

		float max_rel, min_rel, diff, r_rel, g_rel, b_rel;

		max_rel = max_abs / MAX_VALUE;
		min_rel = min_abs / MAX_VALUE;
		diff = max_rel - min_rel;
		r_rel = r / MAX_VALUE;
		g_rel = g / MAX_VALUE;
		b_rel = b / MAX_VALUE;

		if (max_abs == r) {
			hue = (g_rel - b_rel) / diff;

			if (g < b) {
				hue += 6;
			}
		}
		else if (max_abs == g) {
			hue = 2 + (b_rel - r_rel) / diff;
		}
		else { // max_abs == b
			hue = 4 + (r_rel - g_rel) / diff;
		}

		hue *= 60;

		if (hue < 0) {
			hue += 360;
		}
		
	}

	return hue;
}

float *RGB::getHSB() {

	float hsb_h, hsb_s, hsb_b, max_rel, min_rel;

	uint8_t max_abs = std::max({r, g, b});
	uint8_t min_abs = std::min({r, g, b});

	max_rel = max_abs / MAX_VALUE;
	min_rel = min_abs / MAX_VALUE;

	hsb_h = getHue();
	hsb_s = max_abs == 0 ? 0 : (max_rel - min_rel) / max_rel;
	hsb_b = max_rel;

	float hsb[3] = {hsb_h, hsb_s, hsb_b};

	return hsb;
}

float *RGB::getHSL() {
	
	float hsb_h, hsb_s, hsb_l, max_rel, min_rel;

	uint8_t max_abs = std::max({r, g, b});
	uint8_t min_abs = std::min({r, g, b});

	max_rel = max_abs / MAX_VALUE;
	min_rel = min_abs / MAX_VALUE;

	hsb_h = getHue();
	hsb_s = (max_abs == 0 || min_abs == MAX_VALUE)
		? 0
		: (max_rel - min_rel) / (1 - std::abs(max_rel + min_rel - 1));
	hsb_l = (max_rel + min_rel) / 2;

	float hsl[3] = {
		hsb_h,
		hsb_s,
		hsb_l
	};

	return hsl;
}
