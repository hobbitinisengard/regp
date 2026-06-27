//This file is part of pcconvert.

//pcconvert is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 3 of the License, or
//any later version.

//pcconvert is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with pcconvert.  If not, see <http://www.gnu.org/licenses/>.

#include <inttypes.h>
typedef uint8_t byte;

uint32_t to_bmp(byte* in, byte** out,uint32_t, uint32_t, uint8_t deepth, uint8_t pixel_format);

#pragma pack(push, 1)

typedef struct {
    unsigned short type;                 /* Magic identifier            */
    unsigned int size;                       /* File size in bytes          */
    unsigned int reserved;
    unsigned int offset;                     /* Offset to image data, bytes */
} BMPHEADER;

typedef struct {
    unsigned int size;               /* Header size in bytes      */
    int width,height;                /* Width and height of image */
    unsigned short planes;       /* Number of colour planes   */
    unsigned short bits;         /* Bits per pixel            */
    unsigned int compression;        /* Compression type          */
    unsigned int imagesize;          /* Image size in bytes       */
    int xresolution,yresolution;     /* Pixels per meter          */
    unsigned int ncolours;           /* Number of colours         */
    unsigned int importantcolours;   /* Important colours         */
    //additional for 16 bit bitmaps
    unsigned int colorsMask[4];     /* Typically rgba    */
    unsigned int colorsSpaceType;
    unsigned char others[64];
} BMPINFOHEADER;

typedef struct {
    unsigned char r,g,b;
} BMPCOLOURINDEX;

#pragma pack(pop)

