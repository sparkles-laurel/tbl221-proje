/*
 * resmon/version.h - version information for resmon
 * Copyright (C) 2026-2027 Yiğit Cemal Öztürk <251307091@kocaeli.edu.tr>
 *
 * Licensed under 3-Clause BSD License. See LICENSE for more details.
 */

#ifndef VERSION_H
#   define VERSION_H
#   include <stddef.h>
#   include <stdint.h>
/* Endianness enforcement */
#   if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ || \
        defined(__BIG_ENDIAN__) || defined(__ARMEB__)
#           define IS_BIG_ENDIAN 1
#   else
#           define IS_BIG_ENDIAN 0
#   endif

    typedef struct resmon_version {
#       if IS_BIG_ENDIAN
            uint32_t major: 8;
            uint32_t minor: 8;
            uint32_t build: 8;
            uint32_t edit:  8;
#       else
            uint32_t edit:  8;
            uint32_t build: 8;
            uint32_t minor: 8;
            uint32_t major: 8;
#       endif
    } resmon_version_t;

    typedef union resmon_version_transmute {
        uint32_t ver_usign;
        int32_t ver_sign;
        resmon_version_t ver;
    } resmon_version_transmute_t;
#endif
