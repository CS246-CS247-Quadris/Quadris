// Level0.h
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include <iostream>
#include "level.h"
#include <string>

// subclass Level0:
class Level0: public Level {
public:
    // constructor:
    Level0();
    // Generating Next Block according to the Level0 rules:
    Block *getNextBlock();
};

#endif
