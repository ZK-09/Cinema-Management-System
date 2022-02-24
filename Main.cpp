#include "Header.h"

int main() {
	
	login();	//User Login

	string movie[3][7] = {
		{"M0001","Harry Potter","29-9-2022","1830", "3","100","A2"},
		{"M0002","Friends","18-6-2022","1400","4","75","C"},
		{"M0003","Till We Meet Again","2-2-2022","1000","2","66","D"}
	};

	string ticket[3][4] = {
		{"T9001", "A45", "M0001", "109.00"},
		{"T9056", "D22", "M0001", "25.00"},
		{"T9001", "C78", "M0001", "50.50"}
	};

	cout << endl <<  "End Testing Print ! Delete Must !";
	return 0;
}