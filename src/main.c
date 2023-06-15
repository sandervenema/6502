// Copyright (c) 2023 Sander Venema
// SPDX-License-Identifier: MIT

#include <stdio.h>

#include "cpu.h"

int main()
{
    struct Mem mem;
    struct CPU cpu;
    cpu_reset(&cpu, &mem);

    printf("6502 emulator\n");
    return 0;
}