#include "aes_encrypt.h"
#include "subbytes.h"
#include "shiftrows.h"
#include "mixcolumns.h"
#include "addroundkey.h"
void AESEncrypt(uint8_t* input,uint8_t* output,uint8_t* roundKeys){ 
uint8_t state[16]; 
int i;
for(i=0;i<16;i++) 
state[i]=input[i]; 
AddRoundKey(state, roundKeys); 
int round;
for(round=1;round<=9;round++){ 
SubBytes(state); 
ShiftRows(state); 
MixColumns(state); 
AddRoundKey(state, roundKeys + round*16); 
} 
SubBytes(state); 
ShiftRows(state); 
AddRoundKey(state, roundKeys + 10*16); 
for(i=0;i<16;i++) output[i]=state[i]; 
}
