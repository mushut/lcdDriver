/* Program for testing LCD driver
 * Aki Sipovaara 2018
 */

#define F_CPU 16000000UL
#include <util/delay.h>
#include "lcdDriver.h"

int main(void)
{
	init();

	printChar('a');
	_delay_ms(1000);
	clearScreen();

	printStr("abcdefghijkl");
	_delay_ms(1000);
	clearScreen();

	int cursor = 0;
	while (1) {
		printChar('a'+cursor);
		cursor++;
		if (cursor >= 32) {
			cursor = 0;
		}

		_delay_ms(1000);
	}
}
