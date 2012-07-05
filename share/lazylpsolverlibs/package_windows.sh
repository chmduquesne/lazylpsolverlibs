#!/bin/sh

[ -z $1 ] && echo "Usage: $0 <archive>" && exit

version(){
    echo $package_archive | sed "s/lazylpsolverlibs-\(.*\).tar.gz/\1/g"
}

get_wine_build_deps(){
    mkdir -p share/wine
    wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip
    unzip glib-dev_2.28.8-1_win32.zip -d share/wine
    rm glib-dev_2.28.8-1_win32.zip
    wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime-dev_0.18.1.1-2_win32.zip
    unzip gettext-runtime-dev_0.18.1.1-2_win32.zip -d share/wine
    rm gettext-runtime-dev_0.18.1.1-2_win32.zip
    sed -i "s#^prefix=.*#prefix=share/wine#g" share/wine/lib/pkgconfig/*.pc
}

compile(){
    mkdir -p /tmp/win32
    tar xvzf $package_archive -C /tmp/win32
    cd /tmp/win32/lazylpsolverlibs-$(version)
    get_wine_build_deps
    ./get.headers
    ./configure --prefix=/tmp/win32/install \
                --host=i586-mingw32msvc \
                PKG_CONFIG_LIBDIR=share/wine/lib/pkgconfig \
                CPPFLAGS="-DBUILD_CPXSTATIC -D_WIN32"
    make generate_stubs
    make
    make install
    cd -
}

package(){
    cp share/lazylpsolverlibs.nsi COPYING /tmp/win32/install
    cd /tmp/win32/install
    sed -i "s/VERSION/$(version)/g" lazylpsolverlibs.nsi
    makensis lazylpsolverlibs.nsi
    cd -
    cp /tmp/win32/install/lazylpsolverlibs-$(version)_installer.exe .
}

package_archive=$1
rm -rf /tmp/win32
compile
package
