#!/bin/bash

read line
# 이곳에 스크립트를 작성하시오

name=`echo $line | sed 's/://g' | sed 's/ //g' | sed 's/-//g'| sed 's/^[0-9][0-9]//'`
echo "/home/user/myfile_${name}.bak" 
