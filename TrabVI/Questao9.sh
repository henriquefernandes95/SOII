#!/bin/bash
param=1
for i in $*
do
    echo "Parâmetro" $param:$i
    param=$((param + 1)) 
done 

