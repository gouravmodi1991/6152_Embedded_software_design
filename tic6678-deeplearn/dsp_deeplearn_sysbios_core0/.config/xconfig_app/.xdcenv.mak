#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/ccsv5/ccs_base;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0/.config
override XDCROOT = /opt/ti/xdctools_3_24_06_63
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/ccsv5/ccs_base;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0/.config;/opt/ti/xdctools_3_24_06_63/packages;..
HOSTOS = Linux
endif
