#define _POSIX_C_SOURCE 200112L // Needed with glibc (e.g., linux).
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

void report (uid_t real) {
    printf (
        "Real UID: %d Effective UID: %d\n",
        real,
        geteuid()
    );
}

int main (int argc, char *argv[]) {
    uid_t real = getuid();
    report(real);
    if (real != OPERATOR_ID) return -1;

    char *params[] = {
	"restart",
	"uwsgi"
    };
    printf ("will call the reload function\n");
    pid_t pid = fork(); 
    if (pid == 0)  {
        int res = execl("/usr/bin/systemctl", "systemctl", "restart", "uwsgi");
	printf ("EXEC RES: %d; errno: %d\n", res, errno);
    } else {
        int res = 0;
        pid_t pidret = wait(&res);
	printf ("WAIT RES: %d\n", res);
        return res;
    }
    return 0;
}
