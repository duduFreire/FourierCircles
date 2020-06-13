#pragma once

#include "ofApp.h"
#include "Screen.h"

int getFreq(int i) {
	if (i % 2 == 0) return -i / 2;
	else return (i + 1) / 2;
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(51);

	for (int i = 0; i < nCircles; i++) {
		circles[i].setup(getFreq(i));
	}

	int nPoints = 1280 * 3;
	for (int i = 0; i < nPoints; i++) {
		float r = ofMap(i, 0, nPoints - 1, 0, 9.0f / 16.0f);
		float angle = 5.0f * (float)i / (nPoints - 1) * PI * 2.0f;
		points.emplace_back(r*cos(angle), r*sin(angle));
	}
	for (int i = points.size() - 1; i >= 0; i--) {
		points.emplace_back(points[i].real, points[i].imag);
	}

	for (int i = 0; i < nCircles; i++) {
		circles[i].calcCoefficient(points);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (!animating) {
		ofSetColor(255, 255, 0);
		if (ofGetMousePressed())
			points.emplace_back(screen::scrToReal(mouseX), screen::scrToImag(mouseY));

		if (points.size() == 0) {
			ofPoint(mouseX, mouseY);
		}
		else {
			for (uint32_t i = 0; i < points.size() - 1; i++) {
				ofDrawLine(
					screen::realToScr(points[i].real), screen::imagToScr(points[i].imag),
					screen::realToScr(points[i + 1].real), screen::imagToScr(points[i + 1].imag)
				);
			}
		}
	}
	else {
		circles[0].draw(0, 0, time);

		myComplex vecTip(circles[0].vec.real, circles[0].vec.imag);
		for (int i = 1; i < nCircles; i++) {
			circles[i].draw(vecTip.real, vecTip.imag, time);
			vecTip += circles[i].vec;
		}

		ofFill();
		ofSetColor(0, 0, 255);
		ofDrawCircle(screen::realToScr(vecTip.real), screen::imagToScr(vecTip.imag), 5);

		if (time < 1)
			trail.emplace_back(screen::realToScr(vecTip.real), screen::imagToScr(vecTip.imag));

		ofNoFill();
		ofSetColor(255, 255, 0);
		ofBeginShape();
		for (int i = 0; i < trail.size(); i++) {
			ofVertex(trail[i].x, trail[i].y);
		}
		ofEndShape();

		time += 1.0f / (600.0f * 1);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ' && !animating) {
		for (int i = 0; i < nCircles; i++) {
			circles[i].calcCoefficient(points);
		}
		animating = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}