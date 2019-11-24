//
//  Level2.cpp
//  Quadris
//
//  Created by Russell on 2014-03-28.
//  Copyright (c) 2014 ___Russell___. All rights reserved.
//

#include <iostream>
#include "level2.h"
#include "block.h"
#include <cstdlib>
#include <ctime>
using namespace std;

static int mem[7] = {7, 7, 7, 7, 7, 7, 7};
static int seek = 0;

Level2::Level2():Level(2){}

bool checking2(int i){
    for (int j = 0; j < 7; j++) {
        if (mem[j] == i) return true;
    }
    return false;
}

void checkmem2() {
    bool id = true;
    for (int j = 0; j < 7; j++) {
        if (mem[j] == 7) {
            id = false;
            break;
        }
        else id = true;
    }
    if (id) {
        for (int j = 0; j < 7; j++) mem[j] = 7;
    }
}

Block* Level2::getNextBlock(){
    int count = 7;
    char sequent[] = {'I', 'J', 'O', 'S', 'Z', 'T', 'L'};
    unsigned long colseq[] = {1, 2, 3, 4, 5, 6, 7};
    if (seeder != 0) srand(seeder);
    int buf = rand() % count;
    while (true) {
        if (checking2(buf)) {
            buf = rand() % count;
            continue;
        }
        else {
            mem[seek++] = buf;
            break;
        }
    }
    seek = seek % count;
    checkmem2();
    Block *init = new Block(sequent[buf],colseq[buf]);

    return init;
}
