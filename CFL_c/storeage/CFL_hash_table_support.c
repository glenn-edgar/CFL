#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#include "Cfl_hash_table_support.h"
#include "Cfl_user_functions.h"


/*
  from
  https://stackoverflow.com/questions/2351087/what-is-the-best-32bit-hash-function-for-short-strings-tag-names
  with Perl extensions
*/
#define MULTIPLIER 33
int hash_perl(const char *str) {
  int h;
  unsigned char *p;

  h = 0;
  for (p = (unsigned char *)str; *p != '\0'; p++) {
    h = MULTIPLIER * h + *p;
  }
  h += (h >> 5);
  return h; // or, h % ARRAY_SIZE;
}

// FNV-1a constants
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U

int fnv_hash_string_CFL(const char *data) {
  int len;
  len = strlen(data);
  return fnv_hash_CFL(data, len);
}

// Compute the FNV-1a hash of a buffer
int fnv_hash_CFL(const void *data, int len) {
  const char *ptr = (const char *)data;
  int hash = FNV_OFFSET_32;
  for (int i = 0; i < len; i++) {
    hash ^= ptr[i];
    hash *= FNV_PRIME_32;
  }
  return hash;
}

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))

uint32_t MurmurHash3(const void *key, size_t len, uint32_t seed) {
  const uint8_t *data = (const uint8_t *)key;
  const int nblocks = len / 4;

  uint32_t h1 = seed;
  uint32_t c1 = 0xcc9e2d51;
  uint32_t c2 = 0x1b873593;

  // Body
  const uint32_t *blocks = (const uint32_t *)(data + nblocks * 4);
  for (int i = -nblocks; i; i++) {
    uint32_t k1 = blocks[i];

    k1 *= c1;
    k1 = ROTL32(k1, 15);
    k1 *= c2;

    h1 ^= k1;
    h1 = ROTL32(h1, 13);
    h1 = h1 * 5 + 0xe6546b64;
  }

  // Tail
  const uint8_t *tail = (const uint8_t *)(data + nblocks * 4);
  uint32_t k1 = 0;
  switch (len & 3) {
  case 3:
    k1 ^= tail[2] << 16;
  case 2:
    k1 ^= tail[1] << 8;
  case 1:
    k1 ^= tail[0];
    k1 *= c1;
    k1 = ROTL32(k1, 15);
    k1 *= c2;
    h1 ^= k1;
  }

  // Finalization
  h1 ^= len;
  h1 ^= h1 >> 16;
  h1 *= 0x85ebca6b;
  h1 ^= h1 >> 13;
  h1 *= 0xc2b2ae35;
  h1 ^= h1 >> 16;

  return h1;
}

int JenkinsHash_CFL(const void *key, size_t len) {
  const uint8_t *data = (const uint8_t *)key;
  uint32_t hash = 0;

  for (size_t i = 0; i < len; i++) {
    hash += data[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return (int)hash;
}
 