#include <cstdlib>
#include <cstdio>
#include <time.h>

struct tm *make_tm(int year,int mon,int day,int hour,int min,int sec) {
    struct tm *tmb;
    tmb = (struct tm *)malloc(sizeof(struct tm)); /* okay, example shows correct usage here too but keep as sample */
    if (tmb == NULL) return NULL;
    *tmb = (struct tm){ .tm_sec = sec, .tm_min = min, .tm_hour = hour, .tm_mday = day, .tm_mon = mon, .tm_year = year };
    return tmb;
}

int main() {
    struct tm *time_info = make_tm(2024,9,15,10,30,45);
    if (time_info) {
        std::printf("Time allocated\n");
        free(time_info);
    }
    return EXIT_SUCCESS;
}
