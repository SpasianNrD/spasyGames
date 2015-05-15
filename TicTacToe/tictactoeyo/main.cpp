//###################################//
//## BRUH LETS PLAY TIC-TAC-TOE YO ##//
//###################################//

#include <iostream>
#include <string>
#include <math.h>
#include <cctype>
#include <time.h>
#include <windows.h>

using namespace std;

void twoPlayers(bool &comp);

bool returnR(string i);

int game(char pla1, char pla2, bool com, string rows[], int &winning);

int main(){
	string row[5] = {};
	row[0] = "   |   |   ";
	row[1] = "---+---+---";
	row[2] = "   |   |   ";
	row[3] = "---+---+---";
	row[4] = "   |   |   ";
	char player;
	char player2;
	int whoWon;
	bool comp;

	twoPlayers(comp);
	if (comp == true){ //If true, 1P + Comp
		//cout << "yes" << endl;
	}
	else if (comp == false){ //If false, 2P
		//cout << "no" << endl;
	}

	cout << "  Lets play some tick-tac-toe!  " << endl;
	cout << "--------------------------------" << endl;
	cout << "     Columns" << endl;
	for (int i = 0; i < 5; i++){
		if (i == 0)
			cout << "Rows ";
		else
			cout << "     ";
		cout << row[i] << endl;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
	cout << "Player 1, Do you want X or O ? ";
	cin >> player;
	if (player == 'X'){
		player2 = 'O';
	}
	else if (player == 'O'){
		player2 = 'X';
	}

	if (comp == false){
		cout << "Player 2, You get " << player2 << endl;
	}
	else if (comp == true){
		cout << "You are going to play with the computer, good luck";
		for (int i = 0; i < 4; i++){
			Sleep(300);
			cout << ".";
		}
		cout << endl;
	}

	whoWon = game(player, player2, comp, row, whoWon);

	if (whoWon == 1){
		cout << "Player One Won!" << endl;
	}
	else if (whoWon == 2){
		if (comp == true){
			cout << "Computer has won.....you suck." << endl;
		}
		else if (comp == false){
			cout << "Player Two has won....noice." << endl;
		}
	}

	system("pause");
	return 0;
}

void twoPlayers(bool &comp){
	string input;
	cout << "Are you playing with someone? ";
	cin >> input;
	comp = returnR(input);

}

bool returnR(string i){
	if (i == "Yes" || i == "yes"){
		return false;
	}
	else if (i == "No" || i == "no"){
		return true;
	}
}

void des(int row, int colm, int &t, int &x) {
	t = 0;
	x = 0;

	if (row == 1){
		t = 0;
	}
	else if (row == 2){
		t = 2;
	}
	else if (row == 3){
		t = 4;
	}

	if (colm == 1){
		x = 1;
	}
	else if (colm == 2){
		x = 5;
	}
	else if (colm == 3){
		x = 9;
	}
}

//TODO: Make board checker
void checker(char one, char two, string row[], bool &oneW, bool &twoW){
	cout << "The checker isn't Complete." << endl;
}

int game(char pla1, char pla2, bool com, string rows[], int &winning){
	bool onGoing = true;
	bool oneWon = false;
	bool twoWon = false;
	rows[0] = "   |   |   ";
	rows[1] = "---+---+---";
	rows[2] = "   |   |   ";
	rows[3] = "---+---+---";
	rows[4] = "   |   |   ";

	srand(time(0));
	while (onGoing == true){
		system("CLS");
		int row;
		int colm;
		int trow;
		int tcolm;
		cout << "  The board  " << endl;
		cout << "-------------" << endl;
		for (int i = 0; i < 5; i++){
			cout << rows[i] << endl;
		}
		cout << endl;
		cout << "-------------" << endl;
		cout << "Player 1, where do you want to go?(ex: 1 1) ";  //TODO: Perfecing Position Check
		cin >> row >> colm;
		des(row, colm, trow, tcolm);
		cout << trow << " " << tcolm << " " << pla1 << endl;
		//rows[trow].at(tcolm) = pla1;
		/**/
		int i = 0;
		while (i == 0){
			if (rows[trow].at(tcolm) != ' '){
				cout << "Somone already went there, try again: ";
				cin >> row >> colm;
				des(row, colm, trow, tcolm);
			}
			else if (rows[trow].at(tcolm) == ' '){
				rows[trow].at(tcolm) = pla1;
				i++;
			}
		}
		/**/
		cout << "\n" << endl;

		cout << com << endl;

		tcolm = 0;
		trow = 0;
		if (com == true){
			cout << "1" << endl;
			trow = rand() % 3 + 1;
			tcolm = rand() % 3 + 1;
			rows[trow].at(tcolm) = pla2;
		}
		else if (com == false){
			cout << "Player 2, where do you want to go?(ex: 1 1) ";
			cin >> row >> colm;
			des(row, colm, trow, tcolm);
			//rows[trow].at(tcolm) = pla2;
			/**/
			int i = 0;
			while (i == 0){
				if (rows[trow].at(tcolm) != ' '){
				cout << "Somone already went there, try again: ";
				cin >> row >> colm;
				des(row, colm, trow, tcolm);
			}
			else if (rows[trow].at(tcolm) == ' '){
				rows[trow].at(tcolm) = pla2;
				i++;
			}
			}
			/**/
		}

		checker(pla1,pla2, rows, oneWon, twoWon);

		if (oneWon == true){
			onGoing = false;
			return 1;
		}
		else if (twoWon == true){
			onGoing = false;
			return 2;
		}
		//system("pause");
	}
}