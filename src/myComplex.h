#pragma once

#include "ofMain.h"

class myComplex {
public:
	float real = 0, imag = 0;

	myComplex() :
		real(0.0f),
		imag(0.0f)
	{}

	myComplex(float real, float imag) :
		real(real),
		imag(imag)
	{}

	myComplex operator*(myComplex other) {
		return { real * other.real - imag * other.imag, imag*other.real + other.imag*real };
	}

	void operator +=(myComplex other) {
		real += other.real;
		imag += other.imag;
	}
};

namespace complex {
	myComplex exp(float imag);
	float abs(myComplex& num);
}