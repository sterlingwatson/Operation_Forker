#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 100

int main(void){
	
    int number;
    int i;

    pid_t pid;
    pid_t ppid;

    char filename[50];

    printf("Enter an integer for how many fork processes to make: ");
    scanf("%d", &number);

    printf("Enter a file name for a file to output to: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");

    if (file == NULL){
        fprintf(stderr, "Invalid filename");
        exit(1);
    }

    for (i = 0; i<number; i++){
        fflush(file);
        if(fork() != 0 ){
            //Parent
           // fprintf(file, "This is a parent process with the pid: %d\n\n", getpid());
             waitpid(-1, NULL, 0);
        }else{
            fprintf(file, "Process created with the pid: %d\n", getpid());
            fprintf(file, "This process has the parent with the pid: %d\n\n", getppid());
        }

       /* if (pid == 0){
            //it is a child
            pid = getpid();
            ppid = getppid();
            fprintf(file, "Child created with pid: %d\n", getpid());
            fprintf(file, "This childs parent is: %d\n", ppid);
            fprintf(file, "This child was made on level: %d\n\n", i);

            exit(0);
        }
        else if(pid > 0){
            //Parent
           // fprintf(file, "Parent has the pid: %d\n", getpid());
           // fprintf(file, "It's child is: %d which has the pid: %d\n\n", i+1, pid);
        }
        else{
            fprintf(stderr, "Fork not made\n");
            exit(1);
        }*/


       // fprintf(file, "Process created with the pid: %d\n", getpid());
       // fprintf(file, "This process has the parent with the pid: %d\n\n", getppid());
       // waitpid();
         // exit(0);
    }

    fclose(file);
    return(0);
}

