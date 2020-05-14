/*
	Author: Kevin Lutzer
	Created Date: February 3 2020

	Description: Class for controlling a 7x8 led matrix using charlieplexing.
*/
#include "charlie_plexing.hpp"

/*
	Set an individual led

	Inputs:
		number - the linear index of the led that will be turned on.
*/
void CharliePlex::setLed(uint8_t row, uint8_t column)
{
	PORTA = ncharlieOut[row][column];
	DDRA = ncharlieDir[row][column];
}

/*
	Turn on all LEDs within the matrix. Call this function within a loop to turn all LEDs constantly
*/
void CharliePlex::allLedOn()
{
	for( uint8_t i = 0; i < 7; i ++ ) {
		for( uint8_t j = 0; j < 8; j ++ ) {
			setLed( i, j );
		}
	}
}

/*
	Turn off all LEDs within the matrix.
*/
void CharliePlex::ledOff()
{
	DDRB = 0;
	PORTB = 0;
}

/*
	Scroll through all the LEDs linearly.

	Inputs:
		dir - the boolean direction to determine if the scrolling starts from top to bottom or bottom to top
*/
void CharliePlex::scrollLed(bool dir)
{
	if (dir) {
		for( uint8_t i = 0; i < 7; i ++ ) {
			for( uint8_t j = 0; j < 8; j ++ ) {
				setLed( i, j );
				_delay_ms( 50 );
			}
		}	
	}
}

/*
	Displays an image on a row

	Inputs:
		image - a 4 element array containing binary values
		row - the row that image should be displayed in the matrix
*/
void CharliePlex::displayRow( uint8_t image[], uint8_t row )
{
	for( uint8_t i = 0; i < 8; i ++ )
	{
		if( image[i] ) {
			setLed(row, i);
		}
	}
}

/*
	Displays one frame of a message

	Inputs:
		image - a 4 element array each with an 8 bit number in it that specifies a greyscale value
*/
void CharliePlex::displayFrame( uint8_t image[][8] )
{
	for( int row = 0; row < 7; row ++ ) {
		displayRow( image[row], row );
	}
}

