#!/bin/bash
echo Esse programa verifica a existencia de um arquivo ou diretorio. Entre com o nome a ser verificado\:

read name

if [ -f $name ]
    then
        echo Arquivo encontrado
elif [ -d $name ]
    then
        echo Diretorio encontrado
else
    echo Não foi encontrado
    echo Deseja buscar alguma ocorrência semelhante? s ou n\:
    read opcao
    if [ $opcao = 's' ]
        then 
            echo Encontradas as ocorrências\:
            find / -name trabII 2>/dev/null
    fi
fi

