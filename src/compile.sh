#!/bin/bash
rm -r *.so
gcc -fPIC -shared -o munsterCode.so munsterCode.c
