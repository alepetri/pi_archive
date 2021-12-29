# Old PI Projects

A spattering of Raspberry Pi based programs from when I was first learning to code!

## Contents
1. Simon.c
    - A basic simon says game for a breadboard containing 4 LEDs and 4 Buttons
    - GPIO pin numbers are mapped via macros at the top
    - Keeps on running, adding another LED to the sequence, until the user fails to recreate the sequence correctly
    - [Video Demo!](https://www.youtube.com/watch?v=0gYeD-haYt0)
2. binaryClock.c
    - Uses the Pi's GPIO interface to light 16 LEDs to tell the time in binary
    - Uses a 4 bit Hour, 6 bit Minute, 6 bit Second