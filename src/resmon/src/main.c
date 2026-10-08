/*
 * resmon/main.c - resources monitor syscall invoking helper CLI.
 * Copyright (C) 2026-2027 Yiğit Cemal Öztürk <251307091@kocaeli.edu.tr>
 *
 * Licensed under 3-Clause BSD License. See LICENSE for more details.
 */

#include <asm-generic/fcntl.h>
#include <stdio.h>
#include <syslog.h>
#include <stdint.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/resource.h>
#include "version.h"
#include <sys/stat.h>

int main(int argc, char **argv) {
    /* Report system resource usage in a way it can be parsed with AWK */
    resmon_version_t ver = { .major = 0, .minor = 0, .build = 0, .edit = 0 };
    syslog(LOG_DAEMON | LOG_NOTICE, "[ WIP ] resmon %d.%d.%d.%d", ver.major, ver.minor, ver.build, ver.edit);

    /* Open resources */
    int cpuinfo_fd = open("/proc/cpuinfo", O_RDONLY);
    int meminfo_fd = open("/proc/meminfo", O_RDONLY);
    int stat_fd = open("/proc/stat", O_RDONLY);
}
