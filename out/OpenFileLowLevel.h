/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class OpenFileLowLevel */

#ifndef _Included_OpenFileLowLevel
#define _Included_OpenFileLowLevel
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     OpenFileLowLevel
 * Method:    acquireLock
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_OpenFileLowLevel_acquireLock
  (JNIEnv *, jobject, jstring);

/*
 * Class:     OpenFileLowLevel
 * Method:    releaseLock
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_OpenFileLowLevel_releaseLock
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif