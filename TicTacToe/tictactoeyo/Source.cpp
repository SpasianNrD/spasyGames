/*

 Copyright @ 2015 Nathan Diaz
 http://spasiannrd.me
 Please let me know if there are any issues
 v.1.0.23

 Changelog:
 -Program Finished
 -No more "Start Screen" after playing again

 Future:
 -Let user use any symbol
 -GUI
 -No Spaces needed


*/

//###################################//
//## BRUH LETS PLAY TIC-TAC-TOE YO ##//
//###################################//

#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;

void twoPlayers(bool &comp);

bool returnR(string i);

int game(char pla1, char pla2, bool com, string rows[], int &winning);

void start();

bool first = true;

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
	

	if (first == true){
		start();
	}
	else {}

	first = false;

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

	if (player == 'x'){
		player = 'X';
	}
	else if (player == 'o'){
		player = 'O';
	}
	/**
	if (comp == false && player != 'X' && player != 'O'){
		cout << "Player 2 pick your sybmol: ";
		cin >> player2;
	}
	else /**/if (player == 'X'){
		player2 = 'O';
	}
	else if (player == 'O'){
		player2 = 'X';
	}

	

	if (comp == false){
		cout << "Player 2, You get " << player2 << endl;
		Sleep(1000);
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
		cout << ":::::::::    :::      :::       :::  ::::::::  ::::    :::   ::: " << endl;
		cout << ":+:    :+: :+:+:      :+:       :+: :+:    :+: :+:+:   :+:   :+: " << endl;
		cout << "+:+    +:+   +:+      +:+       +:+ +:+    +:+ :+:+:+  +:+   +:+ " << endl;
		cout << "+#++:++#+    +#+      +#+  +:+  +#+ +#+    +:+ +#+ +:+ +#+   +#+ " << endl;
		cout << "+#+          +#+      +#+ +#+#+ +#+ +#+    +#+ +#+  +#+#+#   +#+ " << endl;
		cout << "#+#          #+#       #+#+# #+#+#  #+#    #+# #+#   #+#+#       " << endl;
		cout << "###        #######      ###   ###    ########  ###    ####   ### " << endl;
	}
	else if (whoWon == 2){
		if (comp == true){
			cout << " ::::::::  :::::::::     :::       :::  ::::::::  ::::    :::  ::: " << endl;
			cout << ":+:    :+: :+:    :+:    :+:       :+: :+:    :+: :+:+:   :+:  :+: " << endl;
			cout << "+:+        +:+    +:+    +:+       +:+ +:+    +:+ :+:+:+  +:+  +:+ " << endl;
			cout << "+#+        +#++:++#+     +#+  +:+  +#+ +#+    +:+ +#+ +:+ +#+  +#+ " << endl;
			cout << "+#+        +#+           +#+ +#+#+ +#+ +#+    +#+ +#+  +#+#+#  +#+ " << endl;
			cout << "#+#    #+# #+#            #+#+# #+#+#  #+#    #+# #+#   #+#+#      " << endl;
			cout << " ########  ###             ###   ###    ########  ###    ####  ### " << endl;
		}
		else if (comp == false){
			cout << ":::::::::   ::::::::       :::       :::  ::::::::  ::::    :::   ::: " << endl;
			cout << ":+:    :+: :+:    :+:      :+:       :+: :+:    :+: :+:+:   :+:   :+: " << endl;
			cout << "+:+    +:+       +:+       +:+       +:+ +:+    +:+ :+:+:+  +:+   +:+ " << endl;
			cout << "+#++:++#+      +#+         +#+  +:+  +#+ +#+    +:+ +#+ +:+ +#+   +#+ " << endl;
			cout << "+#+          +#+           +#+ +#+#+ +#+ +#+    +#+ +#+  +#+#+#   +#+ " << endl;
			cout << "#+#         #+#             #+#+# #+#+#  #+#    #+# #+#   #+#+#       " << endl;
			cout << "###        ##########        ###   ###    ########  ###    ####   ### " << endl;
		}
	}
	else if (whoWon == 3){
		cout << " ::::::::      ::: ::::::::::: ::::::::       ::: " << endl;
		cout << ":+:    :+:   :+: :+:   :+:    :+:    :+:      :+: " << endl;
		cout << "+:+         +:+   +:+  +:+    +:+             +:+ " << endl;
		cout << "+#+        +#++:++#++: +#+    +#++:++#++      +#+ " << endl;
		cout << "+#+        +#+     +#+ +#+           +#+      +#+ " << endl;
		cout << "#+#    #+# #+#     #+# #+#    #+#    #+#          " << endl;
		cout << " ########  ###     ### ###     ########       ### " << endl;
	}

	cout << "\n" << endl;

	string input;
	cout << "Thank you for playing!" << endl;
	cout << "Do you want to go at it agian? ";
	cin >> input;
	if (input == "Yes" || input == "yes" || input == "YES" || input == "y" || input == "Y" || input == "YEs" || input == "yeS" || input == "yES"){
		system("CLS");
		main();
	}
	else if (input == "No" || input == "no" || input == "NO" || input == "n" || input == "N" || input == "nO"){
		system("CLS");
		cout << "\nOk, cool FINE BE LIKE THAT, BYE! \n\n" << endl;
		string copy1 = "Sorry my program still has glitches, ill make sure it's is better behaved soon.";
		string copy2 = "Anyways, thanks. Names Nathan, if your interested in more of this, let me know.";
		string copy3 = "To add to this, let me know if you find anything wrong.";
		string copy4 = "Visit me at http://spasiannrd.me or contact me directly using me@spasiannrd.me.";
		for (int i = 0; i < copy1.length(); i++){
			cout << copy1.at(i);
			Sleep(50);
		}
		cout << endl;
		for (int i = 0; i < copy2.length(); i++){
			cout << copy2.at(i);
			Sleep(50);
		}
		cout << endl;
		for (int i = 0; i < copy3.length(); i++){
			cout << copy3.at(i);
			Sleep(50);
		}
		cout << endl;
		for (int i = 0; i < copy4.length(); i++){
			cout << copy4.at(i);
			Sleep(50);
		}
		cout << "\n" << endl;
		system("pause");
		return 0;
	}

	return 0;
}

void twoPlayers(bool &comp){
	string input;
	cout << "Are you playing with someone? ";
	cin >> input;
	comp = returnR(input);

}

void start(){
	
	string starting= "Loading...";
	for(int i = 0; i < starting.length(); i++){
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

bool returnR(string i){
	if (i == "Yes" || i == "yes" || i == "YES" || i == "y" || i == "Y" || i == "YEs" || i == "yeS" || i == "yES" ){
		return false;
	}
	else if (i == "No" || i == "no" || i == "NO" || i == "n" || i == "N" || i == "nO"){
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
		else if (two == 'X' ){
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
		} else if (j == 1){
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

