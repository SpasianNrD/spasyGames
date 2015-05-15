#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "tictac.h"

using namespace std;



bool returnR(string i){
	if (i == "Yes" || i == "yes" || i == "YES" || i == "y" || i == "Y" || i == "YEs" || i == "yeS" || i == "yES"){
		return false;
	}
	else if (i == "No" || i == "no" || i == "NO" || i == "n" || i == "N" || i == "nO"){
		return true;
	}
}

void twoPlayers(bool &comp){
	string input;
	cout << "Are you playing with someone? ";
	cin >> input;
	comp = returnR(input);

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
	//cout << "The checker isn't Complete." << endl;
	if (row[0] == " X | X | X "){
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[2] == " X | X | X "){
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[4] == " X | X | X "){
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0] == " O | O | O "){
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[2] == " O | O | O "){
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[4] == " O | O | O "){
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(1) == 'X' && row[2].at(1) == 'X' && row[4].at(1) == 'X'){ // Column 1 X
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0].at(5) == 'X' && row[2].at(5) == 'X' && row[4].at(5) == 'X'){ // Column 2 X
		if (one == 'X' || one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0].at(9) == 'X' && row[2].at(9) == 'X' && row[4].at(9) == 'X'){ // Column 3 X
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0].at(1) == 'O' && row[2].at(1) == 'O' && row[4].at(1) == 'O'){ // Column 1 O
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(5) == 'O' && row[2].at(5) == 'O' && row[4].at(5) == 'O'){ // Column 2 O
		if (one == 'O' || one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(9) == 'O' && row[2].at(9) == 'O' && row[4].at(9) == 'O'){ // Column 3 O
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(1) == 'O' && row[2].at(5) == 'O' && row[4].at(9) == 'O'){ // Diag from left O
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(9) == 'O' && row[2].at(5) == 'O' && row[4].at(1) == 'O'){ // Diag from right O
		if (one == 'O'){
			oneW = true;
		}
		else if (two == 'O'){
			twoW = true;
		}
	}
	else if (row[0].at(1) == 'X' && row[2].at(5) == 'X' && row[4].at(9) == 'X'){ // Diag from left X
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0].at(9) == 'X' && row[2].at(5) == 'X' && row[4].at(1) == 'X'){ // Diag from left X
		if (one == 'X'){
			oneW = true;
		}
		else if (two == 'X'){
			twoW = true;
		}
	}
	else if (row[0].at(1) != ' ' && row[0].at(5) != ' ' && row[0].at(9) != ' ' && row[2].at(1) != ' ' && row[2].at(5) != ' ' && row[2].at(9) != ' ' && row[4].at(1) != ' ' && row[4].at(5) != ' ' && row[4].at(9) != ' '){
		oneW = true;
		twoW = true;
	}
}

int game(char pla1, char pla2, bool com, string rows[], int &winning){
	bool onGoing = true;
	bool oneWon = false;
	bool twoWon = false;
	int j = 0;
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

		checker(pla1, pla2, rows, oneWon, twoWon);

		if (oneWon == true && twoWon == true){
			onGoing = false;
			for (int i = 0; i < 5; i++){
				cout << "\t";
				cout << rows[i] << endl;
			} cout << endl;
			return 3;
		}
		else if (oneWon == true){
			onGoing = false;
			for (int i = 0; i < 5; i++){
				cout << "\t";
				cout << rows[i] << endl;
			}cout << endl;
			return 1;
		}
		else if (twoWon == true){
			onGoing = false;
			for (int i = 0; i < 5; i++){
				cout << "\t";
				cout << rows[i] << endl;
			}cout << endl;
			return 2;
		}

		cout << "  The board" << endl;
		cout << "-------------" << endl;
		for (int i = 0; i < 5; i++){
			cout << rows[i] << endl;
		}
		cout << endl;
		cout << "-------------" << endl;
		cout << "Instructions: \n   ~ The first number is the row, second number is the column \n   ~ The range is between 1 and 3 for rows and coloumns \n   ~ Make sure there is a space between each number\n" << endl;

		if (j == 0){
			cout << "Player 1, where do you want to go? (ex: 1 1) ";
			cin >> row >> colm;
			/*

			while (input.size() != 2){
			cin >> input;
			row = (int)input.at(0) + 49;
			colm = (int)input.at(1) + 49;
			}

			*/

			des(row, colm, trow, tcolm);
			//cout << trow << " " << tcolm << " " << pla1 << endl;
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
			j++;
			/**/
		}
		else if (j == 1){
			if (com == true){
				int i = 0;

				row = rand() % 3 + 1;
				colm = rand() % 3 + 1;
				des(row, colm, trow, tcolm);
				while (i == 0){

					if (rows[trow].at(tcolm) != ' '){
						row = rand() % 3 + 1;
						colm = rand() % 3 + 1;
						des(row, colm, trow, tcolm);
					}
					else if (rows[trow].at(tcolm) == ' '){
						rows[trow].at(tcolm) = pla2;
						i++;
					}
				}
				j--;
			}
			else if (com == false){
				cout << "Player 2, where do you want to go? (ex: 1 1) ";
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
				j--;
				/**/
			}
		}




		//system("pause");
	}
}

void start(){

	string starting = "Loading...";
	for (int i = 0; i < starting.length(); i++){
		cout << starting.at(i);
		Sleep(100);
	}

	system("CLS");

	Sleep(1000);
	cout << endl;



	cout << "::::::::::: ::::::::::: :::::::: " << endl;
	cout << "    :+:         :+:    :+:    :+: " << endl;
	cout << "    +:+         +:+    +:+        " << endl;
	cout << "    +#+         +#+    +#+        " << endl;
	cout << "    +#+         +#+    +#+        " << endl;
	cout << "    #+#         #+#    #+#    #+# " << endl;
	cout << "    ###     ########### ########  " << endl;

	Sleep(1000);

	cout << "::::::::::: :::      :::::::: " << endl;
	cout << "    :+:   :+: :+:   :+:    :+: " << endl;
	cout << "    +:+  +:+   +:+  +:+        " << endl;
	cout << "    +#+ +#++:++#++: +#+        " << endl;
	cout << "    +#+ +#+     +#+ +#+        " << endl;
	cout << "    #+# #+#     #+# #+#    #+# " << endl;
	cout << "    ### ###     ###  ########  " << endl;

	Sleep(1000);

	cout << "::::::::::: ::::::::  ::::::::::" << endl;
	cout << "    :+:    :+:    :+: :+:        " << endl;
	cout << "    +:+    +:+    +:+ +:+        " << endl;
	cout << "    +#+    +#+    +:+ +#++:++#   " << endl;
	cout << "    +#+    +#+    +#+ +#+        " << endl;
	cout << "    #+#    #+#    #+# #+#        " << endl;
	cout << "    ###     ########  ########## " << endl;
	Sleep(2000);
	system("CLS");
}