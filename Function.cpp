#include "Header.h"

// Assumption that all the data is pre-sorted
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

} *movieHead, * movieTail, *newMovieHead, *newMovieTail;

struct Ticket {

	string ticketId;		//The id of the ticket
	string seat;			//The seat of the hall
	string movieId;			//The id of the movie
	float ticketPrice;		//Price of the ticket

	Ticket* nextAddress;
	Ticket* previous;

}*ticketHead, * ticketTail, *newTicketHead, *newTicketTail;

//Constructor of Movie & Ticket node
Movie* createMovieNode(string id, string name, string date, string time, string cat, float duration, int seat, int hall) {

	Movie* newMovie = new Movie;
	newMovie->movieId = id;
	newMovie->movieName = name;
	newMovie->movieDate = date;
	newMovie->movieTime = time;
	newMovie->categories = cat;
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
	cout << "||======================================================||\n";
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

	
		/* Movie Add Variables*/
		string id, name, date, times;
		float duration;
		int seat;
		int hall;
		int decision = 1;

		cout << "Enter selection : ";
		cin >> choice;

		switch (choice) {

		case 1: 			
			
			while (decision != 0) {
				cout << "Enter Movie Id : ";
				cin >> id;

				cout << "Enter Movie Name : ";
				cin >> name;

				cout << "Enter Movie Date : ";
				cin >> date;

				cout << "Enter Movie Time : ";
				cin >> times;

				cout << "Enter Movie Duration : ";
				cin >> duration;

				cout << "Enter Movie Seat : ";
				cin >> seat;

				cout << "Enter Movie Hall : ";				
				cin >> hall;

				AddMovie(id, name, date, times, duration, seat, hall );

				//Add Display Function here to see the output
				

				cout << "Enter 1 to continue insert, 0 to stop : ";
				cin >> decision;
				
			}

			DisplayMoive();
		
			break;
		/*case 2: DisplayMoive();
			break;
		case 3: SearchMovie(keyword);
			break;
		case 4: FilterMovie(keywordFilter);
			break;*/
		/*case 5: UpdateMovie();
			break;*/
		/*case 6: SortMovie();
			break;
		case 7: DeleteMovie();
			break;*/
		default: cout << "Invalid, Please Try Again";
			break;
		}
	
	
}

//Customer Menu Function
void MainMenuCustomer() {
	cout << "||======================================================||\n";
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

	

		string idT, idM;
		int seat;
		float ticketPrice;

		int decision = 1;

		cout << "Enter selection\n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			
			while (decision != 0) {
				cout << "Enter Ticket ID : ";
				cin >> idT;

				cout << "Enter Seat : ";
				cin >> seat;

				cout << "Enter Movie ID : ";
				cin >> idM;

				cout << "Enter Ticket Price : ";
				cin >> ticketPrice;
				//TicketPurchase(idT, seat, idM, ticketPrice);

				//Display the output here to see what have added

				cout << "Enter 1 to continue insert, 0 to stop : ";
				cin >> decision;
			}
			break;
		/*case 2: ViewTicket();
			break;*/
		//case 3: SortTicketPrice();
			//break;
		/*case 4: DisplayDetail();
			break;*/
		default: cout << "Invalid, Please Try Again";
			break;
		}
	
}

/* Admin Management Functions (Movie Management) */

void errorDetection() {

}

//Add Movie --> Insert into sorted list
void AddMovie(string id, string name, string date, string times, string cat, float duration, int seat, int hall) {
	
	Movie* newNode = createMovieNode(id, name, date, times, cat,duration, seat, hall);
	
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
		//Movie* previous = newMovieHead;

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

//Inserted In sorted linked list function

//void InsertSorted(Movie*Choose, Movie*newPointerHead, Movie*newPointerTail ) {
//
//	Movie* newNode = createMovieNode(id, name, date, time, duration, seat, hall);
//
//	newNode->nextAddress = NULL;
//	newNode->previous = NULL;
//
//	//Sorted list still do not have any item
//	if (movieHead == NULL) {
//
//		newMovieHead = newMovieTail = newNode;
//
//	}
//	else if (id < newMovieHead->movieId) {	//If movieID is smaller than the head value
//		newNode->nextAddress = newMovieHead;
//		newMovieHead->previous = newNode;
//		newMovieHead = newNode;
//
//	}
//	else if (id > newMovieTail->movieId) {		//If movieId is greater than the head value
//		newMovieTail->nextAddress = newNode;
//		newNode->previous = newMovieTail;
//		newMovieTail = newNode;
//
//	}
//	else {
//
//		Movie* current = newNode->nextAddress;	//Insert in the middle of the list
//
//		while (current != NULL) {
//
//			if (id < current->movieId) {
//				break;
//			}
//
//			current = current->nextAddress;
//		}
//
//		current->previous->nextAddress = newNode;
//		newNode->previous = current->previous;
//		current->previous = newNode;
//		newNode->nextAddress = current;
//
//	}
//}

//Display Movie
void DisplayMoive() {

	Movie* temp = newMovieHead;

	while (temp != NULL)
	{
		cout << temp->movieId << "-" << temp->movieName << "-"
			<< temp->movieDate << "-" << temp->movieTime << "-" << temp->movieDuration
			<< "-" << temp->numOfSeat << "-" << temp->hall << endl;
		temp = temp->nextAddress;
	}
	cout << endl;
}

//Search Movie
void SearchMovie(string keyword) {

}

//Filter Movie
void FilterMovie(string keywordFilter) {

}

//Update Movie ID
void IdUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	getline(cin, temp->movieId);
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Name
void NameUpdate (Movie * temp){
	cout << "Enter New Movie ID : ";
	getline(cin, temp->movieName);
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Date
void DateUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	getline(cin, temp->movieDate);
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Time
void TimeUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	getline(cin, temp->movieTime);
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Duration
void DurationUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	cin >> temp->movieDuration;
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Seat
void SeatUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	cin >> temp->numOfSeat;
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Hall
void HallUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	cin >> temp->hall;
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Information
void UpdateMovie() {

	Movie* temp = movieHead;

	//Get user input to update which part of the movie
	cout << "Select the information to update" << endl;
	cout << "1. Movie ID" << endl;
	cout << "2. Movie Name" << endl;
	cout << "3. Movie Date" << endl;
	cout << "4. Movie Time" << endl;
	cout << "5. Movie Duration" << endl;
	cout << "6. No of Seat" << endl;
	cout << "7. Movie Hall" << endl;

	int decision;
	cout << "Enter 1-7 as option to update :";
	cin >> decision;
	cin.ignore();

	switch (decision) {
		case 1:
			IdUpdate(temp);

		case 2 :
			NameUpdate(temp);

		case 3 :
			DateUpdate(temp);

		case 4 :
			TimeUpdate(temp);

		case 5 :
			DurationUpdate(temp);

		case 6 :
			SeatUpdate(temp);

		case 7 :
			HallUpdate(temp);

		default:
			cout << "Please Enter the correct input. " << endl;
	}
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

		
	}
	cout << "Final result shows as below\n";
		for (int i = 0; i < size; i++)
		{
			cout << billyarrays[i] << " , ";
		}
		cout << endl;

}

//Delete Movie from Movie List
void DeleteMovie() {

}

/* Customer Purchasing Functions (Purchasing Ticket) */

//Purchase Ticket --> Add Purchase
void TicketPurchase(string id, string seat, string movieId, float ticketPrice) {
	
	//Call insert sorted function
	Ticket* newNode = createTicketNode(id, seat, movieId, ticketPrice);

	newNode->nextAddress = NULL;
	newNode->previous = NULL;

	if (ticketHead == NULL) {
		newTicketHead = newTicketTail = newNode;

	} else if (id < newTicketHead->ticketId) {
		newNode->nextAddress = newTicketHead;
		newTicketHead->previous = newNode;
		newTicketHead = newNode;

	} else {

		Ticket* current = newNode->nextAddress;

		while (current != NULL) {
			if (id < current->ticketId) {
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

//View Purchase Transactions
void ViewTicket() {

}

//Sort Purchase Transaction based on total price
void SortTicketPrice(string idd, string seat, string movieId) {

}

//View Purchase Details
void DisplayDetail() {

}