LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_MODULE    := AMLLA
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp \
				   gtasa/sa_2_00.cpp gtasa/sa_2_10_32.cpp
LOCAL_CFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17 -mfpu=neon
LOCAL_C_INCLUDES += ./include
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)