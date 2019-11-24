CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = quadris
OBJECTS = main.o cell.o textdisplay.o grid.o block.o level.o level0.o level1.o level2.o level3.o window.o trie.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -I/usr/X11R6/include -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

