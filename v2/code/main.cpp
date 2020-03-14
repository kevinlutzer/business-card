/*
 * business_card.cpp
 *
 * Created: 2020-03-01
 * Author : Kevin Lutzer
 */

#include <avr/io.h>
#include <util/delay.h>
#include "charlie_plexing.hpp"

#define F_CPU 1000000UL

CharliePlex mux;

uint8_t hi_msg[][8] = {
	{1, 0, 0, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 1, 0},
	{1, 0, 0, 0, 1, 0, 1, 0},
	{1, 1, 1, 1, 1, 0, 1, 0},
	{1, 0, 0, 0, 1, 0, 1, 0},
	{1, 0, 0, 0, 1, 0, 1, 0},
	{1, 0, 0, 0, 1, 1, 1, 1}
};


uint8_t full_frame_display[][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int main(void)
{
	while(1)
    {
		mux.scrollLed(true);
		for( uint8_t i = 0; i < 250; i ++  ) {
			mux.displayFrame(hi_msg);
		}
		mux.ledOff();
		mux.scrollLed(false);
	}
}