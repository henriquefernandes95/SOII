#!/bin/bash
awk -F ":" '{print $6}' /etc/passwd | sort | uniq
echo
