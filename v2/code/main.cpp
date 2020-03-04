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

uint8_t image[7];

// uint64_t message1[] = {
// 	0b1010101010100010101110101010111010001010010011101110111000111011,
// 	0b1010101010100011001110101010101010001010111001001110100000100010,
// 	0b1110111011100011001000101010101010001010010010001000100000100010,
// 	0b1010101010101010101110010010101011101110010011101110100010111011,
// 	0b1010101010101010101110010010101011101110010011101110100010111011,
// 	0b1010101010101010101110010010101011101110010011101110100010111011,
// };

uint64_t message1[] = {
	0b1010101010101111101010001010111010101011101000101001001110111011,
	0b1010101010100011001110101010101010001010111001001110100000100010,
	0b1110111011100011001000101010101010001010010010001000100000100010,
	0b1010101010101010101110010010101011101110010011101110100010111011,
	0b1010101010101010101110010010101011101110010011101110100010111011,
	0b1010101010101010101110010010101011101110010011101110100010111011,
};

CharliePlex mux;

int main(void)
{
	// while(1)
    // {
	// 	for( int j = 63; j >= -6; j -- )
	// 	{
	// 		mux.shiftMessage( message1, image, j );
	// 		mux.ledOff();
	// 		for( uint8_t i = 0; i < 250; i ++ )
	// 		{
	// 			mux.displayFrame(image);
	// 			mux.ledOff();
	// 		}
	// 	}
	// 	mux.ledOff();
	// }

	while(1) {
		mux.scrollLed(true);
	}
	
}