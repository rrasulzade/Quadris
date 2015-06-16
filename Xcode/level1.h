//
//  Level1.h
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//
#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include <iostream>
#include "level.h"

class Level1: public Level {
public:
    Level1();
    Block *getNextBlock();
};

#endif
