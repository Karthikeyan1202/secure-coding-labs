/* relinquish_priv.c
 * Example that opens /etc/zzz, simulates work, drops privileges permanently,
 * then forks and attempts to write to the file descriptor.
 *
 * Intended for educational/demonstration only.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    int fd = open("/etc/zzz", O_RDWR | O_APPEND);
    if (fd == -1) {
        fprintf(stderr, "open(/etc/zzz) failed: %s\n", strerror(errno));
        return 1;
    }

    /* simulate some work */
    sleep(1);

    /* permanently drop root privileges (if running setuid) */
    if (setuid(getuid()) != 0) {
        perror("setuid");
        close(fd);
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid > 0) {
        /* parent */
        close(fd);
        return 0;
    } else {
        /* child: attempt to write after privileges dropped */
        const char payload[] = "Malicious Data\n";
        ssize_t wrote = write(fd, payload, sizeof(payload) - 1);
        if (wrote == -1) {
            fprintf(stderr, "child write failed (expected if privileges dropped): %s\n",
                    strerror(errno));
        } else {
            fprintf(stderr, "child wrote %zd bytes (unexpected if privileges were dropped)\n",
                    wrote);
        }
        close(fd);
        return 0;
    }
}
