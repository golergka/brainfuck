#!/bin/bash

echo "Enter EOF (Ctrl-D) to end each test"
for test_src in ./tests/src/*.bf
do
	output=${test_src/%.bf/.txt}
	output=${output/src/output}
	input=${output/output/input}
	echo "Running $test_src from $input to $output"
	touch $input
	touch $output
	cat | tee $input | ./bin/main $test_src | tee $output
	echo "Recorded input:"
	cat $input
	echo "Recorded output:"
	cat $output
done
