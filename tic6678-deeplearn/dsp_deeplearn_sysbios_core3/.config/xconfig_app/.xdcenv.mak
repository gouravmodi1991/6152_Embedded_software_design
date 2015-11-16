#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_33_08_55/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/mcsdk_2_01_02_06/demos;/opt/ti/ipc_1_25_02_12/packages;/opt/ti/ccsv5/ccs_base;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core3/.config
override XDCROOT = /opt/ti/xdctools_3_24_06_63
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_33_08_55/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/mcsdk_2_01_02_06/demos;/opt/ti/ipc_1_25_02_12/packages;/opt/ti/ccsv5/ccs_base;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core3/.config;/opt/ti/xdctools_3_24_06_63/packages;..
HOSTOS = Linux
endif
