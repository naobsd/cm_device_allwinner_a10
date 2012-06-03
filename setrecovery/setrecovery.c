/*-
 * Copyright (c) 2012 FUKAUMI Naoki.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct bootloader_message {
    char command[32];
    char status[32];
    char recovery[1024];
};

#ifdef GINGERBREAD
#define MISC_PARTITION	"/dev/block/nande"
#else
#define MISC_PARTITION	"/dev/block/nandf"
#endif

int
main(int argc, char *argv[])
{
    struct bootloader_message boot;
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&boot, 0, sizeof(boot));

#ifndef GINGERBREAD
    if (strcmp(argv[1], "bootloader") == 0)
        strlcpy(boot.command, "boot-fastboot", sizeof(boot.command));
    else
#endif
    if (strcmp(argv[1], "recovery") == 0)
        strlcpy(boot.command, "boot-recovery", sizeof(boot.command));
    else {
        fprintf(stderr, "%s: %s: unknown command\n", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(MISC_PARTITION, O_WRONLY | O_SYNC)) == -1)
        err(EXIT_FAILURE, "%s", MISC_PARTITION);

    if (write(fd, &boot, sizeof(boot)) == -1) {
        (void)close(fd);
        err(EXIT_FAILURE, "%s", MISC_PARTITION);
    }

    if (close(fd) == -1)
        err(EXIT_FAILURE, "%s", MISC_PARTITION);

    return EXIT_SUCCESS;
}
