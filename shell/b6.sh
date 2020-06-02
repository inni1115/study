#!/bin/bash

# num에는 사용자로 부터 입력 받은 내용이 들어 있는 변수이다.
read num
# 이곳에 스크립트를 작성하시오
if (($num >= 0 && $num <=100))
then
	echo "OK"
else
	echo "x"
fi  
