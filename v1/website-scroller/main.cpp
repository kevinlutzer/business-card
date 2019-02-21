/*
 * business_card.cpp
 *
 * Created: 2016-03-03 12:21:39 AM
 * Author : Kevin Lutzer
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../business-card-api/charlie_plexing.hpp"

#define F_CPU 1000000UL

#define LINE_A PB1
#define LINE_B PB2
#define LINE_C PB0
#define LINE_D PB4
#define LINE_E PB3

uint8_t image[4];
CharliePlex mux;

uint64_t message1[] = {

	0b1010101010100010101110101010111010001010010011101110111000111011,
	0b1010101010100011001110101010101010001010111001001110100000100010,
	0b1110111011100011001000101010101010001010010010001000100000100010,
	0b1010101010101010101110010010101011101110010011101110100010111011,

},
// overlapping image
message2[] = {

	0b1101110000000000000000000000000000000000000000000000000000000000,
	0b0001010000000000000000000000000000000000000000000000000000000000,
	0b0001010000000000000000000000000000000000000000000000000000000000,
	0b1101111000000000000000000000000000000000000000000000000000000000,

};

int main(void)
{
	while(1)
    {
		for( int j = 63; j >= -6; j -- )
		{
			if( j < 0 )
			{
				mux.shiftMessage( message2, image, j + 58 );
				mux.ledOff();
			}
			else
			{
				mux.shiftMessage( message1, image, j );
				mux.ledOff();
			}
			for( uint8_t i = 0; i < 250; i ++  )
			{
				mux.displayFrame(image);
				mux.ledOff();
			}
		}
		mux.ledOff();
	}
}
