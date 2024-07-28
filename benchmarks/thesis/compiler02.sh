#!/usr/bin/env bash
glibc_install="/root/workdir/install"
set -eux
gcc \
  -L "${glibc_install}/lib" \
  -I "${glibc_install}/include" \
  -Wl,--rpath="${glibc_install}/lib" \
  -Wl,--dynamic-linker="${glibc_install}/lib/ld-linux-x86-64.so.2" \
  -std=c11 \
  -o 02 \
  -v \
  02.c \
  -pthread \
;
ldd ./02
