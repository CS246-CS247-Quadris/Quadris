// Level1.cpp
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#include <iostream>
#include "level1.h"
#include "block.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// this array is used to keep track of Block types according to the given probability;
// since 5 of them have probability of 1/6; and others have 1/12; totally, 12 member array
// needs to be used, mechanics is going likewise in Level0.cpp:
static int mem[12] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
static int seek = 0;                                                                 // for keeping the position of members in mem[12];
                                                                                     // seek's role is the same as mem's in Level0.cpp

Level1::Level1():Level(1){}

bool checking1(int i){
    for (int j = 0; j < 12; j++) {
        if (mem[j] == i) return true;
    }
    return false;
}

void checkmem1() {
    bool id = true;
    for (int j = 0; j < 12; j++) {
        if (mem[j] == 12) {
            id = false;
            break;
        }
        else id = true;
    }
    if (id) {
        for (int j = 0; j < 12; j++) mem[j] = 12;
    }
}

Block* Level1::getNextBlock(){
    int count = 12;
    char sequent[] = {'I', 'J', 'O', 'S', 'Z', 'T', 'L', 'I', 'J', 'O', 'T', 'L'};
    unsigned long colseq[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 7};
    if (seeder != 0) srand(seeder);
    int buf = rand() % count;
    while (true) {
        if (checking1(buf)) {
            buf = rand() % count;
            continue;
        }
        else {
            mem[seek++] = buf;
            break;
        }
    }
    seek = seek % 12;
    checkmem1();
    Block *init = new Block(sequent[buf],colseq[buf]);
    
    return init;
}
