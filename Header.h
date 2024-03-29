#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct Movie {

	string movieId;			//The Id of the movie
	string movieName;		//The name of the movie
	string movieDate;		//The date of movie
	string movieTime;		//The movie start time
	string categories;		//Categories of the movie
	float movieDuration;	//Duration of the movie
	int numOfSeat;			//The available number of seats in the hall
	int hall;				//The Hall of the movie	eg. 'A' == 1, 'C' == 3 , 'D' == 4 Hall

	Movie* nextAddress;
	Movie* previous;

};

struct Ticket {

	string ticketId;		//The id of the ticket
	string seat;			//The seat of the hall
	string movieId;			//The id of the movie
	float ticketPrice;		//Price of the ticket

	Ticket* nextAddress;
	Ticket* previous;

};

void login();
void MainMenuAdmin();
void MainMenuCustomer();
void AddMovie(string id, string name, string date, string times, string cat, float duration, int seat, int hall);
void DisplayMoive();
void ViewMovie();
bool SearchMovie(string keyword);
bool FilterMovie(string keywordFilter);
void DisplayTicket();
void UpdateMovie();
void IdUpdate(Movie* temp);
void TicketPurchase(string id, string seat, string movieId, float ticketPrice);
bool DisplayDetail(string TicketIdentifier);
bool FilterMovie(string keywordFilter);
bool DeleteMovie(string keyword);
void ViewTicket();
void deletefromEnd();
void deletefromspecificlocation(string deleteId);
void deletefromfront();
void SortMovie(struct Movie** head);
void SortTicketPrice(struct Ticket** head);

//#endif // !1
