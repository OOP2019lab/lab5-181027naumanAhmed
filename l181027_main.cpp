#include "bankAccount.h"




void main()
{


	//Exercise 4
	bankAccount myAccount("John Doe" , 549002);
	myAccount.printBankAccount();


	//Exercise 5,6
	for(int i=0; i < 20; i++)
		myAccount.deposit(i*200);
	
	myAccount.withDraw(8000);

	myAccount.printBankAccount();

}