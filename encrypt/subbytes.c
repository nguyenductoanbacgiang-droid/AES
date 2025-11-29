#include "subbytes.h"
#include "sbox.h"
void SubBytes(uint8_t* state) {
	int i;
for(i=0;i<16;i++) state[i] = sbox[state[i]];
}


