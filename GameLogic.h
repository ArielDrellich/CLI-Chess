#ifndef __GAMELOGIC_H
#define __GAMELOGIC_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define SIZE 8
#define FENSIZE (strlen(fen) - (SIZE - 1))
#define BOARDHEIGHT (SIZE + 4)
#define COLSIZE 'a' + SIZE - 1

// Move logical representation
typedef struct {
	char srcPiece, srcRow, srcCol, promotionPiece, destRow, destCol;
	int iSrc, jSrc, iDest, jDest, haveiSrc, havejSrc;
	int isWhite, isCapture, isPromotion, isCheck, isMate, couldntFindSrc;
} Move;

enum color{none, white, black};

void createBoard(char board[][SIZE], char fen[]);
int toDigit(char c);
int charToDigit(char c);
int isWhite(char piece);
int isInCheck(char board[][SIZE], Move move);
int willBeInCheck(char board[][SIZE], Move move, int isWhiteTurn);
int canReach(char board[][SIZE], Move move);
int doPromotion(char board[][SIZE], Move move);
int straightPath(char board[][SIZE], Move move);
int diagonalPath(char board[][SIZE], Move move);
int isBlocked(char board[][SIZE], Move move);
int doMove(char board[][SIZE], Move move, int isWhiteTurn);
int makeMove(char board[][SIZE], char pgn[], int isWhiteTurn);
Move findSrc(char board[][SIZE], Move move, int isWhiteTurn);
Move readMove(char pgn[], int isWhiteTurn);
Move initializeMove();

#endif