// Copyright (c) 2023 Sander Venema
// SPDX-License-Identifier: MIT

#include "cpu.h"

#include <stddef.h>
#include <assert.h>
#include <stdio.h>

// initialise the memory to zero
void mem_initialise(struct Mem *mem)
{
    for (size_t i = 0; i < MAX_MEM; i++)
    {
        mem->data[i] = 0;
    }
}

// fetch 1 byte from memory
uint8_t mem_fetch_byte(struct CPU *cpu, struct Mem *mem, uint32_t *cycles)
{
    assert(cpu != NULL && mem != NULL && cycles != NULL);
    assert(cpu->PC < MAX_MEM);
    uint8_t data = mem->data[cpu->PC];
    cpu->PC++;
    (*cycles)--;
    return data;
}

// read 1 byte from memory
uint8_t mem_read_byte(struct CPU *cpu, struct Mem *mem, uint8_t zp_addr, uint32_t *cycles)
{
    assert(cpu != NULL && mem != NULL && cycles != NULL);
    uint8_t data = mem->data[zp_addr];
    (*cycles)--;
    return data;
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


// set the zero and negative flags correctly for LDA instruction
void cpu_instr_lda_set_status(struct CPU *cpu)
{
    assert(cpu != NULL);
    cpu->Z = (cpu->A == 0);
    cpu->N = (cpu->A & 0x80) > 0;
}

// execute instructions on the cpu for cycles amount of cycles
void cpu_execute(struct CPU *cpu, struct Mem *mem, uint32_t cycles)
{
    assert(cpu != NULL && mem != NULL);
    while (cycles > 0)
    {
        uint8_t instr = mem_fetch_byte(cpu, mem, &cycles);
        switch (instr)
        {
            case INS_LDA_IM: 
            {
                uint8_t value = mem_fetch_byte(cpu, mem, &cycles);
                cpu->A = value;
                cpu_instr_lda_set_status(cpu);
                break;
            };
            default:
            {
                fprintf(stderr, "Instruction not handled: %d\n", instr);
                break;
            };
        }
    }
}