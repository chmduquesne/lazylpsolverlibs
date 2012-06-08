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
setOutPath "$INSTDIR\bin"
file bin\liblazycplex-0.dll
file bin\liblazygurobi-0.dll
file bin\liblazyglpk-0.dll
file bin\liblazyxprs-0.dll
file bin\test_lazycplex.exe
file bin\test_lazyglpk.exe
file bin\test_lazygurobi.exe
file bin\test_lazyxprs.exe
setOutPath "$INSTDIR\lib"
file lib\liblazycplex.a
file lib\liblazycplex.dll.a
file lib\liblazycplex.la
file lib\liblazyglpk.a
file lib\liblazyglpk.dll.a
file lib\liblazyglpk.la
file lib\liblazygurobi.a
file lib\liblazygurobi.dll.a
file lib\liblazygurobi.la
file lib\liblazyxprs.a
file lib\liblazyxprs.dll.a
file lib\liblazyxprs.la
setOutPath "$INSTDIR\lib\pkgconfig"
file lib\pkgconfig\lazycplex.pc
file lib\pkgconfig\lazyglpk.pc
file lib\pkgconfig\lazygurobi.pc
file lib\pkgconfig\lazyxprs.pc
writeUninstaller "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
createDirectory "$SMPROGRAMS\GnuWin32"
createDirectory "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk" "$INSTDIR\bin\test_lazylpsolverlibs.exe"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk" "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
sectionEnd

section "Uninstall"
delete "$INSTDIR\..\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
rmdir  "$INSTDIR\..\uninstall"
delete "$INSTDIR\..\bin\liblazycplex-0.dll"
delete "$INSTDIR\..\bin\liblazygurobi-0.dll"
delete "$INSTDIR\..\bin\liblazyglpk-0.dll"
delete "$INSTDIR\..\bin\liblazyxprs-0.dll"
delete "$INSTDIR\..\bin\test_lazycplex.exe"
delete "$INSTDIR\..\bin\test_lazyglpk.exe"
delete "$INSTDIR\..\bin\test_lazygurobi.exe"
delete "$INSTDIR\..\bin\test_lazyxprs.exe"
rmdir  "$INSTDIR\..\bin"
delete "$INSTDIR\..\lib\pkgconfig\lazycplex.pc"
delete "$INSTDIR\..\lib\pkgconfig\lazyglpk.pc"
delete "$INSTDIR\..\lib\pkgconfig\lazygurobi.pc"
delete "$INSTDIR\..\lib\pkgconfig\lazyxprs.pc"
rmdir  "$INSTDIR\..\lib\pkgconfig"
delete "$INSTDIR\..\lib\liblazycplex.a"
delete "$INSTDIR\..\lib\liblazycplex.dll.a"
delete "$INSTDIR\..\lib\liblazycplex.la"
delete "$INSTDIR\..\lib\liblazyglpk.a"
delete "$INSTDIR\..\lib\liblazyglpk.dll.a"
delete "$INSTDIR\..\lib\liblazyglpk.la"
delete "$INSTDIR\..\lib\liblazygurobi.a"
delete "$INSTDIR\..\lib\liblazygurobi.dll.a"
delete "$INSTDIR\..\lib\liblazygurobi.la"
delete "$INSTDIR\..\lib\liblazyxprs.a"
delete "$INSTDIR\..\lib\liblazyxprs.dll.a"
delete "$INSTDIR\..\lib\liblazyxprs.la"
rmdir  "$INSTDIR\..\lib"
rmdir  "$INSTDIR\..\..\GnuWin32"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk"
rmdir  "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
sectionEnd
