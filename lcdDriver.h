/* LCD driver for Arduino Uno
 * Aki Sipovaara 2018
 */

#include <string.h>
#include <avr.io.h>

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
