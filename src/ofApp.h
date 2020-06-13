#pragma once

#include "ofMain.h"
#include "myCircle.h"
#include "myComplex.h"
#include <vector>

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	std::vector<myComplex> points;
	std::vector<glm::vec2> trail;
	int nCircles = 1000;
	myCircle circles[1000];
	float time = 0.0f;
	bool animating = false;
};
