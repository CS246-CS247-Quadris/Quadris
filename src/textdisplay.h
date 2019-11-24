#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <iostream>
#include <sstream>

#define MAX_COLUMN 10
#define MAX_ROW 15


class TextDisplay {
    char **theDisplay;
  public:
    TextDisplay();   // Default constructor
    void notify(int r, int c, char ch);
    ~TextDisplay();   // Default destructor
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
