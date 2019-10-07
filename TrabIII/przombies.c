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
    
    char dir[256];//diretorio de trabalho

    if(argc<2){
        printf("Erro. Entre com o argumento do tempo de intervalo. Use -help para informações.");
        return 0;
    }
    if(strcmp(argv[1],"-help")==0){
        printf("Esse programa inicia um daemon que irá executar em intervalos de segundos, de acordo com a entrada\n");
        printf("Use a chamada przombies n. Sendo n o intervalo em segundos\n");
    }
    if(atoi(argv[1])<0){
        printf("Erro");
    }
    else{
        printf("Entrada %s inválida. Ente com -help\n",argv[1]);
    }
    getcwd(dir,sizeof(dir));//obtém o local para criar o arquivo
    child=fork();//cria o daemon
    if(!child){//cria o daemon
        execlp(strcat(dir,"/daemon"),strcat(dir,"/daemon"),argv[1],(char*)0);
            
    }
    else{//o pai executa
        return 0;
            
    }
        
    
    


    
    return 0;
}