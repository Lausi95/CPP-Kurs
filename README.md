# CPP-Course Projects
Some C\+\+ / SDL2 games, wich are programmed during the C\+\+ Course in the University "Freie Universität Berlin".
Included are three projects:
- A Pacman clone with no enemies. The player just collects points and fruits
- A "Space" Game, in wich the player flies a space ship throug the stars with paralax scrolling to simulate depth
- A Sidescroller game, wich is a self invented game. It was the proof that we had learned the necessary skills to write a program in c++ to pass the course.

## Prerequisites
```
apt-get install gcc make cmake
```

## Dependencies
The projects are depending on SDL2 and some SDL2-Modules. To install them on Ubuntu run following:
```
apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
```

## Build
All projects are CMake Projects. So to create the make script, run
```
cmake
```
and to build the project:
```
make
```
this will create a binary wich can be executed. 

## Note
The working directory must be the same directory where the binary is, because otherwise, the assetes are not found and the programs will only display a black screen.

## Contibutors
- Hendrik van Essen
- Tom Lausmann
