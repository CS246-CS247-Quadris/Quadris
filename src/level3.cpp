//
//  Level3.cpp
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//
#include <iostream>
#include "level3.h"
#include "block.h"
#include <cstdlib>
#include <ctime>
using namespace std;

static int mem[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
static int seek = 0;

Level3::Level3():Level(3){}

bool checking3(int i) {
    for (int j = 0; j < 9; j++){
        if (mem[j] == i) return true;
    }
    return false;
}

void checkmem3(){
    bool id = true;
    for (int j = 0; j < 9; j++){
        if (mem[j] == 9) {
            id = false;
            break;
        }
        else id = true;
    }
    if (id) {
        for (int j = 0; j < 9; j++) mem[j] = 9;
    }
}

Block* Level3::getNextBlock(){
    int count = 9;
    char sequent[] = {'S', 'Z', 'Z', 'J', 'L', 'I', 'S', 'T', 'O'};
    unsigned long colseq[] = {4, 5, 5, 2, 7, 1, 4, 6, 3};
    if (seeder != 0) srand(seeder);
    int buf = rand() % count;
    while (true) {
        if (checking3(buf)) {
            buf = rand() % count;
            continue;
        }
        else {
            mem[seek++] = buf;
            break;
        }
    }
    seek = seek % count;
    checkmem3();
    Block *init = new Block(sequent[buf],colseq[buf]);
	
    return init;
}
