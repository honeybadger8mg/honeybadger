package com.honeybadger.nativelib;

import android.util.Log;

public class NativeLib1 {
    static {
        System.loadLibrary("nativelib1");
    }

    public static native String DoTest1(String strArg);

    public static native int DoTest2(int iArg);

    // 测试反射
    public static String TestReflect(String strArg) {
        Log.d("NativeLib1", "TestReflect 函数调用  参数是:" + strArg);
        return "ok";
    }
    public static native boolean DoTestReflect();

}