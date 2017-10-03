#include "ofApp.h"

BallObj ball; //hacky as shit call of constructor

//for polyline implementation
//struct LineStruct {
//	ofPolyline pline;
//	bool on;
//};

//vector<LineStruct> polyLineVector;
vector<ofPoint> ptsVec;
vector<BallObj> ballContainer;
vector<int> randomOnOff;

bool collision;


//--------------------------------------------------------------
//The setup method is called only once at the beginning of the 
//  application and it's used to initialize other objects or 
//    variables usually declared in ofApp.h.
void ofApp::setup(){
	ofSetFrameRate(60);

	//set up first ball
	ball.setPositionX(ofGetWidth() / 2);
	ball.setPositionY(0);
	ball.setDirectionX(0);
	ball.setDirectionY(1);

	ballContainer.push_back(ball);

	//default - no collisions bt ball & lines(s) yet
	collision = false;


}

//--------------------------------------------------------------
//Update - meant to be used for updating the state of our application, 
//make calculations/update other objects like video players, 
//grabbers, or any computer vision analysis we might be doing...
void ofApp::update() {
	//------working on it--------------------------------------------------
	//ball.setPositionX(ball.getPosition().y - 30);
	////update ALL balls in container
	//for (int i = 0; i < ballContainer.size(); ++i) {
	//	int d = ballContainer[i].getDirectionY();
	//	////BOUNCE BACK BALL IF IT REACHES EDGES OF CANVAS
	//	//left edge
	//	if (ballContainer[i].getPositionX() < 0) {
	//		ballContainer[i].setDirectionY(abs(ball.getDirectionY()));
	//	}//bottom edge
	//	if (ballContainer[i].getPositionY() > ofGetHeight()) {
	//		ballContainer[i].setDirectionY(-abs(ball.getDirectionY()));
	//	}
	//	ballContainer[i].setPositionY(ballContainer[i].getPositionY()+20);
	//	
	//}
	//----------------------------------------------------------------------

	for (int i = 0; i < ballContainer.size(); ++i) {
		//update position
		ballContainer[i].setPositionY(ballContainer[i].getPositionY() + (ballContainer[i].getDirectionY() * 10));

		if ( (ballContainer[i].getPositionY()) < 0 || (ballContainer[i].getPositionY() > ofGetHeight()) ) {
			ballContainer[i].setDirectionY(-1 * ballContainer[i].getDirectionY());
		}
		/*for (int i = 0; i < ptsVec.size(); ++i) {


		}*/
	}
} 



//Update and draw are called in an infinite loop one after another 
//		in that order
//--------------------------------------------------------------
//draw to the screen
void ofApp::draw() {
	//ofColor colorOne(72, 198, 239);
	//ofColor colorTwo(111, 134, 214);

	ofColor colorTwo(80, 201, 195);
	ofColor colorOne(150, 222, 218);

	//set background to linear gradient
	ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

	vector<ofPoint> pts;
	//set up lines that stretch across canvas
	//FOR POLYLINE IMPLEMENTATION
	//for (int i = 0; i < ofGetHeight() - (ofGetHeight() / 10); i += (ofGetHeight() / 10)) {
	//	LineStruct l;
	//	for (int j = 0; j < ofGetWidth(); ++j) {
	//		pts.push_back(ofPoint(j, i + (ofGetHeight() / 10)));
	//	}
	//	ofPolyline cp(pts);
	//	l.pline = cp;
	//	polyLineVector.push_back(l);

	//	//create random value associated with this polyLine by index
	//	randomOnOff.push_back((int)ofRandom(0, 2));
	//}

	ofSetLineWidth(1);
	//for (int i = 0; i < polyLineVector.size(); ++i) {
	//	//draw each polyline from LineStruct
	//	polyLineVector[i].pline.draw();
	//}

	//int rand = (int)ofRandom(3, 8)
	int rand = 20;
	for( int i = 0; i < ofGetHeight() - (ofGetHeight() / rand); i += (ofGetHeight() / rand)) {
		//draw each line 
		ofDrawLine(0,i + (ofGetHeight() / rand), ofGetWidth(), i + (ofGetHeight() / rand));
		ptsVec.push_back(ofPoint(0, i + (ofGetHeight() / rand)));
		randomOnOff.push_back((int)ofRandom(0, 2));

	}

	//draw ball(s)
	ofNoFill();
	ofSetLineWidth(3);
	for (int i = 0; i < ballContainer.size(); ++i) {
		ofDrawCircle(ballContainer[i].getPositionX(), ballContainer[i].getPositionY(), ballContainer[i].getRadius());
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'n') {
		BallObj ballSpawn(ofGetWidth()/ofRandom(2,6), ofGetHeight() / ofRandom(2, 6));
		ballContainer.push_back(ballSpawn);
		ofDrawCircle(ballSpawn.getPositionX(), ballSpawn.getPositionY(), ballSpawn.getRadius());
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//if any the left || right mouse button is pressed
	if (button == 0 || button == 2) {
		ofDrawCircle(0, 0, 50);

		BallObj ballSpawn(x,y);
		ballContainer.push_back(ballSpawn);
		ofDrawCircle(ballSpawn.getPositionX(), ballSpawn.getPositionY(), ballSpawn.getRadius());
	}
	//add in triangle for long notes -- fades
	//else if (button == 1) { //middle mouse button
	//}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------



//--------------------------------------------------------------
//--------------------------------------------------------------
//I had some connection errors with connecting my class files so 
//	last minute I moved the class from it's own .h and .cpp files

BallObj::BallObj() { radius = 30;  }
BallObj::BallObj(int x, int y) {
	position = ofPoint(x, y);
	radius = 30/y;
}

float BallObj::getDirectionX() { return direction.x; }
float BallObj::getDirectionY() { return direction.y; }

float BallObj::getPositionX() { return position.x; }
float BallObj::getPositionY() { return position.y; }


int BallObj::getRadius() { return radius; }
int BallObj::getSpeed() { return speed; }


void BallObj::setDirectionX(float newDirection) {
	direction.x = newDirection; 
}
void BallObj::setDirectionY(float newDirection) {
	direction.y = newDirection;
}

void BallObj::setPositionX(float newPosition) {
	position.x = newPosition;
}
void BallObj::setPositionY(float newPosition) {
	position.y = newPosition; 
}
void BallObj::setRadius(int r) { radius = r; }
void BallObj::setSpeed(int s) { speed = s; }
//--------------------------------------------------------------
//--------------------------------------------------------------