//
//  Level1.cpp
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#include <iostream>
#include "level1.h"
#include "block.h"
#include <cstdlib>
using namespace std;

static int mem[12] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
static int seek = 0;

Level1::Level1():Level(1){}

bool checking1(int i){
    for (int j = 0; j < 12; j++) {
        if (mem[j] == i) return true;
    }
    return false;
}

void checkmem1() {
    bool id = true;
    for (int j = 0; j < 12; j++) {
        if (mem[j] == 12) {
            id = false;
            break;
        }
        else id = true;
    }
    if (id) {
        for (int j = 0; j < 12; j++) mem[j] = 12;
    }
}

Block* Level1::getNextBlock(){
    int count = 12;
    char sequent[] = {'I', 'J', 'O', 'S', 'Z', 'T', 'L', 'I', 'J', 'O', 'T', 'L'};
    unsigned long colseq[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 7};
    int buf = rand() % count;
    while (true) {
        if (checking1(buf)) {
            buf = rand() % count;
            continue;
        }
        else {
            mem[seek++] = buf;
            break;
        }
    }
    seek = seek % 12;
    checkmem1();
    Block *init = new Block(sequent[buf],colseq[buf]);
    return init;
}
