#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "CFL_hash_table_support.h"




#if 0

/*
  from
  https://stackoverflow.com/questions/2351087/what-is-the-best-32bit-hash-function-for-short-strings-tag-names
  with Perl extensions
*/
#define MULTIPLIER 33
static int hash_perl(const char *str) {
  int h;
  unsigned char *p;

  h = 0;
  for (p = (unsigned char *)str; *p != '\0'; p++) {
    h = MULTIPLIER * h + *p;
  }
  h += (h >> 5);
  return h; // or, h % ARRAY_SIZE;
}
#endif
// FNV-1a constants
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U



// Compute the FNV-1a hash of a buffer
static uint32_t fnv_hash_CFL(const void *data, uint32_t len) {
  const char *ptr = (const char *)data;
  uint32_t hash = FNV_OFFSET_32;
  for (uint32_t i = 0; i < len; i++) {
    hash ^= ptr[i];
    hash *= FNV_PRIME_32;
  }
  return hash;
}

static uint32_t fnv_hash_string_CFL(const char *data) {
  uint32_t len;
  len = strlen(data);
  return fnv_hash_CFL(data, len);
}
#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))


#if 0
// trouble compiling with lua compiler extension

static uint32_t MurmurHash3(const void *key, size_t len, uint32_t seed) {
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
#endif
#if 0
static int JenkinsHash_CFL(const void *key, size_t len) {
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
#endif

static int lua_fnv_hash_string_CFL(lua_State *L ){
   const char* string_name = luaL_checkstring(L, 1);  
    uint32_t hash = fnv_hash_string_CFL(string_name);
    lua_pushinteger(L, hash);
    return 1;
}

 static const luaL_Reg mylib_functions[] = {
   {"fnv_hash", lua_fnv_hash_string_CFL},
    {NULL, NULL}
};

int luaopen_cfl_hash(lua_State* L) {
    luaL_newlib(L, mylib_functions);  // Create a new Lua module table
    return 1;
}
