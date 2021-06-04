#pragma once
#include <iostream>
#include <vector>
class BigInt
{
public:
	std::vector<int> numInt;
	int size;

	BigInt();
	BigInt(std::string input);

	void toString();
	void add(BigInt op2);
	void sub(BigInt op2);
	void addDigit(char digit);
	void addDigit(int digit);
	void setSize();

};

