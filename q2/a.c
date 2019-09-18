#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PATH "/home/goliveira/test"
#define VALID_OPTS "rdlbc"


int walk_dir(const char *path, char type)
{
    DIR *dirp;
    struct dirent *dp;
    char *p, *full_path;
    int len;
    char full_name[NAME_MAX+1];
    int cnt = 0;
    /* abre o diretório */
    if ((dirp = opendir(path)) == NULL)
        return (-1);
    len = strlen(path);
    /* aloca uma área na qual, garantidamente, o caminho caberá */
    if ((full_path = malloc(len + NAME_MAX + 2)) == NULL)
    {
        closedir(dirp);
        return (-1);
    }
    /* copia o prefixo e acrescenta a ‘/’ ao final */
    memcpy(full_path, path, len);
    p = full_path + len;
    *p++ = '/'; /* deixa “p” no lugar certo! */
    while ((dp = readdir(dirp)) != NULL)
    {
        /* ignora as entradas “.” e “..” */
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        strcpy(p, dp->d_name);

        struct stat filestat;
        stat(full_path,&filestat);

        if(type=='r' && S_ISREG(filestat.st_mode) ||
           type=='d' && S_ISDIR(filestat.st_mode) ||
           type=='l' && S_ISLNK(filestat.st_mode) ||
           type=='b' && S_ISBLK(filestat.st_mode) ||
           type=='c' && S_ISCHR(filestat.st_mode))
           cnt++;
        
        ///* “full_path” armazena o caminho */
        //(*func)(full_path);
    }
    free(full_path);
    closedir(dirp);
    return (cnt);
} /* end walk_dir */

int main(int argc, char **argv){
    
    int ret;
    int opt;
    char *path;

    opt = getopt(argc,argv,VALID_OPTS);
    if(opt == -1){
        ret = walk_dir(argv[1],'r');
    }else{
        ret = walk_dir(argv[2],opt);
    }

    printf("%d\n",ret);
    return 0;
}