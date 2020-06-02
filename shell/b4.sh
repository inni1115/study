#!/bin/bash
read N
for x in `eval echo {1..$N}`
do
    read phase
	echo $phase | awk 'BEGIN {FS=":"} {print $1}'
done
