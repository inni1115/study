#!/bin/bash

# word는 사용자로 부터 입력 받은 문자열이 들어 있는 변수이다.
read word
# 이곳에 스크립트를 작성하시오

TRNAME=`echo $word | tr '[A-Z]' '[a-z]'`
echo $TRNAME
