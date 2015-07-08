#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

string playerCountPrompt () {
	string playerCount;
	
	do {
		cout << "Would you like to play with 1 or 2 players? ";
		cin >> playerCount;
		cout << "\n";
	} while (!(playerCount == "1" || playerCount == "2"));
	
	return playerCount;
}

int getPlayerMove(int playerNumber) {
	string move;
	int moveNumber;
	
	cout << "Player " << playerNumber << ", what is your move? ";
	cin >> move;
	cout << "\n";
	
	while(!(move == "rock" || move == "Rock" || move == "paper" || move == "Paper" || move == "scissors" || move == "Scissors")){
		cout << "Sorry, that is not a legal move." << endl;
		cout << "Player " << playerNumber << ", what is your move? ";
		cin >> move;
		cout << "\n";
	}
	
	if (move == "rock" || move == "Rock") {
		moveNumber = 0;
	} else if (move == "paper" || move == "Paper") {
		moveNumber = 1;
	} else if (move == "scissors" || move == "Scissors") {
		moveNumber = 2;
	};

	return moveNumber;
}

int getCompMove () {
	int moveNumber;
	
	srand(time(0));
	int choice = rand() % 4;
	
	if (choice <= 1) {
		moveNumber = 0;
	} else if (choice > 1 && choice <= 2) {
		moveNumber = 1;
	} else if (choice > 2 && choice <= 3) {
		moveNumber = 2;
	};

	return moveNumber;
}

void determineWinner (int player1Move, int player2Move, int *player1Score, int *player2Score) {
	if (player1Move == player2Move) {
		cout << "This round is a tie!\n" << endl;
	} else if (player1Move == 0 && player2Move == 1) {
		*player2Score += 1;
		cout << "Player 2 wins this round!\n" << endl;
	} else if (player1Move == 0 && player2Move == 2) {
		*player1Score += 1;
		cout << "Player 1 wins this round!\n" << endl;
	} else if (player1Move == 1 && player2Move == 0) {
		*player1Score += 1;
		cout << "Player 1 wins this round!\n" << endl;
	} else if (player1Move == 1 && player2Move == 2) {
		*player2Score += 1;
		cout << "Player 2 wins this round!\n" << endl;
	} else if (player1Move == 2 && player2Move == 0) {
		*player2Score += 1;
		cout << "Player 2 wins this round!\n" << endl;
	} else if (player1Move == 2 && player2Move == 1) {
		*player1Score += 1;
		cout << "Player 1 wins this round!\n" << endl;
	}
}

void playOnePlayer () {
	int playerScore = 0;
	int compScore = 0;
	
	for (int round = 0; round <= 2; round++) {
		cout << "-- Round " << round + 1 << " --" << endl;
		cout << "-------------\n" << endl;
		
		int playerMove = getPlayerMove(1);
		int compMove = getCompMove(); 
		
		if (compMove == 0) {
			cout << "Player 2 chooses rock!\n" << endl;
		} else if (compMove == 1) {
			cout << "Player 2 chooses paper!\n" << endl;
		} else if (compMove == 2) {
			cout << "Player 2 chooses scissors!\n" << endl;
		}
		
		determineWinner(playerMove, compMove, &playerScore, &compScore);
	}
	
	cout << "Player 1 has " << playerScore << " point(s)" << endl;
	cout << "Player 2 has " << compScore << " point(s)\n" << endl;
	
	if (playerScore > compScore) {
		cout << "Player 1 wins this game!\n" << endl;
	} else if (compScore > playerScore) {
		cout << "Computer wins this game!\n" << endl;
	} else if (playerScore == compScore) {
		cout << "This game is a tie!\n" << endl;
	}
}

void playTwoPlayer () {
	int playerOneScore = 0;
	int playerTwoScore = 0;
	
	for (int round = 0; round <= 2; round++) {
		cout << "-- Round " << round + 1 << " --" << endl;
		cout << "-------------\n" << endl;
		
		int playerOneMove = getPlayerMove(1);
		int playerTwoMove = getPlayerMove(2); 
		
		determineWinner(playerOneMove, playerTwoMove, &playerOneScore, &playerTwoScore);
	}
	
	cout << "Player 1 has " << playerOneScore << " point(s)" << endl;
	cout << "Player 2 has " << playerTwoScore << " point(s)\n" << endl;
	
	if (playerOneScore > playerTwoScore) {
		cout << "Player 1 wins this game!\n" << endl;
	} else if (playerTwoScore > playerOneScore) {
		cout << "Player 2 wins this game!\n" << endl;
	} else if (playerOneScore == playerTwoScore) {
		cout << "This game is a tie!\n" << endl;
	}
}

int main () {
	string playAgain;

	cout << "Welcome to ROCK PAPER SCISSORS!!!\n" << endl;
	
	while (true) {
	
		string playerCount = playerCountPrompt();
			
		if (playerCount == "1") {
			playOnePlayer();
		} else if (playerCount == "2") {
			playTwoPlayer();
		}
		
		while (true) {
			cout << "Would you like to play again? ";
			cin >> playAgain;
			cout << "\n";
		
			if (playAgain == "yes" || playAgain == "y" || playAgain == "Yes" || playAgain == "Y") {
				break;
			} else if (playAgain == "no" || playAgain == "n" || playAgain == "No" || playAgain == "N") {
				cout << "Thanks for playing!" << endl;
				return 0;
			} else {
				cout << "Sorry, that is not an option." << endl;
				continue;
			}
		}
	}
}


