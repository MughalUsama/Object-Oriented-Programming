#include "Account.h"



Account::Account()
{
	this->balance = 0;
}

Account::Account(double initialDeposit)
{
	if (initialDeposit<0)
	{
		throw "Amount cannot be negative";
	}
	this->balance = initialDeposit;
}

double Account::getBalance()
{
	return this->balance;
}

double Account::deposit(double amount)
{
	if (amount< 0)
	{
		throw "Amount cannot be negative";
	}
	balance += amount;
	return balance;
}

double Account::withdraw(double amount)
{
	if (amount < 0 || amount >this->balance)
	{
		throw "Amount cannot be negative or more than balance";
	}
	balance -= amount;
	return balance;
}
