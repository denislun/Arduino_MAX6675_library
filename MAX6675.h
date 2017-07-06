#ifndef MAX6675_h
#define MAX6675_h

#include "Arduino.h"
#define MAX6675_TERMINAL_CONNECTION_ERROR -999.1

class MAX6675{
public: 
  MAX6675(int cs, int mosi, int miso, int sck); 
  double readTemp(); 
private: 
  int readBits();	
  int _miso, _mosi, _sck, _cs;
}; 

#endif