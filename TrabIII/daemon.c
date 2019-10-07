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
    char *buf;//buffer dos dados entre o filho e pai
    int fd[2];//file descriptors do pipeline
    char dir[256];//diretorio de trabalho
    extern struct _IO_FILE *stdout;


    getcwd(dir,sizeof(dir));//obtém o local para criar o arquivo
    filed=open(strcat(dir,"/log.txt"),O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRWXO);
    while(true){
        
        pipe(fd);//cria o pipe para ser cmpartilhado com o filho após o fork
        child=fork();
        if(child==-1){printf("ERRO");}
        
        //child=popen();//alternativa cria um child com pipe atrelado
        if(!child){//o filho executa
            
            close(fd[0]);//fechando o canal de leitura
            
            dup2(fd[1],1);//tenta redirecionar a saida do filho para o pipe
            execlp("/bin/ps","/bin/ps","-u",(char*)0);
            
        }
        else{//o pai executa
            printf("RODANDO");
            wait(&cstatus);
            waitpid(child,&cstatus,0);//espera o filho executar
            close(fd[1]);//fechando o canal de escrita
            lseek(fd[0],0,SEEK_SET);
            read(fd[0],buf,sizeof(fd[0]));
            fsize=lseek(fd[0],0,SEEK_END);//percorre arquivo para obter o tamanho
            printf("%d",fsize);
            lseek(fd[0],0,SEEK_SET);
            //printf("%ld",read(fd[0],buf,fsize));
            //puts(buf);
            write(filed,buf,sizeof(buf));//escrever o que recebeu do pipe
            
            sleep(atoi(argv[1]));//intervalo definido na chamada do programa
            kill(child,SIGTERM); //encerra o filho para não ser zumbi
            
        }
        
    }
    


    
    return 0;
}