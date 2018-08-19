/* LCD driver for Arduino Uno
 * Aki Sipovaara 2018
 */

#include "lcdDriver.h"

int init(void)
{
	/* Initialize used GPIOs as outputs */
	DDRD |= _BV(DDD0);
	DDRD |= _BV(DDD1);
	DDRD |= _BV(DDD2);
	DDRD |= _BV(DDD3);
	DDRD |= _BV(DDD4);
	DDRD |= _BV(DDD5);
	DDRD |= _BV(DDD6);
	DDRD |= _BV(DDD7);
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

	/* Use gpioState struct to change pin states accordingly.
	 * If pin needs to be high -> use |=
	 * If pin needs to be low -> use &= and ~
	 */
	if (gpioState.data0 == 0) {
		PORTD &= ~_BV(PORTD0);
	}
	else {
		PORTD |= _BV(PORTD0);
	}

	if (gpioState.data1 == 0) {
		PORTD &= ~_BV(PORTD1);
	}
	else {
		PORTD |= _BV(PORTD1);
	}

	if (gpioState.data2 == 0) {
		PORTD &= ~_BV(PORTD2);
	}
	else {
		PORTD |= _BV(PORTD2);
	}

	if (gpioState.data3 == 0) {
		PORTD &= ~_BV(PORTD3);
	}
	else {
		PORTD |= _BV(PORTD3);
	}

	if (gpioState.data4 == 0) {
		PORTD &= ~_BV(PORTD4);
	}
	else {
		PORTD |= _BV(PORTD4);
	}

	if (gpioState.data5 == 0) {
		PORTD &= ~_BV(PORTD5);
	}
	else {
		PORTD |= _BV(PORTD5);
	}

	if (gpioState.data6 == 0) {
		PORTD &= ~_BV(PORTD6);
	}
	else {
		PORTD |= _BV(PORTD6);
	}

	if (gpioState.data7 == 0) {
		PORTD &= ~_BV(PORTD7);
	}
	else {
		PORTD |= _BV(PORTD7);
	}

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
