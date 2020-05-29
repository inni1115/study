#!/bin/bash
read N
for x in `eval echo {1..$N}`
do    
    read PH
    echo "$PH" | 
    {
         # 이곳에 스크립트를 작성하시오
         res=`sed -nr '/^01[016-9]( |:|-)[0-9]{3,4}\1[0-9]{4,4}$/s/( |-|:)/ /gp'`
    	echo ${res:-"wrong number"}
	}
done  
