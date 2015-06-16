//
//  Level0.h
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include <iostream>
#include "level.h"

class Level0: public Level {
public:
    Level0();
    Block *getNextBlock();
};

#endif
