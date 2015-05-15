/*

 Copyright @ 2015 Nathan Diaz
 http://spasiannrd.me
 Please let me know if there are any issues
 v.1.0.25

 Changelog:
 -No more "Start Screen" after playing again
 -Cleaner in a sense

 In the future:
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
#include "tictac.h"

using namespace std;

void twoPlayers(bool &comp);

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










