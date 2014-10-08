//
//  main.cpp
//  Rubics Logic
//
//  Created by Philippe Kayser on 07.10.14.
//  Copyright (c) 2014 Philippe Kayser. All rights reserved.
//

#include <iostream>
#include "Cube.h"

int main(int argc, const char * argv[]) {
    
    Face* f = new Face();
    
    f->printFace();
    
    f->shuffle();
    
    f->printFace();
    
    f = f->rotateRight();
    
    f->printFace();
    
    f = f->rotateLeft();
    f = f->rotateLeft();
    
    f->printFace();
    
    return 0;
}
