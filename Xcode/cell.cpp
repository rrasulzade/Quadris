#include <iostream>
#include <string>
#include <cstdlib>
#include "cell.h"

using namespace std;

// Default constructor
Cell::Cell() {
    isFree = true;
}

// Default destructor
Cell::~Cell() {}


bool Cell::getFree() {return isFree;}



void Cell::setFree() {
    isFree = true;
    letter = ' ';
}

void Cell::unFree() { isFree = false;}

void Cell::setCoords(int r, int c, char letter) {
    this->r = r;
    this->c = c;
    this->letter = letter;
}

/* void Cell::setCoords(int r, int c, int x, int y, int width, int height, char letter, Xwindow *w) {
 this->r = r;
 this->c = c;
 this->x = x;
 this->y = y;
 this->width = width;
 this->height = height;
 this->w = w;
 this->letter = letter;
 }
 */

void Cell::notifyDisplay(TextDisplay &t){
    t.notify(r, c, letter);
}


Cell& Cell::operator=(const Cell &other) {
    if(this == &other) { return *this; }
    letter = other.letter;
    isFree = other.isFree;
    c = other.c;
    r = other.r;
    
    return *this;
}


int Cell::getRow() { return r; }

int Cell::getCol() {return c; }

char Cell::getLet() {return letter; }


void Cell::setLet(char let) { this->letter = let;
}

