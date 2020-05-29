#!/bin/bash
read N
for x in `eval echo {1..$N}`
do
    # 이곳에 스크립트를 작성하시오
    read time 
    res=`echo $time | sed -nr 's/^[0-2][0-3]:[0-5][0-9]:[0-5][0-9]$/YES/p'`
    echo ${res:-"NO"}
done
