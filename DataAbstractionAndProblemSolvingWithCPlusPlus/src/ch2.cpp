/*
 * ch2.cpp
 *
 *  Created on: Jan 24, 2010
 *      Author: jt
 */

#include <iostream>
#include <string.h>
using namespace std;

int MaxArray_ex12( const int A[], int First, int Last)
{
	cout << "First=" << First << ", Last=" << Last << endl;

	if ( First == Last )
	{
		cout << "Returning A[" << First << "]=" << A[First] << endl;
		return A[First];
	}
	else
	{
		int mid = ( Last + First ) / 2;		//1
		int firstMax = MaxArray_ex12( A, First, mid );		//0, 1
		cout << "First max=" << firstMax << endl;
		int secondMax = MaxArray_ex12( A, mid + 1, Last );	//2, 3
		cout << "Second max=" << secondMax << endl;

		if ( firstMax > secondMax )
			return firstMax;
		else
			return secondMax;
	}
}

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

void WriteBackwards_ex11( char S[], int Len )
{
	if ( Len == 0 )
	{
		//No-op.
	}
	else
	{
		WriteBackwards_ex11( S + 1, Len - 1 );
		cout << S[0];
	}
}

void WriteDigits_ex02( int Number )
{
	//Number=1234 -> 4321
	if ( Number > 0 )
	{
		cout << Number % 10;
		WriteDigits_ex02( Number / 10 );
	}
}

void WriteIntegers_st3( int N )
{
	//N=6 -> 654321
	if ( N > 0 )
	{
		cout << N;
		WriteIntegers_st3( N - 1 );
	}
}

void WriteIntegers_ex01( int N )
{
	//N=6 -> 123456
	if ( N > 0 )
	{
		WriteIntegers_ex01( N - 1 );
		cout << N;
	}
}

int Notmain()
{
	double myArray[] = { 3, 6, 9 };
	cout << Product_st1( myArray, 3 ) << endl;

	double product;	//Not initialized here; done in the function.
	Product_st2( myArray, 3, product );
	cout << product << endl;

	WriteIntegers_st3( 6 );
	cout << endl;

	cout << Product_st4( myArray, 0, 2 ) << ", "
	     << Product_st4( myArray, 0, 1 ) << ", "
	     << Product_st4( myArray, 0, 0 ) << endl;

	WriteIntegers_ex01( 6 );
	cout << endl;

	WriteDigits_ex02( 4321 );
	cout << ", ";
	WriteDigits_ex02( 10765 );
	cout << ", ";
	WriteDigits_ex02( 4 );
	cout << endl;

	char str[] = "My test.";
	WriteBackwards_ex11( str, strlen( str ) );
	cout << endl;

	int array2[] = {3, 2, 1, 4, 7, 13, 3, 11, 6, 0};
	cout << "Max=" << MaxArray_ex12( array2, 0, 9 ) << endl;

	cout << "All done, " "bye." << endl;
	return 0;
}
