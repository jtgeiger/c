/*
 * ch3.cpp
 *
 *  Created on: Jan 26, 2010
 *      Author: jt
 */

#include "Polynomial_ch03ex07.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Started." << endl;
	Polynomial_ch03ex07 poly;
	poly.SetCoefficient( 5, 4 );
	poly.SetCoefficient( 3, 7 );
	poly.SetCoefficient( 2, -1 );
	poly.SetCoefficient( 0, 9 );
	poly.PrintYourself();
	cout << "Degree=" << poly.Degree() << endl;
	cout << "coef(3)=" << poly.RetrieveCoefficient( 3 ) << endl;
	cout << "coef(4)=" << poly.RetrieveCoefficient( 4 ) << endl;
	poly.SetCoefficient( 7, -3 );
	cout << "Degree=" << poly.Degree() << endl;
	cout << "Highest degree's coef=" << poly.RetrieveCoefficient( poly.Degree() ) << endl;
	poly.SetCoefficient( 3, poly.RetrieveCoefficient( 3 ) + 8 );
	poly.PrintYourself();
	cout << "coef(3)=" << poly.RetrieveCoefficient( 3 ) << endl;
	return 0;
}
