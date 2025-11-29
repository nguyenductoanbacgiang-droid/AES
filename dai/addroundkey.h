#ifndef ADDROUNDKEY_H
#define ADDROUNDKEY_H
#include <stdint.h>
void AddRoundKey(uint8_t state[16], const uint8_t roundKey[16]);
#endif

