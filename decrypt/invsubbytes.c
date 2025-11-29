#include <stdint.h>
#include "invsubbytes.h"
#include "invsbox.h"

void InvSubBytes(uint8_t state[16]){
	int i;
    for(i=0;i<16;i++)
        state[i]=inv_sbox[state[i]];
}

