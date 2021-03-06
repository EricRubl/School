#!/bin/bash


for file in `find . -name "*.input"`
do
	fileName=`basename $file .input`
	echo $fileName
	time ./cmake-build-debug/Lab2qsum < $file > ./outFiles/checking.out
	
	diff -q ./outFiles/checking.out ./okFiles/$fileName.sum.ok 1>/dev/null
	if [[ $? == "0" ]]
	then
	  	echo "OK"
	else
	  	echo "SOMETHING WENT WRONG"
		rm ./outFiles/checking.out
	  	exit
	fi
	echo
	echo 
	echo

	rm ./outFiles/checking.out

done

