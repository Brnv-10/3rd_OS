// before terminating, the parent waits for the child to finish its task

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Failed to create new process");
        exit(1);
    }
    else if(pid == 0){
        printf("\n Child process having id: %d",getpid());
        exit(0);
    }
    else{
        printf("\n Parent process having id: %d",getpid());
        wait(NULL);
        exit(0);
    }
    return 0;
}