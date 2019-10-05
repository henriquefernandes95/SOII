#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int child(int sec){
    char dir[256];
    char *ps="/bin/ps";
    char *log="> log.txt";
    printf("passou");
    while(true){
        getcwd(dir,sizeof(dir));
        //puts(dir);
        execl(ps,log);
        printf("%d",sec);
        sleep(sec*1000);
        
    }
    
    return 0;
}

int main(int argc, char *argv[]){
    

    if(fork()==0){
        printf("%d",atoi(argv[1]));
        child(atoi(argv[1]));
    }


    
    return 0;
}