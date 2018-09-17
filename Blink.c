#define LED 5

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

void setupWiringGPIO();

int main()
{
	setupWiringGPIO();

	while(1)
	{
		delay(500);
        	digitalWrite(LED, 0) ;
        	delay(500);
        	digitalWrite(LED, 1) ;
	}
    
	return 0;
}

void setupWiringGPIO()
{
	wiringPiSetupGpio() ;
    
	pinMode(LED, OUTPUT) ;
	digitalWrite(LED, 0) ;
}