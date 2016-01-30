#include "Logger.h"
#include "Arduino.h"

Logger::Logger(int baud)
{
  Serial.begin(baud);
}

void Logger::info(String msg)
{
  Serial.println(msg);
}

void Logger::info(int msg)
{
  Serial.println(msg);
}

void Logger::warn(String msg)
{
  Serial.println(msg);
}

void Logger::error(String msg)
{
  Serial.println(msg);
}

void Logger::debug(String msg)
{
  Serial.println(msg);
}
