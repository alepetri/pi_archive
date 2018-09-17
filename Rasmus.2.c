#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <unistd.h>

void setUpPins(int LED, int Button);

int main(void) {
	int Button = 6, LED = 5; //for setting up the Button and LED to the pins they are on
	int buttonPress = 0, currentState = 0;
	
	setUpPins(LED, Button);

	while(true){
		buttonPress = digitalRead(Button);
		delay(125); //holds state for 75 milliseconds to avoid button bounce
		if(buttonPress == 0){
			if (currentState == 0){ //if light is off it is turned on
				currentState = 1; 
				digitalWrite(LED, currentState); //sends signal to turn on to LED
			}
			else if (currentState == 1){ //if light is on it is turned off
				currentState = 0;
				digitalWrite(LED, currentState); //sends signal to turn off to LED
			}
		}
	}
	
	return 0;
}

void setUpPins(int LED, int Button){
	wiringPiSetupGpio();
	
	pinMode (LED, OUTPUT); //setting up the pin for LED, as an output, default state off
	digitalWrite (LED, LOW);
	pinMode (Button, INPUT); //set up button as input
	pullUpDnControl (Button, PUD_UP);
	
	return;
}