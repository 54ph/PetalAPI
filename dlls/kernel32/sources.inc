MAJORCOMP=windows
MINORCOMP=base

!include $(PROJECT_ROOT)\prerelease.inc

SYNCHRONIZE_DRAIN=1

TARGETNAME=kernel32
TARGETPATH=obj
TARGETTYPE=DYNLINK
W32_SB=1

NTTARGETFILE1= \
    $(SDK_LIB_DEST)\$(ALT_PROJECT_TARGET)\$(TARGET_DIRECTORY)\kernl32p.lib \
    $(SDK_LIB_DEST)\$(ALT_PROJECT_TARGET)\$(TARGET_DIRECTORY)\kernel32.lib

DLLDEF=$(O)\kernel32.def

LINKLIBS=\
    $(WINDOWS_LIB_PATH)\conlibk.lib \
    $(PROJECT_ROOT)\win32\winnls\$(ALT_PROJECT)\$(O)\nlslib.lib \
    $(PROJECT_LIB_PATH)\dload.lib \
    $(SDK_LIB_PATH)\ntdll.lib

TARGETLIBS=\
	$(WINDOWS_LIB_PATH)\conlibk.lib \
    $(PROJECT_ROOT)\win32\lz32\winlza\$(O)\winlza.lib \
    $(SDK_LIB_PATH)\uuid.lib

DLLENTRY=BaseDllInitialize

USE_NTDLL=1

INCLUDES=\
    ..;\
    ..\..\inc;\
    $(DS_INC_PATH);\
    $(WINDOWS_INC_PATH);\
    $(TERMSRV_INC_PATH);\
    $(SDKTOOLS_INC_PATH);\
    $(PROJECT_ROOT)\published\$(O);\
    $(PROJECT_ROOT)\win32\lz32\winlza;

CONDITIONAL_INCLUDES=doswin32.h

C_DEFINES=$(C_DEFINES) -D_KERNEL32_

MSC_WARNING_LEVEL=/W3 /WX

DLLORDER=..\kernel32.prf

SOURCES= \
    ..\alignstr.c \
    ..\base.rc    \
    ..\backup.c   \
    ..\beep.c     \
    ..\compname.c \
    ..\copylz.c   \
    ..\curdir.c   \
    ..\datetime.c \
    ..\debug.c    \
    ..\dir.c      \
    ..\dllatom.c  \
    ..\dllini.c   \
    ..\dload.c   \
    ..\dosdev.c   \
    ..\error.c    \
    ..\filefind.c \
    ..\filehops.c \
    ..\filemap.c  \
    ..\filemisc.c \
    ..\fileopcr.c \
    ..\firmware.c \
    ..\gmem.c     \
    ..\handle.c   \
    ..\baseinit.c \
    ..\lcompat.c  \
    ..\lmem.c     \
    ..\mailslot.c \
    ..\message.c  \
    ..\module.c   \
    ..\namepipe.c \
    ..\numa.c     \
    ..\pathmisc.c \
    ..\perfctr.c  \
    ..\pipe.c     \
    ..\power.c    \
    ..\process.c  \
    ..\res.c      \
    ..\sessdev.c  \
    ..\support.c  \
    ..\synch.c    \
    ..\termutil.c \
    ..\thread.c   \
    ..\toolhelp.c \
    ..\ustubs.c   \
    ..\winlzexp.c \
    ..\comm.c     \
    ..\vdm.c      \
    ..\volmount.c \
    ..\updrsrc.cpp   \
    ..\blddcb.c   \
    ..\tapeapi.c  \
    ..\job.c      \
    ..\winlinks.c \
    ..\w98stubs.c \
    ..\sxs.c      \
    ..\sxsfind.c  \
    ..\csrsxs.c   \
    ..\compsup.c  \
    ..\ahcache.c  \
    ..\csrahcache.c \
    ..\webblade.c \
	..\_file.c \
	..\_list.c \
	..\_loader.c \
	..\_kernelbase_debug.c \
	..\_kernelbase_locale.c \
	..\_memory.c \
	..\_process.c \
	..\_synchapi.c \
	..\_security.c \
	..\_system.c

UMTYPE=console
OPTIONAL_UMTEST=tatom*tprof*taskstrs*winperf*tbase*tprof*tfile*ttask*tmem*tlfn

PRECOMPILED_INCLUDE=..\basedll.h
PRECOMPILED_PCH=basedll.pch
PRECOMPILED_OBJ=basedll.obj

# No overflow checking for kernel32.dll
BUFFER_OVERFLOW_CHECKS=0

LINKER_FLAGS=/ignore:4217
