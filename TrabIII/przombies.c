#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int child(int sec){
    char dir[256];

    while(1){
        getcwd(dir,sizeof(dir));
        //puts(dir);
        execl("/bin/ps","> log.txt");
        sleep(sec*1000);
        
    }
    
    return 0;
}

int main(int argc, char *argv[]){
    

    if(fork()==0){
        child(atoi(argv[1]));
    }


    
    return 0;
}