/*
	Author: Kevin Lutzer
	Created Date: February 3 2016

	Description: Class for controlling a 4X5 led matrix using charlieplexing.
*/

#include <avr/io.h>
#include <util/delay.h>

#define LINEA PA0
#define LINEB PA1
#define LINEC PA2
#define LINED PA3
#define LINEE PA4
#define LINEF PA5
#define LINEG PA6
#define LINEH PA7

#define F_CPU 1000000UL
#define SCROLL_DELAY 100

// mapping for led to pin connections for the data direction
const uint8_t charlieDir[] =
{
	// ( ( 1 << LINEA ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINEC ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINED ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINEE ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINEF ) | ( 1 << LINEH ) ), 
	// ( ( 1 << LINEG ) | ( 1 << LINEH ) ), 
	// ( ( 1 << LINEH ) | ( 1 << LINEG ) ), 

	
	// ( ( 1 << LINEA ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINEC ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINED ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINEE ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINEF ) | ( 1 << LINEG ) ),
	// ( ( 1 << LINEG ) | ( 1 << LINEH ) ),
	// ( ( 1 << LINEH ) | ( 1 << LINEA ) ),

	// ( ( 1 << LINEA ) | ( 1 << LINEF ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINEF ) ),
	// ( ( 1 << LINEC ) | ( 1 << LINEF ) ),
	// ( ( 1 << LINED ) | ( 1 << LINEF ) ),
	// ( ( 1 << LINEE ) | ( 1 << LINEF ) ),
	// ( ( 1 << LINEG ) | ( 1 << LINEF ) ), 
	// ( ( 1 << LINEH ) | ( 1 << LINEF ) ), 

	// ( ( 1 << LINEA ) | ( 1 << LINEE ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINEE ) ),
	// ( ( 1 << LINEC ) | ( 1 << LINEE ) ),
	// ( ( 1 << LINED ) | ( 1 << LINEE ) ),
	// ( ( 1 << LINEF ) | ( 1 << LINEE ) ),
	// ( ( 1 << LINEG ) | ( 1 << LINEE ) ), 
	// ( ( 1 << LINEH ) | ( 1 << LINEE ) ), 

	// ( ( 1 << LINEA ) | ( 1 << LINED ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINED ) ),
	// ( ( 1 << LINEC ) | ( 1 << LINED ) ),
	// ( ( 1 << LINEE ) | ( 1 << LINED ) ),
	// ( ( 1 << LINEF ) | ( 1 << LINED ) ),
	// ( ( 1 << LINEG ) | ( 1 << LINED ) ), 
	// ( ( 1 << LINEH ) | ( 1 << LINED ) ),

	// ( ( 1 << LINEA ) | ( 1 << LINEC ) ),
	// ( ( 1 << LINEB ) | ( 1 << LINEC ) ),
	// ( ( 1 << LINED ) | ( 1 << LINEC ) ),
	// ( ( 1 << LINEE ) | ( 1 << LINEC ) ),
	// ( ( 1 << LINEF ) | ( 1 << LINEC ) ),
	// ( ( 1 << LINEG ) | ( 1 << LINEC ) ), 
	// ( ( 1 << LINEH ) | ( 1 << LINEC ) ), 

	( ( 1 << LINEA ) | ( 1 << LINEB ) ),
	( ( 1 << LINEC ) | ( 1 << LINEB ) ),
	( ( 1 << LINED ) | ( 1 << LINEB ) ),
	( ( 1 << LINEE ) | ( 1 << LINEB ) ),
	( ( 1 << LINEF ) | ( 1 << LINEB ) ),
	( ( 1 << LINEG ) | ( 1 << LINEB ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEB ) ), 

	( ( 1 << LINEB ) | ( 1 << LINEA ) ),
	( ( 1 << LINEC ) | ( 1 << LINEA ) ),
	( ( 1 << LINED ) | ( 1 << LINEA ) ),
	( ( 1 << LINEE ) | ( 1 << LINEA ) ),
	( ( 1 << LINEF ) | ( 1 << LINEA ) ),
	( ( 1 << LINEG ) | ( 1 << LINEA ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEA ) ),  
};

// // mapping for led to pin connections for the data direction
const uint8_t charlieOutput[] =
{
	// ( ( 1 << LINEA ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINEC ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINED ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINEE ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINEF ) | ( 0 << LINEH ) ), 
	// ( ( 1 << LINEG ) | ( 0 << LINEH ) ), 
	// ( ( 1 << LINEH ) | ( 0 << LINEG ) ), 

	
	// ( ( 1 << LINEA ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINEC ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINED ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINEE ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINEF ) | ( 0 << LINEG ) ),
	// ( ( 1 << LINEG ) | ( 0 << LINEH ) ),
	// ( ( 1 << LINEH ) | ( 0 << LINEA ) ),

	// ( ( 1 << LINEA ) | ( 0 << LINEF ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINEF ) ),
	// ( ( 1 << LINEC ) | ( 0 << LINEF ) ),
	// ( ( 1 << LINED ) | ( 0 << LINEF ) ),
	// ( ( 1 << LINEE ) | ( 0 << LINEF ) ),
	// ( ( 1 << LINEG ) | ( 0 << LINEF ) ), 
	// ( ( 1 << LINEH ) | ( 0 << LINEF ) ), 

	// ( ( 1 << LINEA ) | ( 0 << LINEE ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINEE ) ),
	// ( ( 1 << LINEC ) | ( 0 << LINEE ) ),
	// ( ( 1 << LINED ) | ( 0 << LINEE ) ),
	// ( ( 1 << LINEF ) | ( 0 << LINEE ) ),
	// ( ( 1 << LINEG ) | ( 0 << LINEE ) ), 
	// ( ( 1 << LINEH ) | ( 0 << LINEE ) ), 

	// ( ( 1 << LINEA ) | ( 0 << LINED ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINED ) ),
	// ( ( 1 << LINEC ) | ( 0 << LINED ) ),
	// ( ( 1 << LINEE ) | ( 0 << LINED ) ),
	// ( ( 1 << LINEF ) | ( 0 << LINED ) ),
	// ( ( 1 << LINEG ) | ( 0 << LINED ) ), 
	// ( ( 1 << LINEH ) | ( 0 << LINED ) ),

	// ( ( 1 << LINEA ) | ( 0 << LINEC ) ),
	// ( ( 1 << LINEB ) | ( 0 << LINEC ) ),
	// ( ( 1 << LINED ) | ( 0 << LINEC ) ),
	// ( ( 1 << LINEE ) | ( 0 << LINEC ) ),
	// ( ( 1 << LINEF ) | ( 0 << LINEC ) ),
	// ( ( 1 << LINEG ) | ( 0 << LINEC ) ), 
	// ( ( 1 << LINEH ) | ( 0 << LINEC ) ), 

	( ( 1 << LINEA ) | ( 0 << LINEB ) ),
	( ( 1 << LINEC ) | ( 0 << LINEB ) ),
	( ( 1 << LINED ) | ( 0 << LINEB ) ),
	( ( 1 << LINEE ) | ( 0 << LINEB ) ),
	( ( 1 << LINEF ) | ( 0 << LINEB ) ),
	( ( 1 << LINEG ) | ( 0 << LINEB ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEB ) ), 

	( ( 1 << LINEB ) | ( 0 << LINEA ) ),
	( ( 1 << LINEC ) | ( 0 << LINEA ) ),
	( ( 1 << LINED ) | ( 0 << LINEA ) ),
	( ( 1 << LINEE ) | ( 0 << LINEA ) ),
	( ( 1 << LINEF ) | ( 0 << LINEA ) ),
	( ( 1 << LINEG ) | ( 0 << LINEA ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEA ) ), 
};

const uint8_t ncharlieOut[7][8] = {

	// Row 0
	( ( 1 << LINEA ) | ( 0 << LINEH ) ),
	( ( 1 << LINEB ) | ( 0 << LINEH ) ),
	( ( 1 << LINEC ) | ( 0 << LINEH ) ),
	( ( 1 << LINED ) | ( 0 << LINEH ) ),
	( ( 1 << LINEE ) | ( 0 << LINEH ) ),
	( ( 1 << LINEF ) | ( 0 << LINEH ) ), 
	( ( 1 << LINEG ) | ( 0 << LINEH ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEG ) ),

	// Row 1
	( ( 1 << LINEA ) | ( 0 << LINEG ) ),
	( ( 1 << LINEB ) | ( 0 << LINEG ) ),
	( ( 1 << LINEC ) | ( 0 << LINEG ) ),
	( ( 1 << LINED ) | ( 0 << LINEG ) ),
	( ( 1 << LINEE ) | ( 0 << LINEG ) ),
	( ( 1 << LINEF ) | ( 0 << LINEG ) ),
	( ( 1 << LINEG ) | ( 0 << LINEF ) ),
	( ( 1 << LINEH ) | ( 0 << LINEF ) ),

	// Row 2
	( ( 1 << LINEA ) | ( 0 << LINEF ) ),
	( ( 1 << LINEB ) | ( 0 << LINEF ) ),
	( ( 1 << LINEC ) | ( 0 << LINEF ) ),
	( ( 1 << LINED ) | ( 0 << LINEF ) ),
	( ( 1 << LINEE ) | ( 0 << LINEF ) ),
	( ( 1 << LINEF ) | ( 0 << LINEE ) ), 
	( ( 1 << LINEG ) | ( 0 << LINEE ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEE ) ), 

	// Row 3
	( ( 1 << LINEA ) | ( 0 << LINEE ) ),
	( ( 1 << LINEB ) | ( 0 << LINEE ) ),
	( ( 1 << LINEC ) | ( 0 << LINEE ) ),
	( ( 1 << LINED ) | ( 0 << LINEE ) ),
	( ( 1 << LINEE ) | ( 0 << LINED ) ),
	( ( 1 << LINEF ) | ( 0 << LINED ) ), 
	( ( 1 << LINEG ) | ( 0 << LINED ) ), 
	( ( 1 << LINEH ) | ( 0 << LINED ) ), 

	// Row 4
	( ( 1 << LINEA ) | ( 0 << LINED ) ),
	( ( 1 << LINEB ) | ( 0 << LINED ) ),
	( ( 1 << LINEC ) | ( 0 << LINED ) ),
	( ( 1 << LINED ) | ( 0 << LINEC ) ),
	( ( 1 << LINEF ) | ( 0 << LINEC ) ),
	( ( 1 << LINEG ) | ( 0 << LINEC ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEC ) ),
	( ( 1 << LINEH ) | ( 0 << LINEC ) ),

	// Row 5
	( ( 1 << LINEA ) | ( 0 << LINEC ) ),
	( ( 1 << LINEB ) | ( 0 << LINEC ) ),
	( ( 1 << LINEC ) | ( 0 << LINEB ) ), 
	( ( 1 << LINED ) | ( 0 << LINEB ) ),
	( ( 1 << LINEE ) | ( 0 << LINEB ) ),
	( ( 1 << LINEF ) | ( 0 << LINEB ) ),
	( ( 1 << LINEG ) | ( 0 << LINEB ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEB ) ), 

	// Row 6	
	( ( 1 << LINEA ) | ( 0 << LINEB ) ),
	( ( 1 << LINEB ) | ( 0 << LINEA ) ),
	( ( 1 << LINEC ) | ( 0 << LINEA ) ),
	( ( 1 << LINED ) | ( 0 << LINEA ) ),
	( ( 1 << LINEE ) | ( 0 << LINEA ) ),
	( ( 1 << LINEF ) | ( 0 << LINEA ) ),
	( ( 1 << LINEG ) | ( 0 << LINEA ) ), 
	( ( 1 << LINEH ) | ( 0 << LINEA ) ),
};

const uint8_t ncharlieDir[7][8] = {

	// Row 0
	( ( 1 << LINEA ) | ( 1 << LINEH ) ),
	( ( 1 << LINEB ) | ( 1 << LINEH ) ),
	( ( 1 << LINEC ) | ( 1 << LINEH ) ),
	( ( 1 << LINED ) | ( 1 << LINEH ) ),
	( ( 1 << LINEE ) | ( 1 << LINEH ) ),
	( ( 1 << LINEF ) | ( 1 << LINEH ) ), 
	( ( 1 << LINEG ) | ( 1 << LINEH ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEG ) ), 

	// Row 1
	( ( 1 << LINEA ) | ( 1 << LINEG ) ),
	( ( 1 << LINEB ) | ( 1 << LINEG ) ),
	( ( 1 << LINEC ) | ( 1 << LINEG ) ),
	( ( 1 << LINED ) | ( 1 << LINEG ) ),
	( ( 1 << LINEE ) | ( 1 << LINEG ) ),
	( ( 1 << LINEF ) | ( 1 << LINEG ) ),
	( ( 1 << LINEG ) | ( 1 << LINEF ) ),
	( ( 1 << LINEH ) | ( 1 << LINEF ) ),

	// Row 2
	( ( 1 << LINEA ) | ( 1 << LINEF ) ),
	( ( 1 << LINEB ) | ( 1 << LINEF ) ),
	( ( 1 << LINEC ) | ( 1 << LINEF ) ),
	( ( 1 << LINED ) | ( 1 << LINEF ) ),
	( ( 1 << LINEE ) | ( 1 << LINEF ) ),
	( ( 1 << LINEF ) | ( 1 << LINEE ) ), 
	( ( 1 << LINEG ) | ( 1 << LINEE ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEE ) ), 

	// Row 3
	( ( 1 << LINEA ) | ( 1 << LINEE ) ),
	( ( 1 << LINEB ) | ( 1 << LINEE ) ),
	( ( 1 << LINEC ) | ( 1 << LINEE ) ),
	( ( 1 << LINED ) | ( 1 << LINEE ) ),
	( ( 1 << LINEE ) | ( 1 << LINED ) ),
	( ( 1 << LINEF ) | ( 1 << LINED ) ), 
	( ( 1 << LINEG ) | ( 1 << LINED ) ), 
	( ( 1 << LINEH ) | ( 1 << LINED ) ), 

	// Row 4
	( ( 1 << LINEA ) | ( 1 << LINED ) ),
	( ( 1 << LINEB ) | ( 1 << LINED ) ),
	( ( 1 << LINEC ) | ( 1 << LINED ) ),
	( ( 1 << LINED ) | ( 1 << LINEC ) ),
	( ( 1 << LINEF ) | ( 1 << LINEC ) ),
	( ( 1 << LINEG ) | ( 1 << LINEC ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEC ) ),
	( ( 1 << LINEH ) | ( 1 << LINEC ) ),

	// Row 5
	( ( 1 << LINEA ) | ( 1 << LINEC ) ),
	( ( 1 << LINEB ) | ( 1 << LINEC ) ),
	( ( 1 << LINEC ) | ( 1 << LINEB ) ), 
	( ( 1 << LINED ) | ( 1 << LINEB ) ),
	( ( 1 << LINEE ) | ( 1 << LINEB ) ),
	( ( 1 << LINEF ) | ( 1 << LINEB ) ),
	( ( 1 << LINEG ) | ( 1 << LINEB ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEB ) ), 
	
	// Row 6	
	( ( 1 << LINEA ) | ( 1 << LINEB ) ),
	( ( 1 << LINEB ) | ( 1 << LINEA ) ),
	( ( 1 << LINEC ) | ( 1 << LINEA ) ),
	( ( 1 << LINED ) | ( 1 << LINEA ) ),
	( ( 1 << LINEE ) | ( 1 << LINEA ) ),
	( ( 1 << LINEF ) | ( 1 << LINEA ) ),
	( ( 1 << LINEG ) | ( 1 << LINEA ) ), 
	( ( 1 << LINEH ) | ( 1 << LINEA ) ),

};

class CharliePlex{

	public:
		// basic led operations
		void setLed(uint8_t number);
		void setLedN(uint8_t row, uint8_t column);
		void allLedOn();
		void ledOff();

		// scrolling and fram operations
		void scrollLed( bool dir );
		void displayFrame( uint8_t image[][8] );
		void displayRow( uint8_t image[], uint8_t row );
		void shiftMessage(uint64_t message[], uint8_t frame[], uint8_t pos);
};
