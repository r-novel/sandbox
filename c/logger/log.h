#ifndef _LOG_H_
#define _LOG_H_

/***
 *       __                             
 *      / /  ___   __ _  __ _  ___ _ __ 
 *     / /  / _ \ / _` |/ _` |/ _ \ '__|
 *    / /__| (_) | (_| | (_| |  __/ |   
 *    \____/\___/ \__, |\__, |\___|_|   
 *                |___/ |___/           
 */


#include <stdio.h>

#define GREEN   "[1;32m"
#define MAGENTA "[1;35m"
#define ORANGE  "[1;38;05;214m"
#define CYAN    "[1;36m"
#define RED     "[1;31m"
#define BLUE    "[1;94m"

#define info    1
#define debug   2
#define trace   3
#define warning 4
#define error   5

#define log(lvl, msg, ...) do { \
  char* prefix; \
  char* color; \
  FILE* stream = stdout; \
  switch(lvl) { \
    case info: prefix = "[i]"; color = GREEN; break; \
    case debug: prefix = "[d]"; color = MAGENTA; break; \
    case trace: prefix = "[t]"; color = CYAN; break; \
    case warning: prefix = "[w]"; color = ORANGE; break; \
    case error: prefix = "[e]"; color = RED; stream = stderr; break; \
    default: break; \
  } \
  fprintf(stream, "[%s %s]\033[1;94m [%s] [%s():%d]\033[0m \033%s %s: "msg" \033[0m\n", \
          __DATE__, __TIME__, __FILE__, \
          __func__, __LINE__, color, prefix, ##__VA_ARGS__); \
} while (0)

#endif //_LOG_H_ 
