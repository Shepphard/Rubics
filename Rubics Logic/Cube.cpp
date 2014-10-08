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

const void Cube::moveRight()
{
    Face* temp;
    
    //Perform necessary rotations
    behindFace = behindFace->rotateLeft();
    behindFace = behindFace->rotateLeft();
    aboveFace = aboveFace->rotateRight();
    belowFace = belowFace->rotateLeft();
    
    temp = behindFace;
    
    leftFace = currentFace;
    currentFace = rightFace;
    rightFace = temp;
}

void Cube::shuffle()
{
    currentFace->shuffle();
    aboveFace->shuffle();
    rightFace->shuffle();
    leftFace->shuffle();
    belowFace->shuffle();
    behindFace->shuffle();
}

void Cube::show()
{
    cout << "      ---------" << endl;
    
    cout << "      | " << aboveFace->getTileColor(0) << " " << aboveFace->getTileColor(1) << " " << aboveFace->getTileColor(2) << " |" << endl;
    cout << "      | " << aboveFace->getTileColor(3) << " " << aboveFace->getTileColor(4) << " " << aboveFace->getTileColor(5) << " |" << endl;
    cout << "      | " << aboveFace->getTileColor(6) << " " << aboveFace->getTileColor(7) << " " << aboveFace->getTileColor(8) << " |" << endl;
    
    cout << "---------------------" << endl;
    
    cout << leftFace->getTileColor(0) << " " << leftFace->getTileColor(1) << " " << leftFace->getTileColor(2) << " | "
         << currentFace->getTileColor(0) << " " << currentFace->getTileColor(1) << " " << currentFace->getTileColor(2) << " | "
         << rightFace->getTileColor(0) << " " << rightFace->getTileColor(1) << " " << rightFace->getTileColor(2) << endl;
    cout << leftFace->getTileColor(3) << " " << leftFace->getTileColor(4) << " " << leftFace->getTileColor(5) << " | "
         << currentFace->getTileColor(3) << " " << currentFace->getTileColor(4) << " " << currentFace->getTileColor(5) << " | "
         << rightFace->getTileColor(3) << " " << rightFace->getTileColor(4) << " " << rightFace->getTileColor(5) << endl;
    cout << leftFace->getTileColor(6) << " " << leftFace->getTileColor(7) << " " << leftFace->getTileColor(8) << " | "
         << currentFace->getTileColor(6) << " " << currentFace->getTileColor(7) << " " << currentFace->getTileColor(8) << " | "
         << rightFace->getTileColor(6) << " " << rightFace->getTileColor(7) << " " << rightFace->getTileColor(8) << endl;
    
    cout << "---------------------" << endl;
    
    cout << "      | " << belowFace->getTileColor(0) << " " << belowFace->getTileColor(1) << " " << belowFace->getTileColor(2) << " |" << endl;
    cout << "      | " << belowFace->getTileColor(3) << " " << belowFace->getTileColor(4) << " " << belowFace->getTileColor(5) << " |" << endl;
    cout << "      | " << belowFace->getTileColor(6) << " " << belowFace->getTileColor(7) << " " << belowFace->getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << "      | " << behindFace->getTileColor(0) << " " << behindFace->getTileColor(1) << " " << behindFace->getTileColor(2) << " |" << endl;
    cout << "      | " << behindFace->getTileColor(3) << " " << behindFace->getTileColor(4) << " " << behindFace->getTileColor(5) << " |" << endl;
    cout << "      | " << behindFace->getTileColor(6) << " " << behindFace->getTileColor(7) << " " << behindFace->getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << endl;
    
    
    
    
    
    
    
    
    
}