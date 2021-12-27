################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp \
../ohmg.cpp \
../ooptool.cpp \
../ooptoolg.cpp \
../resistor.cpp 

OBJS += \
./main.o \
./ohmg.o \
./ooptool.o \
./ooptoolg.o \
./resistor.o 

CPP_DEPS += \
./main.d \
./ohmg.d \
./ooptool.d \
./ooptoolg.d \
./resistor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


