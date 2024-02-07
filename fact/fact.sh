#!/bin/sh

if [ $# -ne 1 ]; then    # 1 argument else error !
  exit 1
fi

if [ $1 -eq 0 ]; then    # 0! = 1
  echo 1

elif [ $1 -eq 1 ]; then  # 1! = 1
  echo 1

else
  x=$1
  res=1
  while [ $x -gt 0 ]; do
    res=$(($res*$x))
    x=$(($x - 1))
  done
  echo $res
exit 0

fi
