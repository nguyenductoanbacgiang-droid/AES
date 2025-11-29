#include <stdint.h>
#include "invshiftrows.h"

void InvShiftRows(uint8_t state[16]){
    uint8_t tmp;

    tmp=state[13]; 
	state[13]=state[9]; 
	state[9]=state[5]; 
	state[5]=state[1]; 
	state[1]=tmp;
    tmp=state[2]; 
	state[2]=state[10]; 
	state[10]=tmp;
    tmp=state[6]; 
	state[6]=state[14]; 
	state[14]=tmp;
    tmp=state[3]; 
	state[3]=state[7]; 
	state[7]=state[11]; 
	state[11]=state[15]; 
	state[15]=tmp;
}

