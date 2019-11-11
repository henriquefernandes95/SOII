#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
    int child;
    
    char dir[256];//diretorio de trabalho

    if(argc<2){
        printf("Erro. Entre com o argumento do tempo de intervalo. Use -help para informações.");
        return 0;
    }
    if(strcmp(argv[1],"-help")==0){
        printf("Esse programa inicia um daemon que irá executar em intervalos de segundos, de acordo com a entrada\n");
        printf("Use a chamada przombies n. Sendo n o intervalo em segundos\n");
    }
    
    getcwd(dir,sizeof(dir));//obtém o local para carregar o daemon
    child=fork();//cria o daemon
    
    if(!child){
        kill(getppid(),SIGTERM);
        execlp(strcat(dir,"/daemon"),"./daemon",argv[1],(char*)0);
        
    }
    else{//o pai executa
        
        return 0;
            
    }
        
    
    


    
    return 0;
}
