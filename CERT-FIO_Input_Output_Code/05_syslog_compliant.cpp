/* FIO30-C: syslog compliant - pass user as argument */
#include <syslog.h>

void incorrect_password_syslog_compliant(const char *user) {
    static const char msg_format[] = "%s cannot be authenticated.\n";
    syslog(LOG_INFO, msg_format, user);
}

int main() {
    const char *username = "user1";
    incorrect_password_syslog_compliant(username);
    return 0;
}
