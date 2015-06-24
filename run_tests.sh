#!/bin/bash

for test_src in ./tests/src/*.bf
do
	input=${test_src/%.bf/.txt}
	input=${input/src/input}
	if [ -e "$input" ]
	then
		output=${input/input/output}
		if [ -e "$output" ]
		then
			echo -n "Running test $test_src ... "
			diff=$(cat $input | ./bin/main $test_src | diff --side-by-side $output -)
			if [ $? -eq 0 ]
			then
				echo "OK"
			elif [ $? -eq 1 ]
			then
				echo "Test failed!"
				echo "$diff"
			else
				echo "Problems with diff"
				echo "$diff"
			fi
		else
			echo "Can't find output file $output!"
		fi
	else
		echo "Cant find input file $input!"
	fi
done
