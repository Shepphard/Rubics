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



/*
 Create a uniform Face with same color.
 */
Face::Face(int color)
{
    f_tiles = new Tile**[3];
    
    for(int i = 0; i < 3; i++)
    {
        f_tiles[i] = new Tile*[3];
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f_tiles[i][j] = new Tile(color);
        }
    }
}

Face::Face(Face const &f)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f.f_tiles[i][j]->setColor(f_tiles[i][j]->getColor());
        }
    }
}

/*
 Create uniform Face with Default Color
 */
Face::Face()
{
    Face(-1);
}

// Destructor
Face::~Face()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            delete [] f_tiles[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        delete [] f_tiles[i];
    }
    delete [] f_tiles;
}


void Face::rotateRight(Face* const f_input, Face* f_output)
{
    Face* temp = f_input;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f_output->setTileColor(i, j, f_input->getTileColor(2-j, i));
        }
    }
}

//Rotate the faces
void Face::rotateLeft(Face* const f_input, Face* f_output)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f_output->setTileColor(i, j, f_input->getTileColor(j, 2-i));
        }
    }
}

int Face::getTileColor(int row, int col) const
{
    return f_tiles[row][col]->getColor();
}

void Face::setTileColor(int row, int col, int color)
{
    f_tiles[row][col]->setColor(color);
}

void Face::shuffle()
{
    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f_tiles[i][j]->setColor(counter++);
        }
    }
}

void Face::printFace()
{
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << f_tiles[i][j]->getColor() << " ";
            if(j == 2)
                cout << endl;
        }
    }
    cout << endl;
}