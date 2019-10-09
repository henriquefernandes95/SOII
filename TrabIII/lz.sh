#!/bin/sh
ps aux \
| awk '{ print $2 " " $8 " " $11 }' \
| grep -w Z \
| awk 'BEGIN{print "PID \t\t PPID \t\t Nome do Programa\
\n=========================================="}; \
 { comm="ps -o ppid= -p " $1; comm | getline x; close(comm); \
 print $1 " \t\t " x " \t\t " $3 }\
 END{print "=========================================="}'>>log.txt