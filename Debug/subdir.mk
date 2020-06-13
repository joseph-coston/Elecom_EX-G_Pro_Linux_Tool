################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../elecom_ex-g_pro_enhancer.c 

OBJS += \
./elecom_ex-g_pro_enhancer.o 

C_DEPS += \
./elecom_ex-g_pro_enhancer.d 


# Each subdirectory must supply rules for building sources it contributes
elecom_ex-g_pro_enhancer.o: ../elecom_ex-g_pro_enhancer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -lxdo -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"elecom_ex-g_pro_enhancer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


