//
//  Face.h
//  Rubics Logic
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#ifndef __Rubics_Logic__Face__
#define __Rubics_Logic__Face__

#include <stdio.h>
#include "Tile.h"
#include <string.h>

#endif /* defined(__Rubics_Logic__Face__) */

class Face
{
private:
    Tile*** f_tiles;
public:
    Face();
    Face(int color);
    ~Face();
    
    void rotateRight();
    void rotateLeft();
    
    void setTileColor(int r, int c, int color);
    void printFace();
    void printEmpty();
};