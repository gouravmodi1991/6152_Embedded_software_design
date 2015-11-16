#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_33_08_55/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/mcsdk_2_01_02_06/demos;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core2/.config
override XDCROOT = /opt/ti/xdctools_3_23_05_61
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_33_08_55/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/mcsdk_2_01_02_06/demos;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core2/.config;/opt/ti/xdctools_3_23_05_61/packages;..
HOSTOS = Linux
endif
