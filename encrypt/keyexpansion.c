#include <stdint.h>
#include "keyexpansion.h"
#include "sbox.h"

#define Nb 4
#define Nk 4
#define Nr 10

static const uint8_t Rcon[11] = {0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};
static void RotWord(uint8_t *w){
    uint8_t t=w[0]; 
	w[0]=w[1]; 
	w[1]=w[2]; 
	w[2]=w[3]; 
	w[3]=t;
}
static void SubWord(uint8_t *w){
	int i;
    for(i=0;i<4;i++) w[i]=sbox[w[i]];
}
void KeyExpansion(const uint8_t key[16], uint8_t roundKeys[176]){
    int i=0; uint8_t temp[4];
    for(i=0;i<16;i++) roundKeys[i]=key[i];
    i=Nk;
    while(i<Nb*(Nr+1)){
        temp[0]=roundKeys[4*(i-1)+0]; 
		temp[1]=roundKeys[4*(i-1)+1];
        temp[2]=roundKeys[4*(i-1)+2]; 
		temp[3]=roundKeys[4*(i-1)+3];
        if(i%Nk==0){ 
		RotWord(temp); 
		SubWord(temp); temp[0]^=Rcon[i/Nk]; 
		}
        roundKeys[4*i+0]=roundKeys[4*(i-Nk)+0]^temp[0];
        roundKeys[4*i+1]=roundKeys[4*(i-Nk)+1]^temp[1];
        roundKeys[4*i+2]=roundKeys[4*(i-Nk)+2]^temp[2];
        roundKeys[4*i+3]=roundKeys[4*(i-Nk)+3]^temp[3];
        i++;
    }
}

