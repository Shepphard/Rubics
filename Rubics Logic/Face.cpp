//
//  Face.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include "Face.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;



// Create a uniform Face with same color.

Face::Face(int color)
{
    f_tiles = new Tile[9];
    
    for(int i = 0; i < 9; i++)
    {
        f_tiles[i].setColor(color);
    }
}

//Copy Constructor
Face::Face(const Face& f)
{
    f_tiles = new Tile[9];
    
    for(int i = 0; i < 9; i++)
    {
        f_tiles[i].setColor(f.getTileColor(i));
    }
}

// Destructor
Face::~Face()
{
    delete [] f_tiles;
}

// Rotate whole face by -90°
void Face::rotateRight()
{
    //Make temporary copy of the face
    Face* temp = new Face(*this);
    
    //Perform the changes
    this->setTileColor(0, temp->getTileColor(6));
    this->setTileColor(1, temp->getTileColor(3));
    this->setTileColor(2, temp->getTileColor(0));
    
    this->setTileColor(3, temp->getTileColor(7));
    this->setTileColor(4, temp->getTileColor(4));
    this->setTileColor(5, temp->getTileColor(1));
    
    this->setTileColor(6, temp->getTileColor(8));
    this->setTileColor(7, temp->getTileColor(5));
    this->setTileColor(8, temp->getTileColor(2));
    
    delete temp;
}

//Rotate face by 90°
void Face::rotateLeft()
{
    //Make temporary copy of the Face
    Face* temp = new Face(*this);
    
    //Perform the changes
    this->setTileColor(0, temp->getTileColor(2));
    this->setTileColor(1, temp->getTileColor(5));
    this->setTileColor(2, temp->getTileColor(8));
    
    this->setTileColor(3, temp->getTileColor(1));
    this->setTileColor(4, temp->getTileColor(4));
    this->setTileColor(5, temp->getTileColor(7));
    
    this->setTileColor(6, temp->getTileColor(0));
    this->setTileColor(7, temp->getTileColor(3));
    this->setTileColor(8, temp->getTileColor(6));
    
    delete temp;
}

int Face::getTileColor(int index) const
{
    return f_tiles[index].getColor();
}

void Face::setTileColor(int index, int color)
{
    f_tiles[index].setColor(color);
}