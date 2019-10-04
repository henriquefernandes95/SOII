#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int isopen (int fd);

int isopen(int fd){
  
  if(fdopen(fd,"rb")==NULL){
    return 0;
  }
  else{
    return 1;
  }
  
}


int main (void){
  
  int nopen, fd;
  for (nopen = fd = 0;fd < getdtablesize(); fd++){
      if (isopen(fd)){
        nopen++;
      }

  }
  printf ("Existem %d descritores abertos\n", nopen);
  return (0);
}/* end main */
