#include "mixcolumns.h"
static uint8_t xtime(uint8_t x) { return (uint8_t)((x<<1) ^ ((x & 0x80) ? 0x1b : 0x00)); }
void MixColumns(uint8_t* state) {
uint8_t i,t,Tmp,Tm;
for(i=0;i<4;i++){
t = state[i*4];
Tmp = state[i*4] ^ state[i*4+1] ^ state[i*4+2] ^ state[i*4+3];
Tm = state[i*4] ^ state[i*4+1]; 
Tm = xtime(Tm); 
state[i*4] ^= Tm ^ Tmp;
Tm = state[i*4+1] ^ state[i*4+2]; 
Tm = xtime(Tm); 
state[i*4+1] ^= Tm ^ Tmp;
Tm = state[i*4+2] ^ state[i*4+3]; 
Tm = xtime(Tm); 
state[i*4+2] ^= Tm ^ Tmp;
Tm = state[i*4+3] ^ t; 
Tm = xtime(Tm); 
state[i*4+3] ^= Tm ^ Tmp;
}
}
