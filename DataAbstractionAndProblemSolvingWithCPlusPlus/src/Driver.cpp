/*
 * Driver.cpp
 *
 *  Created on: Jan 31, 2010
 *      Author: jt
 */
#include <iostream>
#include "ch2.h"
#include "ch3.h"
using namespace std;

int main()
{
	cout << "Started driver." << endl;

	//int ret = main_ch2();
	int ret = main_ch3();

	cout << "Finished driver." << endl;
	return ret;
}
