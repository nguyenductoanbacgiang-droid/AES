# AES Encryption / Decryption

## 1. Cách biên dịch và chạy

### Trên Linux:
gcc src/*.c -I include -o aes_encrypt
./aes_encrypt

### Trên Windows (Dev-C++, CodeBlocks):
- Add folder /include vào Compiler search path
- Add toàn bộ .c trong /src vào project
- Bấm Compile & Run

---

## 2. Bộ Test Vector (Chuẩn NIST FIPS-197)

Key:
2B 7E 15 16 28 AE D2 A6 AB F7 15 88 09 CF 4F 3C

Plaintext:
32 43 F6 A8 88 5A 30 8D 31 31 98 A2 E0 37 07 34

Expected Ciphertext:
39 25 84 1D 02 DC 09 FB DC 11 85 97 19 6A 0B 32

---

## 3. Project Structure
AES_Project/
│
├── aes_encrypt.c
├── aes_encrypt.h
├── aes_decrypt.c
├── aes_decrypt.h
│
├── keyexpansion.c
├── keyexpansion.h
│
├── addroundkey.c
├── addroundkey.h
│
├── subbytes.c
├── subbytes.h
├── sbox.c
├── sbox.h
│
├── shiftrows.c
├── shiftrows.h
│
├── mixcolumns.c
├── mixcolumns.h
│
├── invsubbytes.c
├── invsubbytes.h
├── invsbox.c
├── invsbox.h
│
├── invshiftrows.c
├── invshiftrows.h
│
├── invmixcolumns.c
├── invmixcolumns.h
│
├── main.c
├── README.md

