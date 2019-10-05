#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
    int child, cstatus, filed,fsize;
    char *buf;
    int fd[2];
    char dir[256];

    while(true){
        getcwd(dir,sizeof(dir));
        filed=open(strcat(dir,"/log.txt"),O_RDWR, S_IRUSR |S_IXOTH);
        //puts(dir);
        //child=fork();
        pipe(fd);
        //child=popen();
        printf("PROCESSO DE ID %d",child);
        if(!child){
            printf("passou");
            close(fd[0]);
            execl("/bin/ps","/bin/ps","-aux",(char*)0);
            
        }
        else{
            close(fd[1]);
            fsize=lseek(fd[0],0,SEEK_END);
            read(fd[0],buf,fsize);
            write(filed,read,sizeof(fd[0]));
            wait(&cstatus);
            //printf("%d",sec);
            sleep(atoi(argv[1]));
            kill(child,SIGTERM);
            waitpid(child,&cstatus,0);
        }
        
    }
    


    
    return 0;
}