################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lcd.c \
../adc.c \
../dc_motor.c \
../gpio.c \
../lm35.c \
../main.c \
../timer0.c 

OBJS += \
./Lcd.o \
./adc.o \
./dc_motor.o \
./gpio.o \
./lm35.o \
./main.o \
./timer0.o 

C_DEPS += \
./Lcd.d \
./adc.d \
./dc_motor.d \
./gpio.d \
./lm35.d \
./main.d \
./timer0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


