#include <iostream>
using namespace std;

/*TODO:
	Na ftiakso to board
*/ 

class ChessBoard{
	int rows;
	int cols;
	char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int turn; /*turn = 0 -> computer, turn = 1 -> you */
	int winner; /* -1 -> tie, 0 -> computer, 1 -> you */
	int empty;
	int aiMoveX = -1;
	int aiMoveY = -1;
	char copyBoard[3][3];
	char mySymbol;
	char pcSymbol;
	public:
		ChessBoard();
		void printBoard();
		int setMove(int row, int col);
		char getSymbol();
		int getEmpty();
		int ai();
		int isWinner();
		int aiMove(int depth, bool isMax);
		int isWinAi();
		int getX();
		int getY();
		int getTurn();
		
};

int ChessBoard::getTurn(){
	return turn;
}
int ChessBoard::getX(){
	return aiMoveX;
}

int ChessBoard::getY(){
	return aiMoveY;
}

int ChessBoard::ai(){
	
	if(isWinner() == 0){
		return 10;
	}else{
		return -10;
	}
}

int ChessBoard::aiMove(int depth, bool isMax){
	int evaluate;
	evaluate = ai();
	if(evaluate == 10){
		return evaluate;
	}
	
	if(evaluate == -10){
		return evaluate;
	}
	
	if(empty == 0){
		return 0;
	}
	
	if(isMax){
		int best = -1000;
		
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(board[i][j] == ' '){
					board[i][j] = pcSymbol;
					empty--;
					best = max(best,aiMove(depth+1,!isMax));
					board[i][j] = ' ';
					empty++;
				}
			}
		}
		return best;
	
	}
	else{
		int best = 1000;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(board[i][j] == ' '){
					board[i][j] = mySymbol;
					empty--;
					best = max(best,aiMove(depth+1,!isMax));
					board[i][j] = ' ';
					empty++;
				}
			}
		}
		return best;		
	}
	
}

void ChessBoard::printBoard(){
	int i,j;

	cout << "   1   2   3" << endl;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(j == 0){ 
				cout << "   ";
			}
			cout << board[i][j];
			if(j == cols - 1){
				continue;
			}
			cout << " | ";
		}

		if(i == rows - 1){
			cout << "  C ";
			continue;
		}
		switch(i){
			case 0:
				cout << "  A ";
				break;
			case 1:
				cout << "  B ";
				break;
		}

		cout << endl << "   ----------" << endl;
	}
}

ChessBoard::ChessBoard(){
	rows = 3;
	cols = 3;
	board[rows][cols] = {};
	turn = 1;
	winner = -1;
	empty = rows * cols;
	copyBoard[3][3] = {};	

	cout << "Type your symbol: ";
	cin >> mySymbol;
	
	pcSymbol = 'X' != mySymbol ? 'X' : 'O';
	cout << rows << endl;

}
int ChessBoard::isWinAi(){
	int bestVal = -1000;
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == ' '){
				board[i][j] = pcSymbol;
				empty--;
				int moveVal = aiMove(0, false);
				board[i][j] = ' ';
				empty++;
				if(moveVal > bestVal){
					aiMoveX = j;
					aiMoveY = i;
					bestVal = moveVal;
				}
			}
		}
	}
	return 1;
}
int ChessBoard::isWinner(){
	int row, col;
	/* isWinner returns the !turn because it is called after setMove. setMove changes the turn */
	
	/* Checking for cols */
	for(row = 0; row < rows; row++){
		if(board[row][0] == board[row][1] && board[row][0] == board[row][2]){
			if(board[row][0] == pcSymbol){
				return 0;
			}else if(board[row][0] == mySymbol){
				return 1;
			}
		}
	}
	/* Checking for rows */
	for(col = 0; col < cols; col++){
		if(board[0][col] == board[1][col] && board[0][col] == board[2][col]){
			if(board[0][col] == pcSymbol){
				return 0;
			}else if(board[0][col] == mySymbol){
				return 1;
			}
		}
	}	
	
	/* Diagonal left -> right*/
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
			if(board[0][0] == pcSymbol){
				return 0;
			}else if(board[0][0] == mySymbol){
				return 1;
			}
	}

	/* Diagonal right -> left */
	if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
			if(board[0][2] == pcSymbol){
				return 0;
			}else if(board[0][2] == mySymbol){
				return 1;
			}
	}
	return -1;
}
int ChessBoard::setMove(int row, int col){
	if(board[row][col] == ' '){
		if(turn == 0){
			board[row][col] = pcSymbol;
			turn = 1;
		}else{
			board[row][col] = mySymbol;	
			turn = 0;		
		}
		empty--;
		return 1;
	}
	else{
		return 0;
	}
}

char ChessBoard::getSymbol(){
	return mySymbol;
}

int ChessBoard::getEmpty(){
	return empty;
}
int main(){
	ChessBoard board;
	board.printBoard();
	int row, col, temp;
	while(board.getEmpty() != 0){
			
			cout << endl << "Enter the row: ";
			cin >> row;
			cout << endl << "Enter the column: ";
			cin >> col;
	    	cout << endl;
			cout << col << endl << row;	
			if(board.setMove(row-1,col-1) == 0)
				cout << endl << "Invalid position. Try another one! " << endl;
			
			
			board.printBoard();	
			temp = board.isWinner();
			if(temp == 0){
				cout << endl << "You've lost." << endl;
				break;
			}else if(temp == 1){
				cout << endl << "Congrats you've won!!!" << endl;
				break;
			}
			board.isWinAi();
			board.setMove(board.getX(), board.getY());
			system("cls");
			board.printBoard();
			if(temp == 0){
				cout << endl << "You've lost." << endl;
				break;
			}else if(temp == 1){
				cout << endl << "Congrats you've won!!!" << endl;
				break;
			}
	}
	return 0;
}
