AC_PREREQ(2.61)

# package version number (not shared library version)
# odd micro numbers indicate in-progress development
# even micro numbers indicate released versions
m4_define(rsiTest_version_major, 0)
m4_define(rsiTest_version_minor, 1)
m4_define(rsiTest_version_micro, 0)

m4_define([rsiTest_version],
          [rsiTest_version_major.rsiTest_version_minor.rsiTest_version_micro])
m4_define([rsiTest_api_version],
          [rsiTest_version_major.rsiTest_version_minor])

AC_INIT(rsiTest, rsiTest_version)
AM_INIT_AUTOMAKE(rsiTest, rsiTest_version)
AC_CONFIG_HEADERS(config.h)

# Checks for programs.
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_PROG_INSTALL

AC_SUBST(rsiTest_CFLAGS)
AC_SUBST(rsiTest_LIBS)

AC_OUTPUT([
Makefile
src/Makefile
])

echo ""
echo "   RSI $VERSION"
echo "   ====================="
echo ""
echo "   To build the project, run \"make\""
echo ""
