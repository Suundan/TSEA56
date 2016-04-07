/*
 * TWI_comm_buss.c
 *
 * Created: 4/5/2016 11:43:18 AM
 *  Author: marha996
 */ 

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1000000UL

uint8_t sensorData[4];

//Avbrottsvektor
ISR(TWI_vect){
	
	// Arbitration lost; general-calladress mottagen, ack mottagen
	if ((TWSR & 0xF8) == 0x78);

	TWCR = (0<<TWIE)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA); //Avaktiverar avbrott, sätter avbrottsflaggan, aktiverar bussen, aktiverar ackflaggan
		
	while(!(TWCR & (1<<TWINT))); //Vänta på sändar-adressen
		
	//Data mottagen, ack mottagen	
	if (!((TWSR & 0xF8) == 0x80 || (TWSR & 0xF8) == 0x90)) {
		while(1){};
	}
			
	TWIRecieveFromSens();

}

//Initierar bussen
void TWIInit(void) {
	
	DDRD = 0x80;
	
	//Globalt avbrott aktiverat
	sei();
	
	//Sätter SCL hastigheten
	TWSR = (0<<TWPS0)|(0<<TWPS1); //Sätter prescaler-värdet till 1
	TWBR = 0x0C;  //Sätter bit rate registry till 12
	
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWIE); //Aktiverar bussen, avktiverar ackflaggan, aktiverar avbrott
	
	//Slavadress (sista ska vara ett för att enabla general call)
	//Kommmudul: 0x11 
	//Sensormodul: 0x21
	//Styrmodul: 0x41
	
	TWAR = 0x11;
}

//Skickar startbit
void TWIStart(void) {
	TWCR = (1<<TWSTA)|(1<<TWINT)|(0<<TWIE)|(1<<TWEN); //Skickar startbit, sätter avbrottsflaggan, avaktiverar avbrott, aktiverar bussen
	while (!(TWCR & (1<<TWINT)));  //Väntar på att start-signalen ska skickas iväg ifall bussen är upptagen t.ex.

	//Behöver ej kolla 0x08 eller 0x10, start eller repeterad start
}

//Skickar stoppbit
void TWIStop(void) {
	TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWIE)|(1<<TWEN)|(1<<TWEA); //Skickar stoppbit, sätter avbrottsflaggan, aktiverar avbrott, aktiverar bussen, aktiverar ackflaggan
}

//Skickar adress + data
void TWITransmitData(uint8_t data) {
	
	TWIStart();
	
	//Skickar mottagaradress
	TWISend(0x40); 
	
	//Kolla om arbitration lost
	if ((TWSR & 0xF8) == 0x38) {
		TWIStop(); //Släpp kontroll av bussen
		return;
	}
	
	//Adress mottagen, "not ack" mottagen
	if ((TWSR & 0xF8) == 0x20) {
		
		PORTD = 0x80;
		_delay_us(40);
		PORTD = 0x00;
		_delay_us(10);
		PORTD = 0x80;
		_delay_us(20);
		PORTD = 0x00;
		
		//Eventuellt fatal error badness 1000000000
		//Kanske inte behöver skicka ett stoppvilkor utan att det räcker att skicka ett repeated start och hantera det i styr...
		TWIStop();
		TWITransmitData(data); //Nytt försök att skicka data
		return;
	}
	
	//Skickar sändaradress
	TWISend(0x10);
	
	for (int i = 0; i < 2; i++) {
		TWISend(data);
	}
	
	TWIStop();
}

//Skicka data
void TWISend(uint8_t data) {
	TWDR = data; //Sparar datan på TWDR
	TWCR = (0<<TWSTA)|(1<<TWINT)|(1<<TWEN); //Skickar datan
	
	while (!(TWCR & (1<<TWINT))); //Väntar på ackbit
	
	//Data mottagen, "not ack" mottagen
	if ((TWSR & 0xF8) == 0x30) {
		
		PORTD = 0x80;
		_delay_us(10);
		PORTD = 0x00;
		_delay_us(20);
		PORTD = 0x80;
		_delay_us(40);
		PORTD = 0x00;
		//handle "not ack" received something very wrong has happened
		
		while(1){};
	}
}

//Ta emot data från sensormodulen
void TWIRecieveFromSens(void) {
	
	for (int i = 0; i < 4; i++) {
			
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); //Sätter avbrottsflaggan, aktiverar bussen, aktiverar ackflaggan
		
		while(!(TWCR & (1<<TWINT))); //Vänta på data
		
		//Data inte mottagen och ackbit inte mottagen
		if ((TWSR & 0xF8) != 0x90) {
			while(1){};
		}
		
		sensorData[i] = TWDR;
	}

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(!(TWCR & (1<<TWINT))); //Väntar på stoppbit
	
	//Om inte det är en stoppbit
	if ((TWSR & 0xF8) != 0xA0) {
		while(1){};
	}
	
	TWCR = (1<<TWIE)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
}

//Main-loop
int main(void)
{
 	TWIInit();

	while(1) {
		TWITransmitData(0xAA);
		for(int i = 0; i < 100; i ++);
	}
}