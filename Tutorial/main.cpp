#include <iostream>
#include <cstdlib>
#include <time.h>
#include <csignal>
#include <ctype.h>
#include <string.h>
using namespace std;

void guessTheNumber() {

	srand (time(NULL));
	int diceNumber = rand() % 100 + 1;

	int userInput;
	int attempt = 0;
	while(true) {

		attempt++;
		cout << "Attempt: " << attempt << endl;
		cin >> userInput;

		if(userInput > diceNumber) {
			cout << "zu groß" << endl;
		}
		else if(userInput < diceNumber) {
			cout << "zu klein" << endl;
		}
		else {
			cout << "korrekt du spongo" << endl;
			break;
		}
	}
}

void threeDices() {

	const int MAX_ATTEMPTS = 10;
	const int DICE_COUNT = 10;

	srand (time(NULL));

	int attempts = MAX_ATTEMPTS;
	int sum;
	while(true) {

		attempts--;
		sum = 0;
		for(int index = 0; index < DICE_COUNT; index++) {

			int newDiceNumber = rand() % 100 + 1;
			cout << "Dice" << index << ": " << newDiceNumber << endl;
			sum += newDiceNumber;
		}
		cout << "Sum: " << sum << endl;

		if(attempts == 0) {

			cout << "No attempts left" << endl;
			cout << "sum " << sum << endl;
			break;
		}
		else {
			cout << "Left attempts: " << attempts << endl;
		}

		char userInput;
		cin >> userInput;
		if(userInput == 'x') {
			cout << "you took sum " << sum << endl;
			cout << "you used " << (MAX_ATTEMPTS - attempts) << " attempts";
			break;
		}
	}
}

void fiveOfAKind() {

	const int DICE_COUNT = 5;
	const int MAX_ATTEMPTS = 10;
	int dices[DICE_COUNT];
	bool locked[DICE_COUNT];
	memset(&locked, 0, DICE_COUNT * sizeof(bool));

	srand (time(NULL));

	for(int attempt = MAX_ATTEMPTS; attempt > 0; attempt--) {

		cout << "Attempt: " << (MAX_ATTEMPTS-attempt+1) << endl;
		for(int dice = 0; dice < DICE_COUNT; dice++) {

			if( !locked[dice]) {
				dices[dice] = rand() % 6 + 1;
			}
		}

		//print all dices
		for(int i = 0; i < DICE_COUNT; i++) {
			cout << dices[i];
			if(locked[i]) {
				cout << "(x)";
			}
			cout << "|";
		}
		cout << endl;

		//check if user won
		int diceNumberToBeEqual = dices[0];
		bool allOfAKind = true;
		for(int i = 1; i < DICE_COUNT; i++) {
			if(diceNumberToBeEqual != dices[i]) {
				allOfAKind = false;
			}
		}
		if(allOfAKind) {
			cout << "YOU WON!!!1!11!eleven!!" << endl;
			break;
		}
		else if(attempt == 1) {
			cout << "YOU LOOSE!!!1!11!eleven!!" << endl;
			break;
		}

		while(true) {
			cout << "Do you want to lock a dice? Press A, B, C, D, or E. Any other key to continue" << endl;
			char input;
			cin >> input;
			input = tolower(input);
			//locked[input - 'a'] = true;

			switch(input) {
				case 'a':
					locked[0] = true;
					break;
				case 'b':
					locked[1] = true;
					break;
				case 'c':
					locked[2] = true;
					break;
				case 'd':
					locked[3] = true;
					break;
				case 'e':
					locked[4] = true;
					break;
				default:
					//stop asking for locking and start new round
					goto endOfLoop;//aaahh i hate myself
			}
		}
		endOfLoop:
		cout << endl;
	}
}

void signalHandler(int signum) {

   exit(signum);
}

int main () {

	signal(SIGINT, signalHandler);

	//guessTheNumber();
	//threeDices();
	fiveOfAKind();

	return 0;
}
