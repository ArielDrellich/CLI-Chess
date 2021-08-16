#ifndef __PRINTLOGIC_H
#define __PRINTLOGIC_H
#include "GameLogic.h"

void printColumns();
void printSpacers();
void printRow(char row[], int rowIdx);
void printBoardFromFEN(char fen[]);
void printBoard(char board[][SIZE]);
void printFen(char board[][SIZE]);

static char helpText[] = "_____Help_____\n\nIn-Game Commands:\n1) exit: enter \"exit\" to leave the game.\n\
2) restart: enter \"restart\" to go back to the main menu.\n3) fen: enter \"fen\" to print the current\
 state of the board (to save for future games).\nFor more information about pgn commands and fen, visit chess.com.\n\n";

#endif