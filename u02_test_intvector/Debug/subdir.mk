################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IntVector.cpp \
../gtest_main.cpp \
../ooptool.cpp \
../test_intvector1.cpp 

OBJS += \
./IntVector.o \
./gtest_main.o \
./ooptool.o \
./test_intvector1.o 

CPP_DEPS += \
./IntVector.d \
./gtest_main.d \
./ooptool.d \
./test_intvector1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


