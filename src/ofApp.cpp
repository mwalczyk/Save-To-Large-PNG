#include "ofApp.h"

void ofApp::setup()
{
    // First, allocate space for the FBO - set these values to the width and height you want to print
    fbo.allocate(PRINT_WIDTH, PRINT_HEIGHT);
    fbo.begin();
    ofClear(0, 0, 0, 255);
    fbo.end();
    
    // Then, allocate the same amount of space for your ofPixels
    pixels.allocate(PRINT_WIDTH, PRINT_HEIGHT, OF_IMAGE_COLOR_ALPHA);
}

void ofApp::update()
{

}

void ofApp::draw()
{
    fbo.begin(); //----Anything you want to be in the final print should go in between this begin() and end()
    
    // Draw a grid of white circles into the FBO
    int xSpacing = fbo.getWidth() / NUM_CIRCLES_X;
    int ySpacing = fbo.getHeight() / NUM_CIRCLES_Y;
    
    for (int i = 0; i < NUM_CIRCLES_Y; ++i)
    {
        for (int j = 0; j < NUM_CIRCLES_X; ++j)
        {
            ofDrawCircle(j * xSpacing + xSpacing / 2, i * ySpacing + ySpacing / 2, 10);
        }
    }
    
    fbo.end(); //----Anything you want to be in the final print should go in between this begin() and end()
    
    
    // Finally, draw the FBO onto the screen - it will be cut off (because our monitor isn't big enough
    // to display the whole thing), but that's OK
    fbo.draw(0, 0);
}

void ofApp::keyPressed(int key)
{
    // Press 's' to save the screen
    if(key =='s')
    {
        cout << "Saving...\n";
        fbo.readToPixels(pixels);
        ofSaveImage(pixels, "Test_Image.png", OF_IMAGE_QUALITY_BEST);
    }
}


