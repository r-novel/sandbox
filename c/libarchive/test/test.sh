#!/usr/bin/env bash

prj=`pwd`
bin_d=$prj/bin
test_d=$prj/test

function prepare() {
	cd $test_d
	dd if=/dev/urandom of=test.txt bs=10k count=16
	printf "\033[1;32m[i]: have been created dummy file;\033[0m\n"
	sleep 1
	tar -zcvf test.tar.gz test.txt
	printf "\033[1;32m[i]: have been created test archive;\033[0m\n"
	sleep 1
	rm test.txt
	printf "\033[1;32m[i]: removed dummy;\033[0m\n"
	sleep 1
	cd ..
}

if [ ! -f $bin_d/extract ]; then
	printf "\033[1;32m[i]: executable file not found. trying build...\033[0m\n"
	make -f $prj/Makefile
fi

prepare
$bin_d/extract $test_d/test.tar.gz

if [ -f $prj/test.txt ]; then
	ls -lah test.txt
	printf "\033[1;32m[i]: extracted test file found; remove...\033[0m\n"
	rm $prj/test.txt
	rm $test_d/test.tar.gz
	make clean
fi
