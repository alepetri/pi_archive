#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <unistd.h>

void setUpPins(int LED);

int main(void) {
	int LED = 5; //for setting up the LED to the pins they are on
	
	setUpPins(LED);

	while(true){
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
	
	return 0;
}

void setUpPins(int LED){
	wiringPiSetupGpio();
	
	pinMode (LED, OUTPUT); //setting up the pin for LED, as an output, default state off
	digitalWrite (LED, LOW);
	
	return;
}