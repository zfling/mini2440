include $(TOPDIR)/config.mk

LIB = libled.a
COBJS = led.o
# COBJS +=
OBJS := $(COBJS)

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) crv $@ $(OBJS)
	
%.o : %.S
	$(CC) $(CPPFLAGS) -o $@ $<
%.o : %.c $(INCLUDES)/led.h
	$(CC) $(CPPFLAGS) -o $@ $<