#pragma once
#include "getdatafromuser.h"
#include <iomanip>
#include <vector>

namespace clientFun {
	
	struct stClientInfo {
		string nameAcount ;
		string name       ;
		string pincode    ;
		string phoneNumber;
		double balance    ;
		
		bool delet = false;
	};

	void fillStClientFromUser(stClientInfo &client) {
		client.nameAcount  = userdata::getString("enter your acount numebr ? ");
		client.pincode     = userdata::getString("enter your pincode ? ");
		client.name        = userdata::getString("enter your name ? ");
		client.phoneNumber = userdata::getString("enter your phonenumber ? ");
		client.balance     = userdata::getValidationNumber("enter your balance ? ");

	}

	void fillUpdateDataFromUser(stClientInfo &client) {
		cout << endl;
		client.pincode     = userdata::getString("enter your pincode ? ");
		client.name        = userdata::getString("enter your name ? ");
		client.phoneNumber = userdata::getString("enter your phonenumber ? ");
		client.balance     = userdata::getValidationNumber("enter your balance ? ");

	}

	void printOneClien(stClientInfo client) {
		cout << "\nThe following are the client details:\n";
		cout << "------------------------------------\n";
		cout << "acount number : " << client.nameAcount;
		cout << "\npin code    : " << client.pincode;
		cout << "\nname        : " << client.name;
		cout << "\nphone       : " << client.phoneNumber;
		cout << "\nbalance     : " << client.balance ;
		cout << "\n------------------------------------\n" << endl;
}

	void printClientAsLine(stClientInfo client) {
		cout << "|" << setw(16) << left << client.nameAcount
			 << "|" << setw(12) << left << client.pincode
		  	 << "|" << setw(24) << left << client.name
			 << "|" << setw(15) << left << client.phoneNumber
			 << "|" << setw(15) << left << client.balance << endl;
	}

	void printBalanceClientAsLine(stClientInfo client) {

		cout<< "|" << setw(25) << left << client.nameAcount
			<< "|" << setw(27) << left << client.name
			<< "|" << setw(30) << left << client.balance << endl;
	}

	void printAllClientAsLine(vector <stClientInfo>clients) {
		cout << endl;
		for (stClientInfo& client : clients) {
		
			printClientAsLine(client);
		}
			cout << "------------------------------------------------------------------------------------------\n\n\n";
	}

	void printAllBalanceClientAsLine(vector <stClientInfo>clients, double& total_B) {
		cout << endl;
		total_B = 0;
		for (stClientInfo& client : clients) {
			total_B += client.balance;
			printBalanceClientAsLine(client);
		}
		cout << "\n------------------------------------------------------------------------------------------\n\n\n";
	}
		
	}







