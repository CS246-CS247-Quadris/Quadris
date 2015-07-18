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
#include "window.h"

using namespace std;

static int level = 0 ,rotate = 0;

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
              if(board->checkPos("col", "dec", rotate) ) {
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
               if(board->checkPos("col", "inc", rotate) ) {
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
              if( !((board->getCurBlock())->getIsSpace()) || board->checkPos("row", "inc", rotate) ) {
                    board->generateBlock();
        board->initBlock(board->getCurBlock());
        board->checkGrid();
	if(!board->checkPos("new", "none", 0)) { board->init(); }
        rotate = 0;
        board->DrawText();
       }
              else {
                    board->cleanBlock();
                    (board->getCurBlock())->down();
                    board->initBlock(board->getCurBlock());
                    board->DrawText();
       }
    }
    else if(in == "clockwise") {
                    rotate++;
   		    if(rotate == 4){ rotate = 0; }
          	    board->cleanBlock();
                   board->rotateCC();
                    board->DrawText();

    }
    else if(in == "counterclockwise") {
		    rotate--;
   		    if(rotate == -1){ rotate = 3; }
          	    board->cleanBlock();
                    board->rotateCCW();
                    board->DrawText();

    }
    else if(in == "drop") {
                 while(((board->getCurBlock())->getIsSpace()) && !board->checkPos("row", "inc", rotate) ) {
                          board->cleanBlock();
                         (board->getCurBlock())->down();
                          board->initBlock(board->getCurBlock());

         }
                board->checkGrid();
		 if(board->checkPos("new", "none", 0)) { board->init(); }
                board->generateBlock();
                board->initBlock(board->getCurBlock());
		rotate = 0;
                board->DrawText();

    }
    else if(in == "levelup") {
          level++;
	  if (level > 3) { level = 3; }
          board->newLevel(level);
    }
    else if(in == "leveldown") {
                  level--;
		  if (level < 0) { level = 0; }
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
}


int main(int argc, char *argv[]) {
  string  in, arg;
  int level = 0;
  int seeding = 0;
  string filename = "sequence.txt";
  if(argc > 2) {
    istringstream ss2(argv[2]);
    istringstream ss1(argv[1]);
    ss1 >> arg;

     if(arg == "-startlevel") {
        if(!(ss2 >> level)) {
             level = 0; 
        }
     }
     if(arg == "-scriptfile") {
         if(!(ss2 >> filename)) {
             filename = "sequence.txt";
         }
     }
     if(arg == "-seed") {
         if(!(ss2 >> seeding)) {
             seeding = 0;
         }
     }
   }   

   Grid *board = new Grid(level);
    board->setFile0(filename);
    board->setSeeder0(seeding);
    if(filename != "sequence.txt") {
         board->init();
        board->generateBlock();
        board->generateBlock();
        board->initBlock(board->getCurBlock());
    }
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

    while(cin >> in)  {
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

   delete board;
   delete trie;

}
