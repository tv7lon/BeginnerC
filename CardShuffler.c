#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define ROW 4
#define COLUMN 13
#define NUMCARDS 52

void populateDeck(int deckIn[][COLUMN], int positionsUsed[], int posCounterIn);
bool isFree(int positionsUsedIn[], int valueToSearch, int posCounterIn);
void printOrder(int deckIn[][COLUMN], const char* suitsIn[], const char* ranksIn[]);
void printDeck(int deckIn[][COLUMN], const char* suitsIn[], const char* ranksIn[]);


int main(){
	
	srand(time(NULL));
	const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char* ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	int deck[ROW][COLUMN] = { 0 };
	int positionsUsed[NUMCARDS] = { 0 };
	int posCounter = 0;

	populateDeck(deck, positionsUsed, posCounter);
	printOrder(deck, suits, ranks);
	printf("\n\n\n");
	printDeck(deck, suits, ranks);

	return 0;
}

void populateDeck(int deckIn[][COLUMN], int positionsUsedIn[], int posCounterIn) {
	for (int i = 0; i < ROW; i++)
	{
		for (int j= 0; j < COLUMN; j++)
		{
			while (deckIn[i][j] == 0) {
				int position = rand() % 52 + 1; //generate a position
				if (isFree(positionsUsedIn, position, posCounterIn))
				{
					deckIn[i][j] = position; //assign this position; inc position; add to used array 
					positionsUsedIn[posCounterIn] = position; // add this position			
					posCounterIn++;
				}
			}
		}
	}

}
bool isFree(int positionsUsedIn[], int valueToSearch, int posCounterIn) {
	for (int i = 0; i < NUMCARDS; i++)
	{
		if (positionsUsedIn[i] == valueToSearch)
		{
			return false; //should stop here and not do lines 51-53
		}
	}

	return true;
 }

// must specify num columns 
void printOrder(int deckIn[][COLUMN], const char* suitsIn[], const char* ranksIn[]) {

	for (int i = 0; i < COLUMN; i++)
	{
		printf("\t%s", ranksIn[i]);
	}
	printf("\n");
	for (int i = 0; i < ROW; i++)
	{
		printf("\n%s : ", suitsIn[i]);
		for (int j = 0; j < COLUMN; j++)
		{
			printf("%2d\t", deckIn[i][j]);
		}
	}
}

void printDeck(int deckIn[][COLUMN], const char* suitsIn[], const char* ranksIn[]) {
	for (int counter = 0; counter < NUMCARDS; counter++)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				if (deckIn[i][j] == counter)
				{
					printf("%5s of %9s\n", ranksIn[j], suitsIn[i]);
				}
			}
		}
	}
	

}
