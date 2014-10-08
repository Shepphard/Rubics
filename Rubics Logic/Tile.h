//
//  Tile.h
//  Rubics Logic
//
//  A Tile is the simplest Element of the Rubics Cube.
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#ifndef __Rubics_Logic__Tile__
#define __Rubics_Logic__Tile__

#include <stdio.h>

#endif /* defined(__Rubics_Logic__Tile__) */

class Tile
{
private:
    int t_color; //The Color of the Tile
    
public:
    //Standard Constructors
    Tile();
    
    //Constructor
    Tile(int c);

    //Set the Color of the Tile
    void setColor(char c){t_color = c;}
    
    int getColor();
};