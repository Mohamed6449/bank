#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace userdata {

	


	double getValidationNumber(string text) {
		cout << text ;
		double number;
		cin >> number;
		
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "rong entry please enter a number  ";
			cin >> number;
		}
			return (double)number;
	}

	string getString(string text) {
			string name;
			cout << text;
			getline(cin>>ws, name);
			return name;
		}

	bool get_y_n(string text) {
		string y_n= getString(text);
	
		while (y_n != "y" && y_n != "Y" && y_n != "N" && y_n != "n") {
			y_n = getString(text);
		}
		return (y_n == "y" || y_n == "Y") ? 1 : 0;
	}


	}






