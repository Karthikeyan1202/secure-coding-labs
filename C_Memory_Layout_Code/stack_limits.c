/* stack_limits.c
 * Query stack limits using getrlimit()
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit lim;
    if (getrlimit(RLIMIT_STACK, &lim) == 0) {
        printf("Soft stack limit = %ld\n", (long)lim.rlim_cur);
        printf("Hard stack limit = %ld\n", (long)lim.rlim_max);
    } else {
        printf("getrlimit failed: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
