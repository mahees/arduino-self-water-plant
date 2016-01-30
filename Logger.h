#ifndef Logger_h
#define Logger_h

#include "Arduino.h"

class Logger
{
  public:
    Logger(int);
    void info(String);
    void info(int);
    void warn(String);
    void error(String);
    void debug(String);
  private:
};

#endif
