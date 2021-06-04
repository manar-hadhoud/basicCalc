#include "BigInt.h"
#include <vector>
#include <string>
#include <iostream>

BigInt::BigInt() {

}
BigInt::BigInt(std::string input) {
	if (input.size() == 0)
		return;
	reverse(input.begin(), input.end());
	for (int i = 0; input[i] != '\0'; i++) {
		this->numInt.push_back((input[i]) - '0');
	}
	this->setSize();
}

// print the array of integers inside the object
void BigInt::toString() {
	for (auto i = this->numInt.rbegin(); i != this->numInt.rend(); ++i)
		std::cout << *i;
}

void BigInt::setSize() {
	this->size = (int) this->numInt.size();
}

// convert the input char to int and add it to the end of the array of Ints.
void BigInt::addDigit(char digit) {
	this->numInt.push_back(digit - '0');
	this->setSize();
}
// add an int to the end of the array of Ints.
void BigInt::addDigit(int digit) {
	this->numInt.push_back(digit);
	this->setSize();
}

//TODO: solve the issue of different size numbers
//TODO: change the function to return bigInt as well

//add 2 Bigints and put the result in a new Bigint 
void BigInt::add(BigInt op2) {
	//initializing some values
	BigInt finalResult("");
	int smallerSize = this->numInt.size() < op2.numInt.size() ? this->numInt.size() : op2.numInt.size();
	int carry = 0, counter = 0;
	//loop over the smaller size int and add each element to the corresponding element in the other array
	for (auto i = this->numInt.begin(), j = op2.numInt.begin(); counter< smallerSize; ++counter, (i != this->numInt.end()) ? ++i : (i + 0), j != op2.numInt.end() ? ++j : j + 0)
	{
		int result = carry + *i + *j;
		if (result > 9) {
			result = result - 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		//check if last round
		if (counter + 1 == smallerSize)
			if(this->size == op2.size)
				finalResult.addDigit(carry? result + 10 : result);
			else if(this->size > op2.size){
				//hanazl el arkam bta3to
				finalResult.addDigit(result);
				for (++i; i != this->numInt.end(); ++i) {
					result = carry + *i;
					if (result > 9) {
						result = result - 10;
						carry = 1;
					}
					else {
						carry = 0;
					}
					finalResult.addDigit(result);
				}
				
				//finalResult.addDigit(int)
			}
			else {
				finalResult.addDigit(result);
				for (++j; j != op2.numInt.end(); ++j) {
					result = carry + *j;
					if (result > 9) {
						result = result - 10;
						carry = 1;
					}
					else {
						carry = 0;
					}
					finalResult.addDigit(result);
				}
			}
		else
			finalResult.addDigit(result);
	}
	//print the final result to use the value return it and change the return datatype to BigInt
	finalResult.toString();
}
void BigInt::sub(BigInt op2) {

}
