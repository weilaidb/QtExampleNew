#Makefile module 1.4
#makfile module make模板[ ok 好使的]
#makefile ok
#makefileok 
#添加目录为目录名
#v1.2
###############################################################################
#$(shell basename $(COMPILE_DIR))文件名
COMPILE_DIR = $(shell pwd)
TARGET  = $(shell basename $(COMPILE_DIR))

SUBDIR = .
#SRC_INC_DIR    = $(shell find src -type d)
#SRC_INC	 = $(SRC_INC_DIR:%=-I%)
LOCAL_INC       = $(SRC_INC) -Iinclude -Iinclude/freetype 
INCPATH	 = $(LOCAL_INC)
TMPOBJPATH      = ./tmp
#LOCALDIR       = `pwd`
LOCAL_LIBDIR    = #lib
LOCAL_LIBS      = -lpthread -lzmq #-Llib #-lporting
LIBS = $(LOCAL_LIBS) $(RPATH_LINK) 
SRC     = $(shell find $(SUBDIR) -name '*.c')
CPPSRC  = $(shell find $(SUBDIR) -name '*.cpp') 
ASMSRC  = $(shell find $(SUBDIR) -name '*.s') 
OBJ     = $(SRC:%.c=$(TMPOBJPATH)/%.o)
CPPOBJ  = $(CPPSRC:%.cpp=$(TMPOBJPATH)/%.o)
SOBJ  = $(ASMSRC:%.s=$(TMPOBJPATH)/%.o)
LIBTARGET       = 
LIBSHAREDTARGET =

EXECDIR = ../exelibtest


COMPILE_PEFIX = #mips-linux-gnu-
CC = $(COMPILE_PEFIX)gcc
CXX = $(COMPILE_PEFIX)g++
AS = $(COMPILE_PEFIX)as
LINK = $(COMPILE_PEFIX)g++
LFLAGS = #-EL #-Wl,-O1
RPATH_LINK = 
DEFINES = #-D_FILE_OFFSET_BITS=64 
#CFLAGS = -w -fPIC -g -x c -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O2 -g -Wall -W -D_REENTRANT $(DEFINES)#-EL 
#CXXFLAGS = -w -fPIC -g -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O2 -g -Wall -W -D_REENTRANT $(DEFINES)
 
CFLAGS = -w -fPIC -g -x c -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O0 -g -Wall -W -D_REENTRANT $(DEFINES)#-EL 
CXXFLAGS = -w -fPIC -g -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O0 -g -Wall -W -D_REENTRANT $(DEFINES)
ASFLAGS = 


AR = $(COMPILE_PEFIX)ar rcs
TAR = tar -cf
COMPRESS = gzip -9f
COPY = cp -f
SED = sed
COPY_FILE = $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE = install -m 644 -p
INSTALL_DIR = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE = rm -f
SYMLINK = ln -sf
DEL_DIR = rmdir
MOVE = mv -f
CHK_DIR_EXISTS= test -d
MKDIR = mkdir -p


aaa:all
	chmod +x  $(TARGET) && ./$(TARGET)


all:$(TARGET)
	@echo current path is $(shell basename $(COMPILE_DIR))
	@echo "$(COPY_FILE) $(TARGET) $(EXECDIR)"
	@echo "$(MKDIR) $(EXECDIR)"
	@$(MKDIR) $(EXECDIR)
	@$(COPY_FILE) $(TARGET) $(EXECDIR)


$(LIBTARGET): $(LIBSHAREDTARGET) $(LIBTARGET) 
	@echo " [AR]    ($@)"
	@$(AR) $@ $(OBJ) $(CPPOBJ) $(SOBJ)
TAGETDIR:
	$(MKDIR) $(TMPOBJPATH)

$(TARGET): TAGETDIR  $(OBJ) $(CPPOBJ) $(SOBJ)
	@echo " [LD]    ($(TARGET))"
	@echo now file is `pwd`
	@echo "$(LINK) $(LFLAGS) -o $(TARGET) $(OBJ) $(CPPOBJ) $(SOBJ) $(LIBS)"
	@$(LINK) $(LFLAGS) -o $(TARGET) $(OBJ) $(CPPOBJ) $(SOBJ) $(LIBS)
dirdep:
	$(MKDIR) $(TMPOBJPATH)

install: all

$(TMPOBJPATH)/%.o : %.c
	@echo " [CC]    ($@)"
	@echo " $(CC) $(CFLAGS) $(INCPATH) -c $< -o $@"
	@$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@
$(TMPOBJPATH)/%.o : %.cpp
	@echo " [CXX]   ($@)"
	@echo " $(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@"
	@$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@
$(TMPOBJPATH)/%.o : %.s
	@echo " [AS]   ($@)"
	@echo " $(AS) $(ASFLAGS) $(INCPATH) $< -o $@"
	@$(AS) $(ASFLAGS) $(INCPATH) $< -o $@

clean:
	@echo " Cleaning... "
	@echo rm -f $(OBJ) $(CPPOBJ) $(SOBJ) $(TARGET) $(LIBTARGET) 
	@rm -f $(OBJ) $(CPPOBJ) $(SOBJ) $(TARGET) $(LIBTARGET)

