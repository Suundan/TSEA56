/*
 * TWI_styr_buss.c
 *
 * Created: 4/6/2016 1:42:45 PM
 *  Author: marha996
 */ 

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1000000UL

uint8_t sensorData[4];
uint8_t kommData[2];

ISR(TWI_vect){
	
	//Kollar om man blivit adresserad och returnerat ack-bit
	
		if ((TWSR & 0xF8) == 0x60 || (TWSR & 0xF8) == 0x70) {
		
		TWCR = (0<<TWIE)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		
		while(!(TWCR & (1<<TWINT))); //wait for data
		
		if (!((TWSR & 0xF8) == 0x80 || (TWSR & 0xF8) == 0x90)) {
			DDRD = 0x80;
			while(1){};
		}
			
		if (TWDR == 0x20) {
			TWIRecieveFromSens();
			return;
		}
		if (TWDR == 0x10) {
			TWIRecieveFromCom();
			return;
		}
	}
}
	
//Initierar bussen
void TWIInit(void) {
	
	//global interupt enable
	sei();
	
	//set SCL speed
	TWSR = (0<<TWPS0)|(0<<TWPS1) ; // set the prescaler bits to 0
	TWBR = 0x0C;  // set TWI bit rate register to 12
	
	//enable TWI samt enable ack-bit, enable interupts
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWIE);
	
	//set slave adress
	//Kommmudul 0x11 (sista ska vara ett för att enabla general call)
	//Sensormodul 0x21
	//Styrmodul 0x41
	
	TWAR = 0x41;
	
}

void TWIRecieveFromSens() {
	
	for (int i = 0; i < 4; i++) {
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		
		while(!(TWCR & (1<<TWINT))); //wait for data
		
		if ((TWSR & 0xF8) != 0x90) { //gilitigt data och ack-bit skickad
			while(1){};
		}
		
		sensorData[i] = TWDR;
	}

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(!(TWCR & (1<<TWINT))); //wait for stopbit
	
	TWCR = (1<<TWIE)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
}

void TWIRecieveFromCom() {
	
	for (int i = 0; i < 2; i++) {
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		
		while(!(TWCR & (1<<TWINT))); //wait for data
		
		if ((TWSR & 0xF8) != 0x80) { //gilitigt data och ack-bit skickad
			while(1){};
		}
		
		kommData[i] = TWDR;
	}

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(!(TWCR & (1<<TWINT))); //wait for stopbit
	
	TWCR = (1<<TWIE)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
}

int main(void)
{
 	TWIInit();
	 
	while(1) {
		int i = 0;
		while (i<10000) {
			i++;
		}
	}
}