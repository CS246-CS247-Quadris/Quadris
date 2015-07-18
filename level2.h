// Level2.h
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include <iostream>
#include "level.h"

// subclass Level2:
class Level2: public Level {
public:
    // constructor:
    Level2();
    // Generating Next Block according to Level2 rules:
    Block *getNextBlock();
};

#endif
