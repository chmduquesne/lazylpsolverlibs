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
file bin\lazycplex.dll
file bin\lazyglpk.dll
file bin\lazygurobi.dll
file bin\lazyxprs.dll
file bin\test_lazycplex.exe
file bin\test_lazyglpk.exe
file bin\test_lazygurobi.exe
file bin\test_lazyxprs.exe
writeUninstaller "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
createDirectory "$SMPROGRAMS\GnuWin32"
createDirectory "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk" "$INSTDIR\bin\test_lazylpsolverlibs.exe"
createShortCut "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk" "$INSTDIR\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
sectionEnd

section "Uninstall"
delete "$INSTDIR\..\uninstall\lazylpsolverlibs-VERSION_uninstaller.exe"
rmdir  "$INSTDIR\..\uninstall"
delete "$INSTDIR\..\bin\lazycplex.dll"
delete "$INSTDIR\..\bin\lazyglpk.dll"
delete "$INSTDIR\..\bin\lazygurobi.dll"
delete "$INSTDIR\..\bin\lazyxprs.dll"
delete "$INSTDIR\..\bin\test_lazycplex.exe"
delete "$INSTDIR\..\bin\test_lazyglpk.exe"
delete "$INSTDIR\..\bin\test_lazygurobi.exe"
delete "$INSTDIR\..\bin\test_lazyxprs.exe"
rmdir  "$INSTDIR\..\bin"
rmdir  "$INSTDIR\..\..\GnuWin32"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\test lazylpsolverlibs VERSION.lnk"
delete "$SMPROGRAMS\GnuWin32\lazylpsolverlibs\uninstall lazylpsolverlibs VERSION.lnk"
rmdir  "$SMPROGRAMS\GnuWin32\lazylpsolverlibs"
sectionEnd
