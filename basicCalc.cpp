// basicCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "string.h"
#include<vector>



struct BigInt {
	std::vector<int> numInt;
	int size;
};

void pout(BigInt op1);
BigInt add(BigInt op1, BigInt op2);
void sub(BigInt op1, BigInt op2);
void addDigit(char digit, BigInt &op1);
void addDigit(int digit, BigInt &op1);
void setSize(BigInt &op1);
void initialize(std::string input, BigInt &op1);









int main()
{
	std::string x, y;
	std::cin >> x;
	std::cin >> y;

	BigInt op1;
	BigInt op2;
	initialize(x, op1);
	initialize(y, op2);

	BigInt result = add(op1,op2);
	pout(result);
	//op1.toString();

}

void initialize(std::string input, BigInt &op1) {
	if (input.size() <= 0)
		return;
	reverse(input.begin(), input.end());
	for (int i = 0; input[i] != '\0'; i++) {
		op1.numInt.push_back((input[i]) - '0');
	}
	setSize(op1);
}

void pout(BigInt op1) {
	for (auto i = op1.numInt.rbegin(); i != op1.numInt.rend(); ++i)
		std::cout << *i;
}

void setSize(BigInt &op1) {
	op1.size = (int)op1.numInt.size();
}

// convert the input char to int and add it to the end of the array of Ints.
void addDigit(char digit, BigInt &op1) {
	op1.numInt.push_back(digit - '0');
	setSize(op1);
}
// add an int to the end of the array of Ints.
void addDigit(int digit, BigInt &op1) {
	op1.numInt.push_back(digit);
	setSize(op1);
}


BigInt add(BigInt op1, BigInt op2) {
	//initializing some values
	BigInt finalResult;
	int smallerSize = op1.size < op2.size ? op1.size : op2.size;
	int carry = 0, result = 0;
	auto i = op1.numInt.begin(), j = op2.numInt.begin();
	//loop over the smaller size int and add each element to the corresponding element in the other array
	for (int counter = 0; counter < smallerSize; ++counter, (i != op1.numInt.end()) ? ++i : (i + 0), j != op2.numInt.end() ? ++j : j + 0)
	{
		result = carry + *i + *j;
		if (result > 9) {
			result = result - 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		//check if last round
		if (counter + 1 == smallerSize)
			continue;
		addDigit(result, finalResult);
	}
	if (op1.size == op2.size)
		addDigit(carry ? result + 10 : result, finalResult);
	else if (op1.size > op2.size) {
		//hanazl el arkam bta3to
		addDigit(result, finalResult);
		for (i; i != op1.numInt.end(); ++i) {
			result = carry + *i;
			if (result > 9) {
				result = result - 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			addDigit(result, finalResult);
		}

	}
	else {
		addDigit(result, finalResult);
		for (j; j != op2.numInt.end(); ++j) {
			result = carry + *j;
			if (result > 9) {
				result = result - 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			addDigit(result, finalResult);
		}
	}
	if(carry)
		addDigit(carry, finalResult);
	//print the final result to use the value return it and change the return datatype to BigInt
	return (finalResult);
}


