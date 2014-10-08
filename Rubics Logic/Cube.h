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
#include "Face.h"
#endif /* defined(__Rubics_Logic__Cube__) */

class Cube
{
private:
    Face* currentFace;
    
    Face* aboveFace;
    Face* belowFace;
    Face* leftFace;
    Face* rightFace;
    Face* behindFace;
    
    
    
public:
    Cube();
    ~Cube();
    
    void shuffle();
    
    const void moveRight();
    const void moveLeft();
    const void moveUp();
    const void moveDown();
    const void moveBehind();
    
};