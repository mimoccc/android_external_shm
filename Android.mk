LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libandroid_shm
LOCAL_SRC_FILES := android_shm.c

include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE := libandroid_shm
LOCAL_SRC_FILES := android_shm.c

include $(BUILD_STATIC_LIBRARY)

