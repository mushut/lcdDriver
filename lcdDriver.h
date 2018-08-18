/* LCD driver for Arduino Uno
 * Aki Sipovaara 2018
 */

#include <string.h>
#include <stdio.h>
#include <avr/io.h>

struct Pins {
	int data0:1;
	int data1:1;
	int data2:1;
	int data3:1;
	int data4:1;
	int data5:1;
	int data6:1;
	int data7:1;
};

/* Initialization function */
int init(void);

/* Clears the LCD screen */
int clearScreen(void);

/* Function for controlling the cursor */
int cursor(int placement);

/* Function for printing character */
int printChar(char character);

/* Function for printing strings */
int printStr(char *string);
