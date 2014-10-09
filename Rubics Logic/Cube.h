//
//  Cube.h
//  Rubics Logic
//
//  Created by Philippe Kayser on 10/7/14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#ifndef __Rubics_Logic__Cube__
#define __Rubics_Logic__Cube__

#include <stdio.h>
#include <iostream>
#include "Face.h"
#endif /* defined(__Rubics_Logic__Cube__) */

using namespace std;

class Cube
{
private:
    Face* allFaces;
    
    Face currentFace;
    
    Face aboveFace;
    Face belowFace;
    Face leftFace;
    Face rightFace;
    Face behindFace;
    
public:
    Cube();
    ~Cube();
    
    void shuffle();
    
    //moving to set new active Face
    const void moveRight();
    const void moveLeft();
    const void moveUp();
    const void moveDown();
    const void moveBehind();
    
    //Move the tiles
    void leftColUp();
    void leftColDown();
    void middleColUp();
    void middleColDown();
    void rightColUp();
    void rightColDown();
    
    void upperRowLeft();
    void upperRowRight();
    void middleRowLeft();
    void middleRowRight();
    void lowerRowLeft();
    void lowerRowRight();
    
    void show();
    
};