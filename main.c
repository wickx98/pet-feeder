/*
 * GccApplication2.c
 *
 * Created: 11/6/2022 9:52:43 PM
 * Author : Hasitha Basnayake
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



void loop(void);
void stepr(void);
void steproff(void);
void OneStep();

unsigned char seconds =0;
int step_number = 0;
int timeCount = 0;

int i= 0;
int j= 0;


void initTimerInterrupt1(void);
void initExternalInterrupt0(void);
void enableTimerInterrupt1(void);
void disableTimerInterrupt1(void);
void initTimerCount(void){timeCount=0;}

void delay_sec(long sec);
void delay_6_hours(void);

int main(void)
{
    /* Replace with your application code */
	DDRB |= 0B00001111; // for output pin 8,9,10,11
	
	DDRD = 0XF0;
	DDRD |= 0XFC;
	
	EICRA = 0x0a; //falling edge
	sei();
	EIMSK |= 0x03; // external interrupts 0
	
	TIMSK1 |= 0B00000010;
	TCCR1A &= 0B11111100;
	TCCR1B |= 0B00001000;
	TCCR1B &= 0B11101111;
	TCCR1B |= 0B00000100;
	TCCR1B &= 0B11111100;
	
	OCR1AH = 0XF4; OCR1AL = 0X24;
	TCNT1L = 0X00; TCNT1H = 0X00;
	
	sei();
	
	
    while (1) 
    {
		//delay_6_hours(); 
		//OneStep(1);
		
	}
    
}

void delay_sec(long sec)
{
	while (sec > 0)
	{
		_delay_ms(1000);
		sec -= 1;
	}
}

enum { seconds_per_hour = 60 * 60 };

void delay_6_hours(void)
{
	delay_sec(6 * seconds_per_hour);
}

ISR(INT0_vect)
{
	switch(step_number){
		case 0:
		PORTB = PORTB | 0B00000001; // pin 8 high
		PORTB = PORTB & 0B11110001;
		break;
		case 1:
		PORTB = PORTB | 0B00000010; // pin 9 high
		PORTB = PORTB & 0B11110010;
		break;
		case 2:
		PORTB = PORTB | 0B00000100; // pin 10 high
		PORTB = PORTB & 0B11110100;
		break;
		case 3:
		PORTB = PORTB | 0B00001000; // pin 11 high
		PORTB = PORTB & 0B11111000;
		break;
	}
	step_number++;
	if(step_number > 3){
		step_number = 0;
	}
		
}


void stepr()
{
	for(int i=0;i<1000;i++)
	{
		OneStep(0);
		_delay_ms(3);
	}
}
ISR(TIMER0_COMPA_vect)
{
	if(i<60)
	{
		i++;
		if(j<60)
		{
			j++;
		}
		else
		{
			OneStep(1);
			
			i=0;
			j=0;
		}
	}
}

void steproff(){
	PORTB = PORTB | 0B00000001; // pin 8 high
	PORTB = PORTB & 0B11110001;//pin9,10,11 low
}

void OneStep(){
	{
		switch(step_number){
			case 0:
			PORTB = PORTB | 0B00000001; // pin 8 high
			PORTB = PORTB & 0B11110001;
			break;
			case 1:
			PORTB = PORTB | 0B00000010; // pin 9 high
			PORTB = PORTB & 0B11110010;
			break;
			case 2:
			PORTB = PORTB | 0B00000100; // pin 10 high
			PORTB = PORTB & 0B11110100;
			break;
			case 3:
			PORTB = PORTB | 0B00001000; // pin 11 high
			PORTB = PORTB & 0B11111000;
			break;
		}
		/*
		}else{
		switch(step_number){
			case 0:
			PORTB = PORTB | 0B00001000; // pin 11 high
			PORTB = PORTB & 0B11111000;
			break;
			case 1:
			PORTB = PORTB | 0B00001000; // pin 11 high
			PORTB = PORTB & 0B11111000;
			break;
			case 2:
			PORTB = PORTB | 0B00000010; // pin 9 high
			PORTB = PORTB & 0B11110010;
			break;
			case 3:
			PORTB = PORTB | 0B00000001; // pin 8 high
			PORTB = PORTB & 0B11110001;


		}
	}*/
	step_number++;
	if(step_number > 3){
		step_number = 0;
	}
}
}