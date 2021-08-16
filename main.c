#include "PrintLogic.h"
#include "GameLogic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void main() {
	char board[SIZE][SIZE];
	char defaultFen[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	char fen[64];
	int keepPlaying = 1;
	int playOption;
	int i = 0;
	char pgn[9];
	while (keepPlaying) {
		printf("_____Welcome to Chess!_____\nTo start a new game, enter 1.\nTo resume a game, enter 2: ");
		scanf(" %d", &playOption);
		if (playOption == 2) {
			printf("Please type a legal FEN to resume game: ");
			scanf("%s", fen);
		} else strcpy(fen, defaultFen);

		createBoard(board, fen);
		printf("\n_____New Game_____\n\nFor help at any point, enter \"help\".\n\n");

		printBoard(board);
		do {
			if ((i + 1) % 2)
				printf("_____White's turn____\nInput a legal command: ");
			else
				printf("_____Black's turn____\nInput a legal command: ");

			scanf("%s", pgn);
			printf("\n");

			if (!strcmp(pgn, "restart")) {
				i = 0;
				break;
			}

			if (!strcmp(pgn, "exit") || !strcmp(pgn, "quit")) {
				keepPlaying = 0;
				break;
			}

			if (!strcmp(pgn, "help")) {
				printf("%s", helpText);
				continue;
			}

			if (!strcmp(pgn, "fen")) {
				printFen(board);
				continue;
			}

			if (makeMove(board, pgn, (i + 1) % 2)) {
				i++;
                printBoard(board);
            } else
				printf("Illegal move/input\n\n");

		} while (!makeMove(board, pgn, (i + 1) % 2));
	}
}
