#ifndef _MEMLOG_H_
#define _MEMLOG_H_

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

void memlog_init(void);
void memlog_add(const char* inStr, int autoNewline);
int memlog_getAll(char* out, int maxOutLen);
void memlog_clear(void);
uint64_t memlog_timestamp(void);
void memlog_printf(const char* fmt, ...);

void memlog_print(void);
char* memlog_get(void);

#ifdef __cplusplus
}
#endif

#endif

