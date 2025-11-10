#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void printenv(void)
{
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
}

int main(void)
{
    pid_t childPid;

    switch (childPid = fork()) {
    case -1:
        perror("fork");
        return 1;
    case 0: /* child process */
        printenv();
        exit(0);
    default: /* parent process */
        /* parent could also call printenv(); lab asks to test both */
        wait(NULL);
        break;
    }

    return 0;
}

