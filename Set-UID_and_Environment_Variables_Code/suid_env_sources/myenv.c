#include <unistd.h>

extern char **environ;

int main(void)
{
    char *argv[2];
    argv[0] = "/usr/bin/env";
    argv[1] = NULL;

    /* Experiment 1: pass NULL as envp - implemented by many examples */
    /* execve("/usr/bin/env", argv, NULL); */

    /* Experiment 2: pass the current environ explicitly */
    execve("/usr/bin/env", argv, environ);

    /* execve returns only on error */
    perror("execve");
    return 1;
}

