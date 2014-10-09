//
//  Cube.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 10/7/14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include "Cube.h"
#include <time.h>
Cube::Cube()
{
    //0 - Current | 1 - left | 2 - Right | 3 - Above | 4 - Below | 5 - Behind
    allFaces = new Face[6];
}

Cube::~Cube()
{
    delete [] allFaces;
}

const void Cube::moveRight()
{
    Face temp;
    
    //Perform necessary rotations
    allFaces[5] = *allFaces[5].rotateLeft();
    allFaces[5] = *allFaces[5].rotateLeft();
    allFaces[3] = *allFaces[3].rotateRight();
    allFaces[4] = *allFaces[4].rotateLeft();
    allFaces[1] = *allFaces[1].rotateLeft();
    allFaces[1] = *allFaces[1].rotateLeft();
    
    temp = allFaces[5];
    
    allFaces[5] = allFaces[1];
    allFaces[1] = allFaces[0];
    allFaces[0] = allFaces[2];
    allFaces[2] = temp;
}

void Cube::shuffle()
{
    srand((unsigned int)std::time(0));
    int* colorCount = new int[6];
    
    for(int k = 0; k < 6; k++)
    {
        for(int i = 0; i < 9; i++)
        {
            bool valid = false;
            int num = 0;
            
            while(!valid)
            {
                num = std::rand() % 6;
                
                cout << num << endl;
                
                if(colorCount[num] >= 9)
                {
                    cerr << num << " is full. Need to find a new value." << endl;
                }
                else
                {
                    valid = true;
                }
            }
            colorCount[num]++;
            allFaces[k].setTileColor(i, num);
        }
    }
}

void Cube::show()
{
    currentFace = allFaces[0];
    leftFace = allFaces[1];
    rightFace = allFaces[2];
    aboveFace = allFaces[3];
    belowFace = allFaces[4];
    behindFace =
    
    allFaces[5];
    
    
    cout << "      ---------" << endl;
    
    cout << "      | " << aboveFace.getTileColor(0) << " " << aboveFace.getTileColor(1) << " " << aboveFace.getTileColor(2) << " |" << endl;
    cout << "      | " << aboveFace.getTileColor(3) << " " << aboveFace.getTileColor(4) << " " << aboveFace.getTileColor(5) << " |" << endl;
    cout << "      | " << aboveFace.getTileColor(6) << " " << aboveFace.getTileColor(7) << " " << aboveFace.
    getTileColor(8) << " |" << endl;
    
    cout << "---------------------" << endl;
    
    cout << leftFace.getTileColor(0) << " " << leftFace.getTileColor(1) << " " << leftFace.getTileColor(2) << " | "
         << currentFace.getTileColor(0) << " " << currentFace.getTileColor(1) << " " << currentFace.getTileColor(2) << " | "
         << rightFace.getTileColor(0) << " " << rightFace.getTileColor(1) << " " << rightFace.getTileColor(2) << endl;
    cout << leftFace.getTileColor(3) << " " << leftFace.getTileColor(4) << " " << leftFace.getTileColor(5) << " | "
         << currentFace.getTileColor(3) << " " << currentFace.getTileColor(4) << " " << currentFace.getTileColor(5) << " | "
         << rightFace.getTileColor(3) << " " << rightFace.getTileColor(4) << " " << rightFace.getTileColor(5) << endl;
    cout << leftFace.getTileColor(6) << " " << leftFace.getTileColor(7) << " " << leftFace.getTileColor(8) << " | "
         << currentFace.getTileColor(6) << " " << currentFace.getTileColor(7) << " " << currentFace.getTileColor(8) << " | "
         << rightFace.getTileColor(6) << " " << rightFace.getTileColor(7) << " " << rightFace.getTileColor(8) << endl;
    
    cout << "---------------------" << endl;
    
    cout << "      | " << belowFace.getTileColor(0) << " " << belowFace.getTileColor(1) << " " << belowFace.getTileColor(2) << " |" << endl;
    cout << "      | " << belowFace.getTileColor(3) << " " << belowFace.getTileColor(4) << " " << belowFace.getTileColor(5) << " |" << endl;
    cout << "      | " << belowFace.getTileColor(6) << " " << belowFace.getTileColor(7) << " " << belowFace.getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << "      | " << behindFace.getTileColor(0) << " " << behindFace.getTileColor(1) << " " << behindFace.getTileColor(2) << " |" << endl;
    cout << "      | " << behindFace.getTileColor(3) << " " << behindFace.getTileColor(4) << " " << behindFace.getTileColor(5) << " |" << endl;
    cout << "      | " << behindFace.getTileColor(6) << " " << behindFace.getTileColor(7) << " " << behindFace.getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << endl;
    
    
    
    
    
    
    
    
    
}