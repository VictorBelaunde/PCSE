################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DHT22/Src/DHT22.c \
../Drivers/DHT22/Src/DHT22_port.c 

OBJS += \
./Drivers/DHT22/Src/DHT22.o \
./Drivers/DHT22/Src/DHT22_port.o 

C_DEPS += \
./Drivers/DHT22/Src/DHT22.d \
./Drivers/DHT22/Src/DHT22_port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DHT22/Src/%.o Drivers/DHT22/Src/%.su: ../Drivers/DHT22/Src/%.c Drivers/DHT22/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-DHT22-2f-Src

clean-Drivers-2f-DHT22-2f-Src:
	-$(RM) ./Drivers/DHT22/Src/DHT22.d ./Drivers/DHT22/Src/DHT22.o ./Drivers/DHT22/Src/DHT22.su ./Drivers/DHT22/Src/DHT22_port.d ./Drivers/DHT22/Src/DHT22_port.o ./Drivers/DHT22/Src/DHT22_port.su

.PHONY: clean-Drivers-2f-DHT22-2f-Src

