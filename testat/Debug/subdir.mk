################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common.cpp \
../mengen.cpp \
../ooptool.cpp 

CPP_DEPS += \
./common.d \
./mengen.d \
./ooptool.d 

OBJS += \
./common.o \
./mengen.o \
./ooptool.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./common.d ./common.o ./mengen.d ./mengen.o ./ooptool.d ./ooptool.o

.PHONY: clean--2e-

