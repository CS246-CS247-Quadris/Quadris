// Level1.h
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include <iostream>
#include "level.h"

// subclass Level1:
class Level1: public Level {
public:
    // constructor:
    Level1();
    // Generating Next Block according to the Level1 rules:
    Block *getNextBlock();
};

#endif
