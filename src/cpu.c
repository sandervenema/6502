// Copyright (c) 2023 Sander Venema
// SPDX-License-Identifier: MIT

#include "cpu.h"

#include <stddef.h>
#include <assert.h>

// initialise the memory to zero
void mem_initialise(struct Mem *mem)
{
    for (size_t i = 0; i < MAX_MEM; i++)
    {
        mem->data[i] = 0;
    }
}

// reset the cpu
void cpu_reset(struct CPU *cpu, struct Mem *mem)
{
    assert(cpu != NULL);
    cpu->PC = 0xfffc;
    cpu->SP = 0x0100;
    cpu->C = cpu->Z = cpu->I = cpu->D = 0;
    cpu->B = cpu->V = cpu->N = 0;
    cpu->A = cpu->X = cpu->Y = 0;
    assert(mem != NULL);
    mem_initialise(mem);
}
