/*
 * Polynomial_ch03ex07.h
 *
 *  Created on: Jan 26, 2010
 *      Author: jt
 */

#ifndef POLYNOMIAL_CH03EX07_H_
#define POLYNOMIAL_CH03EX07_H_

const int MAX_POLYNOMIAL = 10;

class Polynomial_ch03ex07 {
public:
	Polynomial_ch03ex07();
	virtual ~Polynomial_ch03ex07();

	int Degree();
	void SetCoefficient( int I, int Value );
	int RetrieveCoefficient( int I );
	void PrintYourself();
private:
	int Polys[MAX_POLYNOMIAL];
};

#endif /* POLYNOMIAL_CH03EX07_H_ */
