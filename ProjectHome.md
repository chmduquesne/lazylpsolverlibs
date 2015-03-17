# Introduction #

This project provides library replacements for cplex, gurobi, xpress:
  * That are free
  * That you can link to as a replacement for the original solver libraries
  * That load the actual library solver so that you are provided with the exact functionality you are after.

The libraries provided don't re-implement anything and the user **still needs to
obtain the solver by legal means**. The value added is that if you want to write free software that uses a commercial solver, providing a binary distribution is made easier for you: you have an opensource library to link to. At runtime, the actual library is automatically imported (with hints from the user through environment variables).

## Using ##

Using lazylpsolverlibs is very simple: In your build system, where you were using
```
    -l<solver_libdir>
```
use
```
    pkg-config --libs lazy<solver>
```

And where you were using
```
    -I<solver_incdir>
```
use
```
    pkg-config --cflags lazy<solver>
```

## Licensing ##

Dual licensing is applied. In respect with the licensing terms of glpk, the glpk-related binaries (and sources) are licensed under the [GPL v3.0](http://www.gnu.org/licenses/gpl-3.0.html). The rest of the package is licensed under the [MIT license](http://www.opensource.org/licenses/mit-license.php/).

## Misc ##

lazylpsolverlibs was designed to make [coin-osi](https://projects.coin-or.org/Osi) easier to package, but it can be useful in other projects.

Author: Christophe-Marie Duquesne