#include <iostream>
#include <string>
#include <cstdlib>
#include "textdisplay.h"

using namespace std;


// Ctor --> creates a char grid of 10x15
TextDisplay::TextDisplay(){
    theDisplay = new char* [MAX_ROW];
    for(int m=0; m < MAX_ROW; m++) {
        theDisplay[m] = new char[MAX_COLUMN];
    }
    
    for(int i=0; i < MAX_ROW; i++) {
        for(int j=0; j < MAX_COLUMN; j++) {
            theDisplay[i][j] = ' ';
        }
    }
}

// changes value of ch in given coordinates, if theDisplay is not Null
void TextDisplay::notify(int r, int c, char ch){
    if(theDisplay) {
        theDisplay[r][c] = ch;
    }
}


// Dtor
TextDisplay::~TextDisplay(){
    for(int i=0; i < MAX_ROW; i++) {
        delete [] theDisplay[i];       // deallocate colums
    }
    delete [] theDisplay;            // deallocate rows
}

//  Overload operator<<
ostream &operator<<(ostream &out, const TextDisplay &td){
    for(int i=0; i < MAX_ROW; i++) {
        for(int j=0; j < MAX_COLUMN; j++) {
            out<<td.theDisplay[i][j];
        }
        out<<endl;
    }
    return out;
}



