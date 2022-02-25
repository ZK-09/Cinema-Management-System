#include "Header.h"

// Assumption that all the data is pre-sorted
Movie* movieHead, * movieTail, * newMovieHead, * newMovieTail;

Ticket* ticketHead, * ticketTail, * newTicketHead, * newTicketTail;

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
	}
	else if ((username == "Cus") && (password == "Cus")) {
		system("CLS");
		//Call Customer Menu (Purchase Ticket)
		MainMenuCustomer();

	}
	else {

		cout << "You have to login with an account";
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
	cout << "||8.Exit\t\t\t\t\t\t||\n";
	cout << "||======================================================||\n\n";

	int choice;

	/* Movie Add Variables*/
	string id, name, date, times, cat;
	string keyword;
	float duration;
	int seat;
	int hall;
	bool searchFound;

	cout << "Enter selection : ";
	cin >> choice;

	int decision = 1;
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

			cout << "Enter Movie Category : ";
			cin >> cat;

			cout << "Enter Movie Duration : ";
			cin >> duration;

			cout << "Enter Movie Seat : ";
			cin >> seat;

			cout << "Enter Movie Hall : ";
			cin >> hall;


			AddMovie(id, name, date, times, cat, duration, seat, hall);	//Function


			cout << "Enter 1 to continue; 0 to exit: ";
			cin >> decision;

		}

		//Display all the movie listed
		cout << endl << "Movie are listed below : " << endl;
		ViewMovie();

		system("pause");
		system("CLS");
		MainMenuAdmin();

		break;

	case 2:

		DisplayMoive();
		system("pause");
		system("CLS");
		MainMenuAdmin();

		break;
	case 3:

		cout << "Enter Search Keyword : ";
		cin >> keyword;
		cout << endl;
		searchFound = SearchMovie(keyword);

		if (searchFound == true) {
			system("pause");
			system("CLS");
			MainMenuAdmin();

		}
		else {
			cout << "Movie Id not found, enter again :";
			cin >> keyword;
			SearchMovie(keyword);
		}
		break;

	case 4:

		cout << "Please enter the category you want to search(Romance, Comedy, Action) :";
		cin >> keyword;
		searchFound = FilterMovie(keyword);

		if (searchFound == true) {
			system("pause");
			system("CLS");
			MainMenuAdmin();

		}
		else {
			cout << "Please enter the category you want to search(Romance, Comedy, Action) :";
			cin >> keyword;
			searchFound = FilterMovie(keyword);
		}
		break;

	case 5:

		cout << "Enter Movie Id to update : ";
		cin >> keyword;
		cout << endl;

		searchFound = SearchMovie(keyword);

		if (searchFound == true) {
			UpdateMovie();
			
		}
		else {
			cout << "Movie Not Found";
		}

		break;

	case 6: 
		SortMovie(&movieHead);
		
		DisplayMoive();
		MainMenuAdmin();
		break;
	case 7:
		cout << "Please enter the Movie Id you want to delete";
		cin >> keyword;

		searchFound = DeleteMovie(keyword);
		if (searchFound == true) {
			system("pause");
			DisplayMoive();

			system("pause");
			system("CLS");
			MainMenuAdmin();

		}
		else {
			cout << "Please enter the Movie Id you want to delete";
			cin >> keyword;
			searchFound = DeleteMovie(keyword);
		}
		break;
	case 8:
		break;
	default:
		cout << "Invalid, Please Try Again" << endl;
		MainMenuAdmin();
	}


}

//Customer Menu Function
void MainMenuCustomer() {
	cout << "||======================================================||\n";
	cout << "||\t    GRANDPLEX MOVIE TICKETING SYSTEM\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||\t\t\tMENU\t\t\t\t||\n";
	cout << "||======================================================||\n";
	cout << "||1.Add Purchase\t\t\t\t\t||\n";
	cout << "||2.View Purchase\t\t\t\t\t||\n";
	cout << "||3.Sort Purchases\t\t\t\t\t||\n";
	cout << "||4.Purchase Detail\t\t\t\t\t||\n";
	cout << "||5.Exit\t\t\t\t\t\t||\n";
	cout << "||======================================================||\n\n";

	int choice;

	string id;
	string seat;
	string movieId;
	float ticketPrice;
	bool ticketChecker;
	int decision = 1;

	cout << "Enter selection : ";
	cin >> choice;
	cin.ignore();

	switch (choice) {
	case 1:

		while (decision != 0) {

			cout << "Enter Ticket Id : ";
			cin >> id;

			cout << "Enter Seat : ";
			cin >> seat;

			cout << "Enter Movie Id : ";
			cin >> movieId;

			cout << "Enter Ticket Price : ";
			cin >> ticketPrice;

			TicketPurchase(id, seat, movieId, ticketPrice);

			cout << "Enter 1 to continue; 0 to quit : ";
			cin >> decision;
		}
		ViewTicket(); //display from end
		MainMenuCustomer();
		break;
	case 2:

		DisplayTicket();
		MainMenuCustomer();
		break;

	case 3: 
		
		SortTicketPrice(&ticketHead);
		DisplayTicket();
		MainMenuCustomer();
		break;

	case 4:
		cout << "please enter the ticket ID :";
		cin >> id;
		ticketChecker = DisplayDetail(id);
		if (ticketChecker == true) {
			system("pause");
			system("CLS");
			MainMenuCustomer();

		}
		else {
			cout << "please enter the ticket ID :";
			cin >> id;
			ticketChecker = DisplayDetail(id);
		}

		break;
	case 5:
		break;

	default: 
		cout << "Invalid, Please Try Again" << endl;
		MainMenuCustomer();
	}

}

/* Admin Management Functions (Movie Management) */

//Add Movie --> Insert to front
void AddMovie(string id, string name, string date, string times, string cat, float duration, int seat, int hall) {

	Movie* newNode = createMovieNode(id, name, date, times, cat, duration, seat, hall);

	newNode->nextAddress = NULL;
	newNode->previous = NULL;

	
	if (movieHead == NULL) {

		movieHead = movieTail = newNode;

	}
	else {
		newNode->nextAddress = movieHead;
		movieHead->previous = newNode;
		movieHead = newNode;

	}

}

void ViewMovie() {
	Movie* temp = movieTail;

	cout << "Movie ID\tMovie Name\tMovie Date\tMovie Time\tMovie Categories\tMovie Duration\tMovie Seat\tMovie Hall" << endl;

	while (temp != NULL) {
		cout << temp->movieId << "-" << temp->movieName << "-" << temp->movieDate << "-" << temp->movieTime
			<< "-" << temp->categories << "-" << temp->movieDuration << "-" << temp->numOfSeat << "-" << temp->hall << endl;
		temp = temp->previous;
	}
}

//Display Movie
void DisplayMoive() {

	Movie* temp = movieHead;

	while (temp != NULL)
	{
		cout << temp->movieId << "-" << temp->movieName << "-"
			<< temp->movieDate << "-" << temp->movieTime << "-" << temp->categories << "-" 
			<< temp->movieDuration << "-" << temp->numOfSeat << "-" << temp->hall << endl;

		temp = temp->nextAddress;
	}
	cout << endl;
}


//Search Movie
bool SearchMovie(string keyword) {

	Movie* temp = movieHead;	//Assign Movie struct
	int flag = 0;

	while (temp != NULL) {		//Read all the data using temp
		if (temp->movieId == keyword) {
			cout << temp->movieId << "-" << temp->movieName << "-"
				<< temp->movieDate << "-" << temp->movieTime << "-" << temp->categories << "-" << temp->movieDuration
				<< "-" << temp->numOfSeat << "-" << temp->hall << endl;

			temp = temp->nextAddress;
			flag = 1;

		}
		else {
			temp = temp->nextAddress;
		}
	}

	if (flag == 0) {		//Not Found Return false
		cout << "Movie Not Found .." << endl;

		return false;
	}
	else {					//Found True
		return true;
	}
}

//Filter Movie
bool FilterMovie(string keywordFilter) {
	Movie* temp = movieHead;
	bool succesCount = 0;
	while (temp != NULL)
	{
		if (temp->categories == keywordFilter) {
			cout << temp->movieId << "-" << temp->movieName << "-"
				<< temp->movieDate << "-" << temp->movieTime << "-" << temp->categories << "-" << temp->movieDuration
				<< "-" << temp->numOfSeat << "-" << temp->hall << endl;
			temp = temp->nextAddress;
			succesCount = 1;
		}
		else
		{
			temp = temp->nextAddress;
		}
	}
	if (succesCount = 1) {
		cout << "category found, returning to main menu" << endl;
		return true;
	}
	else {
		cout << "category not found, please try again" << endl;
		return false;
	}

}

//Update Movie ID
void IdUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	getline(cin, temp->movieId);
	
	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Name
void NameUpdate(Movie* temp) {
	cout << "Enter New Movie Name : ";
	getline(cin, temp->movieName);

	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Date
void DateUpdate(Movie* temp) {
	cout << "Enter New Movie Date : ";
	getline(cin, temp->movieDate);

	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Time
void TimeUpdate(Movie* temp) {
	cout << "Enter New Movie Time : ";
	getline(cin, temp->movieTime);

	cout << endl << "Update Successfullly." << endl;
}

void CategoryUpdate(Movie* temp) {
	cout << "Enter New Movie Category : ";
	getline(cin, temp->categories);

	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Duration
void DurationUpdate(Movie* temp) {
	cout << "Enter New Movie Duration : ";
	cin >> temp->movieDuration;

	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Seat
void SeatUpdate(Movie* temp) {
	cout << "Enter New Movie Seat : ";
	cin >> temp->numOfSeat;

	cout << endl << "Update Successfullly." << endl;
}

//Update Movie Hall
void HallUpdate(Movie* temp) {
	cout << "Enter New Movie Hall : ";
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
		break;

	case 2:
		NameUpdate(temp);
		break;

	case 3:
		DateUpdate(temp);
		break;

	case 4:
		TimeUpdate(temp);
		break;

	case 5:
		DurationUpdate(temp);
		break;

	case 6:
		SeatUpdate(temp);
		break;

	case 7:
		HallUpdate(temp);
		break;

	default:
		cout << "Please Enter the correct input. " << endl;
	}
}

//Sort Movie based on quantity
void SortMovie(struct Movie** head) {
	struct Movie* current = *head , *index = NULL;

	int temp;

	if (head == NULL) {
		return;
		
	} else {
		while (current != NULL) {
			index = current->nextAddress;

			while (index != NULL) {
				if (current->numOfSeat > index->numOfSeat) {
					temp = current->numOfSeat;
					current->numOfSeat = index->numOfSeat;
					index->numOfSeat = temp;
				}

				index = index->nextAddress;
			}
			current = current->nextAddress;
		}
		
	}
	
}

//Delete Movie from Movie List
bool DeleteMovie(string keyword) {
	Movie* temp = movieHead;
	bool succesCount = false;
	while (temp != NULL)
	{
		if (temp->movieId == keyword) {

			if (temp->previous == NULL) {
				cout << "first one" << endl;
				deletefromfront();
				succesCount = true;
				break;

			}
			else if (temp->nextAddress == NULL)
			{
				cout << "last one" << endl;
				deletefromEnd();
				succesCount = true;
				break;
			}
			else
			{
				cout << "middle one" << endl;
				deletefromspecificlocation(keyword);
				succesCount = true;
				break;
			}

		}
		else
		{
			temp = temp->nextAddress;
		}
	}
	if (succesCount = true) {
		cout << "deleted successfully, viewing the list after delete" << endl;
		return true;
	}
	else {
		cout << "item not found, please try again" << endl;
		return false;
	}
}

void deletefromfront()
{
	//step 1: before delete will check whether the list is empty?
	if (movieHead == NULL)
		return;

	//step 2: create a temp pointer
	Movie* temp = movieHead;

	//step 3: move the head to the next point
	movieHead = movieHead->nextAddress;

	//step 4: before delete display the deleted data first!
	cout << "Movie name " << temp->movieName << " is deleted, returning to main menu" << endl;

	//step 5: remove the data from the linked list
	delete temp;

	//optional: if you have size, then after delete you must reduce the size by 1
}

void deletefromspecificlocation(string deleteId)
{
	//situation 1: list is empty
	if (movieHead == NULL)
	{
		cout << "List is empty! Can't use the delete function!" << endl;
		return;
	}
	//situation 2: list not empty but use the deleted id in first location
	else if (movieHead->movieId == deleteId)
	{
		Movie* temp = movieHead;
		movieHead = movieHead->nextAddress;
		cout << "Movie name " << temp->movieName << " is deleted, returning to main menu" << endl;
		delete temp;
	}
	//situation 3: list not empty not the first location
	else
	{
		Movie* temp = movieHead;
		Movie* prev = NULL;

		while (temp != NULL)
		{
			if (temp->movieId == deleteId)
			{
				prev->nextAddress = temp->nextAddress;
				cout << "Movie name " << temp->movieName << " is deleted, returning to main menu" << endl;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->nextAddress;
		}
		cout << "No such id! " << endl;
	}
}

void deletefromEnd()
{
	//Check if the list is empty
	if (movieHead == NULL)
		return;

	Movie* temp = movieHead;
	Movie* previous = NULL;

	while (temp->nextAddress != NULL) {
		previous = temp;
		temp = temp->nextAddress;

	}

	//Change the previous item nextaddress to NULL
	if (previous == NULL) {
		movieHead = NULL;

	}
	else {
		previous->nextAddress = NULL;
	}

	cout << "Movie name " << temp->movieName << " is deleted, returning to main menu" << endl;

	delete temp;
}

/* Customer Purchasing Functions (Purchasing Ticket) */

//Display From Front
void DisplayTicket() {
	Ticket* temp = ticketHead;
	cout << "Ticket ID\tSeat\tMovie Id\tTicket Price" << endl;
	while (temp != NULL) {
		cout << temp->ticketId << "\t\t" << temp->seat << "\t" << temp->movieId << "\t\t" << temp->ticketPrice << endl;
		temp = temp->nextAddress;
	}

}

//Purchase Ticket --> Add Purchase

//Insert to front using head
void TicketPurchase(string id, string seat, string movieId, float ticketPrice) {

	Ticket* newNode = createTicketNode(id, seat, movieId, ticketPrice);

	newNode->nextAddress = NULL;
	newNode->previous = NULL;

	if (ticketHead == NULL) {
		ticketHead = ticketTail = newNode;

	}
	else {
		newNode->nextAddress = ticketHead;
		ticketHead->previous = newNode;
		ticketHead = newNode;

	}
}

//display from end
//View Purchase Transactions
void ViewTicket() {
	Ticket* temp = ticketTail;

	cout << "Ticket ID\tSeat\tMovie Id\tTicket Price" << endl;
	while (temp != NULL) {
		cout << temp->ticketId << "\t\t" << temp->seat << "\t" << temp->movieId << "\t\t" << temp->ticketPrice << endl;
		temp = temp->previous;
	}
}

//Sort Purchase Transaction based on total price
void SortTicketPrice(struct Ticket ** head) {
	struct Ticket* current = *head , *index = NULL;

	int temp;

	if (head == NULL) {
		return;

	} else {
		while (current != NULL) {
			index = current->nextAddress;

			while (index != NULL) {
				if (current->ticketPrice > index->ticketPrice) {
					temp = current->ticketPrice;
					current->ticketPrice = index->ticketPrice;
					index->ticketPrice = temp;
				}

				index = index->nextAddress;
			}
			current = current->nextAddress;
		}

	}

}

//View Purchase Details
bool DisplayDetail(string TicketIdentifier) {
	Ticket* temp = ticketHead;

	bool succesCount = 0;
	//bool moviesearcher;

	while (temp != NULL)
	{

		if (temp->ticketId == TicketIdentifier) {

			cout << "ticket found, ticket detail is : ";
			cout << temp->ticketId << "\t" << temp->seat << "\t" << temp->movieId << "\t" << temp->ticketPrice << endl;
			cout << "the movie in this ticket is : ";
			bool moviewsearcher = SearchMovie(temp->movieId);

			temp = temp->nextAddress;
			succesCount = 1;
		}
		else
		{
			temp = temp->nextAddress;
		}
	}
	if (succesCount = 1) {

		cout << "details displayed, returning to main menu" << endl;
		return true;
	}
	else {
		cout << "ticket not found, please try again" << endl;
		return false;
	}

}