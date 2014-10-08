//
//  Cube.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 10/7/14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include "Cube.h"

Cube::Cube()
{
    currentFace = new Face(0); //green
    aboveFace = new Face(1); //blue
    belowFace = new Face(2); //white
    leftFace = new Face(3); //yellow
    rightFace = new Face(4); //red
    behindFace = new Face(5); //orange
    
    shuffle();
}

Cube::~Cube()
{
    delete currentFace;
    delete aboveFace;
    delete belowFace;
    delete leftFace;
    delete rightFace;
    delete behindFace;
}

void Cube::shuffle()
{
    currentFace->setTileColor(0, 0, 0);
    currentFace->setTileColor(0, 1, 1);
    currentFace->setTileColor(0, 2, 2);
    
    currentFace->setTileColor(1, 0, 3);
    currentFace->setTileColor(1, 1, 4);
    currentFace->setTileColor(1, 2, 5);
    
    currentFace->setTileColor(2, 0, 6);
    currentFace->setTileColor(2, 1, 7);
    currentFace->setTileColor(2, 2, 8);
    
    currentFace->printFace();
    
    //currentFace->rotateRight();
    
    currentFace->printFace();
}

const void Cube::moveRight()
{
    Face* temp = rightFace;
    
    rightFace  = currentFace;
    currentFace = leftFace;
    
    leftFace = behindFace;
   // leftFace->rotateLeft();
    //leftFace->rotateLeft();
    
    //aboveFace->rotateLeft();
    //belowFace->rotateRight();
    
    //temp->rotateRight();
    //temp->rotateRight();
    behindFace=temp;
}