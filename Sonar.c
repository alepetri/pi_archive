#define Sonar 2

#include <stdio.h>
#include <math.h>
#include <wiringPi.h>
#include <unistd.h>


void setupWiringGPIO();
float distance(float Vm);


int main()
{
	float value = 0;
	setupWiringGPIO();

	while(1 == 1)//infinite loop that runs the clock
	{
		delay(800);
		value = analogRead(Sonar);
		delay(40);
		printf("%lf\n",value);
	}
    
	return 0;
}


void setupWiringGPIO() //sets up all the GPIO to output and off
{
	wiringPiSetupGpio() ;
    
	pinMode(Sonar, INPUT) ;
	pullUpDnControl(Sonar, PUD_UP);

}

float distance(float Vm)
{
	float range = 0;
	range=Vm/.009765625;
	return(range);
}