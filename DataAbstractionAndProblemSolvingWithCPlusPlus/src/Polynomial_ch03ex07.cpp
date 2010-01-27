/*
 * Polynomial_ch03ex07.cpp
 *
 *  Created on: Jan 26, 2010
 *      Author: jt
 */

#include "Polynomial_ch03ex07.h"
#include <iostream>
using namespace std;

Polynomial_ch03ex07::Polynomial_ch03ex07() {
	for ( int i = 0; i < MAX_POLYNOMIAL; i++ )
	{
		Polys[i] = 0;
	}
}

Polynomial_ch03ex07::~Polynomial_ch03ex07() {
	// TODO Auto-generated destructor stub
}

int Polynomial_ch03ex07::Degree()
{
	int degree = 0;

	for ( int i = MAX_POLYNOMIAL - 1; degree == 0 && i >= 0; i-- )
	{
		if ( Polys[i] != 0 )
		{
			degree = i;
		}
	}

	return degree;
}

//Not part of the exercise; added this one myself:
void Polynomial_ch03ex07::PrintYourself()
{
	for ( int i = MAX_POLYNOMIAL - 1; i >= 0; i-- )
	{
		if ( Polys[i] != 0 )
		{
			if ( Polys[i] > 0 )
				cout << "+";

			cout << Polys[i];

			if ( i > 0 )
				cout << "x^" << i;
		}
	}

	cout << endl;
}

int Polynomial_ch03ex07::RetrieveCoefficient( int I )
{
	return Polys[I];
}

void Polynomial_ch03ex07::SetCoefficient( int I, int Value )
{
	Polys[I] = Value;
}
