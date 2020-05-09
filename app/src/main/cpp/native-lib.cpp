#include <jni.h>
#include <string>
#include <stdio.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitestapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitestapplication_MainActivity_anotherStringFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jstring firstName

) {
    std::string hello = "Does this work as I think";
    const char *fN = env->GetStringUTFChars(firstName, NULL);
    return env->NewStringUTF(fN);
}

extern "C" JNIEXPORT jchar JNICALL
Java_com_example_jnitestapplication_MainActivity_charFromAscii(
        JNIEnv* env,
        jobject /* this */,
        jint val

) {
    return char(val);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitestapplication_MainActivity_stringFromChar(
        JNIEnv* env,
        jobject /* this */,
        jchar val

) {
    char c = val;
    // string is a character array
    char str[2];
    str[0] = c;
    //string always ends with a null character
    str[1] = '\0';
    return env->NewStringUTF(str);
}


extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_jnitestapplication_MainActivity_addStringToStringArray(JNIEnv *env, jobject, jobjectArray arr, jstring val) {
    jint len = env->GetArrayLength(arr);
    jint newLen = len+1;
    jobjectArray newArr = env->NewObjectArray(newLen, env->FindClass("java/lang/String"), NULL);
    for(int i = 0; i < len; i++) {
        jstring temp = (jstring ) env->GetObjectArrayElement(arr, i);
        env->SetObjectArrayElement(newArr, i, temp);
    }
    env->SetObjectArrayElement(newArr, newLen-1, val);
    return newArr;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jnitestapplication_MainActivity_printList(JNIEnv *env, jobject thiz,
                                                           jobjectArray arr) {
    jint len = env->GetArrayLength(arr);
    for(int i = 0; i < len; i++) {
        const char *fN = env->GetStringUTFChars((jstring ) env->GetObjectArrayElement(arr, i), NULL);
        printf("Test %s", fN);
    }
}