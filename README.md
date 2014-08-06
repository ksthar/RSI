RSI
===

RS-485/RSI control code.  Requires autotools suite, libtool.

Build Instructions (x86)
========================

Environment Vars:
_None_

Autogen Script:
./autogen.sh

Build Instructions (ARM cross-compile)
======================================

Environment Vars:
- CC=/clickbuild/tmp/sysroots/x86\_64-linux/usr/bin/armv5te-dey-linux-gnueabi/arm-dey-linux-gnueabi-gcc
- LD=/clickbuild/tmp/sysroots/x86\_64-linux/usr/bin/armv5te-dey-linux-gnueabi/arm-dey-linux-gnueabi-ld
- CFLAGS=" -g -O0 -march=armv5te --sysroot=/clickbuild/tmp/sysroots/ccardimx28js"
- CXXFLAGS=" -g -O0 -march=armv5te --sysroot=/clickbuild/tmp/sysroots/ccardimx28js"

Autogen Script:
./autogen.sh --target=armv5te-dey-linux-gnueabi --host=armv5te-dey-linux-gnueabi --build=x86\_64-linux --with-libtool-sysroot=/clickbuild/tmp/sysroots/ccardimx28js 
