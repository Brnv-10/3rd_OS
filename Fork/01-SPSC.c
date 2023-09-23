// Write a program where parent and child execute same program, same code.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t pid, p;
    p = fork();
    pid = getpid();
    if(p<0){
        printf("Failed to create new process");
        return 1;
    }
    printf("\n Fork id: %d \n", p);
    printf("\n Process id: %d \n", pid);
    return 0;

}

// Fork id: 1541 

//  Process id: 1540 

//  Fork id: 0 

//  Process id: 1541 