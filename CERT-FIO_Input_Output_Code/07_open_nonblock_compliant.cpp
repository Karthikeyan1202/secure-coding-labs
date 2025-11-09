/* FIO32-C: Compliant POSIX solution using O_NONBLOCK and checks */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

#ifdef O_NOFOLLOW
  #define OPEN_FLAGS O_NOFOLLOW | O_NONBLOCK
#else
  #define OPEN_FLAGS O_NONBLOCK
#endif

void func(const char *file_name) {
    struct stat orig_st;
    struct stat open_st;
    int fd;
    int flags;

    if ((lstat(file_name, &orig_st) != 0) || (!S_ISREG(orig_st.st_mode))) {
        perror("Error with lstat or not a regular file");
        exit(EXIT_FAILURE);
    }

    fd = open(file_name, OPEN_FLAGS | O_WRONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &open_st) != 0) {
        perror("Error with fstat");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if ((orig_st.st_mode != open_st.st_mode) ||
        (orig_st.st_ino  != open_st.st_ino) ||
        (orig_st.st_dev  != open_st.st_dev)) {
        fprintf(stderr, "The file was tampered with\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    /* Optionally clear O_NONBLOCK */
    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        perror("Error getting file flags");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (fcntl(fd, F_SETFL, flags & ~O_NONBLOCK) == -1) {
        perror("Error setting file flags");
        close(fd);
        exit(EXIT_FAILURE);
    }

    /* Operate on the file */

    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }
    func(argv[1]);
    return EXIT_SUCCESS;
}
