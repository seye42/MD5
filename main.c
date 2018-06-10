# include <stdint.h>
# include <stdio.h>
# include <sys/stat.h>

# include "constants.h"

uint32_t f(const uint32_t x, const uint32_t y, const uint32_t z)
{
  return (x & y) | ((~x) & z);
}

uint32_t g(const uint32_t x, const uint32_t y, const uint32_t z)
{
  return (x & y) | (y & (~z));
}

uint32_t h(const uint32_t x, const uint32_t y, const uint32_t z)
{
  return x ^ y ^ z;
}

uint32_t i(const uint32_t x, const uint32_t y, const uint32_t z)
{
  return y ^ (x | (~z));
}

uint32_t circularLeftShift(uint32_t val, uint32_t shift)
{
  return (val << shift) | (val >> (32 - shift));
}

void round1(uint32_t* A, uint32_t* B, uint32_t* C, uint32_t* D, uint32_t* X)
{
  *A = circularLeftShift(*A + f(*B, *C, *D) + X[0]  + T[0],   7);
  *D = circularLeftShift(*D + f(*A, *B, *C) + X[1]  + T[1],  12);
  *C = circularLeftShift(*C + f(*D, *A, *B) + X[2]  + T[2],  17);
  *B = circularLeftShift(*B + f(*C, *D, *A) + X[3]  + T[3],  22);
  *A = circularLeftShift(*A + f(*B, *C, *D) + X[4]  + T[4],   7);
  *D = circularLeftShift(*D + f(*A, *B, *C) + X[5]  + T[5],  12);
  *C = circularLeftShift(*C + f(*D, *A, *B) + X[6]  + T[6],  17);
  *B = circularLeftShift(*B + f(*C, *D, *A) + X[7]  + T[7],  22);
  *A = circularLeftShift(*A + f(*B, *C, *D) + X[8]  + T[8],   7);
  *D = circularLeftShift(*D + f(*A, *B, *C) + X[9]  + T[9],  12);
  *C = circularLeftShift(*C + f(*D, *A, *B) + X[10] + T[10], 17);
  *B = circularLeftShift(*B + f(*C, *D, *A) + X[11] + T[11], 22);
  *A = circularLeftShift(*A + f(*B, *C, *D) + X[12] + T[12],  7);
  *D = circularLeftShift(*D + f(*A, *B, *C) + X[13] + T[13], 12);
  *C = circularLeftShift(*C + f(*D, *A, *B) + X[14] + T[14], 17);
  *B = circularLeftShift(*B + f(*C, *D, *A) + X[15] + T[15], 22);
  return;
}

void round2(uint32_t* A, uint32_t* B, uint32_t* C, uint32_t* D, uint32_t* X)
{
  *A = circularLeftShift(*A + g(*B, *C, *D) + X[1]  + T[16],  5);
  *D = circularLeftShift(*D + g(*A, *B, *C) + X[6]  + T[17],  9);
  *C = circularLeftShift(*C + g(*D, *A, *B) + X[11] + T[18], 14);
  *B = circularLeftShift(*B + g(*C, *D, *A) + X[0]  + T[19], 20);
  *A = circularLeftShift(*A + g(*B, *C, *D) + X[5]  + T[20],  5);
  *D = circularLeftShift(*D + g(*A, *B, *C) + X[10] + T[21],  9);
  *C = circularLeftShift(*C + g(*D, *A, *B) + X[15] + T[22], 14);
  *B = circularLeftShift(*B + g(*C, *D, *A) + X[4]  + T[23], 20);
  *A = circularLeftShift(*A + g(*B, *C, *D) + X[9]  + T[24],  5);
  *D = circularLeftShift(*D + g(*A, *B, *C) + X[14] + T[25],  9);
  *C = circularLeftShift(*C + g(*D, *A, *B) + X[3]  + T[26], 14);
  *B = circularLeftShift(*B + g(*C, *D, *A) + X[8]  + T[27], 20);
  *A = circularLeftShift(*A + g(*B, *C, *D) + X[13] + T[28],  5);
  *D = circularLeftShift(*D + g(*A, *B, *C) + X[2]  + T[29],  9);
  *C = circularLeftShift(*C + g(*D, *A, *B) + X[7]  + T[30], 14);
  *B = circularLeftShift(*B + g(*C, *D, *A) + X[12] + T[31], 20);
  return;
}

void round3(uint32_t* A, uint32_t* B, uint32_t* C, uint32_t* D, uint32_t* X)
{
  *A = circularLeftShift(*A + h(*B, *C, *D) + X[5]  + T[32],  4);
  *D = circularLeftShift(*D + h(*A, *B, *C) + X[8]  + T[33], 11);
  *C = circularLeftShift(*C + h(*D, *A, *B) + X[11] + T[34], 16);
  *B = circularLeftShift(*B + h(*C, *D, *A) + X[14] + T[35], 23);
  *A = circularLeftShift(*A + h(*B, *C, *D) + X[1]  + T[36],  4);
  *D = circularLeftShift(*D + h(*A, *B, *C) + X[4]  + T[37], 11);
  *C = circularLeftShift(*C + h(*D, *A, *B) + X[7]  + T[38], 16);
  *B = circularLeftShift(*B + h(*C, *D, *A) + X[10] + T[39], 23);
  *A = circularLeftShift(*A + h(*B, *C, *D) + X[13] + T[40],  4);
  *D = circularLeftShift(*D + h(*A, *B, *C) + X[0]  + T[41], 11);
  *C = circularLeftShift(*C + h(*D, *A, *B) + X[3]  + T[42], 16);
  *B = circularLeftShift(*B + h(*C, *D, *A) + X[6]  + T[43], 23);
  *A = circularLeftShift(*A + h(*B, *C, *D) + X[9]  + T[44],  4);
  *D = circularLeftShift(*D + h(*A, *B, *C) + X[12] + T[45], 11);
  *C = circularLeftShift(*C + h(*D, *A, *B) + X[15] + T[46], 16);
  *B = circularLeftShift(*B + h(*C, *D, *A) + X[2]  + T[47], 23);
  return;
}

void round4(uint32_t* A, uint32_t* B, uint32_t* C, uint32_t* D, uint32_t* X)
{
  *A = circularLeftShift(*A + i(*B, *C, *D) + X[0]  + T[48],  6);
  *D = circularLeftShift(*D + i(*A, *B, *C) + X[7]  + T[49], 10);
  *C = circularLeftShift(*C + i(*D, *A, *B) + X[14] + T[50], 15);
  *B = circularLeftShift(*B + i(*C, *D, *A) + X[5]  + T[51], 21);
  *A = circularLeftShift(*A + i(*B, *C, *D) + X[12] + T[52],  6);
  *D = circularLeftShift(*D + i(*A, *B, *C) + X[3]  + T[53], 10);
  *C = circularLeftShift(*C + i(*D, *A, *B) + X[10] + T[54], 15);
  *B = circularLeftShift(*B + i(*C, *D, *A) + X[1]  + T[55], 21);
  *A = circularLeftShift(*A + i(*B, *C, *D) + X[8]  + T[56],  6);
  *D = circularLeftShift(*D + i(*A, *B, *C) + X[15] + T[57], 10);
  *C = circularLeftShift(*C + i(*D, *A, *B) + X[6]  + T[58], 15);
  *B = circularLeftShift(*B + i(*C, *D, *A) + X[13] + T[59], 21);
  *A = circularLeftShift(*A + i(*B, *C, *D) + X[4]  + T[60],  6);
  *D = circularLeftShift(*D + i(*A, *B, *C) + X[11] + T[61], 10);
  *C = circularLeftShift(*C + i(*D, *A, *B) + X[2]  + T[62], 15);
  *B = circularLeftShift(*B + i(*C, *D, *A) + X[9]  + T[63], 21);
  return;
}

uint32_t* readFileToBuffer(const char* name, uint64_t* size)
{
  // local variables
  int ret;
  uint64_t fileSize;
  FILE* fd;

  // get the file size and allocate the buffer
  struct stat st;
  ret = stat(name, &st);
  if (ret != 0)
  {
    perror("readFileToBuffer|stat()");
    exit(1);
  }
  fileSize = st.st_size;

  // determine the necessary padding


  // open the file
  fd = fopen(name, "r");
}

int main(const int argc, const char* argv[])
{
  // local variables
  uint32_t A, B, C, D;
  uint32_t Ap, Bp, Cp, Dp;
  uint32_t block, numBlocks;
    // each block is 512 b = 64 B, so uint32_t will work for files up to ~275 GB
  uint32_t* Xptr;

  // set initial values
  A = initialA;
  B = initialB;
  C = initialC;
  D = initialD;

  // calculate the digest
  for (block = 0; block < numBlocks; ++block)
  {
    Ap = A;
    Bp = B;
    Cp = C;
    Dp = D;
    Xptr = &X[block << 4];  // advance 16 words of 32 b each (= 512 b)
    round1(&A, &B, &C, &D, Xptr);
    round2(&A, &B, &C, &D, Xptr);
    round3(&A, &B, &C, &D, Xptr);
    round4(&A, &B, &C, &D, Xptr);
    A += Ap;
    B += Bp;
    C += Cp;
    D += Dp;
  }

  // display the digest
  printf("0x%08X%08X%08X%08X\n", A, B, C, D);

  return 0;
}
