#include <stdint.h>
#include <stdint.h>
#include "aes_decrypt.h"
#include "invsubbytes.h"
#include "invshiftrows.h"
#include "invmixcolumns.h"
#include "addroundkey.h"
#include "keyexpansion.h"

void AES_Decrypt(uint8_t state[16], const uint8_t roundKeys[176]){
    int Nr=10;
    AddRoundKey(state,&roundKeys[Nr*16]);
    int round;
    for(round=Nr-1;round>=1;round--){
        InvShiftRows(state);
        InvSubBytes(state);
        AddRoundKey(state,&roundKeys[round*16]);
        InvMixColumns(state);
    }
    InvShiftRows(state);
    InvSubBytes(state);
    AddRoundKey(state,&roundKeys[0]);
}

