/*
 * business_card.cpp
 *
 * Created: 2016-03-03 12:21:39 AM
 * Author : Kevin Lutzer
 */

#include <avr/io.h>
#include <util/delay.h>
#include "charlie_plexing.hpp"

CharliePlex charlieplex;

int main(void)
{
	while(1)
    {
			charlieplex.allLedOn();
		}
}
