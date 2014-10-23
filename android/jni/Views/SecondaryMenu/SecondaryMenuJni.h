// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <jni.h>

extern "C"
{
	JNIEXPORT void JNICALL Java_com_eegeo_secondarymenu_SecondaryMenuViewJniMethods_PerformSearchQuery(
	    JNIEnv* jenv, jobject obj,
	    jlong nativeObjectPtr,
	    jstring searchQuery);
}

