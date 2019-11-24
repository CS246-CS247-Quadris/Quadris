// Level.h
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <iostream>
#include <string>

class Block;                                 // forward declaration of Block;

class Level{
    int curLevel; 
 protected:
    std::string filename;
    unsigned int seeder;
 public:
    Level(int current);                      // Constructor;
    virtual ~Level() = 0;                    // Virtual Destructor;
    int getLevelNum();                       // To publicly know which level this is;
    virtual Block *getNextBlock() = 0;       // Generating Next Block;
    void setFile(std::string file);
    void setSeeder(unsigned int given);
};

#endif
