/* FIO45-C: Compliant POSIX - use O_CREAT|O_EXCL to avoid TOCTOU */
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

void open_some_file(const char *file) {
    int fd = open(file, O_CREAT | O_EXCL | O_WRONLY, 0644);
    if (fd == -1) {
        printf("Compliant POSIX Code: Failed to open file (it may already exist).\n");
    } else {
        FILE *f = fdopen(fd, "w");
        if (f != NULL) {
            printf("Compliant POSIX Code: Writing to file.\n");
            if (fclose(f) == EOF) {
                printf("Compliant POSIX Code: Error closing file.\n");
            }
        } else {
            if (close(fd) == -1) {
                printf("Compliant POSIX Code: Error closing file descriptor.\n");
            }
        }
    }
}

int main() {
    open_some_file("example.txt");
    return 0;
}
