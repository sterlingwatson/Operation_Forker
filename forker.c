#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>0

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
        fprintf(file, "Process are listed as follows: parentPID,ChildPID");
        if(fork() != 0 ){
            //Parent
             waitpid(-1, NULL, 0);
        }else{
            //Child
            fprintf(file, "%d," getppid());
            fprintf(file, "%d\n", getpid());
        }

    fclose(file);
    return(0);
}
