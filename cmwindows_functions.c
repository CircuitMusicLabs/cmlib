#include <stdio.h>
#include <math.h>
#include "cmwindows.h"



void cm_hann(double *window, long *length) {
	int i;
	long N = *length - 1;
	for (i = 0; i < *length; i++) {
		window[i] = 0.5 * (1.0 - cos((2.0 * M_PI) * ((double)i / (double)N)));
	}
	return;
}


void cm_hamming(double *window, long *length) {
	int i;
	long N = *length - 1;
	for (i = 0; i < *length; i++) {
		window[i] = 0.54 - (0.46 * cos((2.0 * M_PI) * ((double)i / (double)N)));
	}
	return;
}


void cm_rectangular(double *window, long *length) {
	int i;
	for (i = 0; i < *length; i++) {
		window[i] = 1;
	}
	return;
}


void cm_bartlett(double *window, long *length) {
	int i;
	long N = *length - 1;
	for (i = 0; i < *length; i++) {
		if (i < (*length / 2)) {
			window[i] = (2 * (double)i) / (double)N;
		}
		else {
			window[i] = 2 - ((2 * (double)i) / (double)N);
		}
	}
	return;
}


void cm_flattop(double *window, long *length) {
	int i;
	long N = *length - 1;
	double a0 = 0.21557895;
	double a1 = 0.41663158;
	double a2 = 0.277263158;
	double a3 = 0.083578947;
	double a4 = 0.006947368;
	double twopi = M_PI * 2.0;
	double fourpi = M_PI * 4.0;
	double sixpi = M_PI * 6.0;
	double eightpi = M_PI * 8.0;
	for (i = 0; i < *length; i++) {
		window[i] = a0 - (a1 * cos((twopi * i) / N)) + (a2 * cos((fourpi * i) / N)) - (a3 * cos((sixpi * i) / N)) + (a4 * cos((eightpi * i) / N));
	}
	return;
}


void cm_gauss2(double *window, long *length) {
	int i;
	double n;
	double N = *length - 1;
	double alpha = 2.0;
	double stdev = N / (2 * alpha);
	for (i = 0; i < *length; i++) {
		n = i - N / 2;
		window[i] = exp(-0.5 * pow((n / stdev), 2));
	}
}


void cm_gauss4(double *window, long *length) {
	int i;
	double n;
	double N = *length - 1;
	double alpha = 4.0;
	double stdev = N / (2 * alpha);
	for (i = 0; i < *length; i++) {
		n = i - N / 2;
		window[i] = exp(-0.5 * pow((n / stdev), 2));
	}
}


void cm_gauss8(double *window, long *length) {
	int i;
	double n;
	double N = *length - 1;
	double alpha = 8.0;
	double stdev = N / (2 * alpha);
	for (i = 0; i < *length; i++) {
		n = i - N / 2;
		window[i] = exp(-0.5 * pow((n / stdev), 2));
	}
}
