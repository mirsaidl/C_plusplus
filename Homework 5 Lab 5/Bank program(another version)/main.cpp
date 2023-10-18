#include <iostream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS // for not warning strcpy_s

const int MAX_ACC_NUM = 100;
const int NAME_LEN = 20;

enum bank{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; // enum for menu

void ShowMenu(void); // function prototypes
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int GetAccIdx(int);


class Account {
private:
	int m_accID;
	int m_balance;
	char* m_cusName;
public:
	Account(int a, int b, char *c) : m_accID( a ), m_balance{ b } , m_cusName(c) { // copy constructor
		m_cusName = new char[NAME_LEN + 1];  // allocating memory and copying it
		strcpy_s(m_cusName, NAME_LEN + 1, c);
	};

	~Account() {
		delete[] m_cusName; // free the memory
	}

	int GetAccID(void) {
		return this->m_accID; // return ID of user
	}
	void Deposit(int money) {
		m_balance = m_balance + money;
	}
	
	int Withdraw(int money) { // if it return 1 everything is fine otherwise balance is below 0
		int remaining = m_balance - money;
		if (remaining < 0) {
			return -1;
		}
		else {
			this->m_balance = remaining;
			return 1;
		}
	}

	void ShowAccInfo(void) { // info
		cout << "Account ID: " << m_accID << endl;
		cout << "Name: " << m_cusName << endl;
		cout << "Balance: " << m_balance << endl << endl;
	}
};

Account* accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // # of accounts

int main(void) {
	int choice, i;
	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;
		switch (bank(choice)) {
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::EXIT:
			for (i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
}
void MakeAccount(void) {
	int id;
	char n[NAME_LEN];
	int balance;

	//Taking input
	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> n;
	cout << "Deposit amount: ";
	cin >> balance;

	accArr[accNum] = new Account{ id, balance, n };
	accNum++;
}
void DepositMoney(void) {
	int money;
	int index;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	index = GetAccIdx(id); // determine index of user id in array

    if (index != -1) {
		accArr[index]->Deposit(money); // -> calling class function from outside
	}
	else {
		cout << "Invalid ID! Please try again." << endl;
	}
}

void WithdrawMoney(void) {
	int money;
	int index;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdraw amount: ";
	cin >> money;

	index = GetAccIdx(id);

	if (index != -1) {
		if (accArr[index]->Withdraw(money) == -1) { // if -1 invalid balance
			cout << "Not enough balance!" << endl;
		}
		else {
			accArr[index]->Withdraw(money);
		}
	}
	else {
		cout << "Invalid ID! Please try again." << endl;
	}
}


void ShowAllAccInfo(void) {
	// All infos
	if (accNum == 0) {
		cout << "No account to display. Please make an account first!" << endl;
	}
	else {
		for (int i = 0; i < accNum; i++) {
			accArr[i]->ShowAccInfo();
		}
	}
}


int GetAccIdx(int num) {
	// finding index of user id 
	for (int i = 0; i < accNum; i++) {
		if (num == accArr[i]->GetAccID()) {
			return i;
		}
	}

	return -1;
}

