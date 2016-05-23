/*
	Author: Kevin Lutzer
	Created Date: February 3 2016
	
	Description: Class for controlling a 4X5 led matrix using charlieplexing.
*/

#include <avr/io.h>
#include <util/delay.h>

#define LINEA PB1 
#define LINEB PB2 
#define LINEC PB0
#define LINED PB4
#define LINEE PB3 

#define SCROLL_DELAY 100

const uint8_t charlieDir[] = 
{
	( ( 1 << LINEA ) | ( 1 << LINEE ) ), // LED1
	( ( 1 << LINEB ) | ( 1 << LINEE ) ), // LED2
	( ( 1 << LINEC ) | ( 1 << LINEE ) ), // LED3
	( ( 1 << LINED ) | ( 1 << LINEE ) ), // LED4
	( ( 1 << LINEE ) | ( 1 << LINED ) ), // LED5
	( ( 1 << LINEA ) | ( 1 << LINED ) ), // LED6
	( ( 1 << LINEB ) | ( 1 << LINED ) ), // LED7
	( ( 1 << LINEC ) | ( 1 << LINED ) ), // LED8
	( ( 1 << LINED ) | ( 1 << LINEC ) ), // LED9
	( ( 1 << LINEE ) | ( 1 << LINEC ) ), // LED10
	( ( 1 << LINEA ) | ( 1 << LINEC ) ), // LED11
	( ( 1 << LINEB ) | ( 1 << LINEC ) ), // LED12
	( ( 1 << LINEC ) | ( 1 << LINEB ) ), // LED13
	( ( 1 << LINED ) | ( 1 << LINEB ) ), // LED14
	( ( 1 << LINEE ) | ( 1 << LINEB ) ), // LED15
	( ( 1 << LINEA ) | ( 1 << LINEB ) ), // LED16
	( ( 1 << LINEB ) | ( 1 << LINEA ) ), // LED17
	( ( 1 << LINEC ) | ( 1 << LINEA ) ), // LED18
	( ( 1 << LINED ) | ( 1 << LINEA ) ), // LED19
	( ( 1 << LINEE ) | ( 1 << LINEA ) ), // LED20
},

charlieOutput[] = {
	( 1 << LINEA ), // LED1
	( 1 << LINEB ), // LED2
	( 1 << LINEC ), // LED3
	( 1 << LINED ), // LED4
	( 1 << LINEE ), // LED5
	( 1 << LINEA ), // LED6
	( 1 << LINEB ), // LED7
	( 1 << LINEC ), // LED8
	( 1 << LINED ), // LED9
	( 1 << LINEE ), // LED10
	( 1 << LINEA ), // LED11
	( 1 << LINEB ), // LED12
	( 1 << LINEC ), // LED13
	( 1 << LINED ), // LED14
	( 1 << LINEE ), // LED15
	( 1 << LINEA ), // LED16
	( 1 << LINEB ), // LED17
	( 1 << LINEC ), // LED18
	( 1 << LINED ), // LED19
	( 1 << LINEE ), // LED20
};  

class charliePlex{

	public: 
		void setLed(uint8_t number);
		void allLedOn();
		void ledOff();
		void scrollLed( bool dir );
		void displayFrame( uint8_t image[] );		
		void displayRow( uint8_t image[], uint8_t row );
		void shiftMessage(uint64_t message[], uint8_t frame[], uint8_t pos);
	
};