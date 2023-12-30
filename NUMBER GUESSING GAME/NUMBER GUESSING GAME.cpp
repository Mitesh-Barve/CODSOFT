//Create a program that generates a random number and asks the
//user to guess it.Provide feedback on whether the guess is too
//high or too low until the user guesses the correct number
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {

	srand(time(NULL));
	int secretnum = rand() % 100 + 1;
	int usernum;
	int attempt = 0;
	cout << "********Guessing game*******" << endl;
	do {
		cout << "Enter Your guess (1-100)=";
		cin >> usernum;
		attempt++;
		if (usernum == secretnum) {
			cout << "You guessed the correct number " << attempt << "attempts." << endl;
		}
		else if (usernum < secretnum) {
			cout << "Too Low! Try again." << endl;
		}
		else { 
			cout << "Too High! Try again." << endl;

			 }

	} while (usernum != secretnum);

	return -1;
}
