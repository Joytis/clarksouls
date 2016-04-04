//
// Created by Clark Burton Chambers on 4/4/16.
//
#ifndef __dbg_h_cpp__
#define __dbg_h_cpp__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(E, M, ...)
#else
#define debug(E, M, ...) fprintf(stderr, "[DEBUG] %s:%d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(E, M, ...) fprintf(stderr, "[ERROR] (%s:%d | errno: %s | exception: %s | function: %s ) " M "\n", __FILE__, __LINE__, clean_errno(), #E, __PRETTY_FUNCTION__, ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d | errno: %s | function: %s ) " M "\n", __FILE__, __LINE__, clean_errno(), __PRETTY_FUNCTION__,##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d | function: %s ) " M "\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)

#define check(A, E, M, ...) if(!(A)) { log_err(E, M, ##__VA_ARGS__); errno=0; throw E(); }

#define sentinel(E, M, ...) { log_err(E, M, ##__VA_ARGS__); errno=0; throw E(); }

#define check_mem(A) check((A), e_bad_allocation, "Out of Memory.")

#define check_debug(A, E, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; throw E(); }

#endif
