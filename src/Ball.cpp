#include "Ball.h"

BallObj::BallObj() {
	BallObj(ofColor::crimson, 5, ofPoint(0, 0), ofPoint(0, 0));
}
BallObj::BallObj(ofColor c, int r, ofPoint d, ofPoint p) {
	color = c;
	radius = r;
	direction = d;
	position = p;
}

ofPoint BallObj::getDirection() { return direction; }
ofPoint BallObj::getPosition() { return position; }

int BallObj::getRadius() { return radius; }


void BallObj::setDirection(ofPoint newDirection) {
	direction = newDirection;
}
void BallObj::setPosition(ofPoint newPosition) {
	position = newPosition;
}
//--------------------------------------------------------------



//struct from normanorma: https://gist.github.com/normanorma/4042323
struct BallObj {
	ofColor color;
	int radius;

	// use .x and .y for ofPoint vars
	ofPoint position;
	ofPoint direction;
};
