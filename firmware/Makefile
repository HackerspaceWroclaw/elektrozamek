######################################
# target
######################################
TARGET = elektrozamek


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


# Build path
BUILD_DIR = build

######################################
# source
######################################
# C++ sources
CPP_SOURCES = \
$(wildcard src/*.cpp)

# C sources
C_SOURCES =  \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_spi_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rtc_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_spi.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rtc.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c \
drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c \
$(wildcard hal/*.c)

# ASM sources
ASM_SOURCES =  \
hal/startup_stm32f103xb.s


#######################################
# binaries
#######################################
BINPATH =
PREFIX = arm-none-eabi-
CC = $(BINPATH)$(PREFIX)gcc
CPP = $(BINPATH)$(PREFIX)g++
AS = $(BINPATH)$(PREFIX)gcc -x assembler-with-cpp
CP = $(BINPATH)$(PREFIX)objcopy
AR = $(BINPATH)$(PREFIX)ar
SZ = $(BINPATH)$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# mcu
MCU = $(CPU) -mthumb

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F103xB

# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-Ihal \
-Idrivers/STM32F1xx_HAL_Driver/Inc \
-Idrivers/STM32F1xx_HAL_Driver/Inc/Legacy \
-Idrivers/CMSIS/Device/ST/STM32F1xx/Include \
-Idrivers/CMSIS/Include


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
CFLAGS += -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst))

CPPFLAGS = $(CFLAGS) --std=c++11 -fno-exceptions

#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F103C8Tx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR) 
	$(CPP) -c $(CPPFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(ASFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
