#include <stdint.h>
#include "invmixcolumns.h"

static uint8_t multiply(uint8_t x, uint8_t y){
    uint8_t result=0;
    int i;
    for(i=0;i<8;i++){
        if(y & 1) result ^= x;
        uint8_t hi_bit_set = x & 0x80;
        x <<= 1;
        if(hi_bit_set) x ^= 0x1b;
        y >>= 1;
    }
    return result;
}

void InvMixColumns(uint8_t state[16]){
	int i;
    for(i=0;i<4;i++){
        uint8_t s0=state[i*4+0], s1=state[i*4+1], s2=state[i*4+2], s3=state[i*4+3];
        state[i*4+0]=multiply(s0,0x0e)^multiply(s1,0x0b)^multiply(s2,0x0d)^multiply(s3,0x09);
        state[i*4+1]=multiply(s0,0x09)^multiply(s1,0x0e)^multiply(s2,0x0b)^multiply(s3,0x0d);
        state[i*4+2]=multiply(s0,0x0d)^multiply(s1,0x09)^multiply(s2,0x0e)^multiply(s3,0x0b);
        state[i*4+3]=multiply(s0,0x0b)^multiply(s1,0x0d)^multiply(s2,0x09)^multiply(s3,0x0e);
    }
}

