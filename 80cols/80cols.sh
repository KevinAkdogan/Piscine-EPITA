#!/bin/sh

if [[ -f $1 && -r $1 ]]; then
    continue
else
    exit 1
fi

while read line; do
    if [ $(echo -n $line | wc -m) -gt 80 ]; then
        echo -e $line
    fi
done < $1
exit 0
