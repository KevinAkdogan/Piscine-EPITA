#!/bin/sh

if [ "$1" -lt 0 ]; then
    exit 1
fi

if [ "$2" = 'square' ]; then
    echo " _________________"
    i=0;
    while [ $i -lt $1 ]; do
        echo "|  ___       ___  |"
        echo "| |_|_|     |_|_| |"
        echo "| |_|_|     |_|_| |"
        echo "|                 |"
        i=$(($i + 1))
    done
    echo "|        _        |"
    echo "|       | |       |"
    echo "|       | |       |"
    echo "|_______| |_______|"
elif [ 'triangle' = "$2" ]; then
    echo " _________________"
    i=0;
    while [ $i -lt $1 ]; do
        echo "|                 |"
        echo "|   /\       /\   |"
        echo "|  /__\     /__\  |"
        echo "|                 |"
        i=$(($i + 1))
    done
    echo "|        _        |"
    echo "|       | |       |"
    echo "|       | |       |"
    echo "|_______| |_______|"
else
    exit 1
fi
