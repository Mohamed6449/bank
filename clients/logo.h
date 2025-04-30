#pragma once
#include <iostream>

using namespace std;

namespace logo {

	void printLoginScreen() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "             Login Screen \n";
		cout << "------------------------------------------\n\n";
	}

	void printAllClientsLogo(int number) {
		cout << "\t\t\tclient list (" << number << ") clint (s) \t\t\t\n";
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "| acount number  |  pincode   | client name            | phone         | balance         |\n";
		cout << "------------------------------------------------------------------------------------------\n";

	}

	void printMainMenue() {
		cout << "========================================================\n";
		cout << "                      Main Menue Screen                 \n";
		cout << "========================================================\n";
		cout << "            [1] Show Client List.                       \n";
		cout << "            [2] Add New Client.                         \n";
		cout << "            [3] Apdate Client.                          \n";
		cout << "            [4] Delete Client Info.                     \n";
		cout << "            [5] Find Client.                            \n";
		cout << "            [6] Transactions.                           \n";
		cout << "            [7] Manage Users.                           \n";
		cout << "            [8] Logout.                                 \n";
		cout << "========================================================\n";
	}

	void manageUserLogo() {
		system("cls");
		cout << "========================================================\n";
		cout << "                  Manage User Menue Screen              \n";
		cout << "========================================================\n";
		cout << "            [1] List Users.                             \n";
		cout << "            [2] Add New User.                           \n";
		cout << "            [3] Delete User.                            \n";
		cout << "            [4] Update User.                            \n";
		cout << "            [5] Find User.                              \n";
		cout << "            [6] Main menue.                             \n";
		cout << "========================================================\n";
	}

	void addNewClient() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Add New Client Screen \n";
		cout << "------------------------------------------\n\n";
		cout << "adding new client: " << endl;
	}

	void addNewUser() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Add New user \n";
		cout << "------------------------------------------\n\n";
		cout << "adding new client: " << endl;
	}

	void printFindClient() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Find Client Screen \n";
		cout << "------------------------------------------\n\n";
	}

	void printDeleteClient() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Delete Client Screen \n";
		cout << "------------------------------------------\n\n";
	}

	void printUpdateClient() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Update Client Info Screen \n";
		cout << "------------------------------------------\n\n";
	}

	void printTransactions() {
		system("cls");
		cout << "========================================================\n";
		cout << "              Transactions Menue Screen                 \n";
		cout << "========================================================\n";
		cout << "            [1] Deposit.                                \n";
		cout << "            [2] Withdraw.                               \n";
		cout << "            [3] Total Balance.                          \n";
		cout << "            [4] Main Menue.                             \n";
		cout << "========================================================\n";

	}

	void printDeposit() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Deposit Screen\n";
		cout << "------------------------------------------\n\n";
	}

	void printWithdraw() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Withdraw Screen \n";
		cout << "------------------------------------------\n\n";
	}

	void printTotalBalance(int number) {
		system("cls");
		cout << "\t\t\tBalance List (" << number << ") Clint (s) \t\t\t\n";
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "| acount number           | client name                | balance                         |\n";
		cout << "------------------------------------------------------------------------------------------\n";

	}

	void printUserList() {
		system("cls");
		cout << "\t\t\tUsers list (1) users (s). \t\t\t\n";
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "| User name               | Password                   | permissions                     |\n";
		cout << "------------------------------------------------------------------------------------------\n";

	}

	void printDeleteUser() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Delete user \n";
		cout << "------------------------------------------\n\n";
	}

	void printUpdateUser() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        update user \n";
		cout << "------------------------------------------\n\n";
	}

	void printFindUser() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "        Find user \n";
		cout << "------------------------------------------\n\n";
	}
}














