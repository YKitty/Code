#!/bin/bash 

#read op 

#$1内置变量
case $1 in
  [Ss]tart | -s ) #case 'start':
    echo "start"
    ;; #break
  [Ss]top | -t)
    echo "stop"
    ;;
  [Rr]estart | -rt )
    echo "restart"
    ;;
  [Ss]tatus | -st )
    echo "status"
    ;;
  * )
    echo "default"
    ;;
esac 

#switch()
#{
#
#



#read mystr 
#[[ $mystr ==  [Hh]ella ]] && {
#  echo "hello"
#}

#read myint
#[ $myint -eq 100 ] || {
#  echo "hello $myint"
#[ $myint -le 100 ] || {
#  echo "hello "
#}
#}




#if [ 1 -eq 1 ];then
#if :;then
#  echo "hello"
#fi

#read myint
#
##多行命令写在一行，后面加上;
#if [ $myint -eq 100 ];then
#  #echo "hello"
#  :
#elif [ $myint -gt 100 ];then 
#  echo "big!"
#else 
#  echo "small!"
#  if [ $myint -le 50 ];then 
#    echo "<=50"
#  else 
#    echo ">50"
#  fi
#fi

#read myint 
#[ ! $myint -eq 100 ]
#echo $?

#read file
#[ -c $file ] 
#echo $?
#

#read mystr 
##== != =
#[ "X$mystr" == "Xhelloworld" ]
#echo $?
#

#read myint #读取变量
#echo $myint 
#eq:equal 
#lt:less than
#gt:great than
#le:less and equal
#ge:grear and equal
#[ $myint -eq 100 ] #后面的是参数或者选项,
#]是一个选项，结束标志位
#相等：0
#不相等：1
#echo $? #查看退出码








#str='hello'
#echo ${#str}

#str='helloworld'
#echo ${str:1:4}

#string='bit is a great company'
#echo `expr index "$string" is`

#单引号和引号的区别
#val=100
#
#echo "################1#############"
#echo "hello world : \` : \" : \\ : $val : $(date +%Y)"
#echo "################2#############"
#echo 'hello world : \` : \" : \\ : $val : $(date +%Y)'
#


#DATE=`date`

#DATE=$(date)

#echo $DATE

#echo hello world



#echo $x

#x=123
#
#echo $x
##x=''
#unset x
#echo "x: $x"
#echo "y: a${y}b"

#readonly str="hello"
#str=askdl
#
#echo ${str}aaaa  #$加{}输出变量内容

#echo $str"aaaaa"  #直接写一个东西不带字符串就解释为字符串


#myint=123
#myfloat=3.14
#mystr="helloshell"
#mystr1=",helloworld"
#mychar='c'
#totalStr=$mystr$mystr1
#
#echo $mystr$mystr1
#echo $myint #加上$可以查看环境变量名称
#echo $myfloat #加上$可以查看环境变量名称
#echo $mystr #加上$可以查看环境变量名称
#echo $mychar #加上$可以查看环境变量名称
#

#echo "hello world"

#pwd
#cd ..
#pwd
#
