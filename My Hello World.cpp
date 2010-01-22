//============================================================================
// Name        : My.cpp
// Author      : JT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void PrintDeck( int deck[], int size )
{
	for ( int i = 0; i < size; i++ )
	{
		cout << "Deck[" << i << "]=" << deck[i] << endl;
	}
}

int main() {
	int bacon = 7;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << bacon << endl;
	const int DECK_SIZE = 52;
	int deck[DECK_SIZE];
	for ( int i = 0; i < DECK_SIZE; i++ )
		deck[i] = i + 1;
	PrintDeck( deck, DECK_SIZE );
	return 0;
}
