#!/bin/sh

i=1
for k in $*; do
    if [ $i -ne $# ]; then
        printf "$k," | tr -d rR
        i=$(($i+1))
    else
        printf "$k" | tr -d rR
    fi
done
printf "\n"
