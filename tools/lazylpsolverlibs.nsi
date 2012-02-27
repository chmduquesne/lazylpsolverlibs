!include MUI.nsh

name "lazylpsolverlibs-VERSION_installer.exe"
outFile "lazylpsolverlibs-VERSION_installer.exe"
installDir $PROGRAMFILES\GnuWin32

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "COPYING"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_LANGUAGE "English"

section
setOutPath "$INSTDIR\include"
file include\lazy_loading_status.h
file include\lazycplex.h
file include\lazyglpk.h
file include\lazygurobi.h
file include\lazyxprs.h
setOutPath "$INSTDIR\lib"
file lib\lazycplex.def
file lib\lazycplex.dll
file lib\liblazycplex.a
file lib\lazyglpk.def
file lib\lazyglpk.dll
file lib\liblazyglpk.a
file lib\lazygurobi.def
file lib\lazygurobi.dll
file lib\liblazygurobi.a
file lib\lazyxprs.def
file lib\lazyxprs.dll
file lib\liblazyxprs.a
setOutPath "$INSTDIR\bin"
file bin\lazycplex.dll
file bin\lazyglpk.dll
file bin\lazygurobi.dll
file bin\lazyxprs.dll
file bin\test_lazylpsolverlibs.exe
writeUninstaller "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
createDirectory "$SMPROGRAMS\GnuWin32"
createDirectory "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk" "$INSTDIR\bin\test_lazylpsolverlibs.exe"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk" "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
sectionEnd

section "Uninstall"
delete "$INSTDIR\..\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
rmdir  "$INSTDIR\..\uninstall"
delete "$INSTDIR\..\include\lazy_loading_status.h"
delete "$INSTDIR\..\include\lazycplex.h"
delete "$INSTDIR\..\include\lazyglpk.h"
delete "$INSTDIR\..\include\lazygurobi.h"
delete "$INSTDIR\..\include\lazyxprs.h"
rmdir  "$INSTDIR\..\include"
delete "$INSTDIR\..\lib\lazycplex.def"
delete "$INSTDIR\..\lib\lazycplex.dll"
delete "$INSTDIR\..\lib\liblazycplex.a"
delete "$INSTDIR\..\lib\lazyglpk.def"
delete "$INSTDIR\..\lib\lazyglpk.dll"
delete "$INSTDIR\..\lib\liblazyglpk.a"
delete "$INSTDIR\..\lib\lazygurobi.def"
delete "$INSTDIR\..\lib\lazygurobi.dll"
delete "$INSTDIR\..\lib\liblazygurobi.a"
delete "$INSTDIR\..\lib\lazyxprs.def"
delete "$INSTDIR\..\lib\lazyxprs.dll"
delete "$INSTDIR\..\lib\liblazyxprs.a"
rmdir  "$INSTDIR\..\lib"
delete "$INSTDIR\..\bin\lazycplex.dll"
delete "$INSTDIR\..\bin\lazyglpk.dll"
delete "$INSTDIR\..\bin\lazygurobi.dll"
delete "$INSTDIR\..\bin\lazyxprs.dll"
delete "$INSTDIR\..\bin\test_lazylpsolverlibs.exe"
rmdir  "$INSTDIR\..\bin"
rmdir  "$INSTDIR\..\..\GnuWin32"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk"
rmdir  "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
sectionEnd
