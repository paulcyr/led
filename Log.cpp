#include "Log.h"

Log::Log(int rate) {
  if (Serial) {
    Serial.begin(rate);
  }
}

bool Log::writeln() const {
  if (Serial) {
    return Serial.println() > 0;
  }

  return true;
}


