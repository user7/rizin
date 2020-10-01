/* radare - LGPL - Copyright 2009-2019 - pancake */

#ifndef _BSD_DEBUG_H
#define _BSD_DEBUG_H
#include <rz_debug.h>
#include <sys/ptrace.h>
#define R_DEBUG_REG_T struct reg

int bsd_handle_signals(RzDebug *dbg);
int bsd_reg_write(RzDebug *dbg, int type, const ut8 *buf, int size);
RzDebugInfo *bsd_info(RzDebug *dbg, const char *arg);
RzList *bsd_pid_list(RzDebug *dbg, RzList *list);
RzList *bsd_native_sysctl_map(RzDebug *dbg);
RzList *bsd_desc_list(int pid);
RzList *bsd_thread_list(RzDebug *dbg, int pid, RzList *list);
#endif
