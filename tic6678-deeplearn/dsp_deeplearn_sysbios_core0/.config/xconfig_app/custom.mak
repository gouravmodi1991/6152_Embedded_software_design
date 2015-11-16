## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/app_pe66.oe66 \

linker.cmd: package/cfg/app_pe66.xdl
	$(SED) 's"^\"\(package/cfg/app_pe66cfg.cmd\)\"$""\"/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0/.config/xconfig_app/\1\""' package/cfg/app_pe66.xdl > $@
