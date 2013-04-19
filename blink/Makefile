
include ../common/Makefile

PROJECT = blink

OBJECTS = blink.o

all: ${PROJECT}.bin

${PROJECT}.bin: ${PROJECT}.elf
	${OBJCOPY} -O binary $< $@
	${FIX_CHECKSUM} $@

${PROJECT}.elf: ${OBJECTS} ${SYS_OBJECTS}
	${LD} ${LDFLAGS} -o $@ $^

download:
	${DOWNLOAD_TOOL} ${PROJECT}.bin

clean:
	rm -f ${PROJECT}.bin ${PROJECT}.elf ${OBJECTS} ${SYS_OBJECTS} *.o *.map

