package com.example.hello;

public class HelloJNI {
    // Declare a native method sayHello() that receives nothing and returns void
    private native void sayHello();
    static {
        System.loadLibrary("hello"); // Load native library at runtime
        // hello.dll (Windows) or libhello.so (Unixes)
    }
    // Test Driver
    public static void main(String[] args) {
        System.out.println("Example with JNI");
        new HelloJNI().sayHello();  // invoke the native method
    }
}
