#ifndef __CHESS_H
#define __CHESS_H
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 8


void createBoard(char board[][SIZE], char fen[]);
void printBoard(char board[][SIZE]);
int makeMove(char board[][SIZE], char pgn[], int isWhiteTurn);
void printBoardFromFEN(char fen[]);

void printFen(char board[][SIZE]);
char helpText[] = "_____Help_____\n\nIn-Game Commands:\n1) exit: enter \"exit\" to leave the game.\n\
2) restart: enter \"restart\" to go back to the main menu.\n3) fen: enter \"fen\" to print the current\
 state of the board (to save for future games).\nFor more information about pgn commands and fen, visit chess.com.\n\n";
#endif
