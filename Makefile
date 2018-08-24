OBJS = main.c lcdDriver.c
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p -o
CC = avr-gcc
# DIR must be given from command line

all: lcdTest

lcdTest:
	$(DIR)$(CC) $(CFLAGS) test.exe $(OBJS) 

clean:
	rm test.exe
