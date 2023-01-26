#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
int acquireLock(const char* file);
void releaseLock(int lockFd);

int main() {
   int file = acquireLock("file.txt");


    if(file!=-1){
        sleep(10);
        releaseLock(file);
    } else{
        return 1;
    }

    return 0;
}

int acquireLock(const char* file) {
    int lockFd;

    if (NULL == file) return -1;


    if ((lockFd = open(file, O_RDWR, 0666))  < 0){
        perror ("open");
        return -1;
    }

    else{
        if (flock(lockFd, LOCK_EX | LOCK_NB) < 0) {
            perror ("lock");
            return -1;
        }else{
            return lockFd;
        }
    }
}

void releaseLock(int lockFd){
    flock (lockFd, LOCK_UN);
    close (lockFd);
    perror ("close");
}