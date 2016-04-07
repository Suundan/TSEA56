/*
 * TWI_sens_buss.c
 *
 * Created: 4/6/2016 1:42:45 PM
 *  Author: marha996
 */ 

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1000000UL


//Initierar bussen
void TWIInit(void) {
	
	//Globalt avbrott aktiverat
	sei();
	
	//Sätter SCL hastighet
	TWSR = (0<<TWPS0)|(0<<TWPS1) ; //Sätter prescaler värdet till 1
	TWBR = 0x0C;  //Sätter Bit rate registry till 12
	
	//Aktiverar bussen, aktiverar ackbit, aktiverar avbrott
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWIE);
	
	//Slavadresser (sista ska vara ett för att enabla general call)
	//Kommmudul: 0x11 
	//Sensormodul: 0x21
	//Styrmodul: 0x41
	
	TWAR = 0x21;
}

//Skickar startbit
void TWIStart(void) {
	TWCR = (1<<TWSTA)|(1<<TWINT)|(0<<TWIE)|(1<<TWEN); //Skickar startbit, sätter avbrottsflaggan, avaktiverar avbrott, aktiverar bussen
	while (!(TWCR & (1<<TWINT))); //Väntar på att start-signalen ska skickas iväg ifall bussen är upptagen t.ex.
	
	//Behöver ej kolla 0x08 eller 0x10, startbit eller repeterad startbit
}

//Skickar stoppbit
void TWIStop(void) {
	TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWIE)|(1<<TWEN)|(1<<TWEA); //Skickar stoppbit, sätter avbrottsflaggan, aktiverar avbrott, aktviverar bussen, aktviterar ackbit
}

//Skickar adress + data
void TWITransmitData(uint8_t data[4]) {
	
	TWIStart();

	//Skicka SLA + W, adress 00 för att det är general call (till alla slaves)
	TWISend(0x00); 
	
	//Om inte adress mottagen och inte "not ack" mottagen
	if ((TWSR & 0xF8) == 0x20) {
		
		TWIStop();
		TWITransmitData(data);
		return;
	}

	//Skickar sensormodulens adress
	TWISend(0x20);
	
	//Om data inte mottagen och ack inte mottagen
	if ((TWSR & 0xF8) != 0x28) {
		
		while(1){};
	}
	
	for(int i = 0; i < 4; i++) {
		//Skicka data
		TWISend(data[i]);
		
		//Om data inte mottagen och ack inte mottagen
		if ((TWSR & 0xF8) != 0x28) {
			while(1){};
		}
	}
	
	TWIStop();
}

//Skickar data
void TWISend(uint8_t data) {
	TWDR = data;
	
	TWCR = (0<<TWSTA)|(1<<TWINT)|(1<<TWEN); //Avaktiverar startflaggan och avbrottsflaggan, avktiverar bussen
	
	while (!(TWCR & (1<<TWINT))); //Väntar på ackbit
}


//Main-loop
int main(void)
{
 	TWIInit();

	//Dataarray
	uint8_t testArr[4];
	testArr[1] = 0xAA;
	testArr[2] = 0x55;
	testArr[3] = 0x22;
	testArr[4] = 0x11;

	while(1) {
		TWITransmitData(testArr);
	}
}