/* FIO32-C: Noncompliant - opening arbitrary file with fopen may block on special files */
#include <cstdio>
#include <cstdlib>

void func(const char *file_name) {
    FILE *file;
    if ((file = fopen(file_name, "wb")) == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    /* Operate on the file */
    if (fclose(file) == EOF) {
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
