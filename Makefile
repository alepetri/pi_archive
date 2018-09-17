all:
	sudo gcc -o binaryClock binaryClock.c -lm -lwiringPi
	./binaryClock