#ifndef __CFL_BRAIN_HASH_TABLE_SUPPORT_H__
#define __CFL_BRAIN_HASH_TABLE_SUPPORT_H__

#define hash(x) fnv_hash_string_CFL(x)

int hash_perl(const char *str);
int fnv_hash_string_CFL(const char* data );
int fnv_hash_CFL(const void* data, int len); 
uint32_t JenkinsHash_CFL(const void *key, size_t len);

#endif