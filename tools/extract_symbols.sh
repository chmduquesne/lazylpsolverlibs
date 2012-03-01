#!/bin/sh
objdump -j .text -T $@ | sed 's/\s\+/\t/g' | cut -f7 | sed '/^$/d'
