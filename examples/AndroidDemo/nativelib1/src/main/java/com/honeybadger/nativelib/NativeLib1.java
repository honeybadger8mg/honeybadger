package com.honeybadger.nativelib;

public class NativeLib1 {

    // Used to load the 'nativelib' library on application startup.
    static {
        System.loadLibrary("nativelib1");
    }

    /**
     * A native method that is implemented by the 'nativelib' native library,
     * which is packaged with this application.
     */
    public static native String DoTest1(String strArg);
    public static native int DoTest2(int iArg);
}