#include <stdio.h>
#include <math.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>

#define LED1 26
#define LED2 19
#define LED3 13
#define LED4 6

#define BUTTON1 17
#define BUTTON2 4
#define BUTTON3 3
#define BUTTON4 2

int readButton(int BUTTON);
int updateArray(int Array[], int ele, time_t t);
int Game(int Array[], int ele);
void displayArray(int Array[], int ele);
void flash(int num);
void Lose();
void setupWiringGPIO();

int main()
{
    setupWiringGPIO();
    time_t t = time(NULL);
    int Array[100] = {0};
    int ele = updateArray(Array,-1, t);
    int Win = 1, score = -1;
    delay(2000);
    while(Win == 1)
    {
        score = score + 1;
        displayArray(Array, ele);
        Win = Game(Array, ele);
	    if (Win == 1)
        {
             flash(2);
        }
        ele = updateArray(Array, ele, t);
    }
    Lose();

    printf("Your score is: %d!\n",score);
    return 0;
}

int readButton(int BUTTON)
{
    int Button = 0;
    Button = digitalRead(BUTTON);
    delay(100);
    return Button;
}

int updateArray(int Array[], int ele, time_t t)
{
    time_t c = time(NULL);
    int r = srand(t-c) % 4;
    r = r + 1;
    ele = ele + 1;
    Array[ele] = r;

    return ele;
}

int Game(int Array[], int ele)
{
    int i = 0, Correct = 1, Guess = 0, wait = 1, LED = 0;
    for(i=0;i<=ele;++i)
    {
        wait = 1;
        while(wait == 1)
        {
            if (readButton(BUTTON1)==0)
            {
                Guess = 1;
                wait = 0;
                LED = LED1;
                digitalWrite(LED, 1) ;
            }
            if (readButton(BUTTON2)==0)
            {
                Guess = 2;
                wait = 0;
                LED = LED2;
                digitalWrite(LED, 1) ;
            }
            if (readButton(BUTTON3)==0)
            {
                Guess = 3;
                wait = 0;
                LED = LED3;
                digitalWrite(LED, 1) ;
            }
            if (readButton(BUTTON4)==0)
            {
                Guess = 4;
                wait = 0;
                LED = LED4;
                digitalWrite(LED, 1) ;
            }
        }
        delay(400);
        digitalWrite(LED, 0) ;
        delay(100);
        if (Guess != Array[i])
        {
            Correct = 0;
            break;
        }

    }

    return Correct;
}

void displayArray(int Array[],int ele)
{
    int i=0, LED=0;
    for(i=0; i<=ele; ++i)
    {
        switch(Array[i])
        {
            case 1:
                LED=LED1;
                break;
            case 2:
                LED=LED2;
                break;
            case 3:
                LED=LED3;
                break;
            case 4:
                LED=LED4;
                break;
            default:
                break;
        }
        delay(300);
        digitalWrite(LED, 1) ;
        delay(500);
        digitalWrite(LED, 0) ;
        delay(300);
    }
    return;
}

void flash(int num)
{
    int i=0;
    for(i=0;i<num;++i)
    {
        digitalWrite(LED1, 1) ;
        digitalWrite(LED2, 1) ;
        digitalWrite(LED3, 1) ;
        digitalWrite(LED4, 1) ;
        delay(100);
        digitalWrite(LED1, 0) ;
        digitalWrite(LED2, 0) ;
        digitalWrite(LED3, 0) ;
        digitalWrite(LED4, 0) ;
        delay(100);
    }
    return;
}

void Lose()
{
    int i=0;
    for(i=0;i<3;++i)
    {
        digitalWrite(LED1, 1) ;
        delay(100);
        digitalWrite(LED2, 1) ;
        delay(100);
        digitalWrite(LED3, 1) ;
        delay(100);
        digitalWrite(LED4, 1) ;
        digitalWrite(LED1, 0) ;
        delay(100);
        digitalWrite(LED2, 0) ;
        delay(100);
        digitalWrite(LED3, 0) ;
        delay(100);
        digitalWrite(LED4, 0) ;
    }

        digitalWrite(LED1, 1) ;
        delay(100);
        digitalWrite(LED2, 1) ;
        delay(100);
        digitalWrite(LED3, 1) ;
        delay(100);
        digitalWrite(LED4, 1) ;

    for(i=0;i<5;++i)
    {
        digitalWrite(LED1, 1) ;
        digitalWrite(LED2, 1) ;
        digitalWrite(LED3, 1) ;
        digitalWrite(LED4, 1) ;
        delay(100);
        digitalWrite(LED1, 0) ;
        digitalWrite(LED2, 0) ;
        digitalWrite(LED3, 0) ;
        digitalWrite(LED4, 0) ;
        delay(100);
    }
    return;
}


void setupWiringGPIO() //sets up all the GPIO to output and off
{
    wiringPiSetupGpio() ;

    pinMode(LED1, OUTPUT) ;
    digitalWrite(LED1, 0) ;
    pinMode(LED2, OUTPUT) ;
    digitalWrite(LED2, 0) ;
    pinMode(LED3, OUTPUT) ;
    digitalWrite(LED3, 0) ;
    pinMode(LED4, OUTPUT) ;
    digitalWrite(LED4, 0) ;
    pinMode(BUTTON1, INPUT) ;
    pullUpDnControl(BUTTON1, PUD_UP);
    pinMode(BUTTON2, INPUT) ;
    pullUpDnControl(BUTTON2, PUD_UP);
    pinMode(BUTTON3, INPUT) ;
    pullUpDnControl(BUTTON3, PUD_UP);
    pinMode(BUTTON4, INPUT) ;
    pullUpDnControl(BUTTON4, PUD_UP);

    return;
}
