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
	/* Remember to check that character is valid for printing! */

	struct Pins gpioState;

	gpioState.data0 = ((character & 1) != 0);
	gpioState.data1 = ((character & 2) != 0);
	gpioState.data2 = ((character & 4) != 0);
	gpioState.data3 = ((character & 8) != 0);
	gpioState.data4 = ((character & 16) != 0);
	gpioState.data5 = ((character & 32) != 0);
	gpioState.data6 = ((character & 64) != 0);
	gpioState.data7 = ((character & 128) != 0);

	/* Use gpioState struct to change pin states accordingly */

	return 0;
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
