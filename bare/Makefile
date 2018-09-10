

TOPDIR := $(CURDIR)
export TOPDIR
obj := $(CURDIR)/
export obj
include config.mk

OBJS = start.o
OBJS := $(addprefix $(obj),$(OBJS))
# 子目录
LIBS = led/libled.a
LIBS += nandflash/libnandflash.a

LIBS := $(addprefix $(obj),$(LIBS))

# 暂时使用删除libxxx.a的方法使改变某个源文件重新生成静态库生效
all : delete_liba target
	

$(LIBS) :
	$(MAKE) -C $(dir $(subst $(obj),,$@))

target : $(LIBS) start.o main.o
	@echo "进行到这里，2018-09-10"
	
delete_liba : 
	@$(foreach N,$(dir $(subst $(obj),,$(LIBS))),rm -f $(N)*.a;)
	
clean : 
	@$(foreach N,$(dir $(subst $(obj),,$(LIBS))),rm -f $(N)*.a $(N)*.o;)
	@rm -f start.o main.o
	
%.o : %.S
	$(CC) $(CPPFLAGS) -o $@ $<
%.o : %.c $(INCLUDES)/led.h
	$(CC) $(CPPFLAGS) -o $@ $<