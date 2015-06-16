//
//  Level3.h
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include <iostream>
#include "level.h"

class Level3: public Level {
public:
    Level3();
    Block *getNextBlock();
};

#endif
