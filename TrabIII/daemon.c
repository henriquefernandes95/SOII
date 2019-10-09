#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

void handler(int sig){
    if(sig == SIGTERM){
        printf("O programa recebeu um SIGTERM e foi finalizado\n");
        exit(sig);
    }
    
}

int main(int argc, char *argv[]){
   

    
    while(1){
        signal(SIGTERM,handler);
        
        //carq=popen(strcat(dir,"/log.txt"),"w");//alternativa cria um child com pipe atrelado
        system("ps aux \\ 
        | awk \'{ print $2 \" \" $8 \" \" $11 }\' \\
        | grep -w Z \
        | awk \'BEGIN{print \"PID \\t\\t PPID \\t\\t Nome do Programa\\
        \\n==========================================\"}; \\
        { comm=\"ps -o ppid= -p \" $1; comm | getline x; close(comm); \\
        print $1 \" \\t\\t \" x \" \\t\\t \" $3 }\\
        END{print \"==========================================\"}\'>>log.txt");
        
        sleep(atoi(argv[1]));//intervalo definido na chamada do programa
        
            
        
    }
    


    
    return 0;
}
