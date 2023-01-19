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
    public native String stringFromJNI();
}