#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_honeybadger_nativelib_NativeLib1_DoTest1(
        JNIEnv *env,
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
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_honeybadger_nativelib_NativeLib1_DoTestReflect(JNIEnv *env, jclass clazz) {
    jclass jcTarget = env->FindClass("com/honeybadger/nativelib/NativeLib1");
    if (jcTarget == nullptr) {
        return JNI_FALSE;
    }
    jmethodID mtdTarget = env->GetStaticMethodID(jcTarget, "TestReflect",
                                                 "(Ljava/lang/String;)Ljava/lang/String;");
    if (mtdTarget == nullptr) {
        return JNI_FALSE;
    }
    jstring jsArg = env->NewStringUTF("来自于native的参数");
    jstring jsResult = (jstring) env->CallStaticObjectMethod(jcTarget, mtdTarget, jsArg);
    const char *szResult = env->GetStringUTFChars(jsResult, JNI_FALSE);
    bool bVerify = strcmp(szResult, "ok");
    env->ReleaseStringUTFChars(jsArg, szResult);
    return bVerify;
}