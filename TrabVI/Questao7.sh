#!/bin/bash
awk -F ":" '{print $1" "$5}' /etc/passwd # a opção depois do -F define o demarcador que separa as colunas, no documento é usado :
echo
