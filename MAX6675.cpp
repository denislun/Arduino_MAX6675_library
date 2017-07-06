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
  int temp = readBits();
  temp <<= 8; 
  temp |= readBits(); 
  digitalWrite(_cs,HIGH); 
  if(temp & 0x4) return MAX6675_TERMINAL_CONNECTION_ERROR; 
  temp >>= 3; 
  return temp*.25;
}

int MAX6675::readBits(){
  int resp = 0; 
  for(int i = 0; i < 8; i ++){
    digitalWrite(_sck,HIGH);
    
    resp |= digitalRead(_miso) << (7-i);  
    digitalWrite(_sck,LOW); 
  }
  return resp; 
}
