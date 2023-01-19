#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_honeybadger_nativelib_NativeLib1_stringFromJNI(
        JNIEnv* env,
        jclass, jstring jsArg) {
    const char *szData = env->GetStringUTFChars(jsArg, JNI_FALSE);
    std::string strData = szData;
    env->ReleaseStringUTFChars(jsArg, szData);

    std::string strOut = strData + " 已处理";
    return env->NewStringUTF(strOut.c_str());
}