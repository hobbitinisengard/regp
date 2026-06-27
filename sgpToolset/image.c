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

#include "image.h"
#include <malloc.h> 

uint32_t to_bmp(byte* in, byte** out, uint32_t width, uint32_t height, uint8_t bits, uint8_t pixel_format)
{
    uint8_t offset = sizeof(BMPHEADER)+sizeof(BMPINFOHEADER);
    uint32_t bytes_per_line = width*(bits/8);
    uint8_t padding = 4 - (bytes_per_line % 4);
    if( padding == 4) padding = 0;
    uint32_t data_size = bytes_per_line*height + (height*padding);
    uint32_t file_size = data_size+offset;


    *out = malloc(file_size+256);
    if(!*out)
    {
        printf("Memory allocation error, aborting!\n");
        return 0;
    }

    BMPHEADER *hdr = (BMPHEADER*)*out;
    BMPINFOHEADER *hdrinfo = (BMPINFOHEADER*)&(*out)[14];
    hdr->type = 0x4d42;
    hdr->offset = offset;
    hdr->reserved = 0x00;

    hdrinfo->size = sizeof(BMPINFOHEADER);
    hdrinfo->width = width;
    hdrinfo->height = height;
    hdrinfo->planes = 1;
    hdrinfo->bits = bits;
    hdrinfo->compression = bits == 16 ? 0x3: 0x0;
    hdrinfo->imagesize = file_size;
    hdrinfo->xresolution = 0;
    hdrinfo->yresolution = 0;
    hdrinfo->ncolours = 0;
    hdrinfo->importantcolours = 0;
    hdrinfo->colorsMask[0] = 0x7c00;
    hdrinfo->colorsMask[1] = 0x3e0;
    hdrinfo->colorsMask[2] = 0x1f;
    hdrinfo->colorsMask[3] = 0x0;
    //hdrinfo->colorsMask[3] = 0x8000;
    if (pixel_format == 4)
    {
        hdrinfo->colorsMask[0] = 0xf00;
        hdrinfo->colorsMask[1] = 0xf0;
        hdrinfo->colorsMask[2] = 0xf;
        hdrinfo->colorsMask[3] = 0xf000;
    }

    hdrinfo->colorsSpaceType = 0x73524742;

    hdr->size = file_size;

    uint32_t line, row;

    if(bits == 16)
    {
        uint16_t* clr_in = (uint16_t*)in;
        uint16_t *clr_out = (uint16_t*)&(*out)[offset];
        clr_in += (width*height-width);
        for(line = 0; line <height; ++line)
        {
           for(row = 0; row < width; ++row)
           {
               *clr_out = *clr_in;
               ++clr_in;
               ++clr_out;
           }
           uint8_t* pad = (uint8_t*)clr_out;
           uint8_t i;
           for(i=0; i < padding; ++i, ++pad)
              *pad = 0x00;
           clr_out = (uint16_t*) pad;
           clr_in -= width*2;
        }
    }
    else
    {
        uint8_t* clr_in = (uint8_t*)in;
        BMPCOLOURINDEX *clr_out = (BMPCOLOURINDEX*)&(*out)[offset];
        clr_in += (width*height-width)*3;
        for(line = 0; line <height; ++line)
        {
           for(row = 0; row < width; ++row)
           {
               clr_out->b = *clr_in; ++clr_in;
               clr_out->g = *clr_in; ++clr_in;
               clr_out->r = *clr_in; ++clr_in;
               ++clr_out;
           }
           uint8_t* pad = (uint8_t*)clr_out;
           uint8_t i;
           for(i=0; i < padding; ++i, ++pad)
              *pad = 0x00;
           clr_out = (BMPCOLOURINDEX*) pad;
           clr_in -= width*2*sizeof(BMPCOLOURINDEX);
        }
    }
    return file_size;
}
