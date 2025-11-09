/* FIO30-C: syslog noncompliant example - passing constructed string as format */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <syslog.h>

void incorrect_password_syslog_noncompliant(const char *user) {
    int ret;
    static const char msg_format[] = "%s cannot be authenticated.\n";
    size_t len = strlen(user) + sizeof(msg_format);
    char *msg = (char *)malloc(len);
    if (msg == NULL) {
        syslog(LOG_ERR, "Memory allocation failed.");
        return;
    }
    ret = snprintf(msg, len, msg_format, user);
    if (ret < 0) {
        syslog(LOG_ERR, "Error formatting message.");
        free(msg);
        return;
    } else if ((size_t)ret >= len) {
        syslog(LOG_ERR, "Truncated output.");
        free(msg);
        return;
    }
    /* Vulnerability: msg used as format string */
    syslog(LOG_INFO, msg);
    free(msg);
}

int main() {
    const char *username = "user1";
    incorrect_password_syslog_noncompliant(username);
    return 0;
}
