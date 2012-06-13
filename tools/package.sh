#!/bin/sh

version(){
    echo $package_archive | sed "s/lazylpsolverlibs-\(.*\).tar.gz/\1/g"
}

compile_linux(){
    mkdir -p /tmp/packaging/linux
    tar xvzf $package_archive -C /tmp/packaging/linux
    cd /tmp/packaging/linux/lazylpsolverlibs-$(version)
    ./configure --prefix=/tmp/packaging/linux/install \
    make
    make install
    cd -
}

get_wine_build_deps(){
    mkdir -p tools/wine
    wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip
    unzip glib-dev_2.28.8-1_win32.zip -d tools/wine
    rm glib-dev_2.28.8-1_win32.zip
    wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime-dev_0.18.1.1-2_win32.zip
    unzip gettext-runtime-dev_0.18.1.1-2_win32.zip -d tools/wine
    rm gettext-runtime-dev_0.18.1.1-2_win32.zip
    sed -i "s#^prefix=.*#prefix=tools/wine#g" tools/wine/lib/pkgconfig/*.pc
}

compile_windows(){
    mkdir -p /tmp/packaging/windows
    tar xvzf $package_archive -C /tmp/packaging/windows
    cd /tmp/packaging/windows/lazylpsolverlibs-$(version)
    get_wine_build_deps
    ./get.headers
    ./configure --prefix=/tmp/packaging/windows/install \
                --host=i486-mingw32 \
                PKG_CONFIG_LIBDIR=tools/wine/lib/pkgconfig \
                CPPFLAGS="-DBUILD_CPXSTATIC -D_WIN32"
    make generate_stubs
    make
    make install
    cd -
}

package_debian(){
    fpm -s dir -t deb -n lazylpsolverlibs -v $(version) -C /tmp/packaging/linux/install -p lazylpsolverlibs-VERSION_ARCH.deb -d "libglib2.0-dev(>=0)"
}

package_fedora(){
    fpm -s dir -t rpm -n lazylpsolverlibs -v $(version) -C /tmp/packaging/linux/install -p lazylpsolverlibs-VERSION_ARCH.rpm -d "libglib2.0-dev(>=0)"
}

package_windows(){
    cp tools/lazylpsolverlibs.nsi COPYING /tmp/packaging/windows/install
    cd /tmp/packaging/windows/install
    sed -i "s/VERSION/$(version)/g" lazylpsolverlibs.nsi
    makensis lazylpsolverlibs.nsi
    cd -
    cp /tmp/packaging/windows/install/lazylpsolverlibs-$(version)_installer.exe .
}

package(){
    rm -rf /tmp/packaging
    compile_linux
    package_debian
    package_fedora
    compile_windows
    package_windows
}

package_archive=$1

package
