AC_PREREQ(2.61)

# package version number (not shared library version)
# odd micro numbers indicate in-progress development
# even micro numbers indicate released versions
m4_define(rsiController_version_major, 0)
m4_define(rsiController_version_minor, 1)
m4_define(rsiController_version_micro, 0)

m4_define([rsiController_version],
          [rsiController_version_major.rsiController_version_minor.rsiController_version_micro])
m4_define([rsiController_api_version],
          [rsiController_version_major.rsiController_version_minor])

AC_INIT(rsiController, rsiController_version)
AM_INIT_AUTOMAKE(rsiController, rsiController_version)
AC_CONFIG_HEADERS(config.h)

# Checks for programs.
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_PROG_INSTALL

AC_SUBST(rsiController_CFLAGS)
AC_SUBST(rsiController_LIBS)

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
