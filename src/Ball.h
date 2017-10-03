#pragma once

#ifndef BALL_H
#define BALL_H

#include "ofMain.h"

class BallObj {
public:
	BallObj();
	BallObj(ofColor c, int r, ofPoint d, ofPoint p);

	ofPoint getDirection();
	ofPoint getPosition();
	int getRadius();

	void setDirection(ofPoint newDirection);
	void setPosition(ofPoint newPosition);

private:
	ofColor color;
	// use .x and .y for ofPoint vars
	ofPoint position;
	ofPoint direction;
	int radius;

};


#endif BALL_H
