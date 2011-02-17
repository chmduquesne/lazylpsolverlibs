#include "test_lazylibs.h"
#include "lazy_loading_status.h"
#include <stdio.h>

int test_lazysolver(int (*load)(), int(*solve)(), int (*unload)())
{
    int status;
    int ok;
    ok = 1;
    status = load();
    switch(status) {
        case SYMBOL_LOAD_SUCCESS:
            fprintf(stdout, "The library loaded fine.\n");
            break;
        case SYMBOL_MISSING:
            fprintf(stdout, "The library loaded, though some symbols are missing (probably an old version).\n");
            break;
        case SYMBOL_LOAD_FAIL:
            fprintf(stdout, "The library did not load.\n");
            ok = 0;
            break;
    }

    if (!ok) return -1;

    if (solve() == 0)
        fprintf(stdout, "A problem was sucessfully solved\n");
    else
        fprintf(stdout, "The problem failed to solve\n");

    status = unload();
    switch(status) {
        case SYMBOL_UNLOAD_SUCCESS:
            fprintf(stdout, "The library unloaded fine.\n");
            break;
        case SYMBOL_UNLOAD_FAIL:
            fprintf(stdout, "The library did not unload fine\n");
            break;
    }
    return 0;
}
