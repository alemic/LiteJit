/*
    Copyright (C) 2013 Baptiste COVOLATO <b.covolato@gmail.com>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

/**
**  @file   elf.h
**  @brief  Provide elf support to export/import code into ELF format
**  @author Baptiste Covolato <b.covolato@gmail.com>
**  @date   26 August 2013
*/

#ifndef ELF_H
# define ELF_H

# include <ljit/elf/elf-defs.h>
# include <ljit/elf/elf-header.h>
# include <ljit/elf/elf-section.h>
# include <ljit/elf/elf-write.h>

# ifdef LJIT_DEBUG
#  include <ljit/elf/elf-debug.h>
# endif /* LJIT_DEBUG */

/**
**  @brief  Create a new elf structure
**
**  @return The new elf created, or NULL if something went wrong
*/

ljit_elf *ljit_new_elf(void);

/**
**  @brief  Free an elf
**  @param  elf The elf you want to free
*/

void ljit_free_elf(ljit_elf *elf);


#endif /* !ELF_H */
