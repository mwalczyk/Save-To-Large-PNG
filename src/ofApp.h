#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();    
    void keyPressed(int key);

    const int NUM_CIRCLES_X = 10;
    const int NUM_CIRCLES_Y = 18;
    const int PRINT_WIDTH = 1080;
    const int PRINT_HEIGHT = 1920;
    
    ofFbo       fbo;
    ofPixels    pixels;
    
};
