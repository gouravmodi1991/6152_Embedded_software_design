/*
 * user_config.h
 *
 *  Created on: Sep 30, 2015
 *      Author: chipes
 */

#ifndef USER_CONFIG_H_
#define USER_CONFIG_H_

#define WIDTH  28
#define HEIGHT  28


/* DSP Frequency */
#define DSP_FREQ_IN_MHZ				1000

#define NUM_CORES 8

#ifdef OPERATE_LAYER_3
#define L1_MAPS 16
#define L2_MAPS 64
#define L3_MAPS 128

#define L1_KERNEL_SIZE 9
#define L2_KERNEL_SIZE 7
#define L3_KERNEL_SIZE 5

#else
/* Teradeep */
#define L1_MAPS 50
#define L2_MAPS 128

#define L1_KERNEL_SIZE 9
#define L2_KERNEL_SIZE 7

#define L1_L2_CONNECTIONS 10

#define L1_MAP_SIZE   (sizeof(short)*WIDTH*HEIGHT/4)
#define L2_MAP_SIZE	  (sizeof(short)*WIDTH*HEIGHT/8)

#endif

#ifdef CLASSIFIER
#define CLASSIFIER_INDEX 104
#endif



#define		CORE_L1_SYNC	*((volatile char*)0x80001000)
#define		CORE_L2_SYNC	*((volatile char*)0x80001010)
#define		CORE_L3_SYNC	*((volatile char*)0x80001020)
#define 	CORE_ALL_ACTIVE *((volatile char*)0x80001030)

#define 	CORE0_ACTIVE 	*((volatile char*)0x80001030)
#define 	CORE1_ACTIVE 	*((volatile char*)0x80001031)
#define 	CORE2_ACTIVE 	*((volatile char*)0x80001032)
#define 	CORE3_ACTIVE 	*((volatile char*)0x80001033)
#define 	CORE4_ACTIVE 	*((volatile char*)0x80001034)
#define 	CORE5_ACTIVE 	*((volatile char*)0x80001035)
#define 	CORE6_ACTIVE 	*((volatile char*)0x80001036)
#define 	CORE7_ACTIVE 	*((volatile char*)0x80001037)

#define 	CX_CRITICAL_SECTION_REFERENCE       0x80000000
#define 	L1_DATA_START		0x0C000000 /* a trick to bypass the compiler by hard coding the reference to start of critical section*/
#define     L2_DATA_START		L1_DATA_START+(sizeof(short)*(WIDTH*HEIGHT/4)*L1_MAPS)

#endif /* USER_CONFIG_H_ */
