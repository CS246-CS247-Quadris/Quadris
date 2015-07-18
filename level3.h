// Level3.h
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include <iostream>
#include "level.h"

// subclass Level3:
class Level3: public Level {
public:
    // constructor:
    Level3();
    // Generating Next Block according to the Level3 rules:
    Block *getNextBlock();
};

#endif
