#########################################################################
# File Name: ch.sh
# Author: 
# mail: 
# Created Time: 2019年06月21日 星期五 14时58分55秒
#########################################################################
#!/bin/bash
#a=$1
#if [ "$2"x == "r"x ];then
#	gcc *.c -o ${a:0:3}
#	./${a:0:3}
#fi
if [ "$1"x == "all"x ];then
	make clean
	echo ""
	echo -e "\033[34m\t\tGenerate excute program:\033[0m"
	make || exit $?
	echo ""
	echo ""
	echo -e "\033[32m\t\tThe program run:\033[0m"
	./out/excute || exit $?
	echo -e "\033[32m\t\tRun Success!\033[0m"
	echo ""
	echo ""
fi
