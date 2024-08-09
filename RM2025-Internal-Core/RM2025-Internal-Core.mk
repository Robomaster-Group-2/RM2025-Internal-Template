
CPP_SOURCES += \
$(wildcard $(CORE_DIR)/Drivers/*.cpp) \

C_INCLUDES += \
-I$(CORE_DIR)/Drivers

SystemView_PATH = $(CORE_DIR)/Diagnostic/SystemView
include $(SystemView_PATH)/SystemView.mk

FreeRTOS_DIR = $(CORE_DIR)/FreeRTOS
include $(FreeRTOS_DIR)/FreeRTOS.mk