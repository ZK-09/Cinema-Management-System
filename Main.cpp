#include "Header.h"

int main() {
	string movie[3][8] = {
		{"M0001","Harry Potter","29-9-2022","1830", "Comedy", "3","100","3"},
		{"M0002","Friends","18-6-2022","1400","Comedy", "4","75","1"},
		{"M0003","Till We Meet Again","2-2-2022","1000","Romance", "2","66","4"}
	};
	for (int i = 0; i < 3; i++) {

		AddMovie(movie[i][0], movie[i][1], movie[i][2], movie[i][3], movie[i][4], stoi(movie[i][5]), stoi(movie[i][6]), stoi(movie[i][7]));
	}

	string ticket[3][4] = {
		{"T9001", "A45", "M0001", "109.00"},
		{"T9056", "D22", "M0001", "25.00"},
		{"T9001", "C78", "M0001", "50.50"}
	};
	for (int i = 0; i < 3; i++)
	{
		TicketPurchase((ticket[i][0]), ticket[i][1], ticket[i][2], stoi(ticket[i][3]));
	}
	login();	//User Login


	cout << endl <<  "End Testing Print ! Delete Must !";
	return 0;
}