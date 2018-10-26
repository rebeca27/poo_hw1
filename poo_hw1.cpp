// poo_hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BigInteger.h"

int main()
{
	BigInteger nr1 = BigInteger("12334");

	std::cout << "Hello World! I have changed this line changed\n";
	std::cout << nr1.toString();
}
