#include <iostream>
#include <string>
#include <cstdlib>
#include "grid.h"

using namespace std;


// Default constructor
Grid::Grid(int lev) {
    //  isFull = false;
    td = new TextDisplay;
    hiScore = 0;
    curScore = 0;
    xw = new Xwindow;  
    myLevel = new Level0();
   
    if(1 <= lev && lev <= 3) {
      newLevel(lev);
    }
    if (lev > 3) newLevel(3);

    currentBlock = myLevel->getNextBlock();
    nextBlock = myLevel->getNextBlock();
    init();
    initBlock(currentBlock);

    xw->fillRectangle(0, 0, 130, 500, 9); // LHS of the Xwindow
    xw->fillRectangle(17, 25, 95, 440, 10); // LHS of the Xwindow  


    xw->fillRectangle(358, 0, 147, 500, 9); // RHS of the Xwindow
    xw->fillRectangle(378, 25, 106, 440, 10); // RHS of the Xwindow

    int col = 25;                                // LHS lines
    for(int i = 0; i < 44; i++) {
        xw->fillRectangle(17, col, 95, 5, 3);
        col += 10;
    }
    
     
    col = 25;                                   // RHS lines
    for(int i = 0; i < 44; i++) {
        xw->fillRectangle(378, col, 106, 5, 3);
        col += 10;
    }


// initialize first block 

    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
    
    char let =  currentBlock->getType();
    
        theGrid[r0][c0].unFree();
        theGrid[r1][c1].unFree();
        theGrid[r2][c2].unFree();
        theGrid[r3][c3].unFree();
        theGrid[r0][c0].setLet(let);
        theGrid[r1][c1].setLet(let);
        theGrid[r2][c2].setLet(let);
        theGrid[r3][c3].setLet(let);
        theGrid[r0][c0].notifyDisplay(*td, *xw, currentBlock->getColour());
        theGrid[r1][c1].notifyDisplay(*td, *xw, currentBlock->getColour());
        theGrid[r2][c2].notifyDisplay(*td, *xw, currentBlock->getColour());
        theGrid[r3][c3].notifyDisplay(*td, *xw, currentBlock->getColour());
        
}


// Default destructor
Grid::~Grid() {
   
     delete currentBlock;
    delete nextBlock;
   delete myLevel;
    delete td;
    delete xw;
   
    

     for(int i=0; i < MAX_ROW; i++) {
        delete [] theGrid[i];
     }
   delete [] theGrid;
  
}

// creates new Grid and TextDisplay of length n
// and mutates all coordinates of the Grid using setCoords

void Grid::setFile0(string file){myLevel->setFile(file);}

void Grid::setSeeder0(unsigned int given){myLevel->setSeeder(given);}

void Grid::init(){
    if(theGrid) { clearGrid(); } // need to clean Grid if it is not null

    theGrid = new Cell* [MAX_ROW];
    
    for(int m=0; m < MAX_ROW; m++) {
        theGrid[m] = new Cell[MAX_COLUMN];
    }
    
    for(int i=0; i < MAX_ROW; i++) {
        for(int j=0; j < MAX_COLUMN; j++) {
            theGrid[i][j].setCoords(i,j, ' ', 0);
        }
    }
}


// initializes given block into the grid and the window

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
        theGrid[r0][c0].notifyDisplay(*td, *xw, cur->getColour());
        theGrid[r1][c1].notifyDisplay(*td, *xw, cur->getColour());
        theGrid[r2][c2].notifyDisplay(*td, *xw, cur->getColour());
        theGrid[r3][c3].notifyDisplay(*td, *xw, cur->getColour());
        
    }
    
}


// cleans Block from the grid and window
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
        theGrid[r0][c0].notifyDisplay(*td, *xw, 0);
        theGrid[r1][c1].notifyDisplay(*td, *xw, 0);
        theGrid[r2][c2].notifyDisplay(*td, *xw, 0);
        theGrid[r3][c3].notifyDisplay(*td, *xw, 0);
        
    }
    
}



// changes current block with next one
// and creates new block according to the current level

void Grid::generateBlock() {
    currentBlock = nextBlock;
    nextBlock = myLevel->getNextBlock();
}


// checks the given row and returns true if it is full
// or false otherwise

bool Grid::checkLine(int row) {
    for(int i = 0; i < MAX_COLUMN; i++)
    {
        if(theGrid[row][i].getFree())
            return false;
    }
    return true;
}


// checks whole grid whether there is a row which
// is full and deletes it,
// and calculates the score

void Grid::checkGrid() {
    int lineNum = 0;
    for(int i = 3; i <= 14; i++) {
        if(checkLine(i)) {
            lineNum += 1;
            removeLine(i);
            
        }
    }
    if(lineNum > 0) {
       curScore += (lineNum + myLevel->getLevelNum()) * (lineNum + myLevel->getLevelNum());

    }
}




// Cleans grid and checks HiScore
void Grid::clearGrid() {
  
    for(int i=0; i < MAX_ROW; i++){
        for(int j=0; j < MAX_COLUMN; j++){
            theGrid[i][j].setFree();
            theGrid[i][j].notifyDisplay(*td, *xw, 0);
        }
    }
    if(curScore > hiScore) {
        hiScore = curScore;
    }
    curScore = 0;
}


// returns current Score
int Grid::getScore() { return curScore;}

// returns current Block
Block* Grid::getCurBlock() { return currentBlock; }


// Prints whole grid with current and next blocks 
// to the text display and graphical display
void Grid::DrawText() {
   
    int c;
    ostringstream ss;
    ostringstream ss1;
    ostringstream ss2;
    ostringstream ss3;


    xw->fillRectangle(135, 0, 220, 60, 0);  //cleans Scoreboard

    cout << "Level:" << "     " << myLevel->getLevelNum() << endl;
    c = myLevel->getLevelNum();
    ss << "Level:                   " << c;
    string out = ss.str();
    xw->drawString( 135, 15, out, 11);
    


    cout << "Score:" << "     " << curScore << endl;
    c = curScore;
    ss2 << "Score:                   " << c;
    string out2 = ss2.str();
    xw->drawString( 135, 30, out2, 11);


    cout << "HiScore:" << "   " << hiScore << endl;
    c = hiScore;
    ss3 << "HiScore:                 " << c;
    string out3 = ss3.str();
    xw->drawString( 135, 45, out3, 11);


    cout << "----------" << endl;
    int x = 135;
    for(int i = 1; i <= 10; i++) {
        xw->fillRectangle(x, 55, 20, 5, 4);
        x += 22;
    } 

    cout << *td;

    cout << "----------" << endl;
    x = 135;
    for(int i = 1; i <= 10; i++) {
        xw->fillRectangle(x, 415, 20, 5, 4);
        x += 22;
    }

    cout << "Next:" << endl;
    ss1 << "Next:";
    string out1 = ss1.str();
    xw->drawString( 135, 435, out1, 11);

 xw->fillRectangle(135, 445, 105, 50, 0);
 
    if(nextBlock->getType() == 'L') {
        xw->fillRectangle(179, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(135, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(135, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 467, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'J') {
        xw->fillRectangle(135, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(135, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 467, 21, 21, nextBlock->getColour());

	xw->fillRectangle(135, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(135, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 467, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'T') {
        xw->fillRectangle(135, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());
 
        xw->fillRectangle(135, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'I') {
        xw->fillRectangle(135, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(201, 445, 21, 21, nextBlock->getColour());
	
	xw->fillRectangle(135, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(201, 445, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'S') {
        xw->fillRectangle(157, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(135, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());

	xw->fillRectangle(157, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(135, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'Z') {
        xw->fillRectangle(135, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(179, 467, 21, 21, nextBlock->getColour());

	xw->fillRectangle(135, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(179, 467, 11, 11, nextBlock->getColour()+1);
    }
    else if(nextBlock->getType() == 'O') {
        xw->fillRectangle(135, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 445, 21, 21, nextBlock->getColour());
	xw->fillRectangle(135, 467, 21, 21, nextBlock->getColour());
	xw->fillRectangle(157, 467, 21, 21, nextBlock->getColour());

	xw->fillRectangle(135, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 445, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(135, 467, 11, 11, nextBlock->getColour()+1);
	xw->fillRectangle(157, 467, 11, 11, nextBlock->getColour()+1);
    }

    

    nextBlock->drawBlock();

}


// deletes given row and moves 
// all cells down above it row by row

void Grid::removeLine(int row) {
    int line=0,  num;
    for(int l = row; l >= 1; l--) {
        for(int i = 0; i < MAX_COLUMN; i++) {
            if(theGrid[l][i].getFree()) {
                line++;
            }
        }
        if (line == 10) { num = l; break; }
        else { line = 0; }
    }

        
        // Shifts cells down by one row
     for(int i = row; i >= num; i--) {
        for(int j = 0; j < MAX_COLUMN; j++) {
  

            theGrid[i][j].setLet(theGrid[i-1][j].getLet());
	    theGrid[i][j].setColor(theGrid[i-1][j].getColor());
  
            if(theGrid[i][j].getLet() == ' ') {
                 theGrid[i][j].setFree();
            }

            theGrid[i-1][j].notifyDisplay(*td, *xw, (theGrid[i-1][j].getColor()));
            theGrid[i][j].notifyDisplay(*td, *xw, (theGrid[i][j].getColor()));
        }
     }
}



//Overload operator<<
ostream &operator<<(ostream &out, const Grid &g){
    out << *g.td;
    return out;
}



// changes current level to the given one

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
        else if(lev >= 3) {
              delete myLevel; 
           myLevel = new Level3();
        }
    }
}


// replaces current block with next one in the grid
void Grid::skip() {
    cleanBlock();
    initBlock(nextBlock);
    generateBlock();
}




static int rotateTime1 = 0;
static int IState = 0;


// Rotates current block clockwise, if current block is not O-block

void Grid::rotateCC() {
    char let = currentBlock->getType();
    if (let != 'O'){
    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
    
    int max[4] = {0, 0, 0, 0,};
    max[0] = r0;
    max[1] = r1;
    max[2] = r2;
    max[3] = r3;
    
    int min[4] = {0, 0, 0, 0,};
    min[0] = c0;
    min[1] = c1;
    min[2] = c2;
    min[3] = c3;
    
    
    
	int Min = min[0];
    for(int i = 0; i < 4; i++) {
        if( Min > min[i] ) {
            Min = min[i];
        }
    }
    
    
    int Max = max[0];
    for(int i = 0; i < 4; i++) {
        if( Max < max[i] ) {
            Max = max[i];
        }
    }
    int a, b, r_new0, c_new0, r_new1, c_new1, r_new2, c_new2, r_new3, c_new3;
    if (let != 'I') {
    a = Max-2;  b = Min;
    
    r_new0 = c0 + a - b;
    c_new0 = a + b + 2 -r0;
    
    r_new1 = c1 + a - b;
    c_new1 = a + b + 2 -r1;
    
    r_new2 = c2 + a - b;
    c_new2 = a + b + 2 -r2;
    
    r_new3 = c3 + a - b;
    c_new3 = a + b + 2 -r3;
    }
    else {
        a = Max; b = Min + 3;

        r_new0 = c0 - b + a;
        c_new0 = a - r0 + b;

        r_new1 = c1 - b + a;
        c_new1 = a - r1 + b;

        r_new2 = c2 - b + a;
        c_new2 = a - r2 + b;

        r_new3 = c3 - b + a;
        c_new3 = a - r3 + b;
    }
    
 /*   if(!theGrid[r_new0][c_new0].getFree() && !theGrid[r_new1][c_new1].getFree() &&
      !theGrid[r_new2][c_new2].getFree() && !theGrid[r_new3][c_new3].getFree() &&
    						currentBlock->getType() != 'O') {*/
    unsigned long color = currentBlock->getColour();

  	(currentBlock->getCell(0)).setCoords(r_new0, c_new0, let, color);
	theGrid[r0][c0].setFree();
	theGrid[r0][c0].setLet(' ');
  	theGrid[r0][c0].notifyDisplay(*td, *xw, 0);
    
	(currentBlock->getCell(1)).setCoords(r_new1, c_new1, let, color);
	theGrid[r1][c1].setFree();
	theGrid[r1][c1].setLet(' ');
    	theGrid[r1][c1].notifyDisplay(*td, *xw, 0);

	(currentBlock->getCell(2)).setCoords(r_new2, c_new2, let, color);
	theGrid[r2][c2].setFree();
	theGrid[r2][c2].setLet(' ');
    	theGrid[r2][c2].notifyDisplay(*td, *xw, 0);
    
	(currentBlock->getCell(3)).setCoords(r_new3, c_new3, let, color);
  	theGrid[r3][c3].setFree();
    	theGrid[r3][c3].setLet(' ');
    	theGrid[r3][c3].notifyDisplay(*td, *xw, 0);
        if (let != 'I'){
            rotateTime1++;
            rotateTime1 = rotateTime1 % 4;
            if (rotateTime1 % 2 == 0) {
                currentBlock->down();
            }
            initBlock(currentBlock);
        }
        else {
            IState++;
            IState = IState % 2;
            if (IState == 0) {
                for (int i = 0; i < 3; i++) currentBlock->down();
            }
            for (int i = 0; i < 3; i++) currentBlock->left();
            initBlock(currentBlock);
        }
    }
    else initBlock(currentBlock);
}



// Rotates current block counter-clockwise, if current block is not O-block

void Grid::rotateCCW() {
    char let = currentBlock->getType();
    if (let != 'O') {
    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
    
    int max[4] = {0, 0, 0, 0,};
    max[0] = r0;
    max[1] = r1;
    max[2] = r2;
    max[3] = r3;
    
    int min[4] = {0, 0, 0, 0,};
    min[0] = c0;
    min[1] = c1;
    min[2] = c2;
    min[3] = c3;
    
    
    
	int Min = min[0];
    for(int i = 0; i < 4; i++) {
        if( Min > min[i] ) {
            Min = min[i];
        }
    }
    
    
    int Max = max[0];
    for(int i = 0; i < 4; i++) {
        if( Max < max[i] ) {
            Max = max[i];
        }
    }
    
    int a, b, r_new0, c_new0, r_new1, c_new1, r_new2, c_new2, r_new3, c_new3;
    if (let != 'I') {
     a = Max-2;  b = Min;
    
     r_new0 = a + b + 2 -c0;
     c_new0 = r0 - a + b;
    
     r_new1 = a + b + 2 -c1;
    c_new1 = r1 - a + b;
    
    r_new2 = a + b + 2 -c2;
     c_new2 = r2 - a + b;
    
     r_new3 = a + b + 2 -c3;
    c_new3 = r3 - a + b;
    }
    else {
        a = Max; b = Min;

        r_new0 = a + b - c0;
        c_new0 = r0 - a + b;
        r_new1 = a + b - c1;
        c_new1 = r1 - a + b;
        r_new2 = a + b - c2;
        c_new2 = r2 - a + b;
        r_new3 = a + b - c3;
        c_new3 = r3 - a + b;
    }
    
  /* if(!theGrid[r_new0][c_new0].getFree() && !theGrid[r_new1][c_new1].getFree() &&
      !theGrid[r_new2][c_new2].getFree() && !theGrid[r_new3][c_new3].getFree() &&
      (0 < c_new0 && c_new0 < 9) && (0 < c_new1 && c_new1 < 9) && (0 < c_new2 && c_new2 < 9) && (c_new3 
    						currentBlock->getType() != 'O') {*/
        unsigned long color = currentBlock->getColour();
        
        (currentBlock->getCell(0)).setCoords(r_new0, c_new0, let, color);
        theGrid[r0][c0].setFree();
        theGrid[r0][c0].setLet(' ');
        theGrid[r0][c0].notifyDisplay(*td, *xw, 0);


        (currentBlock->getCell(1)).setCoords(r_new1, c_new1, let, color);
        theGrid[r1][c1].setFree();
        theGrid[r1][c1].setLet(' ');
        theGrid[r1][c1].notifyDisplay(*td, *xw, 0);
        
        (currentBlock->getCell(2)).setCoords(r_new2, c_new2, let, color);
        theGrid[r2][c2].setFree();
        theGrid[r2][c2].setLet(' ');
        theGrid[r2][c2].notifyDisplay(*td, *xw, 0);
        
        (currentBlock->getCell(3)).setCoords(r_new3, c_new3, let, color);
        theGrid[r3][c3].setFree();
        theGrid[r3][c3].setLet(' ');
        theGrid[r3][c3].notifyDisplay(*td, *xw, 0);
        if (let != 'I'){
            rotateTime1--;
            rotateTime1 = 4 - rotateTime1;
            rotateTime1 = rotateTime1 % 4;
            if (rotateTime1 % 2 == 1) {
                currentBlock->left();
            }
            initBlock(currentBlock);
        }
        else {
            IState++;
            IState = IState % 2;
            if (IState == 0) {
                for (int i = 0; i < 3; i++) currentBlock->right();
            }
//            else for (int i = 0; i < 3; i++) currentBlock->right();
            initBlock(currentBlock);
        }
    }
    else initBlock(currentBlock);
}




// Checks rows and colums according to the given commd
// and also uses op for checking forward or backward rows and colums
// In addition, all procces are based on actual position of currentBlock in the grid
// if it is rotated 'rotateTime' finds in which position the block is.

bool Grid::checkPos(string commd, string op, int rotateTime) {
    bool full=false;
    int r0 = currentBlock->getCell(0).getRow();
    int c0 = currentBlock->getCell(0).getCol();
    
    int r1 = currentBlock->getCell(1).getRow();
    int c1 = currentBlock->getCell(1).getCol();
    
    int r2 = currentBlock->getCell(2).getRow();
    int c2 = currentBlock->getCell(2).getCol();
    
    int r3 = currentBlock->getCell(3).getRow();
    int c3 = currentBlock->getCell(3).getCol();
   
    char type = currentBlock->getType();
	
    if(commd == "new") {
    
   	 int r0_ne = nextBlock->getCell(0).getRow();
   	 int c0_ne = nextBlock->getCell(0).getCol();
   		 
    	 int r1_ne = nextBlock->getCell(1).getRow();
   	 int c1_ne = nextBlock->getCell(1).getCol();
    
   	 int r2_ne = nextBlock->getCell(2).getRow();
   	 int c2_ne = nextBlock->getCell(2).getCol();
    
   	 int r3_ne = nextBlock->getCell(3).getRow();
   	 int c3_ne = nextBlock->getCell(3).getCol();

	 if (!theGrid[r0_ne][c0_ne].getFree() || !theGrid[r1_ne][c1_ne].getFree() ||
             !theGrid[r2_ne][c2_ne].getFree() || !theGrid[r3_ne][c3_ne].getFree())  { full = true; }
      }

  
    else if(commd == "row") {
        
       if(rotateTime == 0 ) {
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
        
       else if(rotateTime == 1 ) {
            if(r3 == 14 || r2 == 14 || r1 == 14) {return true; }
            if ((type == 'I') && (!theGrid[r3+1][c3].getFree())) { full = true; }
           
            else if ((type == 'O') && (!theGrid[r2+1][c2].getFree() ||
                                       !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'L' ) && (!theGrid[r0+1][c0].getFree() ||
                                         !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ((type == 'J' ) && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r3+1][c3].getFree())) { full = true; }
            
            else if ( (type == 'S') && (!theGrid[r1+1][c1].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'Z') && (!theGrid[r1+1][c1].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'T') && (!theGrid[r2+1][c2].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
        }
       else if(rotateTime == 2 ) {
            if(r0 == 14 || r3 == 14) {return true; }
            if ((type == 'I') && (!theGrid[r0+1][c0].getFree() ||
                                  !theGrid[r1+1][c1].getFree() ||
                                  !theGrid[r2+1][c2].getFree() ||
                                  !theGrid[r3+1][c3].getFree()) ) { full = true; }
           
            else if ((type == 'O') && (!theGrid[r2+1][c2].getFree() ||
                                       !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'L' ) && (!theGrid[r1+1][c1].getFree() ||
                                         !theGrid[r2+1][c2].getFree() ||
                                         !theGrid[r0+1][c0].getFree()) ) { full = true; }
            
            else if ((type == 'J' ) && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r2+1][c2].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'S') && (!theGrid[r1+1][c1].getFree() ||
                                        !theGrid[r2+1][c2].getFree() ||
                                        !theGrid[r0+1][c0].getFree()) ) { full = true; }
            
            else if ( (type == 'Z') && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r1+1][c1].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'T') && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r2+1][c2].getFree() ||
                                        !theGrid[r1+1][c1].getFree()) ) { full = true; }
            
        }
       else if(rotateTime == 3 ) {
            if(r0 == 14 || r1 == 14 || r2 == 14 || r3 == 14) {return true; }
            if ((type == 'I') && (!theGrid[r0+1][c0].getFree())) { full = true; }
           
            else if ((type == 'O') && (!theGrid[r2+1][c2].getFree() ||
                                       !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
            else if ( (type == 'L' ) && (!theGrid[r1+1][c1].getFree() ||
                                         !theGrid[r0+1][c0].getFree()) ) { full = true; }
            
            else if ((type == 'J' ) && (!theGrid[r1+1][c1].getFree() ||
                                        !theGrid[r0+1][c0].getFree()) ) { full = true; }
            
            else if ( (type == 'S') && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r2+1][c2].getFree()) ) { full = true; }
            
            else if ( (type == 'Z') && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r2+1][c2].getFree()) ) { full = true; }
            
            else if ( (type == 'T') && (!theGrid[r0+1][c0].getFree() ||
                                        !theGrid[r3+1][c3].getFree()) ) { full = true; }
            
        }
 
    }
    
    if(commd == "col") {
       if(op == "inc") {
          if(rotateTime == 0) {
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
        else if(rotateTime == 1) {
            if (type == 'I' && (c3 == 9 || !theGrid[r0][c0+1].getFree() ||
                                            !theGrid[r1][c1+1].getFree() ||
                                            !theGrid[r2][c2+1].getFree() ||
                                            !theGrid[r3][c3+1].getFree())) { full = true; }
            
            else if (type == 'O' && (c1 == 9 || c3 == 9 || !theGrid[r1][c1+1].getFree() ||
                                     !theGrid[r3][c3+1].getFree())) { full = true; }
               
               else if (type == 'L' && (c0 == 9 || !theGrid[r0][c0+1].getFree() ||
                                        !theGrid[r1][c1+1].getFree() ||
                                        !theGrid[r2][c2+1].getFree())) { full = true; }
               
               else if (type == 'J' && (c0 == 9 || !theGrid[r0][c0+1].getFree() ||
                                        !theGrid[r2][c2+1].getFree() ||
                                        !theGrid[r3][c3+1].getFree()) ) { full = true; }
               
               else if (type == 'S' && (c0 == 9 || !theGrid[r1][c1+1].getFree() ||
                                                    !theGrid[r2][c2+1].getFree() ||
                                                    !theGrid[r0][c0+1].getFree()) ) { full = true; }
               
               else if (type == 'Z' && (c1 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                    !theGrid[r1][c1+1].getFree() ||
                                                    !theGrid[r3][c3+1].getFree()) ) { full = true; }
               
               else if (type == 'T' && (c2 == 9 || !theGrid[r2][c2+1].getFree() ||
                                        !theGrid[r0][c0+1].getFree() ||
                                        !theGrid[r1][c1+1].getFree()) ) { full = true; }
           }
        else if(rotateTime == 2) {
            if (type == 'I' && (c0 == 9 || !theGrid[r0][c0+1].getFree()) ) { full = true; }
            
            else if (type == 'O' && (c1 == 9 || c3 == 9 || !theGrid[r1][c1+1].getFree() ||
                                                            !theGrid[r3][c3+1].getFree())) { full = true; }
            
            else if (type == 'L' && (c0 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                !theGrid[r1][c1+1].getFree())) { full = true; }
            
            else if (type == 'J' && (c0 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                !theGrid[r1][c1+1].getFree()) ) { full = true; }
            
            else if (type == 'S' && (c2 == 9 || !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r0][c0+1].getFree()) ) { full = true; }
            
            else if (type == 'Z' && (c0 == 9 || !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r0][c0+1].getFree()) ) { full = true; }
            
            else if (type == 'T' && (c0 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree()) ) { full = true; }
        }
        else if(rotateTime == 3) {
            if (type == 'I' && (c3 == 9 || !theGrid[r0][c0+1].getFree() ||
                                            !theGrid[r1][c1+1].getFree() ||
                                            !theGrid[r2][c2+1].getFree() ||
                                            !theGrid[r3][c3+1].getFree())) { full = true; }
            
            else if (type == 'O' && (c1 == 9 || c3 == 9 || !theGrid[r1][c1+1].getFree() ||
                                                            !theGrid[r3][c3+1].getFree())) { full = true; }
            
            else if (type == 'L' && (c3 == 9 || !theGrid[r3][c3+1].getFree() ||
                                                !theGrid[r1][c1+1].getFree() ||
                                                !theGrid[r2][c2+1].getFree())) { full = true; }
            
            else if (type == 'J' && (c3 == 9 || !theGrid[r1][c1+1].getFree() ||
                                                !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree()) ) { full = true; }
            
            else if (type == 'S' && (c3 == 9 || !theGrid[r1][c1+1].getFree() ||
                                                !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree()) ) { full = true; }
            
            else if (type == 'Z' && (c2 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree()) ) { full = true; }
            
            else if (type == 'T' && (c3 == 9 || !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree() ||
                                                !theGrid[r0][c0+1].getFree()) ) { full = true; }
        }
      }
      else if(op == "dec") {
            if(rotateTime == 0) {
             if (type == 'I' && (c0 == 0 || !theGrid[r3][c0-1].getFree())) { full = true; }

     		  else if (type == 'O' && (c0 == 0 || c2 == 0 || !theGrid[r0][c0-1].getFree() ||
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
            else if(rotateTime == 1) {
                if (type == 'I' && (c3 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                !theGrid[r1][c1-1].getFree() ||
                                                !theGrid[r2][c2-1].getFree() ||
                                                !theGrid[r3][c3-1].getFree())) { full = true; }
                
                else if (type == 'O' && (c0 == 0 || c2 == 0 || !theGrid[r0][c0-1].getFree() ||
                                         !theGrid[r2][c2-1].getFree())) { full = true; }
                
                else if (type == 'L' && (c1 == 0 || !theGrid[r3][c3-1].getFree() ||
                                                    !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree())) { full = true; }
                
                else if (type == 'J' && (c1 == 0 || !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'S' && (c3 == 0 || !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'Z' && (c3 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'T' && (c3 == 0 || !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
            }
            else if(rotateTime == 2) {
                if (type == 'I' && (c3 == 0 || !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'O' && (c0 == 0 || c2 == 0 || !theGrid[r0][c0-1].getFree() ||
                                         !theGrid[r2][c2-1].getFree())) { full = true; }
                
                else if (type == 'L' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree())) { full = true; }
                
                else if (type == 'J' && (c3 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'S' && (c1 == 0 || !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'Z' && (c3 == 0 || !theGrid[r3][c3-1].getFree() ||
                                                    !theGrid[r1][c1-1].getFree()) ) { full = true; }
                
                else if (type == 'T' && (c2 == 0 || !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
            }
            else if(rotateTime == 3) {
                if (type == 'I' && (c3 == 9 || !theGrid[r0][c0+1].getFree() ||
                                                !theGrid[r1][c1+1].getFree() ||
                                                !theGrid[r2][c2+1].getFree() ||
                                                !theGrid[r3][c3+1].getFree())) { full = true; }
                
                else if (type == 'O' && (c0 == 0 || c2 == 0 || !theGrid[r0][c0-1].getFree() ||
                                         !theGrid[r2][c2-1].getFree())) { full = true; }
                
                else if (type == 'L' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree())) { full = true; }
                
                else if (type == 'J' && (c0 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'S' && (c0 == 0 || !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r0][c0-1].getFree()) ) { full = true; }
                
                else if (type == 'Z' && (c1 == 0 || !theGrid[r0][c0-1].getFree() ||
                                                    !theGrid[r1][c1-1].getFree() ||
                                                    !theGrid[r3][c3-1].getFree()) ) { full = true; }
                
                else if (type == 'T' && (c1 == 0 || !theGrid[r2][c2-1].getFree() ||
                                                    !theGrid[r1][c2-1].getFree() ||
                                                    !theGrid[r0][c0-1].getFree()) ) { full = true; }
            }
       }
    }
     return full;
}

