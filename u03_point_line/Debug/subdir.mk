################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Line.cpp \
../Point.cpp \
../main_point_line.cpp \
../ooptool.cpp \
../ooptoolg.cpp 

OBJS += \
./Line.o \
./Point.o \
./main_point_line.o \
./ooptool.o \
./ooptoolg.o 

CPP_DEPS += \
./Line.d \
./Point.d \
./main_point_line.d \
./ooptool.d \
./ooptoolg.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


