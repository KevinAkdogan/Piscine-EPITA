#!/bin/sh

if [ $# -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" 1>&2
    exit 1
fi

if [ $2 -eq 0 ]; then
    exit 1
fi

if [ $2 -le 0 ] && [ $1 -lt $3 ]; then
    exit 1
fi

k=$1

if [ $1 -eq $3 ]; then
    break

elif [ $1 -lt $3 ]; then
    if [ $2 -le 0 ]; then
        exit 1
    fi
    while [ $k -le $3 ]; do
        echo $k
        k=$(($k+$2))
    done

else
    if [ $2 -ge 0 ]; then
        exit 1
    fi
    while [ $k -ge $3 ]; do
        echo $k
        k=$(($k+$2))
    done
fi
if [ $k -ne $3 ]; then
    exit 0
fi
echo $k
