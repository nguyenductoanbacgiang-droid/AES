#include <stdint.h>
#include "addroundkey.h"

void AddRoundKey(uint8_t state[16], const uint8_t roundKey[16]){
	int i;
    for(i=0;i<16;i++) 
	state[i]^=roundKey[i];
}

