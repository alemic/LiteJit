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
**  @file   liveness-utils.h
**  @brief  Data structure management useful for liveness analysis
**  @author Baptiste Covolato <b.covolato@gmail.com>
**  @date   15 September 2013
*/

#ifndef LIVENESS_UTILS_H
# define LIVENESS_UTILS_H

# include <stdlib.h>

typedef struct _ljit_liveness_info_s _ljit_liveness_info;

struct _ljit_liveness_info_s
{
    /*
    **  @brief  The information represent the number of a temporary
    */
    unsigned short elt;

    /*
    **  @brief  The next element in the list
    */
    _ljit_liveness_info *next;
};

/**
**  @brief  Create a new element of an liveness info list
**  @param  elt The element contained in the new liveness info element
**
**  @return The new element if everything went well, NULL otherwise
*/

_ljit_liveness_info *_ljit_liveness_info_new(unsigned short elt);

/**
**  @brief  Free a liveness information list
**  @param  li  The list you want to free
*/

void _ljit_liveness_info_free(_ljit_liveness_info *li);

/**
**  @brief  Represent the minus operation of two lists
**  @param  li  The list where you want to remove the elements
**  @param  rem The elements to remove
*/

void _ljit_liveness_info_minus(_ljit_liveness_info *li,
                               _ljit_liveness_info *rem);

/**
**  @brief  Merge two list and return the new one
**  @brief  li1 The first list to merge
**  @brief  li2 The second list to merge
**
**  @return The result of the merge of li1 and li2, NULL if something wrong
**          happened.
*/

_ljit_liveness_info *_ljit_liveness_info_merge(_ljit_liveness_info *li1,
                                               _ljit_liveness_info *li2);

#endif /* !LIVENESS_UTILS_H */
