#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
private:
	double balance;

public:
	Account();
	Account(double initialDeposit);
	double getBalance();
	double deposit(double amount);
	double withdraw(double amount);
};

#endif