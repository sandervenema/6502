// Copyright (c) 2023 Sander Venema
// SPDX-License-Identifier: MIT

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// available memory
#define MAX_MEM (1024 * 64)

// opcodes
#define INS_LDA_IM 0xa9
#define INS_LDA_ZP 0xa5

struct Mem
{
    uint8_t data[MAX_MEM];
};

struct CPU
{
    uint16_t PC;        // program counter
    uint16_t SP;        // stack pointer

    uint8_t A, X, Y;    // registers

    uint8_t C : 1;      // carry flag
    uint8_t Z : 1;      // zero flag
    uint8_t I : 1;      // interrupt disable flag
    uint8_t D : 1;      // decimal flag
    uint8_t B : 1;      // no cpu effect
    uint8_t V : 1;      // overflow flag
    uint8_t N : 1;      // negative flag
};

void mem_initialise(struct Mem *mem);
uint8_t mem_fetch_byte(struct CPU *cpu, struct Mem *mem, uint32_t *cycles);
uint8_t mem_read_byte(struct CPU *cpu, struct Mem *mem, uint8_t zp_addr, uint32_t *cycles);

void cpu_reset(struct CPU *cpu, struct Mem *mem);
void cpu_instr_lda_set_status(struct CPU *cpu);

#endif /* CPU_H */