
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
pid_t client_pid;

/* registry initialisation */
int main() {
    FILE *ptr = NULL;
    char cmd[128] = "ps -ef | grep stand_alone_registry | grep -v grep | wc -l";
    char buf[150];
    int count;

    client_pid = getpid();

    int stand_alone_fd = open("/usr/local/stand_alone_registry/",O_RDONLY);
    if(fchdir(stand_alone_fd)==-1){
        return -1;
    }
    while (1) {
        if ((ptr = popen(cmd, "r")) == NULL) {
            printf("init registry popen err\n");
            continue;
        }
        memset(buf, 0, sizeof(buf));
        if ((fgets(buf, sizeof(buf), ptr)) != NULL){
            count = atoi(buf);
            if (count <= 0){
                system("/usr/local/stand_alone_registry/stand_alone_registry&");
                printf("start stand_alone_registry \n");
            }else{
                break;
            }
        }
    }
}
