OBJS = main.o lcdDriver.o
CFLAGS = -mmcu=atmega328p
CC = avr-gcc

all: lcdTest

lcdTest: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o 

clean:
	rm lcdTest $(OBJS)
