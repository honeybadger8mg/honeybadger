package com.honeybadger.nativelib;

public class NativeLib1 {
    static {
        System.loadLibrary("nativelib1");
    }

    public static native String DoTest1(String strArg);

    public static native int DoTest2(int iArg);
}