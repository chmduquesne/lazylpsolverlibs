# Installation #

## Linux ##

Just install the package suited for your platform, or compile it. The package can be traditionally compiled and installed using:
```
./configure
make
sudo make install
```

If the configure step fails, make sure glib-2.0 is installed on your computer.

## Windows ##

  * Download and install glpk from http://gnuwin32.sourceforge.net/packages/glpk.htm
  * Download and install the "all-in-one bundle" from http://www.gtk.org/download/win32.php
  * Download and install lazylpsolverlibs from [the download page](https://code.google.com/p/lazylpsolverlibs/downloads/list)

You're done! You can run the glpk test to verify that your setup works.

# Configuration #

## Intro ##

lazylpsolverlibs **loads** [shared libraries](https://secure.wikimedia.org/wikipedia/en/wiki/Library_(computing)#Shared_libraries) and makes their symbols available. While it tries to be clever and guess the names of those libraries by itself, you (as a user) may need to give it some hints.

## Maybe it works already? ##

If the solvers on your system are perfectly installed, lazylpsolverlibs should find them out by itself.

  * On linux, run `test_lazy<solver>`.
  * On windows, run `test_lazy<solver>.exe`

solver being the name (cplex, gurobi, xprs, glpk) of the solver you want to check support for. If the program fails, go on reading. Otherwise, you're done!

## Giving hints to lazylpsolverlibs ##

lazylpsolverlibs relies on **environment variables** to identify where the solvers libraries are located. The default is to search in standard search paths for a suitable library. lazylpsolverlibs tries to guess the name of the library to load from the solver name: at first it looks for a name like `[lib]<solver>.{so,dll}`, then it falls back to trying to load some other known names (with versions, starting from the most recent).

  * on linux, shared libraries use the extension .so and have a name that starts with 'lib'
  * on windows, shared libraries use the extension .dll

## Search path ##

  * on linux, the search path can be altered by appending to the LD\_LIBRARY\_PATH environment variable
  * on windows, it can be altered through the PATH environment variable

## Forcing a library ##

You can also force lazylpsolverlibs to load a specific library of your choice using one of the following environment variables:

```
LAZYLPSOLVERLIBS_GUROBI_LIB
LAZYLPSOLVERLIBS_GLPK_LIB
LAZYLPSOLVERLIBS_CPLEX_LIB
LAZYLPSOLVERLIBS_XPRS_LIB
```

Make sure you specify the full path. lazylpsolverlibs will always try to load this one first.

## Enabling debugging output ##

You can make lazylpsolverlibs verbose about what it does by setting the LAZYLPSOLVERLIBS\_DEBUG environment variable to "on"

```
export LAZYLPSOLVERLIBS_DEBUG=on
```

## Setting environment variables ##

### On linux ###

Execute this in your shell:
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/solverlibrary
```
You can append this command at the end of the file ~/.bashrc to make sure it is executed every time you log in.

### On windows ###

Use "Control Panel" > "System" > tab "Advanced" > "Environment Variables".

## Example ##

if you know cplex is installed in `/usr/ilog`, you can look for the shared library with the following command:
```
 > find /usr/ilog -name "lib*.so"        
/usr/ilog/cplex121/bin/x86_debian4.0_4.1/libcplex121.so
```

You can then add the path to the directory of the cplex library to your LD\_LIBRARY\_PATH:
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/ilog/cplex121/bin/x86_debian4.0_4.1/
```

# Security considerations #

If you fear that someone uses the environment variables to load a malicious solver libraries, be aware that a safe path exists. It is

```
/usr/local/lib/lib<solver>.so
```

This path is always checked first, so if you want to be absolutely sure what library is loaded, create it as a symbolic link to the actual solver library. If this path points to a loadable library, this library will be loaded, and the environment variables will be ignored.