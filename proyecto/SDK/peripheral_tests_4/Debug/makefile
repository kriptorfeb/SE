################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
peripheral_tests_4.elf.size \

ELFCHECK += \
peripheral_tests_4.elf.elfcheck \


# All Target
all: peripheral_tests_4.elf secondary-outputs

# Tool invocations
peripheral_tests_4.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,--no-relax -Wl,-T -Wl,../src/lscript.ld -L../../peripheral_tests_bsp_4/microblaze_0/lib -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -o"peripheral_tests_4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

peripheral_tests_4.elf.size: peripheral_tests_4.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size peripheral_tests_4.elf  |tee "peripheral_tests_4.elf.size"
	@echo Finished building: $@
	@echo ' '

peripheral_tests_4.elf.elfcheck: peripheral_tests_4.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck peripheral_tests_4.elf -hw ../../practica2_hw_platform/system.xml -pe microblaze_0  |tee "peripheral_tests_4.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) peripheral_tests_4.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
