CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 -Wall
# the -Map arg builds us a file with the memory map 
LDFLAGS= -nostdlib -T stm32_linker.ld -Wl,-Map=run.map



# general commands:
# $@: target which is the first arg in the recepie
# $^: is the input 

all: main.o stm32_startup.o run.elf

main.o:main.c # this is a recepie
	$(CC) $(CFLAGS) $^  -o $@

stm32_startup.o: stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

run.elf: main.o stm32_startup.o   # do not use wildcards here, does not work
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rfv *.o *.elf *.map

load:
	openocd -f stm32f4_config.cfg
	# openocd -f board/stm32f4discovery.cfg