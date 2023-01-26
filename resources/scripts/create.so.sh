#!/usr/bin/env bash
gcc -shared -fpic -o libhello.so -I"/home/rcanseco/Desktop/software/jdk1.7.0_79/include/" -I"/home/rcanseco/Desktop/software/jdk1.7.0_79/include/linux" HelloJNI.c
#gcc -shared -fpic -o libfoo.so -I/usr/java/include -I/usr/java/include/linux foo.c