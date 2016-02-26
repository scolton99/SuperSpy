#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

void readmedestroy();	// For the release ReadMe version, delete the readme file after the game ends
void showspy(int i);	// Shows the spy number with a certain number of zeros in front of it depending on the value
void showinfo(int i);	// Show info about a suspect or show the intel again
void listsuspects();	// Show the list of suspects
void youwin();			// Tell user they won and copy their score to a file
void youlose();			// Tell user they lost and end the game
void showtitle();		// Show the title screen
void genreadme();		// Generate a readme file if none exist yet
int turnsleft0(int i);	// Check if the user has no turns left, and if they do not, print a message and change variables 
int randnum();			// Generate a random number

struct player{
	string name;
	int age;
	int gender;
}player;	// Contains player data

int turnsleft = 5;				// The player has 5 turns
int spynumber = randnum();
int suspect;

int main(array<System::String ^> ^args)
{
	int choice, guess, suspecttrue = 3;
	bool suspectmenu = false, mainmenu  = false;

	system("mode con lines=26");

	genreadme();
	
	showtitle();

	cout << endl << "      What is your name?" << endl << endl << "      ";
	getline(cin, player.name);

	system("CLS");

	showtitle();

	cout << endl << "      And your age?" << endl << endl << "      ";
	
	do{
		
		cin >> player.age;
		if(player.age > 100){
			system("CLS");
			showtitle();
			cout << endl <<"      Liar.  Try again." << endl << endl << "      ";
		}
	}while(player.age > 100);
	cin.ignore();

	system("CLS");

	showtitle();

	cout << endl << "      Your gender?" << endl << endl <<
		"      1. Male" << endl << "      2. Female" << endl << endl << "      ";
	do{
		cin >> player.gender;
		if(player.gender > 2 || player.gender < 1){
			system("CLS");
			showtitle();
			cout << endl << "      Liar.  Try again." << endl << 
				endl << "      1. Male" << endl << "      2. Female" << endl << endl << "      ";
		}
	}while(player.gender > 2 || player.gender < 1);
	cin.ignore();

	system("CLS");

	cout << player.name <<"," << endl 
		<< "You have been brought to the Pentagon today because the United States" << endl <<
		"government has recently learned that Iraq is planning a missile strike against" << endl <<
		"the US.  A sleeper cell in the central US has the missile activation code, and" << endl <<
		"will release it tomorrow night at midnight if not stopped.  You have been chosento find them, and" << 
		"take them out silently before 12 AM tomorrow.  You have only" << endl
		<< "one guess at who the suspect is.  You can only look at information 5 times, and" << endl
		<< "there are 5 suspects.  You may look at this information again, but it will cost you a turn.  Good luck." << endl
		<< endl;

	showspy(0);

	cout << endl << endl;
	
	system("pause");

	system("CLS");

	cout << "Intel: "<< endl << "  - Location: Nebraska/Kansas/Oklahoma" << endl <<
		"  - Race:  Unknown, Most likely Caucasian" << endl << "  - Age:  30-50" << endl << endl;

	cout << endl << "The suspects may or may not have a passport.  We have no time to check" << endl
		<< "if the passport is valid.  Most criminals do not get a passport due to" << endl
		<< "possible complications, but this specific one is crafty.  He/she may" << endl
		<< "have one.  The suspects have been through a polygraph test so you can" << endl
		<< "be sure that the information we have on them is true.  Good luck." << endl << endl;
	
	system("pause");

	system("CLS");

	do{					
		choice = 0;

		if(suspectmenu != true || mainmenu == true){
			mainmenu = false;
			
			system("CLS");

			showspy(1);
			cout << endl << endl;
			cout << "Turns left:  " << turnsleft << endl << endl;
			cout << "Choices-------------------" << endl;
			cout << "|1. See information again|" << endl;
			cout << "|2. See suspect Bio      |" << endl;
			cout << "|3. Make a Guess         |" << endl;
			cout << "|4. Quit Game            |" << endl;
			cout << "|5. Advertisement        |" << endl;
			cout << "|6. Credits              |" << endl;
			cout << "--------------------------" << endl;
			cout << endl << "Make a selection: " << endl;

			cin >> choice;
		}

		if(suspectmenu == true){
			choice = 2;
		}

		switch(choice){
		case 1:
			if(turnsleft0(0) == 1){
				break;
			}
			showinfo(0);
			turnsleft--;
			break;
		case 2:
			if(turnsleft0(0) == 1){
				break;
			}
			system("CLS");

			showspy(1);

			cout << endl << endl;

			cout << "Turns left:  " << turnsleft << endl << endl;

			listsuspects();

			cout << endl << "Choose a suspect: (0 to go back)" << endl;
			cin >> suspect; 

			switch(suspect){
			case 0:
				break;
			case 1:
				if(turnsleft0(1) == 1){
					break;
				}
				showinfo(1);
				turnsleft--;
				system("pause");
				break;
			case 2:
				if(turnsleft0(1) == 1){
					break;
				}
				showinfo(2);
				turnsleft--;
				system("pause");
				break;
			case 3:
				if(turnsleft0(1) == 1){
					break;
				}
				showinfo(3);
				turnsleft--;
				system("pause");
				break;
			case 4:
				if(turnsleft0(1) == 1){
					break;
				}
				showinfo(4);
				turnsleft--;
				system("pause");
				break;
			case 5:
				if(turnsleft0(1) == 1){
					break;
				}
				showinfo(5);
				turnsleft--;
				system("pause");
				break;
			default:
				cout << "Incorrect input." << endl << endl;
				system("pause");
				break;
			}
			if(suspect == 0 || turnsleft == 0){
				suspectmenu = false;
			}else{
				suspectmenu = true;
			}
			break;

		case 3:																												
			system("CLS");
			
			showspy(1);
			cout << endl << endl;
			cout << "Turns left: " << turnsleft << endl << endl;
			listsuspects();
			cout << endl << endl << "Make your guess: (Suspect Number, or 0 for back)" << endl;

			cin >> guess;

			if(guess == 0){
				mainmenu = true;
				break;
			}

			if(guess == suspecttrue){
				system("CLS");
				youwin();
				break;
			}else{
				youlose();
				break;
			}

		case 4:
			readmedestroy();
			exit(0);
		case 5:
			system("cls");

			cout<<"Check out Sam's blog at www.nerfmodsbyk.blogspot.com!"<<endl<<endl;

			system("pause");

			break;
		case 6:
			system("CLS");
			cout << "********************************************" << endl;
			cout << "*******************Credits******************" << endl;
			cout << "********************************************" << endl;
			cout << "Developed by:  Spencer Colton               " << endl;
			cout << "Assisted by:   iD Tech Camps C++ Class 2012," << endl;
			cout << "July 16-20                                  " << endl;
			cout << "********************************************" << endl << endl;
			system("pause");
			break;
		default:
			system("CLS");
			cout << "Invalid Input" << endl << endl;
			system("pause");
			break;
		}
	}while(1 == 1);
}

void showinfo(int i){																											// Show information again or show suspect bio
	if ( i == 0 ){

		system("CLS");

		cout << "Intel: "<< endl << "  - Location: Nebraska/Kansas/Oklahoma" << endl <<
		"  - Race:  Unknown, Most likely Caucasian" << endl << "  - Age:  30-50" << endl << endl
		 << "They may or may not have a passport" << endl << endl;

		system("pause");

		return;
	}
	if ( i == 1 ){
		system("CLS");
		cout << "Andrew Davis-----------------------" << endl;
		cout << "|Location: Fort Collins, Colorado |" << endl;
		cout << "|Race: African American           |" << endl;
		cout << "|Age: 55                          |" << endl;
		cout << "|Passport: No                     |" << endl;
		cout << "|Alibi: I don't know any Iraqians.|" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	if ( i == 2 ){
		system("CLS");
		cout << "Vera Green------------------------------" << endl;
		cout << "|Location: Topeka, Kansas              |" << endl;
		cout << "|Race: Caucasian                       |" << endl;
		cout << "|Age: 28                               |" << endl;
		cout << "|Passport: Yes                         |" << endl;
		cout << "|Alibi: I was in Hawaii for two months.|" << endl;
		cout << "----------------------------------------" << endl;
		return;
	}
	if ( i == 3 ){
		system("CLS");
		cout << "Aaron King-----------------------" << endl;
		cout << "|Location: Norman, Oklahoma     |" << endl;
		cout << "|Race: Caucasian                |" << endl;
		cout << "|Age: 36                        |" << endl;
		cout << "|Passport: Yes                  |" << endl;
		cout << "|Alibi: I've never been to Iraq.|" << endl;
		cout << "---------------------------------" << endl;
		return;
	}
	if ( i == 4 ) {
		system("CLS");
		cout << "Dean Williams----------------------------" << endl;
		cout << "|Location: Lincoln, Nebraska            |" << endl;
		cout << "|Race: Asian                            |" << endl;
		cout << "|Age: 40                                |" << endl;
		cout << "|Passport: No                           |" << endl;
		cout << "|Alibi: I didn't know Iraq had missiles.|" << endl;
		cout << "-----------------------------------------" << endl;
		return;
	}
	if ( i == 5 ) {
		system("CLS");
		cout << "Sharon Alvarez--------------------" << endl;
		cout << "|Location: Cheyenne, Wyoming     |" << endl;
		cout << "|Race: Caucasian                 |" << endl;
		cout << "|Age: 49                         |" << endl;
		cout << "|Passport: Yes                   |" << endl;
		cout << "|Alibi: I'm not of Iraqi descent.|" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
}	// Show information on a suspect or show intel again

void listsuspects(){																											// Show list of suspects
	cout << "Suspects-----------------" << endl;
	cout << "|1. Andrew Davis        |" << endl;
	cout << "|2. Vera Green          |" << endl;
	cout << "|3. Aaron King          |" << endl;
	cout << "|4. Dean Williams       |" << endl;
	cout << "|5. Sharon Alvarez      |" << endl;
	cout << "-------------------------" << endl;
	return;
}	// Show the list of suspects

void youwin(){																													// End the game and send score to scores.txt
	ifstream check_stream("scores.txt");
	fstream out_stream;

	cout << "Congratulations." << endl << "You successfully executed the mission and silently disposed of the sleeper cell." << endl << "Not to mention that you did all of this at the age of " << player.age <<"!" << endl << "All of the US is in your debt." << endl;
	
	if(player.gender==1){
		cout << "Your fellow men would be proud." << endl;
	}else if(player.gender==2){
		cout << "Your fellow women would be proud." << endl;
	}
	
	cout << endl;

	if(check_stream.good()){
		check_stream.close();

		out_stream.open("scores.txt", ios::app|ios::out);

		if(out_stream.fail()){
			cout << "Your scores were not written to file." << endl << endl;
		}else{
			cout << "Your scores were written to file.  They can be viewed in scores.txt." << endl << endl;
		}

		if(player.gender == 1){
			if(spynumber < 1000){
				out_stream << player.name << ", 0" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 100){
				out_stream << player.name << ", 00" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 10){
				out_stream << player.name << ", 000" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else{
				out_stream << player.name << ", " << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}
			
		}else if(player.gender == 2){
			if(spynumber < 1000){
				out_stream << player.name << ", 0" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 100){
				out_stream << player.name << ", 00" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 10){
				out_stream << player.name << ", 000" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else{
				out_stream << player.name << ", " << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}
		}
	}else{
		check_stream.close();

		out_stream.open("scores.txt", ios::app|ios::out);

		if(out_stream.fail()){
			cout << "Your scores were not written to file." << endl << endl;
		}else{
			cout << "Your scores were written to file.  They can be viewed in scores.txt." << endl << endl;
		}

		out_stream << "Name, Spy Number, Age, Gender, Turns Taken" << endl << endl;

		if(player.gender == 1){
			if(spynumber < 1000){
				out_stream << player.name << ", 0" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 100){
				out_stream << player.name << ", 00" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 10){
				out_stream << player.name << ", 000" << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}else{
				out_stream << player.name << ", " << spynumber << ", " << player.age << ", " << "Male" << " - " << 5-turnsleft << endl;
			}
			
		}else if(player.gender == 2){
			if(spynumber < 1000){
				out_stream << player.name << ", 0" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 100){
				out_stream << player.name << ", 00" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else if(spynumber < 10){
				out_stream << player.name << ", 000" << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}else{
				out_stream << player.name << ", " << spynumber << ", " << player.age << ", " << "Female" << " - " << 5-turnsleft << endl;
			}
		}
	}		


	out_stream.close();

	readmedestroy();

	system("pause");

	exit(0);
}			// Tell the user they won, and print their score to file

void youlose(){																												// End the game and do not send scores to scores.txt
	system("CLS");

	cout << "You have failed to choose the correct suspect." << endl 
		<< "The missiles were launched and your cover was blown." 
		<< endl << "Maybe this is just not for " << player.age <<" year olds." 
		<< endl << "You now die for your country.";

	if(5-turnsleft == 1){
		cout << endl << endl << "You took " << 5-turnsleft << " turn." ;
	}else if(5-turnsleft > 1 || 5-turnsleft == 0){
		cout << endl << endl << "You took " << 5-turnsleft << " turns."; 
	}

	cout << endl << endl;

	readmedestroy();

	system("pause");

	exit(0);
}			// Tell the player they lost, and end the game
	
int randnum(){																												// Generate spy number
	int random;	
	srand(static_cast<unsigned int>(time(NULL)));
	random = rand() % 9999 + 1;
	return random;
}			// Generate a random number

void showspy(int i){																											// Show spy number
	if(i==0){
		if(spynumber < 10){
			cout << "Your spy number is: 000" << spynumber;
		}else if(spynumber < 100){
			cout << "Your spy number is: 00" << spynumber;
		}else if(spynumber < 1000){
			cout << "Your spy number is: 0" << spynumber;
		}else{
			cout << "Your spy number is: " << spynumber;
		}
	}
	if(i==1){
		if(spynumber < 10){
			cout << "Spy number: 000" << spynumber;
		}else if(spynumber < 100){
			cout << "Spy number: 00" << spynumber;
		}else if(spynumber < 1000){
			cout << "Spy number: 0" << spynumber;
		}else{
			cout << "Spy number: " << spynumber;
		}
	}
	return;
}	// Print the spy number with a certain number of zeros based on value

void showtitle(){
	cout << "-------------------------------------" << endl;													// ASCII Art
	cout << "--------------SUPERSPY---------------" << endl;
	cout << "-------------------------------------" << endl;
	cout << "             ----------              " << endl;
	cout << "            /         /              " << endl;
	cout << "           /         /               " << endl;
	cout << "          /         /                " << endl;
	cout << "       -----------------             " << endl;
	cout << "         |---------%%-|              " << endl;
	cout << "         |            |              " << endl;
	cout << "          |          |               " << endl;
	cout << "          |      ----|               " << endl;
	cout << "          |         |                " << endl;
	cout << "          |        |                 " << endl;
	cout << "          |        |                 " << endl;
	cout << "      ------      ------             " << endl;
	cout << "      |     -----       |            " << endl;
	cout << "      |                 |            " << endl;
}		// Show the title screen

void genreadme(){
	fstream out_readme;

	out_readme.open("ReadMe.txt", ios::app|ios::out);

	out_readme << "------------------------README------------------------" << endl;
	out_readme << "|SuperSpy                                            |" << endl;
	out_readme << "|The object of the game is to determine who is the   |" << endl;
	out_readme << "|sleeper cell in the central united states.          |" << endl;
	out_readme << "|Read all of the suspect bios carefully, as they may |" << endl;
	out_readme << "|be tricky.                                          |" << endl;
	out_readme << "|You only have 5 chances to look at information, but |" << endl;
	out_readme << "|you get a freebee at the beginning of the game when |" << endl;
	out_readme << "|it shows you the intel.  You may look at the intel  |" << endl;
	out_readme << "|again, but it may be unwise, as there are 5 suspects|" << endl;
	out_readme << "|and it takes a turn per suspect bio you view, and a |" << endl;
	out_readme << "|turn per time you view the intel.                   |" << endl;
	out_readme << "|                                                    |" << endl;
	out_readme << "|When you feel that you have enough information,     |" << endl;
	out_readme << "|make a guess.                                       |" << endl;
	out_readme << "|If you guess correctly, your scores are stored in   |" << endl;
	out_readme << "|the scores.txt                                      |" << endl;
	out_readme << "|Good luck.                                          |" << endl;
	out_readme << "------------------------------------------------------" << endl;

	out_readme.close();

	cout << "A ReadMe.txt file has been generated." << endl << "It would be wise to view it before continuing." << endl << endl;

	system("pause");
	system("CLS");

	return;
}		// Generate a readme file

int turnsleft0(int i){
	if(i==0){
		if (turnsleft == 0){
			system("CLS");
			cout << "You must guess now.  You have no turns left." << endl << endl;
			system("pause");
			return 1;
		}else{
			return 0;
		}
	}
	if(i==1){
		if (turnsleft == 0){
			system("CLS");
			cout << "You must guess now.  You have no turns left." << endl << endl;
			suspect = 0;
			system("pause");
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}	 // Check how many turns a player has left

void readmedestroy(){
	remove("ReadMe.txt");
	return;
}	// Destroy the readme in the Release ReadMe verison when the program is closed.