#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
#include "window.h"

class Cell {
      bool isFree;
      int x, y;
      int height, width;
      int r, c;
      unsigned long color;
      char letter;
  public:
      Cell();                    // Default constructor
      ~Cell();                   // Default destructor
      int getRow();
      int getCol();
      char getLet();
      unsigned long getColor();
      void setColor(unsigned long color);
      void setLet(char let);
      bool getFree();           
      void setFree();          
      void unFree();          
      void setCoords(int r, int c, char letter, unsigned long colour);
      void notifyDisplay(TextDisplay &t, Xwindow &w, unsigned long colour); 
      Cell &operator=(const Cell &other);            
    
};
#endif
