#include <jni.h>
#include <string>
#include "auth.h"
#include<android/log.h>


extern "C"
JNIEXPORT jint JNICALL
Java_com_hc_ndkdemo_NDKUtil_doAuth(JNIEnv *env, jobject thiz, jstring file_path, jstring ticket) {

    const char *asset_path = "/storage/emulated/0/Download";


    auth::AuthManager::Instance().SetAssetPath(asset_path);




    return 0;
}