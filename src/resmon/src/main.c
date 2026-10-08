/*
 * resmon/main.c - resources monitor syscall invoking helper CLI.
 * Copyright (C) 2026-2027 Yiğit Cemal Öztürk <251307091@kocaeli.edu.tr>
 *
 * Licensed under 3-Clause BSD License. See LICENSE for more details.
 */

#include <syslog.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>
#include "include/version.h"
#include <sys/stat.h>

int main(int argc, char **argv) {
    /* Report system resource usage in a way it can be parsed with AWK */
    resmon_version_t ver = { .major = 0, .minor = 0, .build = 0, .edit = 0 };
    syslog(LOG_DAEMON | LOG_NOTICE, "[ WIP ] resmon %d.%d.%d.%d", ver.major, ver.minor, ver.build, ver.edit);

    /* Open resources */
    int cpuinfo_fd = open("/proc/cpuinfo", O_RDONLY);
    int meminfo_fd = open("/proc/meminfo", O_RDONLY);
    int stat_fd = open("/proc/stat", O_RDONLY);

    if(cpuinfo_fd == -1) {
        syslog(LOG_DAEMON | LOG_ERR, "Failed to open /proc/cpuinfo: %s", strerror(errno));
        exit(1);
    }
    if(meminfo_fd == -1) {
        syslog(LOG_DAEMON | LOG_ERR, "Failed to open /proc/meminfo: %s", strerror(errno));
        exit(1);
    }
    if(stat_fd == -1) {
        syslog(LOG_DAEMON | LOG_ERR, "Failed to open /proc/stat: %s", strerror(errno));
        exit(1);
    }

}
