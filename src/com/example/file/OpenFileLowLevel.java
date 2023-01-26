package com.example.file;

public class OpenFileLowLevel {
    // Declare a native method sayHello() that receives nothing and returns void
    private native int acquireLock(String s);
    private native void releaseLock(int i);

    static {
        System.loadLibrary("ofll"); // Load native library at runtime;  hello.dll (Windows) or libhello.so (Unixes)

    }

    // Test Driver
    public static void main(String[] args) throws InterruptedException {
                    // invoke the native method
        int fd = new OpenFileLowLevel().acquireLock(args[0]);
        switch (fd){
            case -1:
                System.out.println("cannot open file");
                break;
            case -2:
                System.out.println("cannot lock file");
                break;
            default: {
                System.out.println("file lock, file descriptor:" + fd);
                Thread.sleep(10000);
                new OpenFileLowLevel().releaseLock(fd);  // invoke the native method
            }
        }
        
    }
}
