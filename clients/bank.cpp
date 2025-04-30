#include "files.h"
#include "logo.h"
#include "users.h"
using namespace clientFun;

void maxAmountWithdraw(double maxAmount,double &withdrawamount) {
	while (withdrawamount > maxAmount) {
		cout << "\namount exceeds the balance,you can withdraw up to : " << maxAmount << endl;
		withdrawamount=userdata::getValidationNumber("\nplease enter anther amount? ");
	}
}

bool searchForClient(vector<stClientInfo >stClients, int& number,string &nameAcount) {
	nameAcount = userdata::getString("please enter acount number ? ");
	short counter= 0;
	for (stClientInfo& stC : stClients) {
	
		counter++;
		
		if (stC.nameAcount == nameAcount) {
		
			number = counter;
			return true;
		}
	}
	return false;

}

bool searchForUser(vector<usersFun::stUserInfo>stUsers, short& number, string &name) {
	name= userdata::getString("please enter name number ? ");
	number = 0;
	for (usersFun::stUserInfo i : stUsers) {
		number ++;
		if (i.name == name) {
			return true;
		}
	}
	return false;
}

void findClient(vector<stClientInfo >clientsAs_struct) {
	int number;
	
	string acountNInput;

	logo::printFindClient();
	
	if (searchForClient(clientsAs_struct, number, acountNInput)) {
		
		clientFun::printOneClien(clientsAs_struct[number - 1]);
	}
	else {

		cout << "\nClient with acount number [ "<<acountNInput<<" ] not found \n\n";
	
	}
	cout << "press any key to go back to main menue ";

	system("pause");
}

int  mainMenue() {
	system("cls");
	logo::printMainMenue();
	int number = userdata::getValidationNumber("choose what do you want to do [1 to 8] ? ");
	
	while (number < 1 || number > 8  ){
		number = userdata::getValidationNumber("choose what do you want to do [1 to 8] ? ");
	}
	return number;
}

int transactionMenue() {
	logo::printTransactions();
	int number = userdata::getValidationNumber("choose what do you want to do [1 to 4] ? ");

	while (number < 1 || number > 4) {
		number = userdata::getValidationNumber("choose what do you want to do [1 to 4] ? ");
	}
	return number;

}

int manageMenueScreen() {
	logo::manageUserLogo();
	int number = userdata::getValidationNumber("choose what do you want to do [1 to 6] ? ");

	while (number < 1 || number > 6) {
		number = userdata::getValidationNumber("choose what do you want to do [1 to 6] ? ");
	}
	return number;

}

void printAllClient(vector<stClientInfo >clientsAs_struct) {
	
	system("cls");
	
	logo::printAllClientsLogo(clientsAs_struct.size());
	
	clientFun::printAllClientAsLine(clientsAs_struct);
	cout << "press any key to go back to main menue ";

	system("pause");
}

void addclient(vector<stClientInfo >clientsAs_struct) {
	stClientInfo info;
	logo::addNewClient();
	string  acountNInput;
	int number;
	
	while (searchForClient(clientsAs_struct, number, acountNInput)){
		cout << "\nClient with [ " << acountNInput << " ] already exsists,enter another acount number ? \n";
	}
	
	info.nameAcount = acountNInput;
	clientFun::fillUpdateDataFromUser(info);
	
	files::saveClientInFile("client.text",stringfun::convertStClientToString(info,"#//#"));
	cout << "press any key to go back to main menue ";

	system("pause");
}

void deleteClient(vector<stClientInfo >clientsAs_struct) {

	int number;

	string acountNInput,wantDelete;

	logo::printDeleteClient();

	if (searchForClient(clientsAs_struct, number, acountNInput)) {

		clientFun::printOneClien(clientsAs_struct[number - 1]);
		
		wantDelete = userdata::getString("Are you want delete this client y/n");
		
		if (wantDelete == "y" || wantDelete == "Y" || wantDelete=="yes") {
			
			clientsAs_struct[number - 1].delet = true;
	
			files::reFillFile("client.text", stringfun::convert_vstruct_vstring(clientsAs_struct));

			cout << "\nClient deleted successfully.\n";

		}

	}
	else {

		cout << "\nClient with acount number [ " << acountNInput << " ] not found\n\n";

	}
	cout << "press any key to go back to main menue ";

	system("pause");
}

void updateClient(vector<stClientInfo >clientsAs_struct) {

	int number;

	string acountNInput, wantUpdate;

	logo::printUpdateClient();

	if (searchForClient(clientsAs_struct, number, acountNInput)) {

		clientFun::printOneClien(clientsAs_struct[number - 1]);

		wantUpdate = userdata::getString("Are you want update this client y/n");

		if (wantUpdate == "y" || wantUpdate == "Y" || wantUpdate == "yes") {

			fillUpdateDataFromUser(clientsAs_struct[number - 1]);

			files::reFillFile("client.text", stringfun::convert_vstruct_vstring(clientsAs_struct));

			cout << "\nClient updated successfully.\n\n";

		}

	}
	else {

		cout << "\nClient with acount number [ " << acountNInput << " ] not found\n\n";

	}
	cout << "press any key to go back to main menue ";

	system("pause");
}

void totalBalance(vector<stClientInfo >clientsAs_struct) {
	double total_B;
	logo::printTotalBalance(clientsAs_struct.size());
	printAllBalanceClientAsLine(clientsAs_struct, total_B);

	cout << "                             Total Balance = "<< total_B <<endl<<endl;


}

void deposit(vector<stClientInfo >clientsAs_struct) {

	logo::printDeposit();
	int number;
	double depositAmount;
	string acountNInput, wantUpdate;
	bool search = false;
	while (search == false) {
		if (search = searchForClient(clientsAs_struct, number, acountNInput)) {

			clientFun::printOneClien(clientsAs_struct[number - 1]);
			depositAmount = userdata::getValidationNumber("please enter deposit amount? ");
			wantUpdate = userdata::getString("\nAre you want deposit " + to_string(depositAmount) + " y / n");

			if (wantUpdate == "y" || wantUpdate == "Y" || wantUpdate == "yes") {

				clientsAs_struct[number - 1].balance += depositAmount;

				files::reFillFile("client.text", stringfun::convert_vstruct_vstring(clientsAs_struct));

				cout << "\nClient deposit successfully.\n\n";
			}
		}
		else {

			cout << "\nClient with acount number [ " << acountNInput << " ] not found\n\n";

		}
	}
}

void withdraw(vector<stClientInfo >clientsAs_struct) {

	logo::printWithdraw();
	int number;
	double withdrawAmount;
	string acountNInput, wantUpdate;
	bool search = false;
	while (search == false) {
		if (search = searchForClient(clientsAs_struct, number, acountNInput)) {

			clientFun::printOneClien(clientsAs_struct[number - 1]);
			withdrawAmount = userdata::getValidationNumber("please enter withdaraw amount? ");
		
			maxAmountWithdraw(clientsAs_struct[number - 1].balance,withdrawAmount);

			wantUpdate = userdata::getString("\nAre you want withdraw "+to_string(withdrawAmount)+" y / n");

			if (wantUpdate == "y" || wantUpdate == "Y" || wantUpdate == "yes") {

				clientsAs_struct[number - 1].balance -= withdrawAmount;

				files::reFillFile("client.text", stringfun::convert_vstruct_vstring(clientsAs_struct));

				cout << "\nClient deposit successfully.\n\n";
			}
		}
		else {

			cout << "\nClient with acount number [ " << acountNInput << " ] not found\n\n";

		}
	}
}

void transactions() {

	int number;
	vector<string>clientsAs_string;
	vector<stClientInfo >clientsAs_struct;

	while ((number = transactionMenue())!= 4) {

		clientsAs_string = files::getDataFromFileInVector("client.text");
		clientsAs_struct = stringfun::fillVectorWithStClientInfo(clientsAs_string);

		switch (number) {

		case 1:
			deposit(clientsAs_struct);
			break;
		case 2:
			withdraw(clientsAs_struct);
			break;
		case 3:
			totalBalance(clientsAs_struct);
			break;
		}
		if (number !=4) {

			cout << "press any key to go back to main menue ";

			system("pause");
		}
	}
}

bool isPermission(short permissions, short enPer) {

	if ((permissions&enPer) == 0) {
		system("cls");
		cout << "--------------------------------------------------\n";
		cout << "you dont have apermission to do this \n";
		cout << "please contact your admin \n";
		cout << "--------------------------------------------------\n";
		system("pause");
		return false;
	}
	return true;
}

void userList(vector <usersFun::stUserInfo>usersAs_struct) {
	logo::printUserList();
	usersFun::printAllUsersAsLine(usersAs_struct);
}

void addNewUser(vector<usersFun::stUserInfo>v_stUsers) {
	logo::addNewUser();
	usersFun::stUserInfo stUser;
	short pos=0;
	string name;
	while (true) {
		while (searchForUser(v_stUsers,pos,name)) {
			cout << "\nuser with [ " << name<< " ] already exsists,enter another acount number ? \n";
		}
		stUser.name = name;
		usersFun::fillUpdateUserFromUser(stUser);
		files::saveClientInFile("users.text", stringfun::convertStUsersTOstring(stUser, "#//#"));
		if (!userdata::get_y_n("user added successfully ,do you want add more user[y,n] ?")) {
			break;
		}
		v_stUsers = stringfun::conver_vstring_vstruct_user(files::getDataFromFileInVector("users.text"));
	}
}
	
void deleteUser(vector<usersFun::stUserInfo>v_stUsers) {
	logo::printDeleteUser();
	short number = 0;
	string name;
	bool isExsist = searchForUser(v_stUsers, number, name);
	
	while (name == "admin") {
		cout << "you can not delete admin \n";
		isExsist = searchForUser(v_stUsers, number, name);
	}
	
	while (!isExsist) {
		cout << "\nuser with [ " << name << " ] not exsists,enter another acount number ? \n";
		isExsist = searchForUser(v_stUsers, number, name);
		while(name == "admin") {
			cout << "you can not delete admin \n";
			isExsist = searchForUser(v_stUsers, number, name);
		}
	}
	usersFun::printOneUser(v_stUsers[number-1]);
	if (userdata::get_y_n("are you sure do you want delete this user [y,n]")) {
		v_stUsers[number - 1].delet = true;
	}
	files::reFillFile("users.text", stringfun::convert_vStruct_vSting(v_stUsers));
}

void updateUser(vector<usersFun::stUserInfo>v_stUsers) {
	logo::printUpdateUser();
	short number = 0;
	string name;
	bool isExsist = searchForUser(v_stUsers, number, name);

	while (name == "admin") {

		cout << "you can not update admin \n";

		isExsist = searchForUser(v_stUsers, number, name);
	}

	while (!isExsist) {

		cout << "\nuser with [ " << name << " ] not exsists,enter another acount number ? \n";

		isExsist = searchForUser(v_stUsers, number, name);
 
		while (name == "admin") {

			cout << "you can not update admin \n";

			isExsist = searchForUser(v_stUsers, number, name);
		}
	}
	usersFun::printOneUser(v_stUsers[number - 1]);

	usersFun::fillUpdateUserFromUser(v_stUsers[number - 1]);

	if (userdata::get_y_n("are you sure do you want update this user [y,n]")) {

		files::reFillFile("users.text", stringfun::convert_vStruct_vSting(v_stUsers));
	}
}

void findUser(vector<usersFun::stUserInfo>v_stUsers) {
	logo::printFindUser();
	short pos = 0;
	string name;

	while (!searchForUser(v_stUsers, pos, name)) {
		cout << "\nuser with [ " << name << " ] not exsists,enter another acount number ? \n";
	}
	usersFun::printOneUser(v_stUsers[pos - 1]);

}

void manageMenue() {
	short number;
	
	vector <string>fileUser;
	
	vector <usersFun::stUserInfo>v_st_users;
	
	while ((number = manageMenueScreen()) != 6) {
	
		fileUser = files::getDataFromFileInVector("users.text");
		
		v_st_users = stringfun::conver_vstring_vstruct_user(fileUser);
		
		switch (number) {
		case 1:
			userList(v_st_users);
			break;
		case 2:
			addNewUser(v_st_users);
			break;
		case 3:
			deleteUser(v_st_users);
			break;
		case 4:
			updateUser(v_st_users);
			break;
		case 5:
			findUser(v_st_users);
			break;
		}

		if (number != 6) {

			cout << "press any key to go back to main menue ";

			system("pause");
		}
	}













}

void allMainMenue(short permissions) {

	int number = 2;

	vector<string>clientsAs_string;

	vector<stClientInfo >clientsAs_struct;

	while (number != 8) {
		number = mainMenue();

		if (number != 6 && number != 2) {
			clientsAs_string = files::getDataFromFileInVector("client.text");
			clientsAs_struct = stringfun::fillVectorWithStClientInfo(clientsAs_string);
		}

		switch (number) {

		case 1:
			if (isPermission(permissions, usersFun::enPermissions::show)) {
				printAllClient(clientsAs_struct);
			}
			break;
		case 2:
			if (isPermission(permissions, usersFun::enPermissions::add)) {
				addclient(clientsAs_struct);
			}
			break;
		case 3:
			if (isPermission(permissions, usersFun::enPermissions::update)) {
				updateClient(clientsAs_struct);
			}
			break;
		case 4:
			if (isPermission(permissions, usersFun::enPermissions::deleteC)) {
				deleteClient(clientsAs_struct);
			}
			break;
		case 5:
			if (isPermission(permissions, usersFun::enPermissions::find)) {
				findClient(clientsAs_struct);

			}break;
		case 6:
			if (isPermission(permissions, usersFun::enPermissions::transacion)) {
				transactions();
			}
			break;
		case 7:
			if (isPermission(permissions, usersFun::enPermissions::manage)) {
				manageMenue();
			}
			break;
		}
	}

}

void login() {
	string name,password;
	short number = 0;
	vector<usersFun::stUserInfo>v_stUsers;
	while (true) {
		
		v_stUsers = stringfun::conver_vstring_vstruct_user(files::getDataFromFileInVector("users.text"));
		
		logo::printLoginScreen();
		
		bool search = searchForUser(v_stUsers, number, name);
		password=userdata::getString("enter password ? ");
		if (search) {
			if (v_stUsers[number - 1].password == password) {
				allMainMenue(v_stUsers[number - 1].permissions);
			}
		}
		else {
			cout << "Invalaid name /password\n\n ";
			system("pause");
		}
	
	}
}


int main() {

	login();

	return 0;
}