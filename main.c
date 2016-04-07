/*
 * bluetooth_test.c
 *
 * Created: 2016-04-07 08:58:09
 * Author : Fredrik
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
#define BAUDE 9600		// Bauderate
#define FOSC 1000000	// Intern klockfrekenvs

void init_bluetooth()
{
	
	// Slave mode, XCK �r in
	//DDRB = 0b00000000;
	
	DDRD = 0b00010010; // Utg�ng p� TXD
	
	// Synkron �verf�ring
	UCSRC |= (1<<URSEL);
	UCSRC = (1<<UMSEL);
	//UCSRC |= (1<<UCPOL);
	
	
	
	//Inst�llningar f�r  BAUDRATE
	unsigned int ubrr = 0;
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	
	// M�jligg�r s�ndning, mottagning
	UCSRB = (1<<RXEN)|(1<<TXEN);
	PORTD |= (UMSEL<<PORTD4); // Titta p� UMSEL p� pin18
	// Dubbel �verf�ringshastighet
	// UCSRA |= (1<<U2X);
	
	
	
	
	
	
	// Data format: 8data, 1stop bit ligger som standard
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRC &= ~(1<<USBS);
}

void bluetooth_transmit( unsigned int data )
{
	// V�nta p� tom s�ndbuffert
	while ( !( UCSRA & (1<<UDRE)) )
	{
	}
	// L�gg data i buffer, skickar data
	UDR = data;
}

int main(void)
{
    init_bluetooth();
    while (1) 
    {
		bluetooth_transmit(0b01001100);
		_delay_ms(500);
    }
}

