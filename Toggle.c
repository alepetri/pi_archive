#define LED 5

#define SWITCH 6

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

void setupWiringGPIO();
int readButton();

int main()
{
    setupWiringGPIO();
    int toggle = 0;
    int LEDstate = 0;

	while(1)
	{
	    toggle = readButton();
	    if(toggle != 1)
	    {
	        if (LEDstate == 0)
	        {
	            LEDstate = 1;
                digitalWrite(LED, LEDstate) ;
	        }
	        else
	        {
	            LEDstate = 0;
                digitalWrite(LED, LEDstate) ;
	        }
	    }
	    toggle = 0;
	}
    
	return 0;
}

void setupWiringGPIO()
{
    wiringPiSetupGpio() ;
    
    pinMode(LED, OUTPUT) ;
    digitalWrite(LED, 0) ;
    pinMode(SWITCH, INPUT);
    pullUpDnControl(SWITCH, PUD_UP);
    return;
}

int readButton()
{
    int Button = 0;
    Button = digitalRead(SWITCH);
    delay(100);
    return Button;
}