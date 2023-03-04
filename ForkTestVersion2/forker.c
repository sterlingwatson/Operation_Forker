#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

    fprintf(file, "Process are listed as follows: parentPID,ChildPID\n");
    for (i = 0; i<number; i++){
        fflush(file);
        if(fork() != 0 ){
            //Parent
            //waitpid first arg -1 Wait for ANY child process. 0 Wait for any child process whose group ID is equal to calling process. >0 Wait for the child whose process IP is equal to pid
            //???
             waitpid(0, NULL, 0);
             break;
        }else{
            //Child
            fprintf(file, "%d,", getpid());
            fprintf(file, "%d\n", getppid());
        }
    }
    fclose(file);
    return(0);
    
}
