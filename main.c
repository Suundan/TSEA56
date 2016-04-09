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
	DDRD = 0b00000010; // Utgång på TXD
	
	//Inställningar för  BAUDRATE
	unsigned int ubrr = 0;
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	
	// Möjliggör sändning, mottagning
	UCSRB = (1<<RXEN)|(1<<TXEN);

	// Data format: 8data, 1stop bit ligger som standard
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRC &= ~(1<<USBS);
}

void bluetooth_transmit( unsigned int data )
{
	// Vänta på tom sändbuffert
	while ( !( UCSRA & (1<<UDRE)) )
	{
	}
	// Lägg data i buffer, skickar data
	UDR = data;
}

unsigned int bluetooth_recieve()
{
	while ( !(UCSRA & (1<<RXC)) )
	{
	}
	return UDR;
}

int main(void)
{
    init_bluetooth();
	unsigned int recieved_data = 0;
    while (1) 
    {
		recieved_data = bluetooth_recieve();	// Vänta på att ta emot data
		bluetooth_transmit(recieved_data);		// Återsänd mottagen data
    }
}

