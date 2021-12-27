################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Board.cpp \
../main.cpp \
../ooptool.cpp \
../ooptoolg.cpp 

OBJS += \
./Board.o \
./main.o \
./ooptool.o \
./ooptoolg.o 

CPP_DEPS += \
./Board.d \
./main.d \
./ooptool.d \
./ooptoolg.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


