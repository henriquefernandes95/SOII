#!/bin/bash
word1=$1
word2=$2
if [[ $word1 == *"$word2"* ]]
    then
        echo $word2 está contida em $word1
fi
