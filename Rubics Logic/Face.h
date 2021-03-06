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
#include <string>

#endif /* defined(__Rubics_Logic__Face__) */

class Face
{
private:
    Tile* f_tiles;
    
    
public:
    //Konstruktoren und Destruktoren
    Face(int color = -1);
    Face(const Face& f);
    ~Face();
    
    
    //Face Rotation
    void rotateRight();
    void rotateLeft();
    
    //Get Tile and Set Tile Color at specific row and col
    int getTileColor(int index) const;
    void setTileColor(int index, int color);
};