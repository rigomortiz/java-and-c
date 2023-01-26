#include "/usr/lib/jvm/java-8-oracle/include/jni.h"
#include <stdio.h>
#include "com_example_hello_HelloJNI.h"


// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_com_example_hello_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello World!\n");
   return ;
}
void main(){}