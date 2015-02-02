#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sender.setup("192.168.0.255",
		6666, // port
		100, // interval (1/30 second)
		3000); // interval timescale
	sender.startThread();

	ofBackground(76, 153, 0);
	font.loadFont(OF_TTF_MONO, 72);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	std::string message = ofToString(sender.getFrameNumber());

	font.drawString(message, (ofGetWindowWidth() / 2) - (font.stringWidth(message) / 2), (ofGetWindowHeight() / 2) - (font.stringHeight(message) / 2));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
