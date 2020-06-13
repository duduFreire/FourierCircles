#include "Screen.h"

namespace screen {
	float xRange = 1.0f;
	float yRange = xRange * 9.0f / 16.0f;
	float scale = xRange / 2.0f;

	float realToScr(float real) {
		return ofMap(real, -xRange, xRange, 0, ofGetWidth());
	}

	float imagToScr(float imag) {
		return ofMap(imag, -yRange, yRange, ofGetHeight(), 0);
	}

	float scrToReal(float coord) {
		return ofMap(coord, 0, ofGetWidth(), -xRange, xRange);
	}

	float scrToImag(float coord) {
		return ofMap(coord, 0, ofGetHeight(), yRange, -yRange);
	}
}