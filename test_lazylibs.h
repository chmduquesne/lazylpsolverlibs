#ifndef TEST_LAZYLIBS_H
#define TEST_LAZYLIBS_H

int test_lazysolver(int (*load)(), int(*solve)(), int (*unload)());

#endif /* TEST_LAZYLIBS_H */
