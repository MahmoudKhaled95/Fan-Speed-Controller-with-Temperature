################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../dcmotor.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../mini_project3.c \
../pwm.c 

OBJS += \
./adc.o \
./dcmotor.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./mini_project3.o \
./pwm.o 

C_DEPS += \
./adc.d \
./dcmotor.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./mini_project3.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


