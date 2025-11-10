#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* system() executes "/bin/sh -c <command>", which will receive the calling
       process environment (subject to setuid/setgid and loader security policies). */
    system("/usr/bin/env");
    return 0;
}

