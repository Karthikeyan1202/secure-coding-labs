#include <cstdlib>
#include <cstdio>
#include <time.h>

struct tm *make_tm(int year,int mon,int day,int hour,int min,int sec) {
    struct tm *tmb;
    tmb = (struct tm *)malloc(sizeof(*tmb)); /* recommended: sizeof(*tmb) */
    if (tmb == NULL) return NULL;
    *tmb = (struct tm){ .tm_sec = sec, .tm_min = min, .tm_hour = hour, .tm_mday = day, .tm_mon = mon, .tm_year = year };
    return tmb;
}

int main() {
    struct tm *time_info = make_tm(2024,9,15,10,30,45);
    if (time_info) {
        std::printf("Time: %d-%02d-%02d %02d:%02d:%02d\n",
            time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
            time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
        free(time_info);
    } else {
        std::printf("Error: malloc failed\n");
    }
    return EXIT_SUCCESS;
}
