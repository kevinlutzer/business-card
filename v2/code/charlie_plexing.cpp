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
void CharliePlex::setLed(uint8_t number)
{
	PORTA = charlieOut[number];
	DDRA = charlieDir[number];
}

/*
	Turn on all LEDs within the matrix. Call this function within a loop to turn all LEDs constantly
*/
void CharliePlex::allLedOn()
{
	for( uint8_t i = 0; i < sizeof(charlieDir); i ++ ) {
		setLed( i );
	}
}

/*
	Turn off all LEDs within the matrix.
*/
void CharliePlex::ledOff()
{
	DDRA = 0;
	PORTA = 0;
}

/*
	Scroll through all the LEDs linearly.

	Inputs:
		dir - the boolean direction to determine if the scrolling starts from top to bottom or bottom to top
*/
void CharliePlex::scrollLed( bool dir )
{
	for( uint8_t i = 0; i < sizeof(charlieDir); i ++ ) {
		setLed( i );
		_delay_ms( 100 );
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
		if( image[row] << i & 0b10000000 )
		{
			setLed( i + row * 8 );
		}
	}
}

// /*
// 	Displays one frame of a message

// 	Inputs:
// 		image - a 4 element array each with an 8 bit number in it that specifies a greyscale value
// */
// void CharliePlex::displayFrame( uint8_t image[] )
// {
// 	for( int row = 0; row < 7; row ++ )
// 	{
// 		displayRow( image, row );
// 	}
// }

/*
	function shifts a message over by position and then saves a frame into frame

	Inputs:
		message -  The overall message that is to be displayed on the matrix
		frame - The resultant array containing 7 8-bit numbers
*/
void CharliePlex::shiftMessage( uint64_t message[], uint8_t frame[], uint8_t pos )
{
	for( uint8_t i = 0; i < 7; i ++ )
	{
		 frame[i] = message[i] >> pos;
	}
}
