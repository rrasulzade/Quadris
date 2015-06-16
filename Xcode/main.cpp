//
//  main.cpp
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "textdisplay.h"
#include "grid.h"
#include "cell.h"
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "trie.h"
//#include "window.h"

using namespace std;

static int level = 0;

string take_command(string in) {
    int len = in.length();
    int last;
    for (int i = 0; i < len; i++) {
        if (!((48 <= in[i]) && (in[i] <= 57))) {
            last = i;
            break;
        }
    }
    return in.substr(last, len - last);
}

void command_interpreter(Grid *board, string in){
    if(in == "left") {
              if(board->checkPos("col", "dec") ) {
                     board->DrawText();
               }
              else {
                    board->cleanBlock();
                    (board->getCurBlock())->left();
                    board->initBlock(board->getCurBlock());
                    board->DrawText();
               }
    }
    else if(in == "right") {
               if(board->checkPos("col", "inc") ) {
                  board->DrawText();
               }
               else {
                    board->cleanBlock();
                    (board->getCurBlock())->right();
                    board->initBlock(board->getCurBlock());
                    board->DrawText();
               }
    }
    else if(in == "down") {
              if( !((board->getCurBlock())->getIsSpace()) || board->checkPos("row", "inc") ) {
                    board->generateBlock();
        board->initBlock(board->getCurBlock());
        board->checkGrid();
        board->DrawText();
       }
              else {
                    board->cleanBlock();
                    (board->getCurBlock())->down();
                    board->initBlock(board->getCurBlock());
                //    board->checkGrid();
                    board->DrawText();
       }
    }
    else if(in == "clockwise") {

    }
    else if(in == "counterclockwise") {

    }
    else if(in == "drop") {
                 while(((board->getCurBlock())->getIsSpace()) && !board->checkPos("row", "inc") ) {
                          board->cleanBlock();
                         (board->getCurBlock())->down();
                          board->initBlock(board->getCurBlock());

         }
                board->checkGrid();
                board->generateBlock();
                board->initBlock(board->getCurBlock());
                board->checkGrid();
                board->DrawText();

    }
    else if(in == "levelup") {
          level++;
          board->newLevel(level);
    }
    else if(in == "leveldown") {
                  level--;
                  board->newLevel(level);
    }
    else if(in == "restart") {
                    board->init();
                    board->generateBlock();
                    board->initBlock(board->getCurBlock());
                    board->DrawText();
    }
    else if(in == "skip") {
                    board->skip();
                    board->DrawText();
    }
    else if(in == "remove") {
        board->removeLine(14);
        board->DrawText();
    }
}

int main() {
    
    string  in;
    Grid *board = new Grid;
    board->DrawText();
    TrieNode *trie = new TrieNode;
    trie->insert("left");
    trie->insert("right");
    trie->insert("down");
    trie->insert("clockwise");
    trie->insert("counterclockwise");
    trie->insert("drop");
    trie->insert("levelup");
    trie->insert("leveldown");
    trie->insert("skip");
    trie->insert("restart");

    while(1)  {
        cin >> in;
        int times;
        if ((in[0] >= 48) && (in[0] <= 57)) {times = atoi(in.c_str());}
        else times = 1;
        in = take_command(in);
        in = trie->find(in);
        if (in == "restart") {
            command_interpreter(board,in);
        }
        else if (in == "right" || in == "left") {
            if (times > 10) times = 10;
            for (int i = 0; i < times; i++) command_interpreter(board,in);
        }
        else for (int i = 0; i < times; i++) command_interpreter(board,in);
    }
}
