LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)





LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

#LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp 
#                   ../../Classes/HelloWorldScene.cpp
LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(shell find $(LOCAL_PATH)/../../Classes -name '*.cpp')
#LOCAL_SRC_FILES += $(shell find /Applications/Cocos/Cocos2d-x/cocos2d-x-3.10/cocos -name '*.cpp')
LOCAL_SRC_FILES := $(subst jni/,, $(LOCAL_SRC_FILES))

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES := $(shell find $(LOCAL_PATH)/../../Classes -type d)
#LOCAL_C_INCLUDES += $(shell find /Applications/Cocos/Cocos2d-x/cocos2d-x-3.10/cocos -type d)

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_STATIC_LIBRARIES += cocostudio_static
# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)
#$(call import-module,audio/android)
# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
