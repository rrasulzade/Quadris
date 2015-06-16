//
//  Level.h
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <iostream>

class Block;

class Level{
    int curLevel;
public:
    Level(int current);
    virtual ~Level() = 0;
    int getLevelNum();
    virtual Block *getNextBlock() = 0;
};

#endif
