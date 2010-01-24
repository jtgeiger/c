/*
 * ch2.cpp
 *
 *  Created on: Jan 24, 2010
 *      Author: jt
 */

#include <iostream>
using namespace std;

double Product_st1( const double A[], int N )
{
	if ( N == 1 )
		return A[0];
	else
		return A[N - 1] * Product_st1( A, N - 1 );
}

void Product_st2( const double A[], int N, double& Product )
{
	if ( N == 1 )
		Product = A[0];
	else
	{
		Product_st2( A, N - 1, Product );
		Product *= A[N - 1];
	}
}

double Product_st4( const double A[], int First, int Last )
{
	if ( First == Last )
		return A[First];
	else
		return A[Last] * Product_st4( A, First, Last - 1 );
}

void WriteIntegers_st3( int N )
{
	if ( N > 0 )
	{
		cout << N;
		WriteIntegers_st3( N - 1 );
	}
}

int main()
{
	double myArray[] = { 3, 6, 9 };
	cout << Product_st1( myArray, 3 ) << endl;

	double startProduct;	//Not initialized here; done in the function.
	Product_st2( myArray, 3, startProduct );
	cout << startProduct << endl;

	WriteIntegers_st3( 6 );
	cout << endl;

	cout << Product_st4( myArray, 0, 2 ) << endl;
	cout << Product_st4( myArray, 0, 1 ) << endl;
	cout << Product_st4( myArray, 0, 0 ) << endl;
	return 0;
}
