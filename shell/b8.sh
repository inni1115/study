#!/bin/bash
SAFE=0
is_safe()
{
   # 여기에 코드를 작성한다
   res=`echo "$1" | grep '[0-9]'| grep '[~!@#$%^&*]' | grep '[A-Z]' `
   # res의 결과를 사용하여 길이 검사를 하여 8자 이상이면 SAFE=1 을 수행하도록 한다
	if [ ${#res} -gt 7 ]
	then
		SAFE=1
	fi

}

read line
is_safe "$line"
[ $SAFE -eq 1 ] && echo "YES" || echo "NO"  
