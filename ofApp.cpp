#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 60;
	int tri_size = size * 0.95;
	int y_count = 0;
	ofColor tri_color;

	for (int x = 0; x < ofGetWidth() + size / 2; x += size / 2) {

		y_count = 0;
		for (int y = 0; y < ofGetHeight(); y += size) {

			tri_color.setHsb(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.005) * 255, 255, 255);
			ofSetColor(tri_color);

			
			if (x % size == 0) {

				if (y_count % 2 == 0) {

					ofDrawTriangle(ofVec3f(x - tri_size / 2, y), ofVec3f(x + tri_size / 2, y), ofVec3f(x, y + tri_size));
				}
				else {

					ofDrawTriangle(ofVec3f(x - tri_size / 2, y + tri_size), ofVec3f(x + tri_size / 2, y + tri_size), ofVec3f(x, y));
				}
			}
			else {

				if (y_count % 2 == 0) {

					ofDrawTriangle(ofVec3f(x - tri_size / 2, y + tri_size), ofVec3f(x + tri_size / 2, y + tri_size), ofVec3f(x, y));
				}
				else {

					ofDrawTriangle(ofVec3f(x - tri_size / 2, y), ofVec3f(x + tri_size / 2, y), ofVec3f(x, y + tri_size));
				}
			}

			y_count++;
		}
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}