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

//Rotate the faces
void Face::rotateLeft()
{
    Tile*** temp = f_tiles;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            f_tiles[i][j] = temp[2-j][i];
        }
    }
}


void Face::rotateRight()
{
    Tile*** temp = f_tiles;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp[i][j] = f_tiles[j][2-i];
        }
    }
}

void Face::setTileColor(int r, int c, int color)
{
    f_tiles[r][c]->setColor(color);
}

void Face::printFace()
{
    string s = "";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << f_tiles[i][j]->getColor() << " ";
            if(j == 2)
            {
                cout << endl;
            }
        }
    }
    
    cout << s << endl;
}

void Face::printEmpty()
{
    string s = "";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout  << "- ";
            if(j == 2)
            {
                cout << endl;
            }
        }
    }
    
    cout << s << endl;
}