################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSPF_sp_dotprod.obj: ../DSPF_sp_dotprod.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="DSPF_sp_dotprod.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

DSPF_sp_maxval.obj: ../DSPF_sp_maxval.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="DSPF_sp_maxval.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

DSP_add32.obj: ../DSP_add32.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP_add32.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

DSP_maxval.obj: ../DSP_maxval.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP_maxval.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_3x3_i16s_c16s.obj: ../IMG_conv_3x3_i16s_c16s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_3x3_i16s_c16s.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_3x3_i8_c8s_cn.obj: ../IMG_conv_3x3_i8_c8s_cn.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_3x3_i8_c8s_cn.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_5x5_i16s_c16s.obj: ../IMG_conv_5x5_i16s_c16s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_5x5_i16s_c16s.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_5x5_i8_c8s_cn.obj: ../IMG_conv_5x5_i8_c8s_cn.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_5x5_i8_c8s_cn.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_7x7_i16s_c16s.obj: ../IMG_conv_7x7_i16s_c16s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_7x7_i16s_c16s.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_7x7_i8_c8s_cn.obj: ../IMG_conv_7x7_i8_c8s_cn.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_7x7_i8_c8s_cn.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_conv_9x9_i8_c8s_cn.obj: ../IMG_conv_9x9_i8_c8s_cn.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_conv_9x9_i8_c8s_cn.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

IMG_math.obj: ../IMG_math.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="IMG_math.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: ../app.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_24_06_63/xs" --xdcpath="/opt/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.platforms.evm6678 -r debug -c "/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

deep_learning.obj: ../deep_learning.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="deep_learning.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --opt_for_speed=5 --include_path="/opt/ti/ccsv5/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/opt/ti/imglib_c66x_3_1_1_0/packages" --include_path="/opt/ti/pdk_C6678_1_1_2_6/packages" --include_path="/opt/ti/imglib_c66x_3_1_1_0/inc" -g --multibyte_chars --gcc --define=_CORE0 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


