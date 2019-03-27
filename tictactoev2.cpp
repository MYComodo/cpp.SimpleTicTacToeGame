//TICTACTOE GAME
#include <iostream>
#include <vector>//used for vectors
#include <utility>
#include <limits>

//Shows Main Game Table
void TableShow(std::vector<std::vector<char>> gameTable){
	std::cout << "\n Last Status \n";
	//system("color 1");
	std::cout << "  1 2 3 " << std::endl;
	for(int row = 0; row < 3; row++){
		
		std::cout << " -------" << std::endl;
		std::cout << row+1<<"|";
		for(int col = 0; col < 3; col++){
		
				std::cout << gameTable[row][col] << "|";
		
		
		}
		std::cout << std::endl;	
	}
	std::cout << "-------" << std::endl;
}

//Shows the main menu and returns selected branch
int MainMenu(){
	int mainSelect = 0;
	std::cout   <<"\n1. Begin Game"
				<<"\n2. Exit"
				<<"\nPlease select 1 to play or 2 to exit : ";
	while(!(std::cin >> mainSelect)){
		std::cout<<"PLEASE ENTER 1 or 2 NOT A CHARACTER!!:";
		std::cin.clear();
		std::cin.ignore();
	}
	return mainSelect;
}
//Game intro for understanding how play this game.
void Intro(){
	
	system("mode 800");

	std::cout<<"\nWelcome to TicTacToe game."
			<<"\nThis is a 2 player human game."
			<<"\nFor mark a position you must give correct coordinates.\nWhen you give coordinates it must be like below : \n\nP1:1 1 or P2:2 1 \nNOT LIKE \nP1:21 or P2:13  ...\nFirst input is row and  second is collumn. Beware for order input\n\nP1 is for the first player and has 'X' mark and P2 is for the second player and has 'O' mark.\nGOOD LUCK and HAVE FUN :D\n";
	system("pause");
	system("cls");
}
//Controls if table is filled
bool TableFilled(int counter){
	return counter == 9 ? true : false;
}
//Controls is given inputs are wrong or overflow.
bool InputControl(std::vector<std::vector<char>> &table,int &c1,int &c2){
	
	while(!(std::cin>>c1>>c2)||c1>3||c1<1||c2>3||c2<1){
		std::cin.clear();
		std::cin.ignore();
		std::cout<<"You enterred wrong input type. It means you are typing anything not number or  incorrect range of coordinate .\nPlease try again : ";
		
	}
	while(table[c1-1][c2-1]=='X' || table[c1-1][c2-1] == 'O'){
			std::cout <<"This coordinates is filled. \nPlease mark to empty domain : "; 
			if(InputControl(table,c1,c2));
		
		}
	
	return true;
}

//Controls is the game is finished. Below rules are the main tictactoe rule for win the game
bool IsGameFinish(std::vector<std::vector<char>> tbl, char pMark){
	
	int row = 0 , col = 0;
		

	//Row searching 
	for(row = 0 ; row < 3 ; row++){
		

		if((tbl[row][col]==pMark)&&(tbl[row][col+1]==pMark)&&(tbl[row][col+2]==pMark)){
			return true;
		}
	}
	
	row = 0;
	col = 0;
	//Column searching from left to right
	for(col = 0; col < 3; col++){
		
		if((tbl[row][col]==pMark)&&(tbl[row+1][col]==pMark)&&(tbl[row+2][col]==pMark)){
			return true;
		}
	}
	
	col = 0;
	row = 0;
	//Cross searching from right to left
	if((tbl[row][col]==pMark)&&(tbl[row+1][col+1]==pMark)&&(tbl[row+2][col+2]==pMark)){
		return true;
	}
	
	if((tbl[row+2][col]==pMark)&&(tbl[row+1][col+1]==pMark)&&(tbl[row][col+2]==pMark)){
		return true;
	}
	return false;
}

//Program starts here
int main()
{
	//Initialize requirements 
	std::pair <int,int> coordP1;
	std::pair <int,int> coordP2;
	char P1 = 'X';
	char P2 = 'O';
	int selection = 0;
	int playerTurn = 1;
	int arrayFillCounter = 0;
	bool gameIsNotEnd = true;
	bool programIsFinish = false;
	std::vector<std::vector<char>> gameTable{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	
	
	//Shows intro 
	Intro();
			
	//Main loop
	while(!programIsFinish){
		
		system("cls");
		//Menu selection here
		selection = MainMenu();
		
		switch(selection){
			//It is where game is playing
			case 1:
				system("cls");
				while(gameIsNotEnd){
					
					TableShow(gameTable);
					if(TableFilled(arrayFillCounter)){
						system("cls");
						TableShow(gameTable);
						std::cout<<"\nDRAW GAME. \n";
						system("pause");
						break;
						
					}
					
					std::cout << "Give coordinates for mark ..\n";
					
					std::cout << "P" << playerTurn<< " move: ";
					if(playerTurn==1){
						if(InputControl(gameTable,coordP1.first,coordP1.second));
						gameTable[coordP1.first-1][coordP1.second-1] = P1;
						
						if(IsGameFinish(gameTable,P1)){
							system("cls");
							TableShow(gameTable);
							std::cout<<"\nPLAYER "<<playerTurn<< "WINS!\n";
							system("pause");
							break;
						} 
						playerTurn+=1;
						arrayFillCounter++;
					}
					else{
						if(!InputControl(gameTable,coordP2.first,coordP2.second));
						gameTable[coordP2.first-1][coordP2.second-1] = 'O';
						
						if(IsGameFinish(gameTable,P2)){
							system("cls");
							TableShow(gameTable);
							std::cout<<"\nPLAYER "<<playerTurn<< "WINS!\n";
							system("pause");
							break;
						}
						
						playerTurn-=1;
						arrayFillCounter++;
					}

				}
				continue;
			case 2:
				return 0;
				
			default:
				std::cout << "\nWRONG CHOISE PLEASE ENTER CORRECT CHOISE!!\n";
				continue;
				
		}
	}
	
	
	return 0;
}