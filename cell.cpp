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



// returns value of isFree - accessor
bool Cell::getFree() {return isFree;}


// mutator for isFree
void Cell::setFree() {
    isFree = true;
    letter = ' ';
    color = 0;
}

// mutates isFree as false
void Cell::unFree() { isFree = false;}


// initializes all fields of cell
void Cell::setCoords(int r, int c, char letter, unsigned long colour) {
 this->r = r;
 this->c = c;
 this->x = (6+c)*220/MAX_COLUMN;
 this->y = (r+3.4)*506/23;
 this->width = 220/MAX_COLUMN-1;
 this->height = 506/23-1;
 this->letter = letter;
this->color = colour;
 }
 

// notifies text display and graphical display
void Cell::notifyDisplay(TextDisplay &t, Xwindow &w, unsigned long colour){
    t.notify(r, c, letter);
     this->color = colour;
    w.fillRectangle(x, y, width, height, color);
    if(colour != 0) { w.fillRectangle(x+5, y+5, width-10, height-10, colour+1);  w.fillRectangle(x+8, y+8, width-16, height-16, colour+2); }
}


// Overloads operator= 
Cell& Cell::operator=(const Cell &other) {
    if(this == &other) { return *this; }
    letter = other.letter;
    isFree = other.isFree;
    c = other.c;
    r = other.r;
    color = other.color;
    return *this;
}


// mutator for color field
void Cell::setColor(unsigned long color) { this->color = color; }


// accessor for r field
int Cell::getRow() { return r; }

// accessor for c field
int Cell::getCol() {return c; }

// accessor for letter field
char Cell::getLet() {return letter; }

// accessor for color field
unsigned long Cell::getColor() { return color; }

// mutator for letter field
void Cell::setLet(char let) { this->letter = let; }

