#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <initializer_list>

class Color {

  public:
    
    enum Type
     {
          RGB,
          HSL,
          HSB
     };
    
    Color(Color::Type type, std::initializer_list<uint8_t> values);
    Color(Color::Type type, std::initializer_list<float> values);
    
    void getRGB();
    void getHSL();
    void getHSB();

  protected:
  
    const Type type_;
    struct {
      union {
        struct {
          uint8_t r, g, b;
        };
        struct {
          float h, s, l;
        };
      };
    } value;
  
};

#endif
