#pragma once
#pragma once
#include "getdatafromuser.h"
#include <iomanip>
#include <vector>

namespace usersFun {

	struct stUserInfo {
		string name;
		string password;
		short permissions;
		bool delet = false;
	};

	enum enPermissions{show=1,add=2,deleteC=4,update=8,find=16,transacion=32,manage=64};

	short permissions() {
		short per=0;
		if (userdata::get_y_n("do you want to give full access[y,n] ? ")) {
			per = -1;
		}
		else {
			if (userdata::get_y_n("show client list [y,n] ? ")) {
				per += enPermissions::show;
			}
			if (userdata::get_y_n("add now client [y,n] ? ")) {
				per += enPermissions::add;
			}
			if (userdata::get_y_n("Delete client [y,n] ? ")) {
				per += enPermissions::deleteC;
			}
			if (userdata::get_y_n("Update client [y,n] ? ")) {
				per += enPermissions::update;
			}
			if (userdata::get_y_n("find client [y,n] ? ")) {
				per += enPermissions::find;
			}
			if (userdata::get_y_n("Transaction [y,n] ? ")) {
				per += enPermissions::transacion;
			}
			if (userdata::get_y_n("Manage users [y,n] ? ")) {
				per += enPermissions::manage;
			}
		}
		return per;
	}
	
	void fillStUsersFromUser(stUserInfo &user) {
		user.name =     userdata::getString("enter your name ? ");
		user.password = userdata::getString("enter your password ? ");
		user.permissions = permissions();
	}


	void fillUpdateUserFromUser(stUserInfo &user) {
		user.password = userdata::getString("enter your password ? ");
		user.permissions = permissions();
	}
	

	void printUserAsLine(stUserInfo user) {
		cout << "|" << setw(25) << left << user.name
			<< "|" << setw(27) << left << user.password
			<< "|" << setw(30) << left << user.permissions<< endl;
	}

	void printAllUsersAsLine(vector <stUserInfo>users) {
		cout << endl;
		for (stUserInfo& user : users) {

			printUserAsLine(user);
		}
		cout << "------------------------------------------------------------------------------------------\n\n\n";
	}

	void printOneUser(stUserInfo user) {
		cout << "\nThe following are the client details:\n";
		cout << "------------------------------------\n";
		cout << "Username      : " << user.name;
		cout << "\npassword    : " << user.password;
		cout << "\npermissions : " << user.permissions;
		cout << "\n------------------------------------\n" << endl;
	}
}