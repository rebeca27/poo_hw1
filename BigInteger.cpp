#include "pch.h"
#include "BigInteger.h"


BigInteger::BigInteger()
{
}

BigInteger::BigInteger(const char* numberSequence)
{
	this->numberSequence = (char*)numberSequence;
	this->base = 10;
	this->isUnsigned = numberSequence[0] != '-';
}

BigInteger::BigInteger(const char* numberSequence, int base)
{
	this->numberSequence = (char*)numberSequence;
	this->base = base;
	this->isUnsigned = numberSequence[0] == '-';
}

BigInteger::~BigInteger()
{
	delete this->numberSequence;
	delete &this->base;
	delete &this->isUnsigned;
}

int BigInteger::getBase()
{
	return this->base;
}


char BigInteger::getSign()
{
	return this->isUnsigned ? '+' : '-';
}

char* BigInteger::toString()
{
	return this->numberSequence;
}

