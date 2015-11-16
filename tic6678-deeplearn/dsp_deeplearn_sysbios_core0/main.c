/*******************************************************
* File Name -- main.c
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
#include <csl_tsc.h>
#include <csl_chipAux.h>
#include <tistdtypes.h>
#include <csl_types.h>
#include <csl_cacheAux.h>
#include <csl_psc.h>
#include <csl_pscAux.h>
#include <cslr_emif4f.h>
#include <csl_emif4fAux.h>
#include "c6x.h"
#include "deep_learning.h"
#include "user_config.h"
#include "res/img_dd_28x28.h"

#define ITERATION 100000
CSL_Uint64 startVal,endVal;
double cumulative;

void delaycycles(uint32_t cycles)
{
	uint32_t start_val  = CSL_chipReadTSCL();

	while ((CSL_chipReadTSCL() - start_val) < cycles);

	return;
}

void do_power_gating()
{
	EMIF4F_PWR_MGMT_CONFIG pwrConfig;

	hPscRegs->PDCTL[CSL_PSC_PD_PCIEX] = hPscRegs->PDCTL[CSL_PSC_PD_PCIEX]& 0xFFFF0FFF;
	CSL_PSC_disablePowerDomain (CSL_PSC_PD_PCIEX);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_PCIEX, PSC_MODSTATE_SWRSTDISABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_PCIEX);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_PCIEX));

	hPscRegs->PDCTL[CSL_PSC_PD_SRIO] = hPscRegs->PDCTL[CSL_PSC_PD_SRIO]& 0xFFFF0FFF;
	CSL_PSC_disablePowerDomain (CSL_PSC_PD_SRIO);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SRIO, PSC_MODSTATE_SWRSTDISABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_SRIO);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_SRIO));

	hPscRegs->PDCTL[CSL_PSC_PD_HYPERBRIDGE] = hPscRegs->PDCTL[CSL_PSC_PD_HYPERBRIDGE]& 0xFFFF0FFF;
	CSL_PSC_disablePowerDomain (CSL_PSC_PD_HYPERBRIDGE);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_HYPERBRIDGE, PSC_MODSTATE_SWRSTDISABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_HYPERBRIDGE);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_HYPERBRIDGE));

	hPscRegs->PDCTL[CSL_PSC_PD_PASS] = hPscRegs->PDCTL[CSL_PSC_PD_PASS]& 0xFFFF0FFF;
	CSL_PSC_disablePowerDomain (CSL_PSC_PD_PASS);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_PKTPROC, PSC_MODSTATE_SWRSTDISABLE);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_CPGMAC,  PSC_MODSTATE_SWRSTDISABLE);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_Crypto,  PSC_MODSTATE_SWRSTDISABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_PASS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_PASS));

	CSL_PSC_setModuleNextState (CSL_PSC_LPSC_EMIF25_SPI, PSC_MODSTATE_SWRSTDISABLE);
    CSL_PSC_startStateTransition (CSL_PSC_LPSC_EMIF25_SPI);
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_LPSC_EMIF25_SPI));

	CSL_PSC_setModuleNextState (CSL_PSC_LPSC_TSIP, PSC_MODSTATE_SWRSTDISABLE);
    CSL_PSC_startStateTransition (CSL_PSC_LPSC_TSIP);
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_LPSC_TSIP));

//	CSL_PSC_setModuleNextState (CSL_PSC_LPSC_DEBUGSS_TRC, PSC_MODSTATE_SWRSTDISABLE);
//    CSL_PSC_startStateTransition (CSL_PSC_LPSC_DEBUGSS_TRC);
//    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_LPSC_DEBUGSS_TRC));

    hPscRegs->PDCTL[CSL_PSC_PD_GEM0] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM0]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM1] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM1]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM2] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM2]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM3] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM3]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM4] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM4]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM5] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM5]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM6] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM6]& 0xFFFF0FFF);
    hPscRegs->PDCTL[CSL_PSC_PD_GEM7] = (hPscRegs->PDCTL[CSL_PSC_PD_GEM7]& 0xFFFF0FFF);

    hPscRegs->MDCTL[CSL_PSC_LPSC_EMIF4F] = (hPscRegs->MDCTL[CSL_PSC_LPSC_EMIF4F] | (~0xFFFEFFF));
    CSL_EMIF4F_GetPowerMgmtConfig(&pwrConfig);
    pwrConfig.lpMode = 2;
    CSL_EMIF4F_SetPowerMgmtConfig(&pwrConfig);

//    switch(NUM_CORES)
//    {
//    case 0: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM0);
//    case 1: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM1);
//    case 2: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM2);
//    case 3: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM3);
//    case 4: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM4);
//    case 5: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM5);
//    case 6: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM6);
//    case 7: CSL_PSC_disablePowerDomain (CSL_PSC_PD_GEM7);
//    default:
//    	break;
//    }
}

void main()
{
	uint8_t core_id = DNUM;

	do_power_gating();

    CSL_tscEnable();

	CACHE_setL2Size (CACHE_0KCACHE);
	CACHE_setL1DSize(CACHE_L1_32KCACHE);
	CACHE_disableCaching (128);

#ifdef _CORE0
	memset((void*)0x80001000,0x0,0x40); //clear all the flag bytes
    printf("Given input image size: %dx%d \n", WIDTH, HEIGHT);
#endif

    deeplearn((uint16_t*)in_img, WIDTH, HEIGHT);
}
