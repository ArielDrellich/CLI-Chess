#include "PrintLogic.h"

// FEN separator for strtok()
const char SEP[] = "/";

//prints columns for printBoardFromFEN function
void printColumns() {
	char column = 'A';
	printf("* |");
	for (int i = 0; i < SIZE; i++) {
		if (i)
			printf(" ");
		printf("%c", column);
		column++;
	}
	printf("| *\n");
}

//prints spacers for printBoardFromFEN function
void printSpacers() {
	printf("* -");
	for (int i = 0; i < SIZE; i++) {
		printf("--");
	}
	printf(" *\n");
}

//prints rows for printBoardFromFEN function
void printRow(char row[], int rowIdx) {
	printf("%d ", rowIdx);
	int i = 0;
	while (row[i]) {
		if (isdigit(row[i])) {
			int spaces = toDigit(row[i++]);
			for (int j = 0; j < spaces; j++) {
				printf("| ");
			}
		}
		else {
			printf("|%c", row[i++]);
		}
	}
	printf("| %d\n", rowIdx);
}

/***************
* Function Name: printBoardFromFEN
* Input: fen as a array of chars
* Output:
* Function Operation: calls other basic functions and prints a representaion of the board from the fen
*****************/
void printBoardFromFEN(char fen[]) {
	printColumns();
	printSpacers();
	int rowIdx = SIZE;
	char* fenRow = strtok(fen, SEP);
	while (fenRow != NULL) {
		printRow(fenRow, rowIdx--);
		fenRow = strtok(NULL, SEP);
	}
	printSpacers();
	printColumns();
}

/***************
* Function Name: printBoard
* Input: board
* Output:
* Function Operation: prints the array board with spacers and cloumns
*****************/
void printBoard(char board[][SIZE]) {
	int rowIdx = SIZE;
	for (int i = 0; i < BOARDHEIGHT; i++) {
		if (i == 0) {
			printColumns();
			continue;
		}
		if(i == BOARDHEIGHT - 1) {
			printColumns();
			printf("\n");
			continue;
		}
		if (i == 1 || i == BOARDHEIGHT - 2) {
			printSpacers();
			continue;
		}
		for (int j = 0; j < SIZE; j++) {
			if (j == 0)
				printf("%d ", rowIdx);
			printf("|%c", board[i - 2][j]);
			if (j == SIZE - 1) {
				printf("| %d\n", rowIdx--);
			}
		}
	}
}


/***************
* Function Name: printFen
* Input: board to print
* Function Operation: prints current state of board to screen in fen format
*****************/
void printFen(char board[][SIZE]) {
	char fen[SIZE*SIZE + SIZE];
	int fenIndex = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != ' ') {
				fen[fenIndex++] = board[i][j];
			}
			else {
				//count spaces in a row
				int spaceCounter = 0;
				for (; board[i][j] == ' ' && j < SIZE; j++, spaceCounter++);
				j--;
				fen[fenIndex++] = '0' + spaceCounter;
			}
		}
		//slashes in between rows 
		if (i != SIZE - 1)
			fen[fenIndex++] = '/';
	}
	printf("FEN is: %s\n\n", fen);
}
