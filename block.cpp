#include <iostream>
#include <string>
#include <cstdlib>
#include "block.h"

using namespace std;


Block::Block(char type, unsigned long colour) {
    isSpace = true;

    this->type = type;
    this->colour = colour;
    if(type == 'L') {
        cells[0].setCoords(3, 2, type, colour);
        cells[1].setCoords(4, 0, type, colour);
        cells[2].setCoords(4, 1, type, colour);
        cells[3].setCoords(4, 2, type, colour);
    }
    else if(type == 'J') {
        cells[0].setCoords(3, 0, type, colour);
        cells[1].setCoords(4, 0, type, colour);
        cells[2].setCoords(4, 1, type, colour);
        cells[3].setCoords(4, 2, type, colour);
    }
    else if(type == 'T') {
        cells[0].setCoords(3, 0, type, colour);
        cells[1].setCoords(3, 1, type, colour);
        cells[2].setCoords(3, 2, type, colour);
        cells[3].setCoords(4, 1, type, colour);
    }
    else if(type == 'I') {
        cells[0].setCoords(3, 0, type, colour);
        cells[1].setCoords(3, 1, type, colour);
        cells[2].setCoords(3, 2, type, colour);
        cells[3].setCoords(3, 3, type, colour);
    }
    else if(type == 'S') {
        cells[0].setCoords(3, 1, type, colour);
        cells[1].setCoords(3, 2, type, colour);
        cells[2].setCoords(4, 0, type, colour);
        cells[3].setCoords(4, 1, type, colour);
    }
    else if(type == 'Z') {
        cells[0].setCoords(3, 0, type, colour);
        cells[1].setCoords(3, 1, type, colour);
        cells[2].setCoords(4, 1, type, colour);
        cells[3].setCoords(4, 2, type, colour);
    }
    else if(type == 'O') {
        cells[0].setCoords(3, 0, type, colour);
        cells[1].setCoords(3, 1, type, colour);
        cells[2].setCoords(4, 0, type, colour);
        cells[3].setCoords(4, 1, type, colour);
    }
}


Block::~Block() {
  
 // delete cells;
 
}


void Block::drawBlock() {
    if(type == 'L') {
        cout << "  L" << endl;
        cout << "LLL" << endl;
    }
    else if(type == 'J') {
        cout << "J  " << endl;
        cout << "JJJ" << endl;
    }
    else if(type == 'T') {
        cout << "TTT" << endl;
        cout << " T " << endl;
    }
    else if(type == 'I') {
        cout << "IIII" << endl;
    }
    else if(type == 'S') {
        cout << " SS" << endl;
        cout << "SS" << endl;
    }
    else if(type == 'Z') {
        cout << "ZZ" << endl;
        cout << " ZZ" << endl;
    }
    else if(type == 'O') {
        cout << "OO" << endl;
        cout << "OO" << endl;
    }
}

Block &Block::operator=(const Block &other) {
    if(this == &other) {return *this; }
    this->colour = other.colour;
    this->cells[0] = other.cells[0];
    this->cells[1] = other.cells[1];
    this->cells[2] = other.cells[2];
    this->cells[3] = other.cells[3];
    return *this;
}


void Block::down() {
        
    int r0 = cells[0].getRow();
    int c0 = cells[0].getCol();
    
    int r1 = cells[1].getRow();
    int c1 = cells[1].getCol();
    
    int r2 = cells[2].getRow();
    int c2 = cells[2].getCol();
    
    int r3 = cells[3].getRow();
    int c3 = cells[3].getCol();
    
    if(r3+1 == 14) { isSpace = false; } 
        
    cells[0].setCoords(r0+1, c0, type, colour);
    cells[1].setCoords(r1+1, c1, type, colour);
    cells[2].setCoords(r2+1, c2, type, colour);
    cells[3].setCoords(r3+1, c3, type, colour);  
    
}


void Block::left() {
        
    int r0 = cells[0].getRow();
    int c0 = cells[0].getCol();
    
    int r1 = cells[1].getRow();
    int c1 = cells[1].getCol();
    
    int r2 = cells[2].getRow();
    int c2 = cells[2].getCol();
    
    int r3 = cells[3].getRow();
    int c3 = cells[3].getCol();
       
    cells[0].setCoords(r0, c0-1, type, colour);
    cells[1].setCoords(r1, c1-1, type, colour);
    cells[2].setCoords(r2, c2-1, type, colour);
    cells[3].setCoords(r3, c3-1, type, colour);  

}


void Block::right() {
        
    int r0 = cells[0].getRow();
    int c0 = cells[0].getCol();
    
    int r1 = cells[1].getRow();
    int c1 = cells[1].getCol();
    
    int r2 = cells[2].getRow();
    int c2 = cells[2].getCol();
    
    int r3 = cells[3].getRow();
    int c3 = cells[3].getCol();
    
    cells[0].setCoords(r0, c0+1, type, colour);
    cells[1].setCoords(r1, c1+1, type, colour);
    cells[2].setCoords(r2, c2+1, type, colour);
    cells[3].setCoords(r3, c3+1, type, colour);  

}


char Block::getType() { return type; }

unsigned long Block::getColour() { return colour; }

void Block::setType(char type ) { this->type = type; }

Cell &Block::getCell(int num) { return cells[num]; }

bool Block::getIsSpace() { return isSpace; }


