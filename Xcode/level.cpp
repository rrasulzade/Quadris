#include <iostream>
#include "block.h"
#include "level.h"
using namespace std;

Level::Level(int current) {curLevel = current;}

Level::~Level() {}

int Level::getLevelNum() {return curLevel;}
