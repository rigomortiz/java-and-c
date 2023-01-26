//
// Created by regoeco on 16/05/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>
#include "/usr/lib/jvm/java-8-oracle/include/jni.h"
#include "com_example_file_OpenFileLowLevel.h"

// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT int JNICALL Java_com_example_file_OpenFileLowLevel_acquireLock(JNIEnv *env, jobject thisObj, jstring js_file) {
    int lockFd;
    // Step 1: Convert the JNI String (jstring) into C-String (char*)
    const char *file = (*env)->GetStringUTFChars(env, js_file, NULL);
    if (NULL == file) return -1;

    if ((lockFd = open(file, O_RDWR, 0666))  < 0){
        perror ("open");
        return -1;
    } else{
        if (flock(lockFd, LOCK_EX | LOCK_NB) < 0) {
            perror ("lock");
            return -2;
        }else{
            return lockFd;
        }
    }
}

JNIEXPORT void JNICALL Java_com_example_file_OpenFileLowLevel_releaseLock(JNIEnv *env, jobject thisObj, jint lockFd){
    if ( flock (lockFd, LOCK_UN) < 0) {
        perror ("lock");
    }
    if ( close(lockFd) < 0) {
        perror ("close");
    }
}

void main(){}
