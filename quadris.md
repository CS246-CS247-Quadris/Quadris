CS246—Assignment 5, Group Project (Winter 2014)

B. Lushman

Due Date 1: Friday, March 28, 5pm

Due Date 2: Friday, April 4, 11:59pm

This project is intended to be doable by two people in two weeks.
Because the

breadth of students’ ablilities in this course is quite wide, exactly
what constitutes

two weeks’ worth of work for two students is difficult to nail down.
Some groups will

finish quickly; others won’t finish at all. We will attempt to grade
this assignment

in a way that addresses both ends of the spectrum. You should be able to
pass the

assignment with only a modest portion of your program working. Then, if
you want

a higher mark, it will take more than a proportionally higher effort to
achieve, the

higher you go. A perfect score will require a complete implementation.
If you finish

the entire program early, you can add extra features for a few extra
marks.

Above all, MAKE SURE YOUR SUBMITTED PROGRAM RUNS. The markers

do not have time to examine source code and give partial correctness
marks for nonworking programs. So, no matter what, even if your program
doesn’t work properly,

make sure it at least does something.

Note: If you have not already done so for Assignment 4, make sure you
are able to use graphical

applications from your Unix session. If you are using Linux you should
be fine (if making an

ssh connection to a campus machine, be sure to pass the -Y option). If
you are using Windows

and putty, you should download and run an X server such as XMing, and be
sure that putty is

configured to forward X connections. Alert course staff immediately if
you are unable to set up

your X connection (e.g. if you can’t run xeyes).

Also (if working on your own machine) make sure you have the necessary
libraries to compile

graphics. Try executing the following:

g++ -L/usr/X11R6/lib window.cc graphicsdemo.cc -lX11 -o graphicsdemo

The Game of Quadris

In this project, you and a partner will work together to produce the
video game Quadris, which is

a Latinization of the game Tetris.

A game of Quadris consists of a board, 10 columns wide and 15 rows high.
Blocks consisting of

four cells (tetrominoes) appear at the top of the screen, and you must
drop them onto the board

so as not to leave any gaps. Once an entire row has been filled, it
disappears, and the blocks above

move down by one unit.

Quadris differs from Tetris in one significant way: it is not real-time.
You have as much time

as you want to decide where to place a block.

The major components of the system are as follows:

1

Blocks

There are seven types of blocks, shown below with their names and
initial configurations:

IIII

J

JJJ

L

LLL

OO

OO

I-block

J-block

L-block

O-block

SS

SS

ZZ

ZZ

TTT

T

S-block

Z-block

T-block

Question: How could you design your system to make sure that only these
seven kinds of blocks

can be generated, and in particular, that non-standard configurations
(where, for example, the four

pieces are not adjacent) cannot be produced?

Question: How could you design your system (or modify your existing
design) to allow for some

generated blocks to disappear from the screen if not cleared before 10
more blocks have fallen?

Could the generation of such blocks be easily confined to more advanced
levels?

Blocks can be moved and rotated. When a block is rotated, it should be
done such that the

position of the lower left corner of the smallest rectangle containing
the block is preserved. For

a clockwise rotation, this means that the lower-right corner of the
block should take the place of

the lower-left corner of the original block. For a counterclockwise
rotation, this means that the

top-left corner of the block should take the place of the lower-left
corner of the original block. A

few examples follow (clockwise rotation):

|

|J

|JJJ

+—

—-$>$

|JJ

|J

|J

+—

|

| SS

|SS

+—

—-$>$

|S

|SS

| S

+—

The coordinate axes shown above should be understood as being fixed in
space, and are there to

show the position of the rotated block relative to that of the original.

Board

The board should be 10 columns and 15 rows. Reserve three extra rows at
the top of the board to

give room for blocks to rotate, without falling off the board. If a
block is at the extreme right-hand

side of the board, to the extent that there is no horizontal room to
rotate it, it can’t be rotated.

When a block shows up on the board, it appears in the top-left corner,
just below the three

reserve rows. If there is not room for the block in this position, the
game is over.

When a block is dropped onto the board, check to see whether any rows
have been completely

filled as a result of the block having dropped. If so, remove those rows
from the board, and the

remaining blocks above these rows move down to fill the gap.

Display

You need to provide both a text-based display and a graphical display of
your game board. A

sample text display follows:

Level:

1

Score:

0

Hi Score: 100

———-

TTT

T

S

ZSS

ZZIS

ZJI

OO JI

IIIIOOJJI

———Next:

L

LLL

Your graphical display should be set up in a similar way, showing the
current board, the current

block, the next block to come, and the scoreboard in a single window.
The block types should

be colour-coded, each type of block being rendered in a different
colour. Do your best to make it

visually pleasing.

Next Block

Part of your system will encapsulate the decision-making process
regarding which block is selected

next. The level of difficulty of the game depends on the policy for
selecting the next block. You

are to support the following difficulty levels:

$\bullet$ Level 0: (Make sure you at least get this one working!) Takes
its blocks in sequence

from the file sequence.txt (a sample is provided). This level is
non-random, and can be

used to test with a predetermined set of blocks.

$\bullet$ Level 1: The block selector will randomly choose a block with
probabilities skewed such that

1

S and Z blocks are selected with probability 12

each, and the other blocks are selected with

probability 16 each.

$\bullet$ Level 2: All blocks are selected with equal probability.

$\bullet$ Level 3: The block selector will randomly choose a block with
probabilities skewed such that

S and Z blocks are selected with probability 29 each, and the other
blocks are selected with

probability 19 each.

For random numbers, you can use the rand and srand functions from
$<$cstdlib$>$. Alternatively,

you can use the PRNG class from the course notes (p. 116), which has
been provided for you.

Question: How could you design your program to accommodate the
possibility of introducing

additional levels into the system, with minimum recompilation?

Command Interpreter

You interact with the system by issuing text-based commands. The
following commands are to be

supported:

$\bullet$ left moves the current block one cell to the left. If this is
not possible (left edge of the board,

or block in the way), the command has no effect.

$\bullet$ right as above, but to the right.

$\bullet$ down as above, but one cell downward.

$\bullet$ clockwise rotates the block 90 degrees clockwise, as described
earlier. If the rotation cannot

be accomplished without coming into contact with existing blocks, the
command has no effect.

$\bullet$ counterclockwise as above, but counterclockwise.

$\bullet$ drop drops the current block. It is (in one step) moved
downward as far as possible until

it comes into contact with either the bottom of the board or a block.
This command also

triggers the next block to appear. Even if a block is already as far
down as it can go (as a

result of executing the down command), it still needs to be dropped in
order to get the next

block.

$\bullet$ levelup Increases the difficulty level of the game by one. The
block showing as next still

comes next, but subsequent blocks are generated using the new level. If
there is no higher

level, this command has no effect.

$\bullet$ leveldown Decreases the difficulty level of the game by one.
The block showing as next still

comes next, but subsequent blocks are generated using the new level. If
there is no lower

level, this command has no effect.

$\bullet$ restart Clears the board and starts a new game.

End-of-file (EOF) terminates the game.

Only as much of a command as is necessary to distinguish it from other
commands needs to be

entered. For example, lef is enough to distinguish the left command from
the levelup command,

so the system should understand either lef or left as meaning left.

In addition, commands can take a multiplier prefix, indicating that that
command should be

executed some number of times. For example 3ri means move to the right
by three cells. If,

for example, it is only possible to move to the right by two cells, then
the block should move to

the right by two cells. Similarly, 2levelu means increase the level by
two. Prefixes of 0 or 1 are

permitted, and mean that the comand should be run 0 times and 1 time,
respectively. It is valid to

apply a multiplier to the drop command. The command 3dr (or 3dro or
3drop)) means drop the

current block and then drop the following two blocks from their default
position. It is not valid to

apply a multiplier to the restart command (if a multiplier is supplied,
it would have no effect).

Question: How could you design your system to accommodate the addition
of new command

names, or changes to existing command names, with minimal changes to
source and minimal

recompilation? (We acknowledge, of course, that adding a new command
probably means adding

a new feature, which can mean adding a non-trivial amount of code.) How
difficult would it be to

adapt your system to support a command whereby a user could rename
existing commands (e.g.

something like rename counterclockwise cc)?

The board should be redrawn, both in text and graphically, each time a
command is issued.

For the graphic display, redraw as little of the screen as is necessary
to make the needed changes.

Scoring

The game is scored as follows: when a line (or multiple lines) is
cleared, you score points equal to

(your current level, plus number of lines) squared. (For example,
clearing a line in level 2 is worth 9

points.) In addition, when a block is completely removed from the screen
(i.e., when all of its cells

have disappeared) you score points equal to the level you were in when
the block was generated,

plus one, squared. (For example if you got an O-block while on level 0,
and cleared the O-block in

level 3, you get 1 point.)

You are to track the current score and the hi score. When the current
score exceeds the hi

score, the hi score is updated so that it matches the current score.
When the game is restarted,

the current score reverts to 0, but the hi score persists until the
program terminates.

Command-line Interface

Your program should support the following options on the command line:

$\bullet$ -text runs the program in text-only mode. No graphics are
displayed. The default behaviour

(no -text) is to show both text and graphics.

$\bullet$ -seed xxx sets the random number generator’s seed to xxx. If
you don’t set the seed, you

always get the same random sequence every time you run the program. It’s
good for testing,

but not much fun.

$\bullet$ -scriptfile xxx Uses xxx instead of sequence.txt as a source
of blocks for level 0.

$\bullet$ -startlevel n Starts the game in level n. The game starts in
level 0 if this option is not

supplied.

Grading

Your project will be graded as follows:

Correctness and Completeness

60%

Documentation

Design

20%

20%

Does it work? Does it implement all of the

requirements?

Plan of attack; final design document.

UML; good use of separate compilation, good

object-oriented practice; is it well-stuctured,

or is it one giant function?

Even if your program doesn’t work at all, you can still earn a lot of
marks through good

documentation and design, (in the latter case, there needs to be enough
code present to make a

reasonable assessment).

If Things Go Wrong

If you run into trouble and find yourself unable to complete the entire
assignment, please do your

best to submit something that works, even if it doesn’t solve the entire
assignment. For example:

$\bullet$ can’t do block rotations

$\bullet$ program only produces text output; no graphics

$\bullet$ only one level of difficulty implemented

$\bullet$ does not recognize the full command syntax

$\bullet$ score not calculated correctly

You will get a higher mark for fully implementing some of the
requirements than for a program

that attempts all of the requirements, but doesn’t run.

A well-documented, well-designed program that has all of the
deficiencies listed above, but still

runs, can still potentially earn a passing grade.

Plan for the Worst

Even the best programmers have bad days, and the simplest pointer error
can take hours to track

down. So be sure to have a plan of attack in place that maximizes your
chances of always at least

having a working program to submit. Prioritize your goals to maximize
what you can demonstrate

at any given time. We suggest: save the graphics for last, and first do
the game in pure text. One

of the first things you should probably do is write a routine to draw
the game board (probably

a Board class with an overloaded friend operator$<$$<$). It can start
out blank, and become more

sophisticated as you add features. You should also do the command
interpreter early, so that you

can interact with your program. You can then add commands one-by-one,
and separately work on

supporting the full command syntax. Take the time to work on a test
suite at the same time as

you are writing your project. Although we are not asking you to submit a
test suite, having one

on hand will speed up the process of verifying your implementation.

You will be asked to submit a plan, with projected completion dates and
divided responsibilities,

as part of your documentation for Due Date 1.

If Things Go Well

If you complete the entire project, you can earn up to 10% extra credit
for implementing extra

features. These should be outlined in your design document, and markers
will judge the value of

your extra features.

Submission Instructions

See project guidelines.pdf for instructions about what should be
included in your plan of attack

and final design document.
