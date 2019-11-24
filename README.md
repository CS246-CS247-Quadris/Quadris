# Quadris
Non-Real Time Tetris Game

## CS246: Deliverables, Group Project (Winter 2014)

- **Instructor**: B. Lushman
- **Due Date 1**: Friday, March 28, 5pm
- **Due Date 2**: Friday, April 4, 11:59pm
- Grading will proceed in two phases, outlined below:

### Correctness and Completeness (60%)
The correctness and completeness component of your project will be assessed via a live demo in front of a TA. You will need to sign up for a 20-minute demo slot with a TA; both group members should show up, and you should plan a demo that takes the TA on a tour through all of the required features of the project. Be prepared to explain to the TA how you implemented the various parts of your project. At any time, the TA may ask you to demonstrate a particular element of your project (e.g., whether some boundary case is handled properly). If there is a component of your project that is not working, advise the TA, rather than pretend that it does. After you have demonstrated the core requirements, you may demonstrate any additional features of the project that you may have implemented, for extra credit. The TA will assess the worth of your additional features after your demo is over.

### Documentation (20%) and Design (20%)
Your documentation and design will be assessed via written documents that you will submit to Marmoset as pdfs.

#### On Due Date 1
Submit a plan of attack. This should include a UML that describes how you anticipate your system to be structured (even if you complete the project by due date 1, the UML you submit must be one that you built prior to starting the project). Your UML should show the classes that make up your project and the relationships between them. You only need to show public methods (i.e, you can leave out private fields and protected/private methods, unless you need to show them to illustrate a point, e.g., a design pattern). You will not graded on the degree to which you adhere to this model, but you will be asked to account for any differences that arise between this model and your final submission. In addition your plan of attack must include a breakdown of the project, indicating what you plan to do first, what will come next, and so on. Include estimated completion dates, and which partner will be responsible for which parts of the project. You should try to stick to your plan, but you will not be graded by the degree to which you stick to it. Your initial plan should be realistic, and you will be expected to explain why you had to deviate from your plan (if you did). Finally, your initial plan of attack must include answers to all questions listed within the project specification itself. You should answer in terms of how you would anticipate solving these problems in your project, even though you are not strictly required to do so. If your answers turn out to be inconsistent with your final design, you will have an opportunity to submit revised answers on Due Date 2. Your plan should be no more than 5 pages long.

#### On Due Date 2
On Due Date 2, you must submit all of your code to Marmoset, together with a Makefile, such that issuing the command make builds your project. Your executable should be called quadris for Quadris, cc3k for ChamberCrawler 3000, or chess for Chess. In addition, you must submit a final design document. It must outline the final, actual design of your project, and how it differed from your design on Due Date 1 (if it did). You should include an updated UML, reflecting the actual structure of your project. Do this even if it is the same as the original UML. Your document should provide an overview of all aspects of your project, including how, at a high level, they were implemented. If you made use of design patterns, clearly indicate where. Your system should employ good object-oriented design techniques, as presented in class. Include all answers to questions posed within the project specification, and indicate how they differ from the answers you gave on Due Date 1 (if they did). You should not expect the TA’s to read through all of your code. Therefore, your design document should stand alone – the TA should not need to have your code open in order to understand your document. However, if you wish to highlight certain aspects of your design, you should indicate clearly where they can be found in your code, if the TA wants to have a look.

#### Finally, answer the following questions:
​- What lessons did this project teach you about developing software in teams? If you worked alone, what lessons did you learn about writing large programs?
​- What would you have done differently if you had the chance to start over?

This project is intended to be doable by two people in two weeks. Because the breadth of students’ ablilities in this course is quite wide, exactly what constitutes two weeks’ worth of work for two students is difficult to nail down. Some groups will finish quickly; others won’t finish at all. We will attempt to grade this assignment in a way that addresses both ends of the spectrum. You should be able to pass the assignment with only a modest portion of your program working. Then, if you want a higher mark, it will take more than a proportionally higher effort to achieve, the higher you go. A perfect score will require a complete implementation. If you finish the entire program early, you can add extra features for a few extra marks. Above all, MAKE SURE YOUR SUBMITTED PROGRAM RUNS. The markers do not have time to examine source code and give partial correctness marks for nonworking programs. So, no matter what, even if your program doesn’t work properly, make sure it at least does something.

## Plan of Attack
- **QUESTION**: How could you design your system to make sure that only these seven kinds of blocks can be generated, and in particular, that non-standard configurations (where, for example, the four pieces are not adjacent) cannot be produced?
- **ANSWER**: We decided to initialize each block according to the given character that is one of `I`, `J`, `S`, `Z`, `T`, `O`, or `L`. Hence, if something else is given, it will not create any block and none of the `Cell`'s will be occupied.
- **QUESTION**: How could you design your system (or modify your existing design) to allow for some generated blocks to disappear from the screen if not cleared before 10 more blocks have fallen? Could the generation of such blocks be easily confined to more advanced levels?
- **ANSWER**: Since `Block`s consist of `Cell`s, and each `Cell` has the field called `isFree` and describes whether it is occupied, for `Block`s to disappear we will set each of `Block`s’ `Cell`s free and call `notifyDisplay`. If you meant how `Block`s will disappear while clearing full line, we will call removeline method, and since we do not keep track of dropped `Block`s, removeline method is not about `Block`s, it is about `Cell`s.
- **QUESTION**: How could you design your program to accommodate the possibility of introducing additional levels into the system, with minimum recompilation?
- **ANSWER**: Actually we have a superclass named `Level` and 4 subclasses for each level, so we would create a new subclass for addition level.
- **QUESTION**: How could you design your system to accommodate the addition of new command names, or changes to existing command names, with minimal changes to source and minimal recompilation? (We acknowledge, of course, that adding a new command probably means adding a new feature, which can mean adding a non-trivial amount of code.) How difficult would it be to adapt your system to support a command whereby a user could rename existing commands (e.g. something like rename counter-clockwise cc)?
- **ANSWER**: If new command is added, we would create a new class with definition and declaration of that command and then we can easily connect it to the main source code with `Visitor Pattern`. That will not change other classes and game will accept it.

Among them the main ones are `Grid`, `Block`, and `Level`. One of us – Samir Musali will be responsible for writing implementation of `Level` and its subclasses, and another – Rasul Rasulzada will be responsible for writing implementation of `TextDisplay`, `XWindow`, and `Cell`. We will write implementation of others – `Grid` and `Block` together. The game will be established on `Grid`. `Grid` has 2 `Block` pointers: `current(Block)` and `next(Block)`. `Block`s themselves consist of 4 `Cell`s regardless of their types. `Block`s have their own identification character which will differ one from another according to their type. The movement command functions are defined in the `Block`, and in addition to identification character every `Block` has colour. Default level is set as `Level` 0; so, the game starts within `Level` 0, and the next blocks will be generated according to `sequence.txt`. In the beginning of the game firstly `getNext(Block)` will be called, it will produce our first current block on the `Grid`, and then we will call it again; so, the game is ready to start. After `Drop` command is executed, `current(Block)` will be updated and `getNext(Block)` will be called again to generate new `Block`. The way of generating blocks changes by the `Level`. If player wants to change `Level`, the game will be go on, but the method of generating `Block`s will be changed. If the game will be restarted, the all in `Grid` except `hiScore` will be recreated. We can see that `Down` is a kind of `Drop`; in other words, `Drop` consists of finite number of `Down` functions; so, after each dropping, `Grid` will check its lines in which line is full or not; if any line is full, it will be cleared, and everything above come down. Each `Cell` has its `isFree` field which shows it is active (or occupied) or not. When `next(Block)` will replace the `current(Block)`, the `Cell`s of `next(Block)` will be activated. We know that moving `Block` means moving its `Cell`s; so, when the `Block` will change its coordinates, the `Cell`s in the old coordinates will be freed and the new ones will be occupied. We will use the method `Draw(Block)` for drawing it under the game board to show which `Block` is next. We will use `TextDisplay` and `XWindow` similarly as we used in Assignment 4. In addition, we want to add extra feature called skip in the end of implementation; so, this new feature will skip the `current(Block)`, `current(Block)` will be replaced by `next(Block)`, and new `next(Block)` will be generated.

**Note**: If you have not already done so for Assignment 4, make sure you are able to use graphical applications from your Unix session. If you are using Linux you should be fine (if making an ssh connection to a campus machine, be sure to pass the -Y option). If you are using Windows and putty, you should download and run an X server such as XMing, and be sure that putty is configured to forward X connections. Alert course staff immediately if you are unable to set up your X connection (e.g. if you can’t run xeyes). Also (if working on your own machine) make sure you have the necessary libraries to compile graphics. Try executing the following:
```
g++ -L/usr/X11R6/lib src/window.cc src/graphicsdemo.cc -lX11 -o src/graphicsdemo
```

## The Game of Quadris
In this project, you and a partner will work together to produce the video game Quadris, which is a Latinization of the game Tetris. A game of Quadris consists of a board, 10 columns wide and 15 rows high. Blocks consisting of four cells (tetrominoes) appear at the top of the screen, and you must drop them onto the board so as not to leave any gaps. Once an entire row has been filled, it disappears, and the blocks above move down by one unit. Quadris differs from Tetris in one significant way: it is not real-time. You have as much time as you want to decide where to place a block. There are seven types of blocks, shown below with their names and initial configurations:
1. **I-block**:
```
IIII
```
2. **J-block**:
```
  J
JJJ
```
3. **L-block**:
```
L
LLL
```
4. **O-block**:
```
OO
OO
```
5. **S-block**:
```
 SS
SS
```
6. **Z-block**:
```
ZZ
 ZZ
```
7. **T-block**:
```
TTT
 T
```

- **Question**: How could you design your system to make sure that only these seven kinds of blocks can be generated, and in particular, that non-standard configurations (where, for example, the four pieces are not adjacent) cannot be produced?
- **Question**: How could you design your system (or modify your existing design) to allow for some generated blocks to disappear from the screen if not cleared before 10 more blocks have fallen?
- **Question**: Could the generation of such blocks be easily confined to more advanced levels?

Blocks can be moved and rotated. When a block is rotated, it should be done such that the position of the lower left corner of the smallest rectangle containing the block is preserved. For a clockwise rotation, this means that the lower-right corner of the block should take the place of the lower-left corner of the original block. For a counterclockwise rotation, this means that the top-left corner of the block should take the place of the lower-left corner of the original block. A few examples follow (clockwise rotation):
- **J-block**:
```
J   > JJ
JJJ > J
    > J
```
- **S-block**:
```
 SS > S
SS  > SS
    >  S
```

The coordinate axes shown above should be understood as being fixed in space, and are there to show the position of the rotated block relative to that of the original.

### Board
The board should be 10 columns and 15 rows. Reserve three extra rows at the top of the board to  give room for blocks to rotate, without falling off the board. If a block is at the extreme right-hand side of the board, to the extent that there is no horizontal room to rotate it, it can’t be rotated. When a block shows up on the board, it appears in the top-left corner, just below the three reserve rows. If there is not room for the block in this position, the game is over. When a block is dropped onto the board, check to see whether any rows have been completely filled as a result of the block having dropped. If so, remove those rows from the board, and the remaining blocks above these rows move down to fill the gap.

### Display
You need to provide both a text-based display and a graphical display of your game board. A sample text display follows:
```
Level: 1
Score: 0
Hi Score: 100
———-
TTT
ST
ZSS
ZZIS
ZJI
OO JI
IIIIOOJJI
———
Next:
L
LLL
```
Your graphical display should be set up in a similar way, showing the current board, the current block, the next block to come, and the scoreboard in a single window. The block types should be colour-coded, each type of block being rendered in a different colour. Do your best to make it visually pleasing.

### Next Block
Part of your system will encapsulate the decision-making process regarding which block is selected next. The level of difficulty of the game depends on the policy for selecting the next block. You are to support the following difficulty levels:
- **Level 0**: (Make sure you at least get this one working!) Takes its blocks in sequence from the file sequence.txt (a sample is provided). This level is non-random, and can be used to test with a predetermined set of blocks.
- **Level 1**: The block selector will randomly choose a block with probabilities skewed such that S and Z blocks are selected with probability 12 each, and the other blocks are selected with probability 16 each.
- **Level 2**: All blocks are selected with equal probability.
- **Level 3**: The block selector will randomly choose a block with probabilities skewed such that S and Z blocks are selected with probability 29 each, and the other blocks are selected with probability 19 each.

For random numbers, you can use the `rand` and `srand` functions from `cstdlib`. Alternatively, you can use the PRNG class from the course notes (p. 116), which has been provided for you.

- **Question**: How could you design your program to accommodate the possibility of introducing additional levels into the system, with minimum recompilation?

### Command Interpreter
You interact with the system by issuing text-based commands. The following commands are to be supported:
- `left` moves the current block one cell to the left. If this is not possible (left edge of the board, or block in the way), the command has no effect.
- `right` as above, but to the right.
- `down` as above, but one cell downward.
- `clockwise` rotates the block 90 degrees clockwise, as described earlier. If the rotation cannot be accomplished without coming into contact with existing blocks, the command has no effect.
- `counterclockwise` as above, but counterclockwise.
- `drop` drops the current block. It is (in one step) moved downward as far as possible until it comes into contact with either the bottom of the board or a block. This command also triggers the next block to appear. Even if a block is already as far down as it can go (as a result of executing the down command), it still needs to be dropped in order to get the next block.
- `levelup` increases the difficulty level of the game by one. The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no higher level, this command has no effect.
- `leveldown` decreases the difficulty level of the game by one. The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no lower level, this command has no effect.
- `restart` clears the board and starts a new game.
- `End-of-file (EOF)` terminates the game.

Only as much of a command as is necessary to distinguish it from other commands needs to be  entered. For example, lef is enough to distinguish the left command from the levelup command, so the system should understand either lef or left as meaning left. In addition, commands can take a multiplier prefix, indicating that that command should be executed some number of times. For example 3ri means move to the right by three cells. If, for example, it is only possible to move to the right by two cells, then the block should move to the right by two cells. Similarly, 2levelu means increase the level by two. Prefixes of 0 or 1 are permitted, and mean that the comand should be run 0 times and 1 time, respectively. It is valid to apply a multiplier to the drop command. The command 3dr (or 3dro or 3drop) means drop the current block and then drop the following two blocks from their default position. It is not valid to apply a multiplier to the restart command (if a multiplier is supplied, it would have no effect).

- **Question**: How could you design your system to accommodate the addition of new command names, or changes to existing command names, with minimal changes to source and minimal recompilation? (We acknowledge, of course, that adding a new command probably means adding a new feature, which can mean adding a non-trivial amount of code.) How difficult would it be to adapt your system to support a command whereby a user could rename existing commands (e.g. something like rename `counterclockwise` `cc`)?

The board should be redrawn, both in text and graphically, each time a command is issued. For the graphic display, redraw as little of the screen as is necessary to make the needed changes.

### Scoring
The game is scored as follows: when a line (or multiple lines) is cleared, you score points equal to (your current level, plus number of lines) squared. (For example, clearing a line in level 2 is worth 9 points.) In addition, when a block is completely removed from the screen (i.e., when all of its cells have disappeared) you score points equal to the level you were in when the block was generated, plus one, squared. (For example if you got an **O-block** while on level 0, and cleared the **O-block** in level 3, you get 1 point.) You are to track the current score and the hi score. When the current score exceeds the hi score, the hi score is updated so that it matches the current score. When the game is restarted, the current score reverts to 0, but the hi score persists until the program terminates.

### Command-line Interface (CLI)
Your program should support the following options on the command line:
- `-text` runs the program in text-only mode. No graphics are displayed. The default behaviour (no -text) is to show both text and graphics.
- `-seed xxx` sets the random number generator’s seed to `xxx`. If you don’t set the seed, you always get the same random sequence every time you run the program. It’s good for testing, but not much fun.
- `-scriptfile xxx` uses `xxx` instead of `sequence.txt` as a source of blocks for level 0.
- `-startlevel n` starts the game in level `n`. The game starts in level 0 if this option is not supplied.

### Grading
Your project will be graded as follows:
- **Correctness and Completeness**: 60%
- **Documentation**: 20%
- **Design**: 20%

Does it work? Does it implement all of the requirements?
Even if your program doesn’t work at all, you can still earn a lot of marks through good documentation and design, (in the latter case, there needs to be enough code present to make a reasonable assessment).

#### If Things Go Wrong
If you run into trouble and find yourself unable to complete the entire assignment, please do your best to submit something that works, even if it doesn’t solve the entire assignment. For example:
- can’t do block rotations
- program only produces text output; no graphics
- only one level of difficulty implemented
- does not recognize the full command syntax
- score not calculated correctly

You will get a higher mark for fully implementing some of the requirements than for a program that attempts all of the requirements, but doesn’t run. A well-documented, well-designed program that has all of the deficiencies listed above, but still runs, can still potentially earn a passing grade.

#### Plan for the Worst
Even the best programmers have bad days, and the simplest pointer error can take hours to track down. So be sure to have a plan of attack in place that maximizes your chances of always at least having a working program to submit. Prioritize your goals to maximize what you can demonstrate at any given time. We suggest: save the graphics for last, and first do the game in pure text. One of the first things you should probably do is write a routine to draw the game board (probably a `Board` class with an overloaded friend operator `<<`). It can start out blank, and become more sophisticated as you add features. You should also do the command interpreter early, so that you can interact with your program. You can then add commands one-by-one, and separately work on supporting the full command syntax. Take the time to work on a test suite at the same time as you are writing your project. Although we are not asking you to submit a test suite, having one on hand will speed up the process of verifying your implementation. You will be asked to submit a plan, with projected completion dates and divided responsibilities, as part of your documentation for Due Date 1.

#### If Things Go Well
If you complete the entire project, you can earn up to 10% extra credit for implementing extra features. These should be outlined in your design document, and markers will judge the value of your extra features.

## Final Design Document
Among them the main ones are `Grid`, `Block`, and `Level`. One of us – Samir Musali was responsible for writing implementation of `Level` and its subclasses, and another – Rasul Rasulzada was responsible for writing implementation of `TextDisplay`, `XWindow`, and `Cell`. We wrote implementation of others – `Grid` and `Block` together. The game is established on `Grid`. `Grid` has 2 `Block` pointers: `currentBlock` and `nextBlock`. `Block`s themselves consist of 4 `Cell`s regardless of their types. `Block`s have their own identification character which will differ one from another according to their type. The movement command functions are defined in the Block except rotate functions, and in addition to identification character every Block has a colour. Default level is set as `Level 0`; so, the game starts within `Level 0`, and the next blocks will be generated according to the given file; so, if there is no file, `Level 0` takes `sequence.txt`. In the beginning of the game firstly `getNextBlock` is called, it produces our first current block on the `Grid`, and then we call it again; so, the game is ready to start. After `Drop` command is executed, `currentBlock` is updated and `getNextBlock` will be called again to generate new Block. The way of generating blocks changes by the `Level`. If player wants to change `Level`, the game will be go on, but the method of generating `Block`s will be changed. The block showing as next still comes next, but subsequent blocks are generated using the new level. If the game is restarted, the all in `Grid` except `hiScore` is recreated. We can see that `Down` is a kind of `Drop`; in other words, `Drop` consists of finite number of `Down` functions; so, after each dropping, `Grid` will check its lines in which line is full or not; if any line is full, it will be cleared, and everything above comes down. Each `Cell` has its isFree field which shows it is active (or occupied) or not. When `nextBlock` replaces the `currentBlock`, the `Cell`s of `nextBlock` will be appeared on `Grid`. We know that moving `Block` means moving its `Cell`s; so, when the `Block` changes its coordinates, the `Cell`s in the old coordinates will be freed and the new ones will be occupied. We used the method `DrawBlock` for drawing it under the game board to show which `Block` is next. We used `TextDisplay` and `XWindow` similarly as we used in Assignment 4. In addition, we want to add extra feature called `skip` in the end of implementation; so, this new feature skips the `currentBlock`, `currentBlock` will be replaced by `nextBlock`, and new `nextBlock` will be generated. We have also used `trie.h` library from the Assignment 3 in the `main.cpp` for reading shortened commands. We have also used the special design for graphical display, as extra feature.

- **QUESTION**: How could you design your system to make sure that only these seven kinds of blocks can be generated, and in particular, that non-standard configurations (where, for example, the four pieces are not adjacent) cannot be produced?
- **ANSWER**: We decided to initialize each block according to the given character that is one of `I`, `J`, `S`, `Z`, `T`, `O` or `L`. Hence, if something else is given, it will not create any block and none of the `Cell`s will be occupied.
- **QUESTION**: How could you design your system (or modify your existing design) to allow for some generated blocks to disappear from the screen if not cleared before 10 more blocks have fallen? Could the generation of such blocks be easily confined to more advanced levels?
- **ANSWER**: Since `Block`s consist of `Cell`s, and each `Cell` has the field called `isFree` and describes whether it is occupied, for `Block`s to disappear we will set each of `Block`s’ `Cell`s free and call `notifyDisplay`. If you meant how `Block`s will disappear while clearing full line, we will call removeline method, and since we do not keep track of dropped `Block`s, `removeline` method is not about `Block`s, it is about `Cell`s.
- **QUESTION**: How could you design your program to accommodate the possibility of introducing additional levels into the system, with minimum recompilation?
- **ANSWER**: Actually we have a superclass named `Level` and 4 subclasses for each level, so we would create a new subclass for addition level.
- **QUESTION**: How could you design your system to accommodate the addition of new command names, or changes to existing command names, with minimal changes to source and minimal recompilation? (We acknowledge, of course, that adding a new command probably means adding a new feature, which can mean adding a non-trivial amount of code.) How difficult would it be to adapt your system to support a command whereby a user could rename existing commands (e.g. something like rename `counterclockwise` `cc`)?
- **ANSWER**: If new command is added, we would create a new class with definition and declaration of that command and then we can easily connect it to the main source code with `Visitor Pattern`. That will not change other classes and game will accept it.
- **QUESTION**: What lessons did this project teach you about developing software in teams? If you worked alone, what lessons did you learn about writing large programs?
- **ANSWER**: We have learned working with classes using different patterns. We have learned how to write efficient codes, handle the memory leaks, and work on graphical display.
- **QUESTION**: What would you have done differently if you had the chance to start over?
- **ANSWER**: If we had the chance to start over, we would add two extra functions: one of them substitutes the `NextBlock` with the `CurrentBlock`, and another one finds out the appropriate place for the `CurrentBlock` to drop; also we would like to write the program using `ncurses` library for convenience.