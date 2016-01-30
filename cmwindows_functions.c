#include <stdio.h>
#include <math.h>
#include "cmwindows.h"



// HANN WINDOW
void cm_hann(double *window, int *w_size) {
	int i;
	for (i = 0; i < *w_size; i++) {
		window[i] = 0.5 * (1 - cos((2 * M_PI * i) / (*w_size - 1)));
	}
	return;
}

// RECTANGULAR WINDOW
void cm_rectangular(double *window, int *w_size) {
	int i;
	for (i = 0; i < *w_size; i++) {
		window[i] = 1;
	}
	return;
}
