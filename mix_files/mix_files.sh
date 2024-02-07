#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: mix_files file1 file2" >> /dev/stderr
    exit 1
fi
x=0
y=0

if [ ! -f "$1" ] && [ ! -f "$2" ]; then
    exit 1
elif [ ! -f "$2" ]; then
    cat "$1"
elif [ ! -f "$1" ]; then
    cat "$2"
else
    for k in $(cat "$1" -A); do
        x=$((x+1))
    done
    for i in $(cat "$2" -A); do
        y=$((y+1))
    done

    if [ $x -gt $y ]; then
        z=0
        while [ $z -ne $((y+1)) ]; do
            head "$1" -n $z | tail -n 1
            head "$2" -n $z | tail -n 1
            z=$((z+1))
        done
        while [ $z -ne $((x+1)) ]; do
            head "$1" -n $z | tail -n 1
            z=$((z+1))
        done
    else
        z=0
        while [ $z -ne $((x+1)) ]; do
            head "$1" -n $z | tail -n 1
            head "$2" -n $z | tail -n 1
            z=$((z+1))
        done
        while [ $z -ne $((y+1)) ]; do
            head "$2" -n $z | tail -n 1
            z=$((z+1))
        done
    fi
fi
