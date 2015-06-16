#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
//#include "window.h"

#define MAX_COLUMN 10
#define MAX_ROW 15

class Grid{
	Cell **theGrid;
	TextDisplay *td;
	//Xwindow *xw;
    Level *myLevel;
	Block *currentBlock;
	Block *nextBlock;
	int curScore;
	int hiScore;
	void clearGrid();   // done
    // bool isFull;                    // new
public:
	Grid();       			  // done
	~Grid();      			  // done
	void restart(); 		  // done
	void newLevel(int lev);           // ???
	int getScore(); 		  //done
	void DrawText();   	          // done
	bool checkLine(int row);          // done
	void checkGrid(); 		  // done
	void removeLine(int row);         //done
    void init();                      // new //done
	void initBlock(Block *cur);            //done
   void cleanBlock();
   void generateBlock();  
   bool checkPos(std::string commd, std::string op);     
   void skip(); 
   Block* getCurBlock();
    friend std::ostream &operator<<(std::ostream &out, const Grid &board);
};

#endif
