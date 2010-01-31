/*
 * ch5.cpp
 *
 *  Created on: Jan 31, 2010
 *      Author: jt
 */

#include "ch5.h"
#include <iostream>
using namespace std;

int isPalindrome( const char str[], int start, int end )
{
	if ( start >= end )
		return 1;
	else
		return ( str[start] == str[end] && isPalindrome( str, start + 1, end - 1 ) );
}

int main_ch5()
{
	cout << "Started chapter 5." << endl;

	cout << "Empty: " << isPalindrome( "", 0, 0 ) << endl;
	cout << "One: " << isPalindrome( "G", 0, 0 ) << endl;
	cout << "Two: " << isPalindrome( "GG", 0, 1 ) << endl;
	cout << "Two (non): " << isPalindrome( "GV", 0, 1 ) << endl;
	cout << "Three: " << isPalindrome( "GVG", 0, 2 ) << endl;
	cout << "Three (non): " << isPalindrome( "GVR", 0, 2 ) << endl;
	cout << "Four: " << isPalindrome( "GVVG", 0, 3 ) << endl;
	cout << "Four (non): " << isPalindrome( "GVRG", 0, 3 ) << endl;

	return 0;
}
