#!/bin/bash
read N
for x in `eval echo {1..$N}`
do    
    read PH
    echo "$PH" | 
    {
         # 이곳에 스크립트를 작성하시오
         res=`sed -nr 's/^01[016-9]-[0-9]{3,4}-[0-9]{4,4}$/YES/p'`
    	echo ${res:-"NO"}
	}
done  
