

TOOLCHAIN_PREFIX = arm-none-eabi-

CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)gcc
AS = $(TOOLCHAIN_PREFIX)as
OBJCOPY = $(TOOLCHAIN_PREFIX)objcopy

FIX_CHECKSUM = ../tool/fix_checksum
DOWNLOAD_TOOL = ../tool/LinuxNXPISP.sh

CPU = -mcpu=cortex-m3 -mthumb

LD_SCRIPT = ../common/link.ld
CMSIS_DIR = ../cmsis

AFLAGS += ${CPU}
CFLAGS += ${CPU}
LDFLAGS += ${CPU} -nostartfiles -Wl,--gc-sections -Wl,-Map=out.map -T ${LD_SCRIPT}

VPATH += ${CMSIS_DIR}/src:${CMSIS_DIR}/src/startup

CFLAGS += -I ${CMSIS_DIR}/inc

SYS_OBJECTS += system_LPC13xx.o \
			   startup_LPC13xx.o


