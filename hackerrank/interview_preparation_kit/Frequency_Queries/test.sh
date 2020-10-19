#!/bin/bash

testcases=(input/*.txt)

echo "no of testcases: ${#testcases[@]}"

cnt=1
rm -rf your_output/*
for input in "${testcases[@]}"
do
	output=${input//input/output}
	your_output=your_output/`basename $output`
	export OUTPUT_PATH=$your_output
	echo "$cnt :executing testcase $input"
	./main.exe < $input ##> $your_output
	[[ $? -ne 0 ]] && echo "execution failed!" && exit 1
	result=`diff -w $output $your_output`
	if [[ -z $result ]]
	then
		echo "testcase passed!"
	else
		echo "testcase failed!"
	fi
	cnt=$(($cnt + 1))
done
