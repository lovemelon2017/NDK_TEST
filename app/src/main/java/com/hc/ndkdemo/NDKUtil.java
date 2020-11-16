package com.hc.ndkdemo;

public class NDKUtil {
    static {
        System.loadLibrary("native-lib");
    }

    public native int doAuth(String filePath,String ticket);
}
