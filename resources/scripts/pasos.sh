#!/usr/bin/env bash
DIR_JNI="/home/rcanseco/Desktop/software/jdk1.7.0_79/include/"
PATH_LIB_IN_C="."
JAVA_CLASS="HelloJNI"
FILE_IN_C="HelloJNI.c"
LIB_IN_C="libhello"
javac $JAVA_CLASS + ".java"
javah $JAVA_CLASS

#USE FILE .h
#COMPILE IN LINUX-GNU
gcc -shared -fpic -o $LIB_IN_C+".so" -I $DIR_JNI -I $DIR_JNI+"linux" $JAVA_CLASS

#OPTIONAL
nm $LIB_IN_C+".so" |grep say

#RUN
java -Djava.library.path= $PATH_LIB_IN_C $JAVA_CLASS