#include <iostream>
using namespace std;

class Sudoku{
	private:
		int rows;
		int cols;
		int nextRow;
		int nextCol;
		int board[9][9];
	public:
		Sudoku();
		void printBoard();
		int isFull();
		int nextPosition();
		int isValid(int r, int c);
		int move(int row, int col);
		int getNextRow();
		int getNextCol();
};

Sudoku::Sudoku(){
	rows = 9;
	cols = 9;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			board[i][j] = -1;
		}
	}
	board[0][2] = 9;
	board[8][6] = 5;
	board[1][7] = 4;
	board[3][4] = 6;
	board[2][0] = 7;
	board[2][5] = 3;
	board[3][7] = 1;
	board[0][4] = 6;
}

void Sudoku::printBoard(){
	for(int i = 0; i < rows; i++){
		cout << "   ";
		for(int j = 0; j < cols; j++){
			if(j == cols - 1){
				cout << board[i][j] << endl;
			}else if((j+1) % 3 == 0 && j != 8){
				cout << board[i][j] << "  ||  ";
			}
			else{
				cout << board[i][j] << " |";
			}
		}
		if((i +1)% 3 == 0 && i != 8){
			cout << "  --------------------------------------------" << endl;
		}
	
	}
}

int Sudoku::isFull(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == -1){
				return -1;
			}
		}
	}
	return 0;
}

int Sudoku::isValid(int r, int c){
	for(int i = 0; i < rows; i++){
		if(board[i][c] == board[r][c] && r != i){
			return -1; /*Invalid row*/
		}
	}
	
	for(int j = 0; j < cols; j++){
		if(board[r][j] == board[r][c] && c != j){
			return -1; /*Invalid col*/
		}
	}
	
	/*Gia tetragono*/
	return 1; /*Valid*/
}

int Sudoku::nextPosition(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == -1){
				nextRow = i;
				nextCol = j;
				return 1;
			}
		}
	}
	return 0;
}

int Sudoku::move(int row, int col){
	for(int i = 0; i < 10; i++){
		board[row][col] = i;
		if(isValid(row,col) == 1){
			if(nextPosition() == 0){
	 		 	 
				return 1;
			}
			move(nextRow, nextCol);
		}
		board[row][col] = -1;
	}
	
}

int Sudoku::getNextRow(){
	return nextRow;
}
int Sudoku::getNextCol(){
	return nextCol;
}
int main(){
	Sudoku sudoku;
	sudoku.nextPosition();
	sudoku.move(sudoku.getNextRow(),sudoku.getNextCol());
	sudoku.printBoard();
	return 1;
}
