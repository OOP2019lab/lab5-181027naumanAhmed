#include<iostream>
#include<string>
using namespace std;

class bankAccount 
{

private:

	string name;
	int accountNumber;
	float accountBalance;
	float balanceLimit;

	float *transactions;
	int noOfTransactions;
	int capacity;

	void increaseArray();

public:

	bankAccount();
	bankAccount(string, int);
	void printBankAccount();
	void withDraw(float);
	void deposit(float);
	~bankAccount();

};