# goosegame

TCP Client-Server game that allows a player to confront a CPU in a two-dimensional variation of The Game of The Goose.

# The rules

The aim of the game is for the Player (P) to get to the opposite corner of the field before the opponent (C) does so. The numbers on the field represents bonuses.

```
P| | | | | | | | |C|
 | | | | | | | | | |
2| | | | | | | | | |
 | | | | | | |3|3| |
 | | | | | | | | | |
 |2|1| | | | | | |1|
 | | | | | | | |1| |
 | | | | | | | | | |
 | | | | | | | | | |
 | | | | | | | | | |
 
Roll of the dice gave 1 + 3 = 4

Choose your move by typing a number :
7|8|9
4| |6
1|2|3
1
 
--------------------

 | | | | | | | | | |
 | | | | | | | | | |
2| | | | | | | | | |
 | | | | | | |3|3| |
 | | | | | | | | | |
 |2|1| | | | | | |1|
 | | | | | | | |1| |
 | | | | | | | | | |
 | | | | | | | | | |
C| | | | | |P| | | |

You lost, let's play another match
```

# Compilation
Note: Make sure [CMake](https://cmake.org/download/) is available on your machine

---

Run:

```sh
cd <repo-clone>
cmake .
make
```
  
# Execution
  
- Launch the `GameServer` executable, which will wait for an incoming TCP request. 
- Launch the `GameClient` executable.
