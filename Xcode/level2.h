//
//  Level2.h
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include <iostream>
#include "level.h"

class Level2: public Level {
public:
    Level2();
    Block *getNextBlock();
};

#endif
