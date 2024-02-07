#!/bin/sh

while read k; do
    if echo "$k" | grep -q -E '^[[:blank:]]*$'; then
        echo "it is empty"
    elif echo "$k" | grep -q -E '^[a-zA-Z]+$'; then
        echo "it is a word"
    elif echo "$k" | grep -q -E '^[0-9]$'; then
        echo "it is a digit"
    elif echo "$k" | grep -q -E '^[0-9]+$'; then
        echo "it is a number"
    elif echo "$k" | grep -q -E '^[a-zA-Z0-9]+$'; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done
exit 0
