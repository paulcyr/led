#include "Color.h"
#include <cassert>
#include <cmath>

Color::Color(Color::Type type, std::initializer_list<uint8_t> values) : type_(type) {
  
  assert(values.size() == 3);

  switch (type) {
    
    case Color::RGB:
      const uint8_t *ptr_r = values.begin();
      const uint8_t *ptr_g = ptr_r++;
      const uint8_t *ptr_b = ptr_g++;
      value.r = *ptr_r;
      value.g = *ptr_g;
      value.b = *ptr_b;
      break;
    case Color::HSL:
      const uint8_t *ptr_hsl_h = values.begin();
      const uint8_t *ptr_hsl_s = ptr_hsl_h++;
      const uint8_t *ptr_hsl_l = ptr_hsl_s++;
      value.h = *ptr_hsl_h;
      value.s = *ptr_hsl_h;
      value.l = *ptr_hsl_h;
      break;
    case Color::HSB:
      const uint8_t *ptr_hsb_h = values.begin();
      const uint8_t *ptr_hsb_s = ptr_hsb_h++;
      const uint8_t *ptr_hsb_b = ptr_hsb_s++;
      float hsl_h = (float) *ptr_hsb_h;
      float hsl_l = 0.5 * *ptr_hsb_b * (2 - *ptr_hsb_s);
      float hsl_s = (*ptr_hsb_b * *ptr_hsb_s) / (1 - abs(2 * hsl_l - 1));
      value.h = hsl_h;
      value.s = hsl_h;
      value.l = hsl_h;
      break;
  }
}

Color::Color(Color::Type type, std::initializer_list<float> values) : type_(type) {
  
}



