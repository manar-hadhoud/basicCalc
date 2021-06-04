// basicCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BigInt.h"
#include "string.h"

int main()
{
	std::string x, y;
	std::cin >> x;
	std::cin >> y;



	BigInt op1(x);
	BigInt op2(y);
	//op2.toString();

	op1.add(op2);

	//this code has only one problem when you enter 0001 the output is 0001 also
	//the redundant left zeroes need to be trimmed from the array
	/*for (int i = 0; x[i] != '\0'; i++) {
		xint[i] = (x[i]) - '0';
		std::cout << xint[i];
	}*/
	

	//op1.toString();

}
