#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

const int rowLimit = 10;				//to set maximum book quantity that can be record

string bookTitle[rowLimit] = {};
string bookAuthor[rowLimit] = {};
string bookIDtag[rowLimit] = {};
float bookPrice[rowLimit] = {};

void startLogo()
{
	cout << " ____________________________ " << endl;
	cout << "| LIBRARY MANAGEMENT SYSTEM  |" << endl;
	cout << "| NCS1A Group One            |" << endl;
	cout << "| Assignment                 |" << endl;
	cout << "|____________________________|" << endl;
	cout << endl;
	cout << "Welcome to Library Management System!\n";
	cout << "by Group One\n--> Afiq\n--> Muhaimin\n--> Haikal\n--> Nasrul\n" << flush; //flush forces the printing to the screen before it clears
	this_thread::sleep_for(std::chrono::seconds(3)); //To display logo and team name.Requires header files "chrono" and "thread".
	system("CLS"); //clears the screen
}
void bookAdd()
{
	system("CLS"); //clears the screen
	char bookID[4];
	char nameBook[50];
	char author[15];
	float price = 0;

	cin.ignore();						//Put to avoid whitespace error

	cout << "****************************************************************************************************" << endl;
	cout << "Please enter book info: \n";
	cout << "****************************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "Enter book title (Input max 49 letter) =>";
	cin.getline(nameBook, 50);
	cout << "Enter book author (Input max 14 letter)=>";
	cin.getline(author, 15);
	cout << "Book ID (format must be 1 character and 2 number) such as A01 =>";
	cin.getline(bookID, 4);
	cout << "Enter book price (Please enter number with or without decimal only)=>";
	cin >> price;

	for (int r = 0; r < rowLimit; r++)
	{
		if (bookTitle[r] == "\0")
		{
			bookTitle[r] = nameBook;
			bookAuthor[r] = author;
			bookIDtag[r] = bookID;
			bookPrice[r] = price;
			break;
		}

	}

}
void bookDelete(string search)
{
	system("CLS");

	int counter = 0;
	cout << "===================================================================================================" << endl;
	for (int c = 0; c < rowLimit; c++)
	{
		if (bookIDtag[c] == search)
		{
			counter++;
			bookTitle[c] = "";
			bookAuthor[c] = "";
			bookIDtag[c] = "";
			bookPrice[c] = 0.00;

			cout << endl;
			cout << "The book has been deleted!" << endl;
			cout << "---------------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (counter == 0)
	{
		cout << "Result not found";
	}
	cout << "Press any key to back to refresh page";
	cin.get();
}
void bookUpdate(string search)
{
	system("CLS");
	char bookID[4];
	char nameBook[50];
	char author[15];
	float price = 0;

	int counter = 0;
	cout << "===================================================================================================" << endl;
	for (int v = 0; v < rowLimit; v++)
	{
		if (bookIDtag[v] == search)
		{
			cout << "---------------------------------------------------------------------------------------------------" << endl;
			cout << "Search result" << endl;
			cout << "---------------------------------------------------------------------------------------------------" << endl;
			cout << "  No.|Book ID|                  Book Title                                                         " << endl;
			cout << "===================================================================================================" << endl;
			cout << setw(3) << counter << setw(7) << bookIDtag[v];
			cout << setw(4) << "|";
			cout << bookTitle[v] << endl;
			cout << "===================================================================================================" << endl;

			counter++;
			cout << "Enter new book title => ";
			cin.getline(nameBook, 50);
			cout << "Enter new book author =>";
			cin.getline(author, 15);
			cout << "Enter new Book ID (format must be 1 character and 2 number) such as A01 =>";
			cin.getline(bookID, 4);
			cout << "Enter new book price (Please enter number with or without decimal only)=>";
			cin >> price;

			bookTitle[v] = nameBook;
			bookAuthor[v] = author;
			bookIDtag[v] = bookID;
			bookPrice[v] = price;

			cout << "Successfully update the book!" << endl;
			break;
		}

	}
	if (counter == 0)
	{
		cout << "Result not found" << endl;
	}
	cout << "===================================================================================================" << endl;
	cout << "*Press any key to return to menu";
	cin.get();
}
void bookDisplay()
{
	system("CLS");
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "All Book in Library List Diplay" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "  No.|Book ID|                  Book Title                                |    Author     |  Price " << endl;
	cout << "===================================================================================================" << endl;
	int counter = 0;
	for (int z = 0; z < rowLimit; z++)
	{
		if (bookIDtag[z] != "\0")
		{
			counter++;
			cout << setw(3) << counter << setw(3) << "|" << setw(4) << bookIDtag[z];
			cout << setw(4) << "|";
			const string temp = bookTitle[z];
			int p = temp.length();
			if (p < 50)
			{
				cout << bookTitle[z];
				for (int e = 0; e < (50 - p); e++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << bookTitle[z];
			}

			cout << setw(11) << "|";
			const string tempA = bookAuthor[z];
			int g = tempA.length();
			if (g < 15)
			{
				cout << bookAuthor[z];
				for (int w = 0; w < (15 - g); w++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << bookAuthor[z];
			}
			cout << setw(1) << "|";
			cout << setw(1) << setprecision(2) << fixed << bookPrice[z] << endl;
		}

	}
	if (counter == 0)
	{
		cout << "Library is empty. Please go to add book record!" << endl;
	}
	cout << "===================================================================================================" << endl;
	cout << "*Press any key to return to menu";
	cin.get();
	cin.get();
}
void bookSearch(string search)
{
	system("CLS");
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Search result" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "  No.|Book ID|                  Book Title                                                         " << endl;
	cout << "===================================================================================================" << endl;

	int counter = 0;
	for (int f = 0; f < rowLimit; f++)
	{
		if (bookIDtag[f] == search)
		{
			counter++;
			cout << setw(3) << counter << setw(7) << bookIDtag[f];
			cout << setw(4) << "|";
			cout << bookTitle[f] << endl;
			break;
		}
	}
	if (counter == 0)
	{
		cout << "Result not found" << endl;
	}
	cout << "===================================================================================================" << endl;
	cout << "*Press any key to return to menu";
	cin.get();

}
void LibraryValue()
{
	system("CLS"); //clears the screen
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "All Book in Library List Diplay" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "  No.|Book ID|  Price                                                                              " << endl;
	cout << "===================================================================================================" << endl;
	int counter = 0;
	float bookSum = 0;
	for (int z = 0; z < rowLimit; z++)
	{
		if (bookIDtag[z] != "\0")
		{
			counter++;
			cout << setw(3) << counter << setw(3) << "|" << setw(4) << bookIDtag[z];
			cout << setw(4) << "|";
			cout << setw(3) << bookPrice[z] << endl;


			bookSum += bookPrice[z];
		}
	}
	if (counter == 0)
	{
		cout << "Library is empty!" << endl;
	}
	cout << "****************************************************************************************************" << endl;
	cout << "Library Value => RM " << setprecision(2) << fixed << bookSum << endl;
	cout << "===================================================================================================" << endl;
	cout << "*Press any key to return to menu";
	cin.get();
	cin.get();
}
void menuPage()
{
	system("CLS");
	cout << "---------------------------------------------------------------------------------------------------";
	cout << endl;
	cout << "Please choose one of the option below: ";
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------";
	cout << endl;
	cout << endl;
	cout << "(S) Search Book by Book ID" << endl << endl;
	cout << "(D) Display List of Books Avalible" << endl << endl;
	cout << "(A) Add a Book" << endl << endl;
	cout << "(U) Update Book info" << endl << endl;
	cout << "(X) Delete a Book" << endl << endl;
	cout << "(V) All Book Values (Library Asset)" << endl << endl;
	cout << "(E) Exit" << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------";
	cout << endl;
	cout << "Enter option :> ";
}
void exitLogo()
{
	system("CLS"); //clears the screen
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(15) << "Thank you for using\n";
	cout << setw(10) << "Group One Library Management System!";
	cout << endl;
	cout << endl;
	cout << endl;
}
void Login_ID()
{
	class Register { public:string username, password; };
	class Login { public:string inpUsername, inpPassword; };

	Register newUser;
	cout << "\n\n***Welcome to Libray Management System ***";
	cout << "\n***Please register First***\n\n";
	cout << "\nEnter your username: ";
	cin >> newUser.username;
	cout << "Enter your password: ";
	cin >> newUser.password;
	system("CLS");
	cout << "\nSuccessfully Registered your account, Please login below.\n\n";

	for (int i = 1; i >= 0; i--)
	{
		cout << "Please enter your password you have " << i << " attempts remaining: ";
		// login
		Login newLogin;
		cout << "Please Login ";
		cout << "\nUsername: ";
		cin >> newLogin.inpUsername;
		cout << "Password: ";
		cin >> newLogin.inpPassword;

		if (newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password)
		{
			cout << "\nSuccessfully logged in, loading your dashboard...";
			break;
		}
		else
		{
			cout << "Login Failed! Please try again\n\n";
		}
	exit(4);
	}		
	system("CLS");
}
int main()
{
	startLogo();		//print out Logo
	Login_ID();
	bool exit = true;	// declaring a boolean variable with true value   
	char response;		//variable to accept response value
	string inputID;

	do
	{
		menuPage();			//print out Menu
		cin >> response;
		switch (response)	//for selection of function					
		{
		case ('S'): case ('s'):
			cin.ignore();
			cout << "Search by using Book ID. Please enter ID=> ";
			getline(cin, inputID);
			bookSearch(inputID);					//call function
			break;
		case 'D': case ('d'):						//call function
			bookDisplay();
			break;
		case 'A': case ('a'):						//call function
			bookAdd();
			break;
		case 'U': case ('u'):						//call function
			cin.ignore();
			cout << "Please enter the book ID that need to be updated =>";
			getline(cin, inputID);
			bookUpdate(inputID);
			break;
		case 'X': case ('x'):						//call function
			cin.ignore();
			cout << "Please enter the book ID that need to be deleted =>";
			getline(cin, inputID);
			bookDelete(inputID);
			break;
		case 'V': case ('v'):						//call function
			LibraryValue();
			break;
		case 'E': case ('e'):						//to exit loop and end program
			exit = false;
			break;
		default:									//to inform unknown selection and  inform user to enter again.
			cout << "Unknown response. Please enter again.";
			cin.get();
			break;
		}
	} while (exit);
	cout << endl;
	exitLogo();

	return 0;
}
//{"mode":"full", "isActive" : false}
