#include "MAX6675.h"
MAX6675::MAX6675(int cs, int mosi, int miso, int sck){
  _miso = miso;
  _mosi = mosi;
  _sck = sck; 
  _cs = cs; 
  pinMode(_cs,OUTPUT);
  pinMode(_miso, INPUT);
  pinMode(_mosi, OUTPUT);
  pinMode(_sck, OUTPUT); 
  digitalWrite(_cs,HIGH);
}

double MAX6675::readTemp(){ 
  digitalWrite(_cs,LOW); 
  delay(1);
  int temp = shiftIn(_miso, _sck, MSBFIRST);
  temp <<= 8; 
  temp |= shiftIn(_miso, _sck, MSBFIRST); 
  digitalWrite(_cs,HIGH); 
  if(temp & 0x4) return MAX6675_TERMINAL_CONNECTION_ERROR; 
  temp >>= 3; 
  return temp*.25;
}
