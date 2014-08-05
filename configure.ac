AC_PREREQ(2.61)

# package version number (not shared library version)
# odd micro numbers indicate in-progress development
# even micro numbers indicate released versions
m4_define(POC_0528_version_major, 0)
m4_define(POC_0528_version_minor, 1)
m4_define(POC_0528_version_micro, 0)

m4_define([POC_0528_version],
          [POC_0528_version_major.POC_0528_version_minor.POC_0528_version_micro])
m4_define([POC_0528_api_version],
          [POC_0528_version_major.POC_0528_version_minor])

AC_INIT(POC_0528, POC_0528_version)
AM_INIT_AUTOMAKE(POC_0528, POC_0528_version)
AC_CONFIG_HEADERS(config.h)

# Checks for programs.
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_PROG_INSTALL

AC_SUBST(POC_0528_CFLAGS)
AC_SUBST(POC_0528_LIBS)

AC_OUTPUT([
Makefile
src/Makefile
])

echo ""
echo "   POC_0528 $VERSION"
echo "   ====================="
echo ""
echo "   To build the project, run \"make\""
echo ""
