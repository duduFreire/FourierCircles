#pragma once

#include "ofMain.h"
#include "myComplex.h"
#include "Screen.h"

class myCircle
{
public:
	float tipX, tipY;
	float radius;
	myComplex coefficient, vec;
	float freq;

	myCircle() = default;

	void setup(float freq)
	{
		this->freq = freq;
	}

	void calcCoefficient(std::vector<myComplex>& points) {
		int rectNum = 50000;
		for (int i = 0; i < rectNum; i++) {
			float t = (float)i / (rectNum - 1);
			coefficient += points[int(t * (points.size() - 1))] * complex::exp((float)-freq * 2.0f * PI * t);
		}

		coefficient.real /= (float)rectNum;
		coefficient.imag /= (float)rectNum;
		radius = complex::abs(coefficient);
	}

	void calcValues(float centerX, float centerY, float time) {
	}

	void draw(float centerX, float centerY, float time) {
		vec = complex::exp(freq * PI * 2 * time) * coefficient;

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(screen::realToScr(centerX), screen::imagToScr(centerY), (float)radius * 1280.0f / 2.0f);

		ofSetColor(ofColor(255, 0, 0));
		ofDrawLine(
			screen::realToScr(centerX), screen::imagToScr(centerY),
			screen::realToScr(vec.real + centerX), screen::imagToScr(vec.imag + centerY)
		);
	}
};
