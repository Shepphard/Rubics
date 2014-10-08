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
    Tile*** f_tiles;
    
    
public:
    Face();
    Face(int color);
    Face(Face const &f);
    ~Face();
    
    void rotateRight(Face* const f_input, Face* f_output);
    void rotateLeft(Face* const f_input, Face* f_output);
    
    int getTileColor(int row, int col) const;
    void setTileColor(int row, int col, int color);
    
    void shuffle();
    void printFace();

};