################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../app.cfg 

C_SRCS += \
../DSPF_sp_dotprod.c \
../DSPF_sp_maxval.c \
../DSP_add32.c \
../DSP_maxval.c \
../IMG_conv_3x3_i16s_c16s.c \
../IMG_conv_3x3_i8_c8s_cn.c \
../IMG_conv_5x5_i16s_c16s.c \
../IMG_conv_5x5_i8_c8s_cn.c \
../IMG_conv_7x7_i16s_c16s.c \
../IMG_conv_7x7_i8_c8s_cn.c \
../IMG_conv_9x9_i8_c8s_cn.c \
../IMG_math.c \
../deep_learning.c \
../main.c 

OBJS += \
./DSPF_sp_dotprod.obj \
./DSPF_sp_maxval.obj \
./DSP_add32.obj \
./DSP_maxval.obj \
./IMG_conv_3x3_i16s_c16s.obj \
./IMG_conv_3x3_i8_c8s_cn.obj \
./IMG_conv_5x5_i16s_c16s.obj \
./IMG_conv_5x5_i8_c8s_cn.obj \
./IMG_conv_7x7_i16s_c16s.obj \
./IMG_conv_7x7_i8_c8s_cn.obj \
./IMG_conv_9x9_i8_c8s_cn.obj \
./IMG_math.obj \
./deep_learning.obj \
./main.obj 

GEN_SRCS += \
./configPkg/compiler.opt \
./configPkg/linker.cmd 

C_DEPS += \
./DSPF_sp_dotprod.pp \
./DSPF_sp_maxval.pp \
./DSP_add32.pp \
./DSP_maxval.pp \
./IMG_conv_3x3_i16s_c16s.pp \
./IMG_conv_3x3_i8_c8s_cn.pp \
./IMG_conv_5x5_i16s_c16s.pp \
./IMG_conv_5x5_i8_c8s_cn.pp \
./IMG_conv_7x7_i16s_c16s.pp \
./IMG_conv_7x7_i8_c8s_cn.pp \
./IMG_conv_9x9_i8_c8s_cn.pp \
./IMG_math.pp \
./deep_learning.pp \
./main.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_SRCS__QUOTED += \
"configPkg/compiler.opt" \
"configPkg/linker.cmd" 

GEN_MISC_DIRS__QUOTED += \
"configPkg/" 

C_DEPS__QUOTED += \
"DSPF_sp_dotprod.pp" \
"DSPF_sp_maxval.pp" \
"DSP_add32.pp" \
"DSP_maxval.pp" \
"IMG_conv_3x3_i16s_c16s.pp" \
"IMG_conv_3x3_i8_c8s_cn.pp" \
"IMG_conv_5x5_i16s_c16s.pp" \
"IMG_conv_5x5_i8_c8s_cn.pp" \
"IMG_conv_7x7_i16s_c16s.pp" \
"IMG_conv_7x7_i8_c8s_cn.pp" \
"IMG_conv_9x9_i8_c8s_cn.pp" \
"IMG_math.pp" \
"deep_learning.pp" \
"main.pp" 

OBJS__QUOTED += \
"DSPF_sp_dotprod.obj" \
"DSPF_sp_maxval.obj" \
"DSP_add32.obj" \
"DSP_maxval.obj" \
"IMG_conv_3x3_i16s_c16s.obj" \
"IMG_conv_3x3_i8_c8s_cn.obj" \
"IMG_conv_5x5_i16s_c16s.obj" \
"IMG_conv_5x5_i8_c8s_cn.obj" \
"IMG_conv_7x7_i16s_c16s.obj" \
"IMG_conv_7x7_i8_c8s_cn.obj" \
"IMG_conv_9x9_i8_c8s_cn.obj" \
"IMG_math.obj" \
"deep_learning.obj" \
"main.obj" 

C_SRCS__QUOTED += \
"../DSPF_sp_dotprod.c" \
"../DSPF_sp_maxval.c" \
"../DSP_add32.c" \
"../DSP_maxval.c" \
"../IMG_conv_3x3_i16s_c16s.c" \
"../IMG_conv_3x3_i8_c8s_cn.c" \
"../IMG_conv_5x5_i16s_c16s.c" \
"../IMG_conv_5x5_i8_c8s_cn.c" \
"../IMG_conv_7x7_i16s_c16s.c" \
"../IMG_conv_7x7_i8_c8s_cn.c" \
"../IMG_conv_9x9_i8_c8s_cn.c" \
"../IMG_math.c" \
"../deep_learning.c" \
"../main.c" 

CFG_SRCS__QUOTED += \
"../app.cfg" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 


