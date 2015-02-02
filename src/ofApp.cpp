#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sender.setup("192.168.0.255",
		6666, // port
		100, // interval (1/30 second)
		3000); // interval timescale
	sender.startThread();

	// tell any existing clients to reset frame numbers
	ofxOscMessage message;
	message.setAddress("/frame_number_reset");
	message.addInt64Arg(0);
	sender.send(message);

	ofBackground(76, 153, 0);
	font.loadFont(OF_TTF_MONO, 72);

	show_stats = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	std::string message = ofToString(sender.getFrameNumber());

	font.drawString(message, (ofGetWindowWidth() / 2) - (font.stringWidth(message) / 2), (ofGetWindowHeight() / 2) - (font.stringHeight(message) / 2));

	ofDrawBitmapString("Type s to toggle statistics display on clients", 10, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's')
	{
		show_stats = !show_stats;

		ofxOscMessage message;
		message.setAddress("/display_stats");
		message.addIntArg(show_stats);
		sender.send(message);
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
