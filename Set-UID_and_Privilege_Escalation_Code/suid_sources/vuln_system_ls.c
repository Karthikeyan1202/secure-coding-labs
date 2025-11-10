/* vuln_system_ls.c
 * Simple example that uses system("ls")
 */
#include <stdlib.h>

int main(void)
{
    /* vulnerable usage example (uses /bin/sh) */
    system("ls");
    return 0;
}
