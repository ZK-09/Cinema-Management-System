#include "Header.h"

struct Movie {

	string movieId;			//The Id of the movie
	string movieName;		//The name of the movie
	string movieDate;		//The date of movie
	string movieTime;		//The movie start time
	float movieDuration;	//Duration of the movie
	int numOfSeat;			//The specific location of the seat in the hall
	int hall;				//The Hall of the movie

	Movie* nextAddress;
	Movie* previous;

} /**movieHead, * movieTail*/;

struct Ticket {

	string ticketId;		//The id of the ticket
	string seat;			//The seat of the hall
	string movieId;			//The id of the movie
	float ticketPrice;		//Price of the ticket

	Ticket* nextAddress;
	Ticket* previous;

}/**ticketHead, * ticketTail*/;

//Constructor of Movie & Ticket node
Movie* createMovieNode(string id, string name, string date, string time, float duration, int seat, int hall) {

	Movie* newMovie = new Movie;
	newMovie->movieId = id;
	newMovie->movieName = name;
	newMovie->movieDate = date;
	newMovie->movieTime = time;
	newMovie->movieDuration = duration;
	newMovie->numOfSeat = seat;
	newMovie->hall = hall;

	newMovie->nextAddress = NULL;
	newMovie->previous = NULL;
	
	return newMovie;
}

Ticket* createTicketNode(string ticketId, string seat, string movieId, float price) {

	Ticket* newTicket = new Ticket;
	newTicket->ticketId = ticketId;
	newTicket->seat = seat;
	newTicket->movieId = movieId;
	newTicket->ticketPrice = price;

	newTicket->nextAddress = NULL;
	newTicket->previous = NULL;

	return newTicket;
}

//Login Function
void login() {

	string username;	//User's Registered username
	string password;	//Password of the user

	cout << "Enter username : ";
	cin >> username;

	cout << "Enter Password : ";
	cin >> password;

	if ((username == "Admin") && (password == "Admin")) {

		system("CLS");
		//Call Admin Menu (Manage Movie)

	} else {

		system("CLS");
		//Call Customer Menu (Purchase Ticket)
	}

}

//Admin Menu Function
void MainMenuAdmin() {
	cout << "HI";
}

//Customer Menu Function
void MainMenuCustomer() {

}

/* Admin Management Functions (Movie Management) */

//Add Movie
void AddMovie() {

}

//Display Movie
void DisplayMoive() {

}

//Search Movie
void SearchMovie(string keyword) {

}

//Filter Movie
void FilterMovi(string keywordFilter) {

}

//Update Movie Information
void UpdateMovie() {

}

//Sort Movie based on quantity
void SortMovie() {

}

//Delete Movie from Movie List
void DeleteMovie() {

}

/* Customer Purchasing Functions (Purchasing Ticket) */

//Purchase Ticket
void TicketPurchase(string id, string seat, string movieId) {

}

//View Purchase Transactions
void ViewTicket() {

}

//Sort Purchase Transaction based on total price
void SortTicketPrice(string idd, string seat, string movieId) {

}

//View Purchase Details
void DisplayDetail() {

}