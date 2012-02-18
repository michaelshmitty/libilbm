/**
 * Copyright (c) 2012 Sander van der Burg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __ILBM_COLORRANGE_H
#define __ILBM_COLORRANGE_H

#include <ifftypes.h>
#include <chunk.h>

#define ILBM_COLORRANGE_MAX_ACTIVE_VALUE 16384

typedef struct
{
    IFF_Group *parent;
    
    IFF_ID chunkId;
    IFF_Long chunkSize;

    IFF_Word pad1;
    IFF_Word rate;
    IFF_Word active;
    IFF_UByte low, high;
}
ILBM_ColorRange;

ILBM_ColorRange *ILBM_createColorRange(void);

IFF_Chunk *ILBM_readColorRange(FILE *file, const IFF_Long chunkSize);

int ILBM_writeColorRange(FILE *file, const IFF_Chunk *chunk);

int ILBM_checkColorRange(const IFF_Chunk *chunk);

void ILBM_freeColorRange(IFF_Chunk *chunk);

void ILBM_printColorRange(const IFF_Chunk *chunk, const unsigned int indentLevel);

#endif
