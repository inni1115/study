#!/bin/bash
res=`echo $1 | sed -nr '/^01[016-]( |-|:)[0-9]{3,4}\1[0-9]{4,4}$/s/( |:|-)/ /gp'`
echo ${res:-"wrong number"}
