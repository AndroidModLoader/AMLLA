LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp
				   
ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
	LOCAL_MODULE := AMLLA
	LOCAL_SRC_FILES += gtasa/sa_2_00.cpp gtasa/sa_2_10_32.cpp gtavc/vc_1_09.cpp
else
	LOCAL_MODULE := AMLLA64
	LOCAL_SRC_FILES += gtasa/sa_2_10_64.cpp
endif

LOCAL_CFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17 -mfpu=neon
LOCAL_C_INCLUDES += ./include
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)