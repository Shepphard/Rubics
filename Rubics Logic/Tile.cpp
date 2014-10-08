//
//  Tile.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include "Tile.h"

Tile::Tile(int c)
{
    t_color = c;
}

Tile::Tile()
{
    t_color = -1; // Default Value -1
}

int Tile::getColor()
{
    return t_color;
}