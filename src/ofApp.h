#pragma once

#include "ofMain.h"
//#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};

//--------------------------------------------------------------
//--------------------------------------------------------------
//I had some connection errors with connecting my class files so 
//	last minute I moved the class from it's own .h and .cpp files
class BallObj{
public:
	BallObj();
	BallObj(int x, int y);

	float getDirectionX();
	float getDirectionY();

	float getPositionX();
	float getPositionY();

	int getRadius();
	int getSpeed();


	void setDirectionX(float newDirection);
	void setDirectionY(float newDirection);

	void setPositionX(float newPosition);
	void setPositionY(float newPosition);

	void setRadius(int r);
	void setSpeed(int s);

private:
	ofColor color;
	// use .x and .y for ofPoint vars
	ofPoint position;
	// x,y where x will be randomized upon collision
	//		and y will toggle b/t 1 and -1
	ofPoint direction;
	int speed;
	int radius;

};
