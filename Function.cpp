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

} *movieHead, * movieTail;

struct Ticket {

	string ticketId;		//The id of the ticket
	string seat;			//The seat of the hall
	string movieId;			//The id of the movie
	float ticketPrice;		//Price of the ticket

	Ticket* nextAddress;
	Ticket* previous;

}*ticketHead, * ticketTail;

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

	cout << "||======================================================||\n";
	cout << "||\t    GRANDPLEX MOVIE TICKETING SYSTEM\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||\t\t\tLOGIN\t\t\t\t||\n";
	cout << "||======================================================||\n";

	cout << "Enter username : ";
	cin >> username;

	cout << "Enter Password : ";
	cin >> password;

	if ((username == "Admin") && (password == "Admin")) {

		system("CLS");
		//Call Admin Menu (Manage Movie)
		MainMenuAdmin();
	} else {

		system("CLS");
		//Call Customer Menu (Purchase Ticket)
	}

}

//Admin Menu Function
void MainMenuAdmin() {
	/*cout << "||======================================================||\n";
	cout << "||\t    GRANDPLEX MOVIE TICKETING SYSTEM\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||\t\t\tMENU\t\t\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||1.Add Product\t\t\t\t\t\t||\n";
	cout << "||2.Display Product\t\t\t\t\t||\n";
	cout << "||3.Product Search\t\t\t\t\t||\n";
	cout << "||4.Category Filter\t\t\t\t\t||\n";
	cout << "||5.Update Product\t\t\t\t\t||\n";
	cout << "||6.Sort Product\t\t\t\t\t||\n";
	cout << "||7.Delete Product\t\t\t\t\t||\n";
	cout << "||======================================================||\n\n";

	int choice;

	do
	{
		cout << "Enter selection\n";
		cin >> choice;
		switch (choice)
		{
		case 1: AddMovie();
			break;
		case 2: DisplayMoive();
			break;
		case 3: SearchMovie(keyword);
			break;
		case 4: FilterMovie(keywordFilter);
			break;
		case 5: UpdateMovie();
			break;
		case 6: SortMovie();
			break;
		case 7: DeleteMovie();
			break;
		default: cout << "Invalid, Please Try Again";
			break;
		}
	}*/
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
void FilterMovie(string keywordFilter) {

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