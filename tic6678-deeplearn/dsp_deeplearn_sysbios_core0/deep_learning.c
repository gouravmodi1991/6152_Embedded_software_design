/*******************************************************
* File Name -- deep_learn.c
*
* Authors:  Nachiappan, Gourav, Mahesh
*
* Created on : 27-September-2015
*
* Contents: Deeplearn algorithm implementation
*           for TI TMS320C6678 - DSP
*
********************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "user_config.h"
#include <csl_tsc.h>
#include "c6x.h"
#include <csl_cacheAux.h>

#include "imglib.h"
#include "DSP_maxval.h"
#include "IMG_conv_9x9_i8_c8s_cn.h"
#include "IMG_conv_3x3_i8_c8s_cn.h"
#include "IMG_conv_5x5_i8_c8s_cn.h"
#include "IMG_conv_7x7_i8_c8s_cn.h"
#include "DSPF_sp_dotprod.h"

#include "inc/kernel_3x3.h"
#include "inc/kernel_5x5.h" /*TODO: generate kernels*/
#include "inc/kernel_7x7.h"
#include "inc/kernel_9x9.h"
#include "inc/weights.h"

typedef enum CRITICAL_SECTION
{
	L1_MAPS1,
	L2_MAPS1,
#ifdef OPERATE_LAYER_3
	L3_MAPS1,
#endif
	MAX_CRITICAL_SECTION
}CRITICAL_SECTION;

typedef struct SharedMem
{
	uint16_t		nSize;
	uint16_t		nElements;
	void*			nSegment;
}SharedMem;

unsigned int core_id;

#pragma DATA_SECTION(ImageData1, ".local_ram")
#pragma DATA_ALIGN(ImageData1,4)
short 	ImageData1[WIDTH][HEIGHT] ={{0}};

#pragma DATA_SECTION(L1Data2, ".local_ram")
#pragma DATA_ALIGN(L1Data2,4)
short 	L1Data2[WIDTH/2][HEIGHT/2] ={{{0}}};

#pragma DATA_SECTION(L2Data2, ".local_ram")
#pragma DATA_ALIGN(L2Data2,4)
short 	L2Data2[WIDTH/4][HEIGHT/4] ={{{0}}};

#pragma DATA_SECTION(dilate, ".local_ram")
#pragma DATA_ALIGN(dilate,8)
short dilate[9] = {0};

#pragma DATA_SECTION(kernel, ".local_ram")
#pragma DATA_ALIGN(kernel,8)
const short kernel[9] = { 1, 1, 1,
		                  1, 1, 1,
		                  1, 1, 1
                        };

#ifdef _CORE0

#pragma DATA_SECTION(L1Data1, ".critical_section")
#pragma DATA_ALIGN(L1Data1,128)
short	L1Data1[L1_MAPS][WIDTH/2][HEIGHT/2] ={{{0}}};

#pragma DATA_SECTION(L2Data1, ".critical_section")
#pragma DATA_ALIGN(L2Data1,128)
short 	L2Data1[L2_MAPS][WIDTH/4][HEIGHT/4] ={{{0}}};

#ifdef OPERATE_LAYER_3
#pragma DATA_SECTION(L3Data1, ".critical_section")
#pragma DATA_ALIGN(L3Data1,4)
short 	L3Data1[L3_MAPS][WIDTH/8][HEIGHT/8]={{{0}}};
#endif

#pragma DATA_SECTION(gCriticalMemRef, ".critical_section_reference")
SharedMem	gCriticalMemRef[MAX_CRITICAL_SECTION] =
{

	WIDTH/2*HEIGHT/2, 1,(void*)&L1Data1[0][0][0],

	WIDTH/4*HEIGHT/4, 1,(void*)&L2Data1[0][0][0],
#ifdef OPERATE_LAYER_3
	WIDTH/8*HEIGHT/8, 1,(void*)&L3Data1[0][0][0]
#endif
};


#ifdef CLASSIFIER

#pragma DATA_SECTION(data, ".critical_section")
#pragma DATA_ALIGN(data,8)
float data[CLASSIFIER_INDEX];

#pragma DATA_SECTION(data1, ".critical_section")
#pragma DATA_ALIGN(data1,8)
float data1[CLASSIFIER_INDEX];

#pragma DATA_SECTION(data2, ".critical_section")
#pragma DATA_ALIGN(data2,8)
float data2[CLASSIFIER_INDEX];

#pragma DATA_SECTION(data3, ".critical_section")
#pragma DATA_ALIGN(data3,8)
float data3[CLASSIFIER_INDEX];

static float *fData  = &data[0];
static float *fData1 = &data1[0];
static float *fData2 = &data2[0];
static float *fData3 = &data3[0];
#endif

SharedMem *gCriticalMemRefPtr = (SharedMem *)&gCriticalMemRef;

#else /* _CORE0 */

SharedMem *gCriticalMemRefPtr = (SharedMem *)CX_CRITICAL_SECTION_REFERENCE;

#endif


char  *gL1Data1  = NULL;
char  *gL2Data1  = NULL;
#ifdef OPERATE_LAYER_3
char  *gL3Data1  = NULL;
#endif

void MemMgr_InitCriticalMemory()
{

#ifdef _CORE0
	memset((void*)gL1Data1, 0, gCriticalMemRefPtr[L1_MAPS1].nSize*gCriticalMemRefPtr[L1_MAPS1].nElements);
	memset((void*)gL2Data1, 0, gCriticalMemRefPtr[L2_MAPS1].nSize*gCriticalMemRefPtr[L2_MAPS1].nElements);
#ifdef OPERATE_LAYER_3
	memset((void*)gL3Data1, 0, gCriticalMemRefPtr[L3_MAPS1].nSize*gCriticalMemRefPtr[L3_MAPS1].nElements);
#endif
#endif
	gL1Data1 		= (char*)(gCriticalMemRefPtr[L1_MAPS1].nSegment);
	gL2Data1 		= (char*)(gCriticalMemRefPtr[L2_MAPS1].nSegment);
#ifdef OPERATE_LAYER_3
	gL3Data1 		= (char*)(gCriticalMemRefPtr[L3_MAPS1].nSegment);
#endif
}

#ifdef CLASSIFIER
uint8_t MaxValue(uint8_t *image1, int M, int N)
{
    int row, col;
    uint8_t max;

    max = image1[0]; //1st element

    for (row = 0; row < M; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (*(image1 + N* row + col) > max)
            {
                max = (*(image1 + N* row + col));
            }
        }
    }
    return max;
}
#endif

static void Dilate3x3(short *image,short *dest_image, int M, int N)
{
    int row, col;
    for (row = 0; row < M; row++)
    {
        for (col = 0; col < N; col++)
        {

        	IMG_conv_3x3_i16s_c16s((image + N*row + col),&dilate[0],9,N,&kernel[0],0);
        	*(dest_image + N*row + col) = DSP_maxval(&dilate[0],9);
        }
    }
}

static void SubSampleBy2Fun(short *image, short *dest_image, int R, int C)
{
    int row, col;
    for (row = 0; row < R; row++)
    {
        for (col = 0; col <C; col++)
        {
            *(dest_image + C*row + col) = (*(image + 2 * (C*row + col) + 1));
        }

    }
}

static void s_img_add_weighted(short *image1, short *image2, int M, int N, int scale)
{
   int row,col;
   for (row = 0; row < M; row++)
   {
       for (col = 0; col < N; col++)
       {
        	   *(image2 + N*row + col) = (*(image1 + N*row + col) + *(image2 + N*row + col)) >> scale;
       }
   }
}

uint32_t operateLayer1(uint16_t** src, uint32_t w, uint32_t h)
{
    uint8_t i;
    uint32_t j;
    short * ImageDataPtr = (short*)&ImageData1[0][0];  //TODO: num larger 128 ??
    const short *src_ptr = (const short*)*src;
    short pixels = w*h;
    short shift = 0;
    uint8_t num_maps;

	if(DNUM < (L1_MAPS%NUM_CORES))
		num_maps = (L1_MAPS/NUM_CORES)+1;
	else
		num_maps = L1_MAPS/NUM_CORES;

    for (i = 0; i<num_maps; i++)
    {

    	IMG_conv_7x7_i16s_c16s (src_ptr, ImageDataPtr, pixels, h, &kernel7x7[i][0],shift); /*9x9, all cores read image from cs here*/

    	for (j=0; j<pixels; j++)
        {
        	ImageDataPtr[j] = ((ImageDataPtr[j] < 0) ? 0 : ImageDataPtr[j]);
        }

        Dilate3x3(ImageDataPtr,ImageDataPtr, w, h);     // currently using same input as ouput, thinking it should not affect the results, saving data space

        if(i<(L1_MAPS/NUM_CORES))
        {
        	SubSampleBy2Fun(ImageDataPtr,(short*)(gL1Data1+(core_id*(L1_MAPS/NUM_CORES))+(i*L1_MAP_SIZE)), w/2, h/2);  // all cores will write to critical section here, but before read we need to sync.
        }
        else
        {
        	SubSampleBy2Fun(ImageDataPtr,(short*)(gL1Data1 + (NUM_CORES*(L1_MAPS/NUM_CORES))+(core_id*L1_MAP_SIZE)), w/2, h/2);

        }
    }
    return 0;
}

uint32_t operateLayer2(uint32_t w, uint32_t h)
{
    uint8_t i,k,selection,num_maps;
    uint32_t j;
    short *ImageDataPtr = &L1Data2[0][0];
    short* ptr1 = NULL;
    short* ptr2 = NULL;
    short pixels = w*h;
    short shift = 0;

	if(DNUM < (L2_MAPS%NUM_CORES))
		num_maps = (L2_MAPS/NUM_CORES)+1;
	else
		num_maps = L2_MAPS/NUM_CORES;

    for (i = 0; i<num_maps; i++)
    {
    	selection = rand() % L1_MAPS;
        ptr1 = (short*)(gL1Data1+(selection*L1_MAP_SIZE));
        for(k=0;k<L1_L2_CONNECTIONS;k++)
        {
        	selection = rand() % L1_MAPS;
        	ptr2 = (short*)(gL1Data1+(selection*L1_MAP_SIZE));
        	s_img_add_weighted(ptr1,ptr2,w,h,1); //TODO:logically correct ?? optimize??
        }
        IMG_conv_5x5_i16s_c16s(ptr2,ImageDataPtr, pixels, h, &kernel5x5[i][0],shift);

        for (j=0; j<w*h; j++)
        {
        	ImageDataPtr[j] = ((ImageDataPtr[j] < 0) ? 0 : ImageDataPtr[j]);
        }

        Dilate3x3(ImageDataPtr,ImageDataPtr, w, h);

        if(i<(L2_MAPS/NUM_CORES))
        {
        	SubSampleBy2Fun(ImageDataPtr,(short*)(gL2Data1+(core_id*(L2_MAPS/NUM_CORES))+(i*L2_MAP_SIZE)), w/2, h/2);
        }
        else
        {
        	SubSampleBy2Fun(ImageDataPtr,(short*)(gL2Data1+(NUM_CORES*(L2_MAPS/NUM_CORES))+(core_id*L2_MAP_SIZE)), w/2, h/2);
        }
    }
    return 0;
}

#ifdef OPERATE_LAYER_3
uint32_t operateLayer3(uint32_t w, uint32_t h)
{
    uint8_t i,k;
    uint32_t j;
    uint8_t selection;
    char *ImagePtr = (char*)&L2Data2[0][0];
    signed char* ptr1 = NULL;
    signed char* ptr2 = NULL;
    short pixels = w*h;
    short shift = 0;
    uint8_t num_maps;

	if(DNUM < (L3_MAPS%NUM_CORES))
		num_maps = (L3_MAPS/NUM_CORES)+1;
	else
		num_maps = L3_MAPS/NUM_CORES;

    for (i = 0; i<num_maps; ++i)
    {
    	selection = rand() % L2_MAPS;
        ptr1 = (signed char*)&gL2Data1[selection][0][0];
        for(k=0;k<1;k++)
        {
        	selection = rand() % L2_MAPS;
        	ptr2 = (signed char*)&gL2Data1[selection][0][0];
        	s_img_add_weighted((uint8_t*)ptr1,(uint8_t*)ptr2,w,h,1);
        }
        IMG_conv_5x5_i8_c8s((unsigned char*)ptr2,(unsigned char*)ImagePtr, pixels, h, &kernel5x5[i][0],shift);
        for (j=0; j<w*h; j++)
        {
        	ImagePtr[j] = ((ImagePtr[j] < 0) ? 0 : ImagePtr[j]);
        }
        Dilate3x3((unsigned char*)ImagePtr, (unsigned char*)ImagePtr, w, h);

        if(num_maps<(L2_MAPS/NUM_CORES))
        	SubSampleBy2Fun((uint8_t*)ImagePtr, (uint8_t*)gL3Data1[core_id*(L3_MAPS/NUM_CORES)+i][0][0], w/2, h/2);
        else
        	SubSampleBy2Fun((uint8_t*)ImagePtr, (uint8_t*)gL3Data1[NUM_CORES*(L3_MAPS/NUM_CORES)+core_id][0][0], w/2, h/2);

    }

    return 0;
}
#endif

#ifdef CLASSIFIER
#ifdef _CORE0
uint8_t classifier(uint8_t** src_initial, int w, int h)
{
    uint8_t  maxVal;
    uint32_t index;
    uint8_t* src = *src_initial;
    float   sum;
    const float * const fKernel = input_weights[0];

    //Normalize.
    maxVal = MaxValue(src, w,h);
    //maxVal = DSP_maxval(src,w*h);

    for (index = 0; index<104; index++)
    {
        fData[index] = (float)(src[index] / maxVal);
    }

    //Input layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData,fKernel,104);
        fData1[index] = (float)tanh(sum);
    }
    //Hidden Layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData1,fKernel,104);
        fData2[index] = (float)tanh(sum);
    }
    //Output Layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData1,fKernel,104);
        fData3[index] = (float)tanh(sum);
    }
    return 0;
}
#endif
#endif

uint8_t deeplearn(uint16_t* data, uint32_t w, uint32_t h)
{
	core_id = DNUM;

	MemMgr_InitCriticalMemory();

    operateLayer1(&data, w, h);
    CACHE_wbAllL1dWait();

    operateLayer2(w / 2, h / 2);
    CACHE_wbAllL1dWait();

#ifdef OPERATE_LAYER_3
    startVal = CSL_tscRead();
    operateLayer3(w / 4, h / 4);
    endVal = CSL_tscRead();
    _mfence();
    printf ("L3 %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_MHZ);
#endif

#ifdef CLASSIFIER
#ifdef _CORE0
    startVal = TSCL;
    classifier(&data, w / 8, h / 8);
    endVal = TSCL;
   printf ("classifier %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_MHZ);
#endif
#endif
    return 0;
}
