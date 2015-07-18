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
#include "window.h"
#include <string>

#define MAX_COLUMN 10
#define MAX_ROW 15

class Grid{
	Cell **theGrid;
	TextDisplay *td;
	Xwindow *xw;
    Level *myLevel;
	Block *currentBlock;
	Block *nextBlock;
	int curScore;
	int hiScore;
	void clearGrid();   
public:
	Grid(int lev);       			  
	~Grid();
	void setFile0(std::string file);
	void setSeeder0(unsigned int given);
	void newLevel(int lev);    
	int getScore(); 		  
	void DrawText();   	          
	bool checkLine(int row);          
	void checkGrid(); 		 
	void removeLine(int row);         
    void init();
	void initBlock(Block *cur);            
    void cleanBlock();
    void generateBlock();
    bool checkPos(std::string commd, std::string op, int rotate);
    void skip();
    void rotateCC();
    void rotateCCW();
    Block* getCurBlock();
    friend std::ostream &operator<<(std::ostream &out, const Grid &board);
};

#endif
