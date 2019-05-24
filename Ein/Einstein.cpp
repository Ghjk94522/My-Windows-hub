#define _CRT_SECURE_NO_WARNINGS
#include "Einstein.h"

#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
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

//the function to set the color of a chess
chessColor setColor(int s){
	if(s > 0 && s < 7)
		return red;
	else if(s == 0)
		return white;
	else
		return blue;
}


//return 1 means right/left, 2 means up/down, 3 means rightdown/leftup
//the first check without the surrounding of the target
int checkSafety(int s, chessColor c){
	if(c == red){ //c is red
		chessColor tempc6 = setColor(chessBoard[s+6]), tempc1 = setColor(chessBoard[s+1]), tempc5 = setColor(chessBoard[s+5]);

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
		chessColor tempc6 = setColor(chessBoard[s-6]), tempc1 = setColor(chessBoard[s-1]), tempc5 = setColor(chessBoard[s-5]);
		
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
	
	static int count = 1;
	//get the message from sever
	clientsocket.recvMsg();
	string reciveCB = clientsocket.getRecvMsg();
	if(reciveCB == "RESULT : BLUEWIN" || reciveCB == "RESULT : REDWIN"){
		logging(reciveCB);
		return 0;
	}
	cout << count << reciveCB << endl;
	parse(reciveCB);
	chessMove = reciveCB[25];

	//set the color of the chessMove
	chessColor toMove = setColor(chessMove);
	

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

	//set the orderSend
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
			if(toMove == red) //to move is red
				switch(checkSafety(pos, red)){
						case 1: orderSend = to_string(chessMove) + "|right"; break;
						case 2: orderSend = to_string(chessMove) + "|down"; break;
						case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
						default: {
							cout << "Something wrong with checkSafety.\n";
							return 0;
						}
					}
			
			
			else{ // tomove is blue
				switch(pos){
					case 2: orderSend = to_string(chessMove) + "|left"; break;
					case 7: orderSend = to_string(chessMove) + "|leftup"; break;
					case 11: {
						if(setColor(chessboard[5] != blue))
							orderSend = to_string(chessMove) + "|leftup";
						else if(setColor(chessboard[6] == blue))
							orderSend = to_string(chessMove) + "|leftup";
						else
							orderSend = to_string(chessMove) + "|up";
					}; break;
					case 10: orderSend = to_string(chessMove) + "|up"; break;
					default :{
						cout << "Something wrong with pos.\n";
						return 0;
					}
				}
			}
		};break;
		case 5:{
			if(toMove == red)
				switch(pos){
					case 4: orderSend = to_string(chessMove) + "|down"; break;
					case 9: orderSend = to_string(chessMove) + "|down"; break;
					case 15: orderSend = to_string(chessMove) + "|right"; break;
					case 20: orderSend = to_string(chessMove) + "|right"; break;
					case 21: orderSend = to_string(chessMove) + "|right"; break;
					case 16:
					case 3:
					case 8:{
						switch(checkSafety(pos, red)){
							case 1: orderSend = to_string(chessMove) + "|right"; break;
							case 2: orderSend = to_string(chessMove) + "|down"; break;
							case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
					}; break;
					default :{
						cout << "Something wrong with pos.\n";
						return 0;
					}
				}
			else{ // tomove is blue
				switch(pos){
					case 4: orderSend = to_string(chessMove) + "|left"; break;
					case 3: orderSend = to_string(chessMove) + "|left"; break;
					case 15: orderSend = to_string(chessMove) + "|up"; break;
					case 20: orderSend = to_string(chessMove) + "|up"; break;
					case 21:
					case 9: 
					case 16:
					case 8:{
						switch(checkSafety(pos, blue)){
							case 1: orderSend = to_string(chessMove) + "|left"; break;
							case 2: orderSend = to_string(chessMove) + "|up"; break;
							case 3: orderSend = to_string(chessMove) + "|leftup"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
					}; break;
					default :{
						cout << "Something wrong with pos.\n";
						return 0;
					}
				}
			}
		};break;
		case 6:{
			if(toMove == red)
				switch(checkSafety(pos, red)){
							case 1: orderSend = to_string(chessMove) + "|right"; break;
							case 2: orderSend = to_string(chessMove) + "|down"; break;
							case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
			else
				switch(checkSafety(pos, blue)){
							case 1: orderSend = to_string(chessMove) + "|left"; break;
							case 2: orderSend = to_string(chessMove) + "|up"; break;
							case 3: orderSend = to_string(chessMove) + "|leftup"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
		};break;
		case 7:{
			if(toMove == red)
				switch(pos){
					case 14: orderSend = to_string(chessMove) + "|down"; break;
					case 27: orderSend = to_string(chessMove) + "|right"; break;
					case 13:
					case 17: switch(checkSafety(pos, red)){
							case 1: orderSend = to_string(chessMove) + "|right"; break;
							case 2: orderSend = to_string(chessMove) + "|down"; break;
							case 3: orderSend = to_string(chessMove) + "|rightdown"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}; break;
					default :{
						cout << "Something wrong with the pos.\n";
						return 0;
					}
				}
			else // tomove is blue
				switch(checkSafety(pos, blue)){
							case 1: orderSend = to_string(chessMove) + "|left"; break;
							case 2: orderSend = to_string(chessMove) + "|up"; break;
							case 3: orderSend = to_string(chessMove) + "|leftup"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
		};break;
		case 8:{
			if(toMove == red)
				switch(pos){
					case 19: orderSend = to_string(chessMove) + "|down"; break;
					case 18: orderSend = to_string(chessMove) + "|rightdown"; break;
					case 23: orderSend = to_string(chessMove) + "|right"; break;
					default :{
						cout << "Something wrong with pos.\n";
						return 0;
					}
				}
			else //tomove is blue
				switch(checkSafety(pos, blue)){
							case 1: orderSend = to_string(chessMove) + "|left"; break;
							case 2: orderSend = to_string(chessMove) + "|up"; break;
							case 3: orderSend = to_string(chessMove) + "|leftup"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
		};break;
		case 9:{
			switch(checkSafety(pos, blue)){
							case 1: orderSend = to_string(chessMove) + "|left"; break;
							case 2: orderSend = to_string(chessMove) + "|up"; break;
							case 3: orderSend = to_string(chessMove) + "|leftup"; break;
							default :{
								cout << "Something wrong with checkSafety.\n";
								return 0;
							}
						}
		};break;
		default:{
			cout << "There is something wrong with the variable valuePos.\n";
			return 0;
		}
	}

	cout << count++ << orderSend << endl;
	//send the order to the sever
	clientsocket.sendMsg(orderSend.data());

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


//the function to put the string of log into the ram vector
int Einstein::logging(string s){
	string temp;
	//get time
	temp += getTime();
	temp = temp + "\t" + s;
	
	//put the temp into the vector
	ramString.push_back(temp);
	return 0;
}


//put the ram vector into the logfile
int Einstein::writelog(){
	ofstream out;
	out.open("TestServer.log", ios::out);
	for(vector<string>:: iterator t = ramString.begin(); t != ramString.end(); t++)
		out << *t << "\n";

	out.close();
	return 0;
}