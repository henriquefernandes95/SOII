#!/bin/bash
for i in $*
do
    echo -n $i | tr -d " " #saida na mesma linha e exclui os espaços
done 
echo  # pula uma linha para igualar ao exemplo
