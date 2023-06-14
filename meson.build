# Copyright (c) 2023 Sander Venema
# SPDX-License-Identifier: MIT

project('6502emu', 'c', 
    version: '0.0.1',
    license: 'MIT',
    default_options: ['c_std=c11', 'warning_level=3', 'werror=true'])
add_global_arguments(['-Wshadow', '-Wstrict-overflow', '-fanalyzer'], language: 'c')

subdir('src')
