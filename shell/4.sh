#!/bin/bash
read line
# 이곳에 스크립트를 작성하시오
echo dir=${line%/*} name=${line##*/}
