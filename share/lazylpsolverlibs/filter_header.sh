#!/bin/sh
#
# This file is part of lazylpsolverlibs.
#
# You can redistribute it and/or modify it under the terms of the Eclipse
# Public License version 1.0, or (at your option) any later version.
#
# You should have received a copy of the Eclipse Public License along
# with lazylpsolverlibs (file EPL). If not, see
# http://www.eclipse.org/legal/epl-v10.html

header=$1

gatename=_$(echo $(basename $header)|sed 's/\./_/g'|sed 's/\(.*\)/\U\1/g')

tmp=$(mktemp)
trap 'rm "$tmp"' EXIT

echo "#ifndef $gatename" >> $tmp
echo "#define $gatename" >> $tmp
echo "
/*
 * This header was partly generated from a solver header of the same name,
 * to make lazylpsolverlibs callable. It contains only constants,
 * structures, and macros generated from the original header, and thus,
 * contains no copyrightable information.
 *
 * Additionnal hand editing was also probably performed.
 */
 " >> $tmp
gcc -fpreprocessed -dD -E $1 |\
    sed '/^$/d' |\
    grep -v '^#\s\+[0-9]\+\s\+".*"' |\
    head -n-1 |\
    tail -n+3 >> $tmp

echo "" >> $tmp
echo "#endif /* $gatename */" >> $tmp

cat $tmp | indent -gnu --no-tabs
