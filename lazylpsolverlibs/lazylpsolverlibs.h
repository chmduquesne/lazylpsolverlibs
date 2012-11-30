/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs.
 *
 * You can redistribute it and/or modify it under the terms of the MIT
 * license.
 *
 * You should have received a copy of the MIT license along
 * with lazylpsolverlibs (file MIT). If not, see
 * http://www.opensource.org/licenses/mit-license.php/
 */
#ifndef _LAZYLPSOLVERLIBS_H
#define _LAZYLPSOLVERLIBS_H

/*
 * Using functions of this file, you may set the behavior of the
 * lazylpsolverlibs when errors are encountered. A typical usage is shown
 * in helpers/lazylpsolverlibs-config.c
 */
void set_lazycplex_failure_callback(void (*f)(const char *err));
void set_lazygurobi_failure_callback(void (*f)(const char *err));
void set_lazyxprs_failure_callback(void (*f)(const char *err));
void set_lazyglpk_failure_callback(void (*f)(const char *err));

#endif /* _LAZYLPSOLVERLIBS_H */
