#include <iostream>
#include <string>
#include <cstdlib>
#include "grid.h"

using namespace std;


// Default constructor
Grid::Grid() {
    //  isFull = false;
    td = new TextDisplay;
    hiScore = 0;
    curScore = 0;
    //  xw = new Xwindow;

    
    myLevel = new Level1();
    
    currentBlock = myLevel->getNextBlock();
    nextBlock = myLevel->getNextBlock();
    init();
    initBlock(currentBlock);
}


// Default destructor
Grid::~Grid() {
    clearGrid();
    delete td;
    // delete xw;
}


// creates new Grid and TextDisplay of length n
// and mutates all coordinates of the Grid using setCoords

void Grid::init(){
    if(theGrid) { clearGrid(); } // need to clean Grid if it is not null

    theGrid = new Cell* [MAX_ROW];
    
    for(int m=0; m < MAX_ROW; m++) {
        theGrid[m] = new Cell[MAX_COLUMN];
    }
    
    for(int i=0; i < MAX_ROW; i++) {
        for(int j=0; j < MAX_COLUMN; j++) {
            // theGrid[i][j].setCoords(i,j, j*500/MAX_COLUMN, i*500/MAX_ROW, 500/MAX_COLUMN , 500/MAX_ROW, xw, ' ');     // <--- WINDOW
            theGrid[i][j].setCoords(i,j, ' ');
        }
    }
}


void Grid::initBlock(Block *cur){
    
    int r0 = cur->getCell(0).getRow();
    int c0 = cur->getCell(0).getCol();
    
    int r1 = cur->getCell(1).getRow();
    int c1 = cur->getCell(1).getCol();
    
    int r2 = cur->getCell(2).getRow();
    int c2 = cur->getCell(2).getCol();
    
    int r3 = cur->getCell(3).getRow();
    int c3 = cur->getCell(3).getCol();
    
    char let = cur->getType();
    
  
    if(theGrid[r0][c0].getFree() && theGrid[r1][c1].getFree() && theGrid[r2][c2].getFree() && theGrid[r3][c3].getFree()) {
        theGrid[r0][c0].unFree();
        theGrid[r1][c1].unFree();
        theGrid[r2][c2].unFree();
        theGrid[r3][c3].unFree();
        theGrid[r0][c0].setLet(let);
        theGrid[r1][c1].setLet(let);
        theGrid[r2][c2].setLet(let);
        theGrid[r3][c3].setLet(let);
        theGrid[r0][c0].notifyDisplay(*td);
        theGrid[r1][c1].notifyDisplay(*td);
        theGrid[r2][c2].notifyDisplay(*td);
        theGrid[r3][c3].notifyDisplay(*td);
        
    }
    
}



void Grid::cleanBlock() {
    
    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
    
    char let = ' ';
    
    if(!theGrid[r0][c0].getFree() && !theGrid[r1][c1].getFree() && !theGrid[r2][c2].getFree() && !theGrid[r3][c3].getFree()) {
        theGrid[r0][c0].setFree();
        theGrid[r1][c1].setFree();
        theGrid[r2][c2].setFree();
        theGrid[r3][c3].setFree();
        theGrid[r0][c0].setLet(let);
        theGrid[r1][c1].setLet(let);
        theGrid[r2][c2].setLet(let);
        theGrid[r3][c3].setLet(let);
        theGrid[r0][c0].notifyDisplay(*td);
        theGrid[r1][c1].notifyDisplay(*td);
        theGrid[r2][c2].notifyDisplay(*td);
        theGrid[r3][c3].notifyDisplay(*td);
        
    }
    
}


bool Grid::checkPos(string commd, string op) {
    bool full=false;
    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
    
   // if(r3 == 14 || r2 == 14 || c2 == 9 || c3 == 9) {return true; }

    char type = currentBlock->getType();

    if(commd == "row") {
       if(r3 == 14) {return true; }
       if ((type == 'I') && (!theGrid[r0+1][c0].getFree() || 
			      !theGrid[r1+1][c1].getFree() ||
   			      !theGrid[r2+1][c2].getFree() || 
			      !theGrid[r3+1][c3].getFree()) ) { full = true; }

       else if ((type == 'O') && (!theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }

       else if ( (type == 'L' ) && (!theGrid[r1+1][c1].getFree() || 
   			           !theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }
 
       else if ((type == 'J' ) && (!theGrid[r1+1][c1].getFree() || 
   			           !theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }

       else if ( (type == 'S') && (!theGrid[r1+1][c1].getFree() || 
   			           !theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }

       else if ( (type == 'Z') && (!theGrid[r0+1][c0].getFree() || 
   			           !theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }

      else if ( (type == 'T') && (!theGrid[r0+1][c0].getFree() || 
   			           !theGrid[r2+1][c2].getFree() || 
			           !theGrid[r3+1][c3].getFree()) ) { full = true; }

    }
    if(commd == "col") {
       if(op == "inc") {
           //if(c3 == 0) {return true; }
              if (type == 'I' && (c3 == 9 || !theGrid[r3][c3+1].getFree()) ) { full = true; }

     		  else if (type == 'O' && (c1 == 9 || c3 == 9 || !theGrid[r1][c1+1].getFree() ||
			                                !theGrid[r3][c3+1].getFree())) { full = true; }

     		  else if (type == 'L' && (c0 == 9 || c3 == 9 || !theGrid[r0][c0+1].getFree() ||
   			                                !theGrid[r3][c3+1].getFree())) { full = true; }
 
     		  else if (type == 'J' && (c3 == 9 || !theGrid[r0][c0+1].getFree() ||
   			                                !theGrid[r3][c3+1].getFree()) ) { full = true; }

     		  else if (type == 'S' && (c1 == 9 || !theGrid[r1][c1+1].getFree() ||
   			                                !theGrid[r3][c3+1].getFree()) ) { full = true; }

     		  else if (type == 'Z' && (c3 == 9 || !theGrid[r1][c1+1].getFree() ||
   			                                 !theGrid[r3][c3+1].getFree()) ) { full = true; }

     		 else if (type == 'T' && (c2 == 9 || !theGrid[r2][c2+1].getFree() ||
   			                                 !theGrid[r3][c3+1].getFree()) ) { full = true; }

        }
      else if(op == "dec") {
            // if(r3 == 14) {return true; }
             if (type == 'I' && (c0 == 0 || !theGrid[r3][c0-1].getFree())) { full = true; }

     		  else if (type == 'O' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
                                            !theGrid[r2][c2-1].getFree())) { full = true; }

     		  else if (type == 'L'  && (c0 == 0 || c1 == 0 || !theGrid[r0][c0-1].getFree() ||
                                            !theGrid[r1][c1-1].getFree())) { full = true; }
 
     		  else if (type == 'J' && (c0 == 0 || c1 == 0 || !theGrid[r0][c0-1].getFree() ||
                                           !theGrid[r1][c1-1].getFree()) ) { full = true; }

     		  else if (type == 'S' && (c2 == 0 || !theGrid[r0][c0-1].getFree() ||
                                            !theGrid[r2][c2-1].getFree()) ) { full = true; }

     		  else if (type == 'Z' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
   			                                !theGrid[r2][c2-1].getFree()) ) { full = true; }

     		 else if (type == 'T' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
   			                                !theGrid[r3][c3-1].getFree()) ) { full = true; }


        }
    }
     return full;
}


void Grid::generateBlock() {
    currentBlock = nextBlock;
    nextBlock = myLevel->getNextBlock();
}



bool Grid::checkLine(int row) {
    for(int i = 0; i < MAX_COLUMN; i++)
    {
        if(theGrid[row][i].getFree())
            return false;
    }
    return true;
}



void Grid::checkGrid() {
    int lineNum = 0;
    for(int i = MAX_ROW - 1; i >= 0; i--) {
        if(checkLine(i)) {
            lineNum++;
            removeLine(i);
            
        }
    }
    if(lineNum > 0) {
       curScore += (lineNum + myLevel->getLevelNum()) * (lineNum + myLevel->getLevelNum());

    }
}




// Deletes all rows and colums of the Grid
void Grid::clearGrid() {
  /*  for(int i=0; i < MAX_ROW; i++) {
        delete [] theGrid[i];
    }
    delete [] theGrid;*/
    
    
    for(int i=0; i < MAX_ROW; i++){
        for(int j=0; j < MAX_COLUMN; j++){
            theGrid[i][j].setFree();
            theGrid[i][j].notifyDisplay(*td);
        }
    }
    if(curScore > hiScore) {
        hiScore = curScore;
    }
    curScore = 0;
}



int Grid::getScore() {
    return curScore;
}

Block* Grid::getCurBlock() { return currentBlock; }



void Grid::DrawText() {
    cout << "Level:" << "     " << myLevel->getLevelNum() << endl;
    cout << "Score:" << "     " << curScore << endl;
    cout << "HiScore:" << "   " << hiScore << endl;
    cout << "----------" << endl;
    cout << *td;
    cout << "----------" << endl;
    cout << "Next:" << endl;
    nextBlock->drawBlock();

}



void Grid::removeLine(int row) {
    int line=0,  num;
    for(int l = row; l >= 5; l--) {
        for(int i = 0; i < MAX_COLUMN; i++) {
            if(theGrid[l][i].getFree()) {
                line++;
            }
        }
        if (line == 10) { num = l; break; }
        else { line = 0; }
    }
 /*
    
  for(int l = row; l >= num; l--) {
    for(int i = 0; i < MAX_COLUMN; i++) {
        //theGrid[row][i].setFree();
        theGrid[l][i].setLet(theGrid[l-1][i].getLet());
       // theGrid[l][i] = theGrid[l-1][i];
        if(l == num) {
            theGrid[l][i].setFree();
        }
        theGrid[l-1][i].notifyDisplay(*td);
        theGrid[l][i].notifyDisplay(*td);
     }
  }
  */
    
    
    
 /*   int lastRow = 0;
    
   for(int i = 0; i < MAX_ROW; i++) {
        for(int j = 0; j < MAX_COLUMN; j++) {
            if(!theGrid[i][j].getFree()) {
                lastRow = i;
                break;
            }
        }
        if(lastRow > 0) {break; }
    }*/
        
        // Shifts cells down by one row
    for(int j = 0; j < MAX_COLUMN; j++) {
        for(int i = row; i >= num; i--) {
            //theGrid[row][i].setFree();
        theGrid[i][j].setLet(theGrid[i-1][j].getLet());
            // theGrid[l][i] = theGrid[l-1][i];
          /*  if(i == num) {
                theGrid[i-1][j].setFree();
                theGrid[i][j].setFree();
                theGrid[i+1][j].setFree();
            }*/
            if(theGrid[i][j].getLet() == ' ') {
                 theGrid[i][j].setFree();
            }
            theGrid[i-1][j].notifyDisplay(*td);
            theGrid[i][j].notifyDisplay(*td);
            }
        }
}



//Overload operator<<
ostream &operator<<(ostream &out, const Grid &g){
    out << *g.td;
    return out;
}

void Grid::newLevel(int lev) {
    if(myLevel->getLevelNum() != lev) {
        if(lev == 0) {
           delete myLevel; 
           myLevel = new Level0();
        }
        else if(lev == 1) {
              delete myLevel; 
           myLevel = new Level1();
        }
        else if(lev == 2) {
              delete myLevel; 
           myLevel = new Level2();
        }
        else if(lev == 3) {
              delete myLevel; 
           myLevel = new Level3();
        }
    }
}


void Grid::skip() {
    cleanBlock();
    initBlock(nextBlock);
    generateBlock();
}

/*
int main() {
    
    string  in;
    
    Grid *board = new Grid;
    board->DrawText();
    
    delete board;
    return 0;
}
*/

