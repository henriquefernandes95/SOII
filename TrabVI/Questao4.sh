#!/bin/bash
cont=$1
while [ $cont -gt 0 ]
do
    echo -n $cont   #-n evita criar nova linha
    cont=$(($cont - 1))
done
echo #pula uma linha ao fim para igualar aos exemplos
