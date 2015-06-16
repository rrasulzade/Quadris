#include <iostream>
#include <fstream>
#include "level0.h"
#include "block.h"
#include <string>
using namespace std;

static int mem = 0;

Level0::Level0():Level(0){}

Block* Level0::getNextBlock(){
    string take;
    ifstream seq;
    seq.open("sequence.txt");
    
   
    string sequent; // = "IJOSZTL";

    seq >> take;
   
    while (!seq.eof()) {
     sequent += take;
     seq >> take;
    }
 
    seq.close();
    unsigned long color = mem + 1;
    Block *init = new Block(sequent[mem++],color);
    if (mem == 7) {mem = 0;}
    return init;
}

/*
Block* Level0::getNextBlock(){
    string take;
    string buf = ""; // = "IJOSZTL";
    ifstream seq;
    seq.open("sequence.txt");
    while (seq >> take) {buf += take;}
    seq.close();
    unsigned long color = mem;
    Block *init = new Block(buf[mem++],color);
    if (mem == 7) {mem = 0;}
    return init;
}*/
