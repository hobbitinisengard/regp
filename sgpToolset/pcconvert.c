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

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <malloc.h> 
#include "image.h"

extern uint32_t decompress(uint8_t* in, uint8_t* out);

int main(int argc, char *argv[])
{
	FILE *f;
	uint8_t *fcontent, *bitmapPixelsBuffer, *compressedStream, *out_buff;
    uint16_t imgWidth, imgHeight;
	uint32_t fsize, bitmapPixelsSize, dsize, pformat, out_data_len;
    char *out_filename;
    
    // pixels format setup
    uint8_t bits_pp = 16;
    // RGBA 4444
    //pformat = 4;
    
    pformat = 0;

	if(argc <= 1)
	{
		printf("%s", "Please specify SGP *.PC filepath to decompress. Output is written in same place but as bmp.\n");
		return 0;
	}
	
	f = fopen(argv[1], "rb");
    
    if(!f)
    {
       printf("No such file! %s \n", argv[1]);
       return 0;
    }
    
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  //same as rewind(f);

	fcontent = (uint8_t*) malloc(fsize + 1);
    if(!fcontent)
    {
        printf("Memory allocation error, aborting!\n");
        return 0;
    }
	fread(fcontent, fsize, 1, f);
	fclose(f);

    if (fcontent[0] != 'T' && fcontent[1] != 'M' && fcontent[2] != '!')
    {
        printf("File header not recognized, aborting!\n");
        return 0;
    } 
    //printf("PTRS: %p %p\n", fcontent, bitmapPixelsBuffer);
    
    imgWidth = *((uint16_t*)&fcontent[6]);
    imgHeight = *((uint16_t*)&fcontent[8]);
    bitmapPixelsSize = imgWidth * imgHeight * 2 ;
    
    printf("Image size: %d x %d\n", imgWidth, imgHeight);
    
    // compressed data starts from 0xA
    compressedStream = &fcontent[0xA];
    
    bitmapPixelsBuffer = (uint8_t*) malloc(bitmapPixelsSize);
    if(!bitmapPixelsBuffer)
    {
        printf("Memory allocation error, aborting!\n");
        return 0;
    }
    
	dsize = decompress(compressedStream, bitmapPixelsBuffer);
    
    out_data_len = to_bmp(bitmapPixelsBuffer, &out_buff, imgWidth, imgHeight, bits_pp, pformat);

    out_filename = malloc(strlen(argv[1])+10);
    if(!out_filename)
    {
        printf("Memory allocation error, aborting!\n");
        return 0;
    }
    strcpy(out_filename, argv[1]);
    strcpy(&out_filename[strlen(out_filename)-3], ".bmp");
    printf("%s \n", out_filename);
	f = fopen(out_filename, "wb");
	fwrite(out_buff, out_data_len, 1, f);
	fclose(f);
    free(bitmapPixelsBuffer);
    free(fcontent);
    free(out_buff);
	printf("DONE %d \n", dsize);
    
    return 0;
}
