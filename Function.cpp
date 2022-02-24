#include "Header.h"

// Assumption that all the data is pre-sorted
 Movie *movieHead, * movieTail, *newMovieHead, *newMovieTail;

Ticket *ticketHead, * ticketTail, *newTicketHead, *newTicketTail;

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
		MainMenuCustomer();
	}

}

void CreateData() {
	string movieId[] = {"M0001","M0002","M0003"};
	string movieName[] = { "Harry Potter","Friends","Till We Meet Again" };
	string movieDate[] = { "29-9-2022","18-6-2022","2-2-2022" };
	string movieTime[] = { "1830","1400","1000" };
	string categories[] = { "Comedy","Comedy","Romance" };
	float movieDuration[] = { 3,4,2 };
	int numOfSeat[] = {100,75,66};
	int hall[] = {3,1,4 };

	for (int i = 0; i < 3; i++) {
		Movie newMovie =  Movie();
		newMovie.movieId = movieId[i];
		newMovie.movieName = movieName[i];
		newMovie.movieDate = movieDate[i];
		newMovie.movieTime = movieTime[i];
		newMovie.categories = categories[i];
		newMovie.movieDuration = movieDuration[i];
		newMovie.numOfSeat = numOfSeat[i];
		newMovie.hall = hall[i];
	}
	

	string ticketId[] = {"T9001","T9056","T9002"};		
	string seat[] = { "A45","D22","C78" };			
	string movieId[] = { "M0001","M0001","M0001" };			
	float ticketPrice[] = { 109.00, 25.00, 50.50};
	for (int i = 0; i < 3; i++) {
		Ticket newTicket = Ticket();
		newTicket.ticketId = ticketId[i];
		newTicket.seat = seat[i];
		newTicket.movieId = movieId[i];
		newTicket.ticketPrice = ticketPrice[i];
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

	string movie[3][8] = {
		{"M0001","Harry Potter","29-9-2022","1830", "Comedy", "3","100","3"},
		{"M0002","Friends","18-6-2022","1400","Comedy", "4","75","1"},
		{"M0003","Till We Meet Again","2-2-2022","1000","Romance", "2","66","4"}
	};

	int choice;

		/* Movie Add Variables*/
		string id, name, date, times, cat;
		float duration;
		int seat;
		int hall;

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

					
					AddMovie(id, name, date, times, cat, duration, seat, hall );	//Function
					

					cout << "Enter 1 to continue insert, 0 to stop : ";
					cin >> decision;
				
				}

				//Display all the movie listed
				cout << "Movie are listed below : " << endl;
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
			default: 
				cout << "Invalid, Please Try Again";
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

	const int sizes = 10;
	string ticket[sizes][4] = {
		{"T9001", "A45", "M0001", "109.00"},
		{"T9056", "D22", "M0001", "25.00"},
		{"T9001", "C78", "M0001", "50.50"}
	};

	
	int choice;	

		string idT, idM;
		string seat;
		float ticketPrice;

		int decision = 1;
		int count = 1;

		int length = sizeof(ticket) / sizeof(ticket[0]);
		cout << "The length of the linked list: " << length << endl;

		cout << "Enter selection : ";
		cin >> choice;

		switch (choice) {
			case 1: 
				/*int count = 1;*/
				/*cout << "Enter the numbers to add : " ;
				cin >> count;*/

				

				for (int i = 0; i < length; i++) {

					Ticket* newTicket = new Ticket;
					newTicket->ticketId = ticket[i][0];
					newTicket->movieId = ticket[i][2];
					newTicket->seat = ticket[i][1];
					newTicket->ticketPrice = stoi(ticket[i][3]);

					displayFromFront(ticketHead);

					while (count != 0) {
						/*for (int i = 0; i < count; i++) {*/
						cout << "Enter Ticket ID : ";
						cin >> idT;

						cout << "Enter Seat : ";
						cin >> seat;

						cout << "Enter Movie ID : ";
						cin >> idM;

						cout << "Enter Ticket Price : ";
						cin >> ticketPrice;

						TicketPurchase(&ticketHead, idT, seat, idM, ticketPrice);

						cout << "Enter 1 to continue : ";
						cin >> count;

						cout << newTicket->ticketId << " " << newTicket->movieId << " " << newTicket->seat << " " << newTicket->ticketPrice << endl;

						//Display the output here to see what have added
						/*ViewTicket(ticket);*/
					}

					cout << "Information has added are" << endl;
					DisplayTicket2();
				}
				//}
				

				

				break;
			case 2: 

				ViewTicket(ticket);
				break;
			//case 3: SortTicketPrice();
				//break;
			/*case 4: DisplayDetail();
				break;*/
			default: cout << "Invalid, Please Try Again";
				break;
		}
	
}

/* Admin Management Functions (Movie Management) */


//Add Movie --> Insert into sorted list
void AddMovie(string id, string name, string date, string times, string cat, float duration, int seat, int hall) {
	
	Movie* newNode = createMovieNode(id, name, date, times, cat,duration, seat, hall);
	
	newNode->nextAddress = NULL;
	newNode->previous = NULL;

	//Sorted list still do not have any item
	if (movieHead == NULL) {

		movieHead = newNode;

	}
	else {
		

	
	}

}

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

void DisplayTicket2() {
	Ticket* temp = ticketHead;

	while (temp != NULL)
	{
		cout << temp->ticketId << "-" << temp->seat << "-"
			<< temp->movieId << "-" << temp->ticketPrice << endl;

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

void CategoryUpdate(Movie* temp) {
	cout << "Enter New Movie ID : ";
	getline(cin, temp->categories);
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
void SortMovie() {



	//int key, currentcolindex; 

	//for (int roundindex = 1; roundindex < size; roundindex++)
	//{
	//	key = billyarrays[roundindex];
	//	currentcolindex = roundindex;

	//	//currentcolindex > 0 -> you still got previous items in front of current item
	//	while (currentcolindex > 0 && billyarrays[currentcolindex - 1] > key)
	//	{
	//		billyarrays[currentcolindex] = billyarrays[currentcolindex - 1];
	//		currentcolindex--;
	//	}
	//	billyarrays[currentcolindex] = key;

	//	
	//}
	//cout << "final result shows as below\n";
	//	for (int i = 0; i < size; i++)
	//	{
	//		cout << billyarrays[i] << " , ";
	//	}
	//	cout << endl;

}

//Delete Movie from Movie List
void DeleteMovie() {

}

/* Customer Purchasing Functions (Purchasing Ticket) */

//Display From Front
void displayFromFront(Ticket* head) {
	Ticket* temp = head;

	while (temp) {
		cout << temp->ticketId << "-" << temp->seat << "-" << temp->movieId << "-" << temp->ticketPrice << endl;
		temp = temp->nextAddress;
	}

	cout << "Ended";
}

//Purchase Ticket --> Add Purchase
void TicketPurchase(Ticket** head, string id, string seat, string movieId, float ticketPrice) {
	
	/*for (int i = 0; i < 5; i++) {*/

		//Call insert sorted function
		Ticket* newNode = createTicketNode(id, seat, movieId, ticketPrice);

		newNode->nextAddress = (*head);
		(*head) = newNode;

		newNode->nextAddress = NULL;
		newNode->previous = NULL;

		if (ticketHead == NULL) {
			ticketHead = newNode;

		} else {
			Ticket* current = ticketHead;
			while (current->nextAddress != NULL) {
				current = current->nextAddress;
			}

			current->nextAddress = newNode;
		}
		//cout << newNode->ticketId << " " << newNode->movieId << " " << newNode->seat << " " << newNode->ticketPrice << endl;
	//}
	/*::size++;*/
}

//View Purchase Transactions
void ViewTicket(string ticket[3][4]) {
	int ROW = 10;
	for (int i = 0; i < ROW; i++) {
			Ticket* newTicket = new Ticket;
			newTicket->ticketId = ticket[i][0];
			newTicket->movieId = ticket[i][2];
			newTicket->seat = ticket[i][1];
			newTicket->ticketPrice = stoi(ticket[i][3]);

			cout << newTicket->ticketId << " " << newTicket->movieId << " " << newTicket->seat << " " << newTicket->ticketPrice << endl;

	}
}

//Sort Purchase Transaction based on total price
void SortTicketPrice(string idd, string seat, string movieId) {

}

//View Purchase Details
void DisplayDetail() {

}