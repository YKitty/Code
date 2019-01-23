#!/bin/bash 


echo $RANDOM


#-e开启转义，-c不换行
#echo -e "OK! \c a"
#echo "sadas"

#字符串运算符
#a="abc"
#
#if [ $a ];then 
#  echo "true"
#else
#  echo "false"
#fi
#
#布尔运算
#a=10
#b=20
#
#if [ $a -lt 100 -a $b -gt 0 ];then
#  echo "true"
#else
#  echo "false"
#fi
#
#if [ $a -lt 2 -o $b -gt 0 ];then
#  echo "true"
#else
#  echo "false"
#fi

#使用expr进行算术运算
#a=10
#b=20
#
##必须要使用命令代换$()或``
#val=$(expr $a + $b)
#echo "a + b = $val"
#
#val=`expr $a  \* $b`
#echo "a * b = $val"
#
#if [ $a == $b ];then
#  echo "=="
#else
#  echo "!="
#fi
#
#
#if [ $a != $b ];then
#  echo "!="
#else
#  echo "=="
#fi
#
#进行了文件包含
#. api.sh 
#
#read d1 d2 
#result=$(intAdd $d1 $d2)
#
#echo $result



#str1="hello"
#
#if [ $str == $str1 ];then
#  echo "true"
#else
#  echo "false"
#fi 


#case $1 in
#  'start' )
#    echo "start"
#    ;;
#  'stop' )
#    echo "stop"
#    ;;
#  * )
#    echo "default"
#    ;;
#
#esac
#

#trap 'echo "hello";exit 1' SIGINT
#until false
#do 
#  :
#done

#arr=(1 2 3 4 5 5)

#echo ${arr[0]}
#echo ${arr[0]}
##echo ${arr[@]}
##echo ${#arr[*]}
#echo ${#arr[@]}
#echo ${arr[*]}
