#pragma once
#include "clients.h"
#include <vector>
#include "users.h"


namespace stringfun {

	vector<string> spliteString(string text, string calim) {
		vector<string>stringAfterSplite;
		int pos = 0;
		string word;
		while ((pos = text.find(calim)) != text.npos) {
			word = text.substr(0, pos);
			if (word != "") {
				stringAfterSplite.push_back(word);
			}
			text.erase(0, pos + calim.length());
		}
		if (text != "") {
			stringAfterSplite.push_back(text);
		}
		return stringAfterSplite;
	}


	vector <clientFun::stClientInfo>fillVectorWithStClientInfo(vector<string>LinesFile) {

		vector <clientFun::stClientInfo>fill_V_W_C_i;

		short pos = 0;

		clientFun::stClientInfo client;

		vector<string>vClientStr;

		for (string& line : LinesFile) {
			vClientStr = spliteString(line, "#//#");

			client.nameAcount  = vClientStr[0];
			client.pincode     = vClientStr[1];
			client.name        = vClientStr[2];
			client.phoneNumber = vClientStr[3];
			client.balance     = stod(vClientStr[4]);

			fill_V_W_C_i.push_back(client);


		}
		return fill_V_W_C_i;
	}


	string convertStClientToString(clientFun::stClientInfo client,string calim) {
		string stringClient = "";

			   stringClient += client.nameAcount + calim;
			   stringClient += client.pincode + calim;
			   stringClient += client.name + calim;
			   stringClient += client.phoneNumber + calim;
			   stringClient += to_string(client.balance);

			   return stringClient;
	}


	vector <string>convert_vstruct_vstring(vector <clientFun::stClientInfo>v_st_client) {
		
		vector <string>vstringclients;
		
		for (clientFun::stClientInfo& s : v_st_client) {
			
			if (s.delet == false){
			
				vstringclients.push_back(convertStClientToString(s, "#//#"));
			}
		}
		return vstringclients;
	}
	
	vector <usersFun::stUserInfo>conver_vstring_vstruct_user(vector<string>lineUsers) {
		
		vector <usersFun::stUserInfo>v_st_user;
		vector<string>vString;
		usersFun::stUserInfo stUser;
		
		for (string s : lineUsers) {
			vString=spliteString(s,"#//#");
			stUser.name = vString[0];
			stUser.password = vString[1];
			stUser.permissions =stoi( vString[2]);
			v_st_user.push_back(stUser);
		}

		return v_st_user;
	}

	string convertStUsersTOstring(usersFun::stUserInfo user, string calim) {
		string strUser = "";
		strUser += user.name + calim;
		strUser += user.password + calim;
		strUser += to_string(user.permissions);
		return strUser;
	}

	vector <string>convert_vStruct_vSting(vector<usersFun::stUserInfo>v_st_users) {
		vector<string>v_user_string;
		for (usersFun::stUserInfo i : v_st_users) {
			if (i.delet == false) {
				v_user_string.push_back(convertStUsersTOstring(i, "#//#"));
			}
		}
		return v_user_string;
	}
	

}

