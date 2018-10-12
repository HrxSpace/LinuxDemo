# 强制用bash，有的系统/bin/sh默认是用dash的，用dash会导致echo -e显示时多出一个-e
SHELL = /bin/bash

#编译器
COMPILE = gcc
#编译器选项
CFLAGS += $(INCLUDES) -Wall

#关联库
SHARE_LIBS +=
STATIC_LIBS +=
LIBS += $(SHARE_LIBS) $(STATIC_LIBS)

#编译目标
TARGET := mydemo

#目标文件目录
BUILDDIR ?= _build
TEMPDIR	?= $(BUILDDIR)/temp

#关联头文件目录
INCLUDES += -ImoduleMain/h -ImoduleA/h -ImoduleB/h -ImoduleC/h

#源文件
SOURCES	+= ${wildcard moduleMain/c/*.c}
SOURCES	+= ${wildcard moduleA/c/*.c}
SOURCES	+= ${wildcard moduleB/c/*.c}
SOURCES	+= ${wildcard moduleC/c/*.c}

#依赖文件
DEPENDS := $(patsubst %.c,$(TEMPDIR)/%.d,$(filter %.c, $(SOURCES)))
-include $(DEPENDS)

#对象文件
OBJECTS	:= $(patsubst %.c,$(TEMPDIR)/%.o,$(filter %.c, $(SOURCES)))

$(TEMPDIR)/%.d: %.c
	@echo "$@: $<:$(notdir $*)"
	@mkdir -pv $(@D)
	@set -e; rm -f $@; \
	$(COMPILE) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,$(notdir $*)\.o[ :]*,$(TEMPDIR)/$*\.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(TEMPDIR)/%.o: %.c
	@mkdir -pv $(@D)
	$(COMPILE) $(CFLAGS) -c -o $@ $<

sources:
	@echo "$(SOURCES)"

#生成目录
buildDir:
	@mkdir -pv $(BUILDDIR)
	@mkdir -pv $(TEMPDIR)

all: buildDir $(OBJECTS)
	@echo "Building for $(TARGET) ..."
	$(COMPILE) $(CFLAGS) $(OBJECTS) -o $(BUILDDIR)/$(TARGET) $(LIBS)
	@echo "********** Build Finish !!! **********"
	
clean:
	@rm -fv $(BUILDDIR) -r

