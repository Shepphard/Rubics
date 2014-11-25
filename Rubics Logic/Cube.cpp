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
<<<<<<< HEAD
    int c = 0;
=======
>>>>>>> FETCH_HEAD
    allFaces = new Face[6];
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            allFaces[i].setTileColor(j, c);
        }
        c++;
    }
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

void Cube::leftColUp()
{
    Face* temp = new Face(allFaces[3]);
    
    allFaces[1].rotateLeft();
    
    allFaces[3].setTileColor(0, allFaces[0].getTileColor(0));
    allFaces[3].setTileColor(3, allFaces[0].getTileColor(3));
    allFaces[3].setTileColor(6, allFaces[0].getTileColor(6));
    
    allFaces[0].setTileColor(0, allFaces[4].getTileColor(0));
    allFaces[0].setTileColor(3, allFaces[4].getTileColor(3));
    allFaces[0].setTileColor(6, allFaces[4].getTileColor(6));
    
    allFaces[4].setTileColor(0, allFaces[5].getTileColor(0));
    allFaces[4].setTileColor(3, allFaces[5].getTileColor(3));
    allFaces[4].setTileColor(6, allFaces[5].getTileColor(6));
    
    allFaces[5].setTileColor(0, temp->getTileColor(0));
    allFaces[5].setTileColor(3, temp->getTileColor(3));
    allFaces[5].setTileColor(6, temp->getTileColor(6));
}

void Cube::middleColUp()
{
    Face* temp = new Face(allFaces[3]);
    
    allFaces[3].setTileColor(1, allFaces[0].getTileColor(1));
    allFaces[3].setTileColor(4, allFaces[0].getTileColor(4));
    allFaces[3].setTileColor(7, allFaces[0].getTileColor(7));
    
    allFaces[0].setTileColor(1, allFaces[4].getTileColor(1));
    allFaces[0].setTileColor(4, allFaces[4].getTileColor(4));
    allFaces[0].setTileColor(7, allFaces[4].getTileColor(7));
    
    allFaces[4].setTileColor(1, allFaces[5].getTileColor(1));
    allFaces[4].setTileColor(4, allFaces[5].getTileColor(4));
    allFaces[4].setTileColor(7, allFaces[5].getTileColor(7));
    
    allFaces[5].setTileColor(1, temp->getTileColor(1));
    allFaces[5].setTileColor(4, temp->getTileColor(4));
    allFaces[5].setTileColor(7, temp->getTileColor(7));
}

void Cube::rightColUp()
{
    Face* temp = new Face(allFaces[3]);
    
    allFaces[2].rotateRight();
    
    allFaces[3].setTileColor(2, allFaces[0].getTileColor(2));
    allFaces[3].setTileColor(5, allFaces[0].getTileColor(5));
    allFaces[3].setTileColor(8, allFaces[0].getTileColor(8));
    
    allFaces[0].setTileColor(2, allFaces[4].getTileColor(2));
    allFaces[0].setTileColor(5, allFaces[4].getTileColor(5));
    allFaces[0].setTileColor(8, allFaces[4].getTileColor(8));
    
    allFaces[4].setTileColor(2, allFaces[5].getTileColor(2));
    allFaces[4].setTileColor(5, allFaces[5].getTileColor(5));
    allFaces[4].setTileColor(8, allFaces[5].getTileColor(8));
    
    allFaces[5].setTileColor(2, temp->getTileColor(2));
    allFaces[5].setTileColor(5, temp->getTileColor(5));
    allFaces[5].setTileColor(8, temp->getTileColor(8));
}

void Cube::leftColDown()
{
    this->leftColUp();
    this->leftColUp();
    this->leftColUp();
}

void Cube::middleColDown()
{
    this->middleColUp();
    this->middleColUp();
    this->middleColUp();
}

void Cube::rightColDown()
{
    this->rightColUp();
    this->rightColUp();
    this->rightColUp();
}

void Cube::upperRowLeft()
{
    Face* temp = new Face(allFaces[0]);
    
    allFaces[3].rotateRight();
    
    allFaces[0].setTileColor(0, allFaces[2].getTileColor(0));
    allFaces[0].setTileColor(1, allFaces[2].getTileColor(1));
    allFaces[0].setTileColor(2, allFaces[2].getTileColor(2));
    
    allFaces[2].setTileColor(0, allFaces[5].getTileColor(8));
    allFaces[2].setTileColor(1, allFaces[5].getTileColor(7));
    allFaces[2].setTileColor(2, allFaces[5].getTileColor(6));
    
    allFaces[5].setTileColor(8, allFaces[1].getTileColor(0));
    allFaces[5].setTileColor(7, allFaces[1].getTileColor(1));
    allFaces[5].setTileColor(6, allFaces[1].getTileColor(2));
    
    allFaces[1].setTileColor(0, temp->getTileColor(0));
    allFaces[1].setTileColor(1, temp->getTileColor(1));
    allFaces[1].setTileColor(2, temp->getTileColor(2));

}

void Cube::middleRowLeft()
{
    Face* temp = new Face(allFaces[0]);
    
    allFaces[0].setTileColor(3, allFaces[2].getTileColor(3));
    allFaces[0].setTileColor(4, allFaces[2].getTileColor(4));
    allFaces[0].setTileColor(5, allFaces[2].getTileColor(5));
    
    allFaces[2].setTileColor(3, allFaces[5].getTileColor(5));
    allFaces[2].setTileColor(4, allFaces[5].getTileColor(4));
    allFaces[2].setTileColor(5, allFaces[5].getTileColor(3));
    
    allFaces[5].setTileColor(5, allFaces[1].getTileColor(3));
    allFaces[5].setTileColor(4, allFaces[1].getTileColor(4));
    allFaces[5].setTileColor(3, allFaces[1].getTileColor(5));
    
    allFaces[1].setTileColor(3, temp->getTileColor(3));
    allFaces[1].setTileColor(4, temp->getTileColor(4));
    allFaces[1].setTileColor(5, temp->getTileColor(5));
    
}

void Cube::lowerRowLeft()
{
    Face* temp = new Face(allFaces[0]);
    
    allFaces[4].rotateLeft();
    
    allFaces[0].setTileColor(6, allFaces[2].getTileColor(6));
    allFaces[0].setTileColor(7, allFaces[2].getTileColor(7));
    allFaces[0].setTileColor(8, allFaces[2].getTileColor(8));
    
    allFaces[2].setTileColor(6, allFaces[5].getTileColor(2));
    allFaces[2].setTileColor(7, allFaces[5].getTileColor(1));
    allFaces[2].setTileColor(8, allFaces[5].getTileColor(0));
    
    allFaces[5].setTileColor(2, allFaces[1].getTileColor(6));
    allFaces[5].setTileColor(1, allFaces[1].getTileColor(7));
    allFaces[5].setTileColor(0, allFaces[1].getTileColor(8));
    
    allFaces[1].setTileColor(6, temp->getTileColor(6));
    allFaces[1].setTileColor(7, temp->getTileColor(7));
    allFaces[1].setTileColor(8, temp->getTileColor(8));
    
}

void Cube::upperRowRight()
{
    this->upperRowLeft();
    this->upperRowLeft();
    this->upperRowLeft();
}

void Cube::middleRowRight()
{
    this->middleRowLeft();
    this->middleRowLeft();
    this->middleRowLeft();
}

void Cube::lowerRowRight()
{
    this->lowerRowLeft();
    this->lowerRowLeft();
    this->lowerRowLeft();
}

void Cube::shuffle()
{
<<<<<<< HEAD
    int num = 0;
    
    for(int i = 0; i < 200; i++)
    {
        num = std::rand() % 17;
        
        switch(num)
        {
            case 0: moveRight(); break;
            case 1: moveLeft(); break;
            case 2: moveUp(); break;
            case 3: moveDown(); break;
            case 4: moveBehind(); break;
            case 5: leftColUp(); break;
            case 6: leftColDown(); break;
            case 7: middleColUp(); break;
            case 8: middleColDown(); break;
            case 9: rightColUp(); break;
            case 10: rightColDown(); break;
            case 11: upperRowLeft(); break;
            case 12: upperRowRight(); break;
            case 13: middleRowLeft(); break;
            case 14: middleRowRight(); break;
            case 15: lowerRowLeft(); break;
            case 16: lowerRowRight(); break;
            default: moveRight(); break;
        }
    }
    /*
=======
    
>>>>>>> FETCH_HEAD
    //Initialize the randomizer with the time (first cast of time to uInt)
    srand((unsigned int)std::time(0));
    
    //Array to count to 9 for color 0-5, there alway only are 9 tiles of the same color
    int* colorCount = new int[6];
    
    //Count through the Faces of the Cube (6 in Total)
    for(int k = 0; k < 6; k++)
    {
        //Count through the Tiles of the Face (9 in Total)
        for(int i = 0; i < 9; i++)
        {
            
            bool valid = false; // boolean that says if the current number selected for the tiles is valid.
            
            int num = 0;//The current number
            
            //As long as we haven't found a valid number
            do
            {
                //Get a random number, mod 6 to get a number between 0 and 5
                num = std::rand() % 6;
                
                //If the colorCount for that number is too big (>=9) we need to find a new value.
                if(colorCount[num] >= 9)
                {
                    cerr << num << " is full. Need to find a new value." << endl;
                }
                else //we set valid as true and we fall out of the loop
                {
                    cout << num << endl;
                    valid = true;
                }
            }while(!valid);
            
            //We set the colorCount for that number +1;
            colorCount[num]++;
            
            //The current Face will get the color "num" for the current Tile
            allFaces[k].setTileColor(i, num);
        }
    }*/
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