#include <time.h>
#include <stdio.h>

void check_time(void) {
    time_t now = time(NULL);

    if (now != (time_t)-1) { // Proper comparison
        printf("Current time: %ld\n", (long)now);
    } else {
        printf("Error retrieving time.\n");
    }
}

int main(void) {
    check_time();
    return 0;
}
