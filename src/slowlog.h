/*
 * Copyright (c) 2009-Present, Redis Ltd.
 * All rights reserved.
 *
 * Licensed under your choice of the Redis Source Available License 2.0
 * (RSALv2) or the Server Side Public License v1 (SSPLv1).
 */

#ifndef __SLOWLOG_H__
#define __SLOWLOG_H__

#define SLOWLOG_ENTRY_MAX_ARGC 32
#define SLOWLOG_ENTRY_MAX_STRING 128

/* This structure defines an entry inside the slow log list */
typedef struct slowlogEntry {
    long long id;           /* Unique entry identifier */
    long long time;         /* UNIX timestamp of the command execution */
    long long duration;     /* Command execution time in microseconds */
    robj **argv;            /* Command arguments array */
    int argc;               /* Number of arguments */
    sds peerid;             /* Client IP address and port (since Redis 4.0) */
    sds cname;              /* Client name (since Redis 4.0) */
    int dbid;               /* Database ID where command was executed */ // New field
} slowlogEntry;

/* Exported API */
void slowlogInit(void);
void slowlogPushEntryIfNeeded(client *c, robj **argv, int argc, long long duration);

#endif /* __SLOWLOG_H__ */
