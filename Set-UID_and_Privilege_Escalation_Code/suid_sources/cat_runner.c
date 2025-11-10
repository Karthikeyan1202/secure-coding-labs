/* cat_runner.c
 * Demonstrates difference between system() and execve().
 *
 * Usage:
 *   ./cat_runner [-e] <filename>
 *   -e : use execve() to run /bin/cat
 *   (default without -e uses system())
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int use_exec = 0;
    int argi = 1;

    if (argc >= 2 && strcmp(argv[1], "-e") == 0) {
        use_exec = 1;
        argi = 2;
    }

    if (argi >= argc) {
        fprintf(stderr, "Usage: %s [-e] <filename>\n", argv[0]);
        return 1;
    }

    char *target = argv[argi];
    char *cat_path = "/bin/cat";
    char *const args[] = { (char *)cat_path, target, NULL };

    if (!use_exec) {
        /* system() path */
        size_t n = strlen(cat_path) + 1 + strlen(target) + 1;
        char *cmd = malloc(n);
        if (!cmd) {
            perror("malloc");
            return 1;
        }
        snprintf(cmd, n, "%s %s", cat_path, target);
        system(cmd);
        free(cmd);
    } else {
        /* execve() path; envp = NULL */
        execve(cat_path, args, NULL);
        /* execve returns only on error */
        perror("execve");
        return 1;
    }

    return 0;
}
