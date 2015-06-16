#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
//#include "window.h"

class Cell {
    bool isFree;
    // int x, y;
    // int height, width;
    // Xwindow *w;
    int r, c;
    char letter; //   new
public:
    Cell();                    // Default constructor
    ~Cell();                   // Default destructor
    int getRow();
    int getCol();
    char getLet();
    void setLet(char let);
    bool getFree();           // Returns the value of isFree.
    void setFree();          // Explicitly sets ..
    void unFree();          // ..
    void setCoords(int r, int c, char letter);
    // void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w); // ...
    void notifyDisplay(TextDisplay &t); // ...
    Cell &operator=(const Cell &other);            // new
    
};
#endif
