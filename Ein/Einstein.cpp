#include "Einstein.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
# Author : Yang Zhibin
# Id : 181860126
# Last Edit at : 2019 5 22
*/

/*
  ____           _    ____  _                  __  __            ____          _
 / ___| ___   __| |  | __ )| | ___  ___ ___   |  \/  |_   _     / ___|___   __| | ___
| |  _ / _ \ / _` |  |  _ \| |/ _ \/ __/ __|  | |\/| | | | |   | |   / _ \ / _` |/ _ \
| |_| | (_) | (_| |  | |_) | |  __/\__ \__ \  | |  | | |_| |   | |__| (_) | (_| |  __/
 \____|\___/ \__,_|  |____/|_|\___||___/___/  |_|  |_|\__, |   \____\___/ \__,_|\___|
                                                      |___/ 

*/

Einstein::Einstein()
{
	this->clientsocket.connectServer();
	clientsocket.sendMsg(ID);
}

Einstein::~Einstein()
{
	this->clientsocket.close();
}


//the beginnig of the 'parse' function

//posValue, chessMove, chessBoard
vector<int> posValue = {1, 2, 4, 5, 5, 2, 2, 4, 5, 5, 4, 4, 6, 7, 7, 5, 5, 7, 8, 8, 5, 5, 7, 8, 9};
											//set the value of each position to move the chess more effectively
int chessMove;
vector<int> chessBoard;

//the assitant function to transfer the array of char to an int
int charToint(string a) {
	int b[2]; int i = 0;
	for (; a[i] != '\0'; i++)
		b[i] = a[i] - 48;
	if (i == 2)
		return 10 * b[0] + b[1];
	else
		return b[0];
}

//the function to divide the string to some individual words
vector<int> diviStr(string s) {
	//if we are the starter
	//if(s[83] != '\0' && s[84] != '\0'){
L0:	vector<int> result; int tempint;
	string temp;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ' && s[i] != '[' && s[i] != ']' && s[i] != ',' && s[i] != '|')
			temp += s[i];
		else {
			tempint = charToint(temp);
			result.push_back(tempint);
			temp.clear();
		}
	}
	tempint = charToint(temp);
	result.push_back(tempint);
	return result;
	//}
	
	//the other condition
	/*else{
		string temp;
		temp += s[82];
		int chessTomove = charToint(temp);
		temp.clear();
		string order;
		int boolcheck = 0;
		
		for(int i = 84; s[i] != '\0'; i++){
			if(s[i] ==  ':')
				boolcheck = 1;
			else if(boolcheck = 1){
				temp += s[i+1];
			}
		}
		temp = temp.substr(1);
		order = temp;

		int pos = 0; //the position of the chesstomove
		for(; s[pos] != chessTomove; pos++);

		//process the order and edit the string s 
		if(order == "right"){
			s[pos] = 0;
			s[pos + 1] = chessTomove;
		}
		else if(order == "down"){
			s[pos] = 0;
			s[pos+5] = chessTomove;
		}
		else if(order == "rightdown"){
			s[pos] = 0;
			s[pos+6] = chessTomove;
		}

		//reprocess the string s
		s = s.substr(0, 
	}*/
}


//the 0 is not a new game , 1 is a new game
int checkNew(vector<int> a) {
	if (a[0] != 0 && a[1] != 0 && a[2] != 0 && a[5] != 0 && a[6] != 0 && a[10] != 0)
		return 1;
	else
		return 0;
}



//the main function to edit the status of the chessboard
//put the message to the vector of chessBoard 
int Einstein::parse(string s){

	//operator the string
	chessBoard = diviStr(s);

	return 1;
}


//the beginning of the 'handle' function

enum chessColor{blue, red, white};

//the assistant function to find if the chess tomove is still on the board
int findChess(int s){
	for(int j = 0; j < 25; j++){
			if(chessBoard[j] == s)
				return 1;
	}
	return 0;
}

//the assistant function to check if a opposite chess is on the position
//if return 1 means is red, if return 0 means is blue
int setOppo(int n){
	if(n > 0 && n < 7)
		return 1;
	else
		return 0;
}

//return 1 means right/left, 2 means up/down, 3 means rightdown/leftup
//the first check without the surrounding of the target
int checkSafety(int s, chessColor c){
	if(c == red){ //c is red
		chessColor tempc6, tempc1, tempc5;
		if(chessBoard[s+1] != 0){
			if(chessBoard[s+1] > 0 && chessBoard[s+1] < 7)
				tempc1 = red;
			else
				tempc1 = blue;
		}
		else
			tempc1 = white;
		
		if(chessBoard[s+5] != 0){
			if(chessBoard[s+5] > 0 && chessBoard[s+5] < 7)
				tempc5 = red;
			else
				tempc5 = blue;
		}
		else
			tempc5 = white;
		
		if(chessBoard[s+6] != 0){
			if(chessBoard[s+6] > 0 && chessBoard[s+6] < 7)
				tempc6 = red;
			else
				tempc6 = blue;
		}
		else
			tempc6 = white;

		if(tempc6 == blue)
			return 3;
		else{ //tempc6 is red or white
			if(tempc1 == blue)
				return 1;
			else{ // tempc1 is red or white
				if(tempc5 == blue)
					return 2;
				else //tempc6 is red or white and tempc1 is red or white and tempc5 is red or white
					return 3;
			}
		}
		
		}
	
	
	else{ //c is blue
		chessColor tempc6, tempc1, tempc5;
		if(chessBoard[s-1] != 0){
			if(chessBoard[s-1] > 0 && chessBoard[s-1] < 7)
				tempc1 = red;
			else
				tempc1 = blue;
		}
		else
			tempc1 = white;
		
		if(chessBoard[s-5] != 0){
			if(chessBoard[s-5] > 0 && chessBoard[s-5] < 7)
				tempc5 = red;
			else
				tempc5 = blue;
		}
		else
			tempc5 = white;
		
		if(chessBoard[s-6] != 0){
			if(chessBoard[s-6] > 0 && chessBoard[s-6] < 7)
				tempc6 = red;
			else
				tempc6 = blue;
		}
		else
			tempc6 = white;

		if(tempc6 == red)
			return 3;
		else{ //tempc6 is blue or white
			if(tempc1 == red)
				return 1;
			else{ // tempc1 is blue or white
				if(tempc5 == red)
					return 2;
				else //tempc6 is blue or white and tempc1 is blue or white and tempc5 is blue or white
					return 3;
			}
		}
		
	}
	
	
	
}


//the main function to move a chess
int Einstein::handle(){
	//test the function of parse
	//clientsocket.recvMsg();
	//string tempget = clientsocket.getRecvMsg();
	//cout << tempget;
	
	//get the message from sever
	clientsocket.recvMsg();
	string reciveCB = clientsocket.getRecvMsg();
	cout << 1 << reciveCB << endl;
	clientsocket.recvMsg();
	string reciveCB = clientsocket.getRecvMsg();
	cout << 2 << reciveCB << endl;
	parse(reciveCB);
	chessMove = reciveCB[25];

	chessColor toMove;
	//set the color of the chessMove
	if(chessMove > 0 && chessMove < 7){
		toMove = red;
	}
	else if(chessMove > 6 && chessMove <13){
		toMove = blue;
	}

	//set the bound of chessmove
	int bound1 = 0, bound2 = 0;
	if(toMove == red){
		bound1 = 0; bound2 = 7;
	}
	else{
		bound1 = 6; bound2 = 13;
	}
	
	//set the opportunity
	int chess1 = 0, chess2 = 0;
	if(0 == findChess(chessMove)){
		chess1 = chessMove - 1; chess2 = chessMove + 1;
	}

	int flag1 = 0, flag2 = 0; //record how many chess can be control actually

	//if flag was setted as 1, that means the chess can be moved
	while(chess1 > bound1 && chess1 < bound2){
		if (findChess(chess1) == 0){
			chess1--; flag1 = 1;
		}
		else
			break;
	}
	while(chess2 > bound1 && chess2 < bound2){
		if (findChess(chess2) == 0){
			chess2--; flag2 = 1;
		}
		else
			break;
	}

	//begin to make a decision
	
	//the messsage send to server
	string orderSend;

	//the position of the chessMove
	int pos = 0;
	
	//only the chessMove:
	if(flag1 == 0 && flag2 ==0){
		for(; pos < 25; pos++)
			if(chessBoard[pos] == chessMove)
				break;
	}
	int valuePos = posValue[pos]; //set the value of the chessMove

	switch(valuePos){
		case 1:{
			switch(checkSafety(pos, red)){
				case 1: orderSend = to_string(chessMove) + "|right"; break;
				case 2: orderSend = to_string(chessMove) + "|down"; break;
				case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
				default : {
					cout << "Something wrong with checksafety.\n";
					return 0;
				}
			}
		};break;
		case 2:{
			if(toMove == blue){
				switch(pos){
					case 1: orderSend = to_string(chessMove) + "|left"; break;
					case 6: orderSend = to_string(chessMove) + "|leftup"; break;
					case 5: orderSend = to_string(chessMove) + "|up"; break;
				}
			}
			else{ //to move is red
				if(pos == 6)
					orderSend = to_string(chessMove) + "|rightdown";
				else{
				switch(checkSafety(pos, red)){
					case 1: orderSend = to_string(chessMove) + "|right"; break;
					case 2: orderSend = to_string(chessMove) + "|down"; break;
					case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
				}
				}
			}
		};break;
		case 4:{
			
		};break;
		case 5:{};break;
		case 6:{};break;
		case 7:{};break;
		case 8:{};break;
		case 9:{};break;
		default:{
			cout << "There is something wrong with the variable valuePos.\n";
			return 0;
		}
	}
	


	return 1;
}



//the beginning of the logging function

vector<string> ramString;

//the assistant function to get the local system time
string getTime(){
	time_t nowTime;
	nowTime = time(NULL);
	tm* tTm = localtime(&nowTime);
	string temp =  asctime(tTm);
	return "Current time is: " + temp;
} 


int Einstein::logging(string s){
	string temp;
	//get time
	temp += getTime();


	return 0;
}

int Einstein::writelog(){
	
	return 0;
}