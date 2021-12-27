################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sequence.cpp \
../Studi.cpp \
../ooptool.cpp \
../seqstud_main.cpp 

OBJS += \
./Sequence.o \
./Studi.o \
./ooptool.o \
./seqstud_main.o 

CPP_DEPS += \
./Sequence.d \
./Studi.d \
./ooptool.d \
./seqstud_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


