#pragma once
#include <fstream>
#include "stringfunction.h"


namespace files {

	void saveClientInFile(string fileName, string strClient) {

		fstream file;
		file.open(fileName, ios::out | ios::app);

		if (file.is_open()) {

			file << strClient << endl;

			file.close();
		}
	}

	vector<string>getDataFromFileInVector(string fileName) {
		
		vector<string>data;
		fstream file;

		file.open(fileName, ios::in);
		
		if (file.is_open()) {
			string line;

			while (getline(file, line)) {
				data.push_back(line);
			}
			file.close();
		}
		return data;
	}

	void reFillFile(string fileName ,vector <string>data) {
		fstream file;
		file.open(fileName,ios::out);

		if (file.is_open()) {

			for (string& s : data) {
				file << s << endl;
			}
			file.close();
		}
	}

}

