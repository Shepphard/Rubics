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
    
    Cube* cube = new Cube();
    cube->show();
    
    cube->shuffle();

    cube->show();

    cube->show();

    cube->leftColUp();

    cube->show();
    
    return 0;
}
