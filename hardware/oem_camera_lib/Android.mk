LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES	:= \
	oem_test_camera.c \
	oem_camera_hw_interface.c \
  	oem_camera_hw_display.c \
  	oem_camera_v4l2_interface.c

LOCAL_C_INCLUDES += \
	$(TOP)/frameworks/native/include	\
	$(TOP)/system/core/include	\
	$(TOP)/hardware/libhardware/include	\
	$(TOP)/vendor/library/video_api/src	\
	$(TOP)/vendor/library/video_api/src/include	\
	$(TOP)/vendor/library/video_api/src/include/linux \
	$(TOP)/external/libdrm	\
	$(TOP)/hardware/gralloc \
	$(TOP)/hardware/oem_camera_lib/scaler	\
	$(TOP)/hardware/renderer/include \
	$(TOP)/hardware/v4l2

LOCAL_SHARED_LIBRARIES := \
	libcutils	\
	libbinder	\
	libutils \
	libgui \
	libui \
	libion \
	libhardware \
	libcamera_scaler	\
	libdrm	\
	libcamera_video_api

LOCAL_MODULE := camera_native
LOCAL_MODULE_PATH := $(LOCAL_PATH)/bin

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
