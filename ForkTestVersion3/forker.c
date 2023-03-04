#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	
    int number;
    int i;
    int level =0;

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

    fprintf(file, "Process are listed as follows: ChildPID,ParentPID\n");
    for (i = 0; i<number; i++){
        fflush(file);
        if(fork() != 0 ){
            //Parent
             waitpid(-1, NULL, 0);
        }else{
            //Child
            (level++);
            fprintf(file, "Level: %d,", level);
            fprintf(file, "%d,", getpid());
            fprintf(file, "%d\n", getppid());
        }
    }
    fclose(file);
    return(0);
    
}
