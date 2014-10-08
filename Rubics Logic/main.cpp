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
    
    Face* f = new Face(3);
    Face* f2 = new Face(3);
    
    f->shuffle();
    f2->shuffle();
    
    f->printFace();
    
    f->rotateLeft(f2, f);
    
    f->printFace();
    
    f->rotateRight(f, f);
    
    f->printFace();
    
    return 0;
}
