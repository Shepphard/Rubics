//
//  Tile.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include "Tile.h"

Tile::Tile(int color)
{
    t_color = color;
}

Tile::Tile()
{
    t_color = -1; // Default Value -1
}

void Tile::setColor(int const color)
{
    t_color = color;
}

int Tile::getColor() const
{
    return t_color;
}