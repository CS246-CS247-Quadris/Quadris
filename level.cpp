// Level.cc
// Project: Quadris
// Samir Musali [20491904], Rasul Rasulzada [20488806]

#include <iostream>
#include "block.h"
#include "level.h"
#include <string>
using namespace std;

Level::Level(int current) {curLevel = current;}

Level::~Level() {}

int Level::getLevelNum() {return curLevel;}

void Level::setFile(std::string file){ filename = file;}

void Level::setSeeder(unsigned int given){seeder = given;}
