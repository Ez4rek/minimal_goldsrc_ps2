EE_BIN = goldsrc_ps2.elf

EE_OBJS = \
main.o \
platform/ps2_video.o \
platform/ps2_input.o \
platform/ps2_system.o \
renderer/r_main.o \
engine/host.o \
math/vec3.o

EE_INCS += -I./ -I$(PS2SDK)/ports/include

EE_LIBS += -ldmakit -lgskit -lpad -lm

EE_CFLAGS = -O2 -G0 -Wall

all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal