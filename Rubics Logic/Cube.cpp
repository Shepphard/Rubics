//
//  Cube.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 10/7/14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

//0 - Current | 1 - left | 2 - Right | 3 - Above | 4 - Below | 5 - Behind

#include "Cube.h"
#include <time.h>

Cube::Cube()
{
    allFaces = new Face[6];
}

Cube::Cube(const Cube &c)
{
    allFaces = new Face[6];
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            allFaces[i].setTileColor(j, c.allFaces[i].getTileColor(j));
        }
    }
}

Cube::~Cube()
{
    delete [] allFaces;
}

const void Cube::moveRight()
{
    
    //Perform necessary rotations
    allFaces[5].rotateLeft();
    allFaces[5].rotateLeft();
    
    allFaces[3].rotateRight();
    
    allFaces[4].rotateLeft();
    
    allFaces[1].rotateLeft();
    allFaces[1].rotateLeft();
    
    //Do the changes
    Face* temp = new Face(allFaces[5]);
    
    allFaces[5] = allFaces[1];
    allFaces[1] = allFaces[0];
    allFaces[0] = allFaces[2];
    allFaces[2] = *temp;
}

const void Cube::moveLeft()
{
    //1 Turn Left = 3 Turns Right
    this->moveRight();
    this->moveRight();
    this->moveRight();
}

const void Cube::moveDown()
{
    
    //Perform necessary rotations
    allFaces[1].rotateLeft();
    allFaces[2].rotateRight();
    
    //Do the changes
    Face* temp = new Face(allFaces[3]);
    
    allFaces[3] = allFaces[0];
    allFaces[0] = allFaces[4];
    allFaces[4] = allFaces[5];
    allFaces[5] = *temp;
}

const void Cube::moveBehind()
{
    //Moving behind is going down 2 times
    this->moveDown();
    this->moveDown();
}

const void Cube::moveUp()
{
    //Moving up is going up 2 times
    this->moveDown();
    this->moveDown();
    this->moveDown();
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
                
                
                
                if(colorCount[num] >= 9)
                {
                    cerr << num << " is full. Need to find a new value." << endl;
                }
                else
                {
                    cout << num << endl;
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

    cout << "      ---------" << endl;
    
    cout << "      | " << allFaces[3].getTileColor(0) << " " << allFaces[3].getTileColor(1) << " " << allFaces[3].getTileColor(2) << " |" << endl;
    cout << "      | " << allFaces[3].getTileColor(3) << " " << allFaces[3].getTileColor(4) << " " << allFaces[3].getTileColor(5) << " |" << endl;
    cout << "      | " << allFaces[3].getTileColor(6) << " " << allFaces[3].getTileColor(7) << " " << allFaces[3].getTileColor(8) << " |" << endl;
    
    cout << "---------------------" << endl;
    
    cout << allFaces[1].getTileColor(0) << " " << allFaces[1].getTileColor(1) << " " << allFaces[1].getTileColor(2) << " | "
         << allFaces[0].getTileColor(0) << " " << allFaces[0].getTileColor(1) << " " << allFaces[0].getTileColor(2) << " | "
         << allFaces[2].getTileColor(0) << " " << allFaces[2].getTileColor(1) << " " << allFaces[2].getTileColor(2) << endl;
    
    cout << allFaces[1].getTileColor(3) << " " << allFaces[1].getTileColor(4) << " " << allFaces[1].getTileColor(5) << " | "
         << allFaces[0].getTileColor(3) << " " << allFaces[0].getTileColor(4) << " " << allFaces[0].getTileColor(5) << " | "
         << allFaces[2].getTileColor(3) << " " << allFaces[2].getTileColor(4) << " " << allFaces[2].getTileColor(5) << endl;
    
    cout << allFaces[1].getTileColor(6) << " " << allFaces[1].getTileColor(7) << " " << allFaces[1].getTileColor(8) << " | "
         << allFaces[0].getTileColor(6) << " " << allFaces[0].getTileColor(7) << " " << allFaces[0].getTileColor(8) << " | "
         << allFaces[2].getTileColor(6) << " " << allFaces[2].getTileColor(7) << " " << allFaces[2].getTileColor(8) << endl;
    
    cout << "---------------------" << endl;
    
    cout << "      | " << allFaces[4].getTileColor(0) << " " << allFaces[4].getTileColor(1) << " " << allFaces[4].getTileColor(2) << " |" << endl;
    cout << "      | " << allFaces[4].getTileColor(3) << " " << allFaces[4].getTileColor(4) << " " << allFaces[4].getTileColor(5) << " |" << endl;
    cout << "      | " << allFaces[4].getTileColor(6) << " " << allFaces[4].getTileColor(7) << " " << allFaces[4].getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << "      | " << allFaces[5].getTileColor(0) << " " << allFaces[5].getTileColor(1) << " " << allFaces[5].getTileColor(2) << " |" << endl;
    cout << "      | " << allFaces[5].getTileColor(3) << " " << allFaces[5].getTileColor(4) << " " << allFaces[5].getTileColor(5) << " |" << endl;
    cout << "      | " << allFaces[5].getTileColor(6) << " " << allFaces[5].getTileColor(7) << " " << allFaces[5].getTileColor(8) << " |" << endl;
    
    cout << "      ---------" << endl;
    
    cout << endl;
    
    
    
    
    
    
    
    
    
}