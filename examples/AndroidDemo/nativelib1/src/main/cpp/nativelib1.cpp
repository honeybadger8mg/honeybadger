#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_honeybadger_nativelib_NativeLib1_DoTest1(
        JNIEnv* env,
        jclass, jstring jsArg) {
    const char *szData = env->GetStringUTFChars(jsArg, JNI_FALSE);
    std::string strData = szData;
    env->ReleaseStringUTFChars(jsArg, szData);

    std::string strOut = strData + " 已处理";
    return env->NewStringUTF(strOut.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_honeybadger_nativelib_NativeLib1_DoTest2(JNIEnv *env, jclass clazz, jint i_arg) {
    int iOut = i_arg + 100;
    return iOut;
}