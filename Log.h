#ifndef LOG_H
#define LOG_H

#include <SPI.h>

class Log {

  public:
    
    Log(int rate = 9600);
    bool writeln() const;

    template<typename T>
    bool write(T value = "") const {
      if (Serial) {
        return Serial.print(value) > 0;
      }
  
      return true;
    }

    template<typename T>
    bool write(T value, int format) const {
      if (Serial) {
        return Serial.print(value, format) > 0;
      }
  
      return true;
    }

    template<typename T>
    bool writeln(T value = "") const {
      if (Serial) {
        return Serial.println(value) > 0;
      }
    
      return true;
    }

    template<typename T>
    bool writeln(T value, int format) const {
      if (Serial) {
        return Serial.println(value, format) > 0;
      }
    
      return true;
    }
  
};

#endif


