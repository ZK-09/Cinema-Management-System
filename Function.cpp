#include "Header.h"

// Assumption that all the data is pre-sorted
struct Movie {

	string movieId;			//The Id of the movie
	string movieName;		//The name of the movie
	string movieDate;		//The date of movie
	string movieTime;		//The movie start time
	float movieDuration;	//Duration of the movie
	int numOfSeat;			//The total number of seat in the hall
	int hall;				//The Hall of the movie

	Movie* nextAddress;
	Movie* previous;

} *movieHead, * movieTail, *newMovieHead, *newMovieTail;

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
	/*cout << "||======================================================||\n";
	cout << "||\t    GRANDPLEX MOVIE TICKETING SYSTEM\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||\t\t\tMENU\t\t\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||1.Add Purchase\t\t\t\t\t\t||\n";
	cout << "||2.View Purchase\t\t\t\t\t||\n";
	cout << "||3.Sort Purchases\t\t\t\t\t||\n";
	cout << "||4.Purchase Detail\t\t\t\t\t||\n";
	cout << "||======================================================||\n\n";

	int choice;

	do
	{
		cout << "Enter selection\n";
		cin >> choice;
		switch (choice)
		{
		case 1: TicketPurchase();
			break;
		case 2: ViewTicket();
			break;
		case 3: SortTicketPrice();
			break;
		case 4: DisplayDetail();
			break;
		default: cout << "Invalid, Please Try Again";
			break;
		}
	}*/
}

/* Admin Management Functions (Movie Management) */

//Add Movie --> Insert into sorted list
void AddMovie(string id, string name, string date, string time, float duration, int seat, int hall) {
	
	cout << "Enter Movie Id : ";
	cin >> id;

	cout << "Enter Movie Name : ";
	cin >> name;

	cout << "Enter Movie Date : ";
	cin >> date;

	cout << "Enter Movie Time : ";
	cin >> time;

	cout << "Enter Movie Duration : ";
	cin >> duration;

	cout << "Enter Movie Seat : ";
	cin >> seat;

	cout << "Enter Movie Hall : ";
	cin >> hall;

	Movie* newNode = createMovieNode(id, name, date, time, duration, seat, hall);

	newNode->nextAddress = NULL;
	newNode->previous = NULL;

	//Sorted list still do not have any item
	if (movieHead == NULL) {

		newMovieHead = newMovieTail = newNode;

	} else if (id < newMovieHead->movieId) {	//If movieID is smaller than the head value
		newNode->nextAddress = newMovieHead;
		newMovieHead->previous = newNode;
		newMovieHead = newNode;

	} else if (id > newMovieTail->movieId){		//If movieId is greater than the head value
		newMovieTail->nextAddress = newNode;
		newNode->previous = newMovieTail;
		newMovieTail = newNode;

	} else {
		
		Movie* current = newNode->nextAddress;	//Insert in the middle of the list

		while (current != NULL) {

			if (id < current->movieId) {
				break;
			}

			current = current->nextAddress;
		}

		current->previous->nextAddress = newNode;
		newNode->previous = current->previous;
		current->previous = newNode;
		newNode->nextAddress = current;

	}

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

	//Get user input to update which part of the movie
	cout << "Select the information to update" << endl;
	cout << "1. Movie ID" << endl;
	cout << "2. Movie Name" << endl;
	cout << "3. Movie Date" << endl;
	cout << "4. Movie Time" << endl;
	cout << "5. Movie Duration" << endl;
	cout << "6. No of Seat" << endl;
	cout << "7. Movie Hall" << endl;
}

//Sort Movie based on quantity
void SortMovie(int *billyarrays, int size) {

	int key, currentcolindex; 

	for (int roundindex = 1; roundindex < size; roundindex++)
	{
		key = billyarrays[roundindex];
		currentcolindex = roundindex;

		//currentcolindex > 0 -> you still got previous items in front of current item
		while (currentcolindex > 0 && billyarrays[currentcolindex - 1] > key)
		{
			billyarrays[currentcolindex] = billyarrays[currentcolindex - 1];
			currentcolindex--;
		}
		billyarrays[currentcolindex] = key;

		//finish swapping
		cout << "Round " << roundindex << " = ";
		for (int i = 0; i < size; i++)
		{
			cout << billyarrays[i] << " , ";
		}
		cout << endl;

		cout << "Final result shows as below\n";
		for (int i = 0; i < size; i++)
		{
			cout << billyarrays[i] << " , ";
		}
		cout << endl;
	}
}

//Delete Movie from Movie List
void DeleteMovie() {

}

/* Customer Purchasing Functions (Purchasing Ticket) */

//Purchase Ticket --> Add Purchase
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