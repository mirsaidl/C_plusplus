#include <iostream>
#include <string>
#include "bank.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // # of accounts

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
	cout << "6. Delete account" << endl;
	cout << "7. Delete all accounts" << endl;
	cout << "8. Change ID" << endl;
}
void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;
	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}
	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;
	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, sizeof(accArr[accNum].cusName), name);
	accNum++;
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "Deposit completed"
				<< endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		<< endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance"
					<< endl << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "Withdrawal completed"
				<< endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		<< endl;
}

void ShowAllAccInfo(void) {
	if (accNum == 0) {
		cout << "No account to display. Please make an account first!" << endl;
	}
	
	
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i].accID << endl;
		cout << "Name: " << accArr[i].cusName << endl;
		cout << "Balance: " << accArr[i].balance << endl << endl;
	}
}
int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			return i;
		}
	}
	return -1;
}

void DeleteAccount()
{
	int id;
	int staccNum = accNum;
	int removedid = 101;
	cout << "Enter Id of the account you want to delete: ";
	cin >> id;
	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i].accID) {
			removedid = i;
		}
	}


	if (removedid >= 0 && removedid < accNum) {
		for (int i = removedid; i < accNum - 1; i++) {
			accArr[i] = accArr[i + 1]; // Shift elements to the left
		}

		accNum--; // Decrease the size of the array
	}

	if (staccNum == accNum)
		cout << "ERROR: Account not found!! Please try again" << endl;
	else
		cout << "Account Deleted!" << endl;
	
}

void DeleteAllAccs()
{
	string ans;
	cout << "Do you want to delete all the accounts you created? (Y(yes)/N(no)";
	cin >> ans;



	if (ans == "Y") {
		accNum = 0;
		cout << "Deleted!!!";
	};
}

void ChangeInfo()
{
	cout << "In this section, you can change id of your account." << endl;
	int id;
	cout << "Account Id: ";
	cin >> id;
	int index = GetAccIdx(id);

	int changedid;
	cout << "Account Id you want change to: ";
	cin >> changedid;

	if (index != -1) {
		accArr[index].accID = changedid;
		cout << "Your id has been changed." << endl;
	}
	else
		cout << "Account not found" << endl;
}



