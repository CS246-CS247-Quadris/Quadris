// Level0.cpp
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#include <iostream>
#include <fstream>
#include "level0.h"
#include "block.h"
#include <string>
using namespace std;

// for keeping track of block types according to the required probability;
// in this case, Blocks will be generated according to the given file; so,
// Block types in the file will first be loaded into string, and
// the same [positioned] char member of the string must not be selected till all char members are selected.
// After all char members are selected, mem will again be zero; i.e. refreshing.
static int mem = 0;

// Constructor:
Level0::Level0():Level(0){
    filename = "sequence.txt";
}

Block* Level0::getNextBlock(){
    string take;                                // for reading from the file
    string buf = "";                            // for keeping all things in the file without whitespace
    ifstream seq;                               // for opening the file
    seq.open(filename.c_str());                 // opening provided file
    while (seq >> take) {buf += take;}          // loading into buf
    seq.close();                                // closing provided file since loading process is completed
    unsigned long color = mem + 1;              // setting color
    int count = buf.length();
    /* Colors will be same for the same positioned member of buf; in other words, for the same type of block */

    Block *init = new Block(buf[mem++],color);  // creating new Block with the type and color
    if (mem == count) {mem = 0;}                    // refreshing mem
    return init;                                // return the new created Block
}
