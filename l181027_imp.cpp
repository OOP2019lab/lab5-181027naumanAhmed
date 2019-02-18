#include "bankAccount.h"

// default constructor
bankAccount::bankAccount()
{
	//initialization to default values:

		accountNumber =0;
		accountBalance =0;
		balanceLimit = 200000;

		noOfTransactions =0;
		capacity = 10;


}

//parameterized constructor
bankAccount::bankAccount(string nam, int accNum)
{

	//reinitialization to default values:

		accountNumber =0;
		accountBalance =0;
		balanceLimit = 200000;

		noOfTransactions = 0;
		capacity =10;

	//dynamic transaction array created:

		transactions = new float[capacity];

	//assigning values passed through constructor call:

		name = nam;
		accountNumber = accNum;

}


//prints bank account details
void bankAccount::printBankAccount()
{

	cout<< "Name of account holder: " << name << endl;
	cout<< "Accounnt Number: " << accountNumber << endl;
	cout<< "Account Balance: " << accountBalance << endl;
	cout<< "Total transactions: " << noOfTransactions << endl;
	cout<< "Transactions: ";


	cout<< "{";
	for(int i =0; i <noOfTransactions; i++)
	{
		cout<< transactions[i];
		if ( i != noOfTransactions -1)
			cout<<",";
	}
	cout<<"}" << endl;

}



// deposit function
void bankAccount::deposit(float amount)
{

	
	if ( amount + accountBalance <= balanceLimit)
	{
		cout<<"Transaction Successful!\n";
		accountBalance += amount;

		
		if(noOfTransactions >= capacity)
		{
			//utility function called
			increaseArray();

		}
		transactions[noOfTransactions] = +amount;
		noOfTransactions++;

	}
	else
		cout<<"Transaction Unsuccessful!\nBalance limit reached!\n";

}

//withdraw function
void bankAccount::withDraw(float amount)
{

	if ( amount  < accountBalance)
	{
		cout<<"Transaction Successful!\n";
		accountBalance -= amount;

		if(noOfTransactions >= capacity)
		{

			increaseArray();

		}
		transactions[noOfTransactions] = -amount;
		noOfTransactions++;

	}
	else
		cout<<"Transaction Unsuccessful!\nInsufficient Balance!\n";

}


//utility function to increase array
void bankAccount:: increaseArray()
{
	float *arr = new float[capacity*2];

	for(int i =0; i < capacity; i++)
	{
		arr[i] = transactions[i];
	}

	delete [] transactions;
	transactions = arr;


	capacity *=2;

}

//destructor
bankAccount::~bankAccount()
{

	accountNumber = 0;
	accountBalance = 0;
	balanceLimit = 0;

	noOfTransactions = 0;
	capacity =0;

	delete [] transactions;
	transactions = nullptr;


}