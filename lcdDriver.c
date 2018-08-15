/* LCD driver for Arduino Uno
 * Aki Sipovaara 2018
 */

#include "lcdDriver.h"

int init(void)
{
}

int clearScreen(void)
{
}

int cursor(int placement)
{
}

int printChar(char character)
{
}

int printStr(char *string)
{
	/* Use printChar for printing the string
	 * What if string is longer than what can be printed?
	 */
	clearScreen();
	cursor(0);

	size_t i = 0;
	size_t length = strlen(string);
	for (; i < length; i++) {
		cursor(i)
		printChar(*(string + i));
	}

	return 0;
}
