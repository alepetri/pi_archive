/*  
    Writer: Andrew Lepetri
	Date: 10/28/2015
	Purpose: CompE 160 Final Project
	Description: Binary Clock:
	4-bit hours    6-bit minutes     6-bit seconds
*/

//defines all of the GPIO pin locations to variables
#define hr0 5
#define hr1 6
#define hr2 13
#define hr3 19

#define min0 18
#define min1 23
#define min2 12
#define min3 16
#define min4 20
#define min5 21

#define sec0 2
#define sec1 3
#define sec2 4
#define sec3 17
#define sec4 27
#define sec5 22

#include <stdio.h>
#include <math.h>
#include <wiringPi.h>
#include <unistd.h>

void Dec2Bin (int dec, int bin[], int bit);
void updateTime(int *hr, int *min, int *sec);
void updateDisplay(int hr, int min, int sec);
void setupWiringGPIO();


int main()
{
    int hr=0,min=0,sec=0;
    setupWiringGPIO();
	printf("Input current time in the format hr min sec\n");
	scanf("%d %d %d",&hr,&min,&sec);//prompts and then stores intial time
	updateDisplay(hr,min,sec);

	while(1 == 1)//infinite loop that runs the clock
	{
	    delay(1000);
	    updateTime(&hr,&min,&sec);
	    updateDisplay(hr,min,sec);
	}
    
	return 0;
}

void Dec2Bin (int dec, int bin[], int bit)//converts decimal to binary array
{
    int x=0,n=-1,i=0;
    while (x<=dec)
    {
        ++n;
        x = pow(2,n);
    }
    --n;
    if (dec == 0)
    {
        bin[bit-1] = 0;
    }
    else
    {
        for(i=0;i<=n;++i)
        {
            if (pow(2,(n-i))<=dec)
            {
                bin[(bit-1)-(n-i)] = 1;
                dec = dec - pow(2,(n-i));
            }
        }
    }
    
    return;
}

void updateTime(int *hrP, int *minP, int *secP)//calculates new time after adding one second
{
    int carryMin=0,carryHr=0,hr=0,min=0,sec=0;
    hr = *hrP;
    min = *minP;
    sec = *secP;
    sec = sec + 1;
    if (sec == 60)
    {
        sec = 0;
        carryMin = 1;
    }
    if (carryMin == 1)
    {
        min = min + 1;
    }
    if (min == 60)
    {
        min = 0;
        carryHr = 1;
    }
    if (carryHr == 1)
    {
        hr = hr + 1;
    }
    if (hr == 13)
    {
        hr = 1;
    }
    *hrP = hr;
    *minP = min;
    *secP = sec;
    
    return;
}

void updateDisplay(int hr, int min, int sec) //converts decimal to binary and then updates the LEDS
{
    int binHr[4]={0,0,0,0}, binMin[6]={0,0,0,0,0,0}, binSec[6]={0,0,0,0,0,0};
    Dec2Bin(hr,binHr,4);
    Dec2Bin(min,binMin,6);
    Dec2Bin(sec,binSec,6);
    
    digitalWrite(hr0,binHr[3]);
    digitalWrite(hr1,binHr[2]);
    digitalWrite(hr2,binHr[1]);
    digitalWrite(hr3,binHr[0]);
    
    digitalWrite(min0,binMin[5]);
    digitalWrite(min1,binMin[4]);
    digitalWrite(min2,binMin[3]);
    digitalWrite(min3,binMin[2]);
    digitalWrite(min4,binMin[1]);
    digitalWrite(min5,binMin[0]);
    
    digitalWrite(sec0,binSec[5]);
    digitalWrite(sec1,binSec[4]);
    digitalWrite(sec2,binSec[3]);
    digitalWrite(sec3,binSec[2]);
    digitalWrite(sec4,binSec[1]);
    digitalWrite(sec5,binSec[0]);
    
    return;
}

void setupWiringGPIO() //sets up all the GPIO to output and off
{
    wiringPiSetupGpio() ;
    
    pinMode(hr0, OUTPUT) ;
    digitalWrite(hr0, 0) ;
    pinMode(hr1, OUTPUT) ;
    digitalWrite(hr1, 0) ;
    pinMode(hr2, OUTPUT) ;
    digitalWrite(hr2, 0) ;
    pinMode(hr3, OUTPUT) ;
    digitalWrite(hr3, 0) ;
    pinMode(min0, OUTPUT) ;
    digitalWrite(min0, 0) ;
    pinMode(min1, OUTPUT) ;
    digitalWrite(min1, 0) ;
    pinMode(min2, OUTPUT) ;
    digitalWrite(min2, 0) ;
    pinMode(min3, OUTPUT) ;
    digitalWrite(min3, 0) ;
    pinMode(min4, OUTPUT) ;
    digitalWrite(min4, 0) ;
    pinMode(min5, OUTPUT) ;
    digitalWrite(min5, 0) ;
    pinMode(sec0, OUTPUT) ;
    digitalWrite(sec0, 0) ;
    pinMode(sec1, OUTPUT) ;
    digitalWrite(sec1, 0) ;
    pinMode(sec2, OUTPUT) ;
    digitalWrite(sec2, 0) ;
    pinMode(sec3, OUTPUT) ;
    digitalWrite(sec3, 0) ;
    pinMode(sec4, OUTPUT) ;
    digitalWrite(sec4, 0) ;
    pinMode(sec5, OUTPUT) ;
    digitalWrite(sec5, 0) ;
}