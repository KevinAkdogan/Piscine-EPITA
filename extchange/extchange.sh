#!/bin/sh

if [ "$#" -ne 2 ]; then
    >&2 echo "Usage: extchange.sh 'ext1' 'ext2'"
    exit 1
fi

for k in *.$1; do
    if [ -f "$k" ]; then
        mv $k ${k%$1}$2
        echo "mv $k ${k%$1}$2"
    else
        exit 2
    fi
done
exit 0
