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

// Destructor
Face::~Face()
{
    delete [] f_tiles;
}

// Rotate whole face by -90°
Face* Face::rotateRight()
{
    Face* temp = new Face();
    
    temp->setTileColor(0, this->getTileColor(6));
    temp->setTileColor(1, this->getTileColor(3));
    temp->setTileColor(2, this->getTileColor(0));
    
    temp->setTileColor(3, this->getTileColor(7));
    temp->setTileColor(4, this->getTileColor(4));
    temp->setTileColor(5, this->getTileColor(1));
    
    temp->setTileColor(6, this->getTileColor(8));
    temp->setTileColor(7, this->getTileColor(5));
    temp->setTileColor(8, this->getTileColor(2));
    
    return temp;
    
}

//Rotate face by 90°
Face* Face::rotateLeft()
{
    Face* temp = new Face();
    
    temp->setTileColor(0, this->getTileColor(2));
    temp->setTileColor(1, this->getTileColor(5));
    temp->setTileColor(2, this->getTileColor(8));
    
    temp->setTileColor(3, this->getTileColor(1));
    temp->setTileColor(4, this->getTileColor(4));
    temp->setTileColor(5, this->getTileColor(7));
    
    temp->setTileColor(6, this->getTileColor(0));
    temp->setTileColor(7, this->getTileColor(3));
    temp->setTileColor(8, this->getTileColor(6));
    
    return temp;
}

int Face::getTileColor(int index) const
{
    return f_tiles[index].getColor();
}

void Face::setTileColor(int index, int color)
{
    f_tiles[index].setColor(color);
}




////////////////////////////////////////////
void Face::shuffle()
{
    int counter = 0;
    for(int i = 0; i < 9; i++)
    {
        f_tiles[i].setColor(counter++);
    }
}

void Face::printFace()
{
    
    for(int i = 0; i < 9; i++)
    {
        if(i%3 == 0)
            cout << endl;
        
        cout << f_tiles[i].getColor() << " ";
        
    }
    
    cout << endl;
}