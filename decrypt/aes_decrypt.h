#ifndef AES_DECRYPT_H
#define AES_DECRYPT_H
#include <stdint.h>
void AES_Decrypt(uint8_t state[16], const uint8_t roundKeys[176]);
#endif

