#include <iostream>

using namespace std;

const int rows = 3;
const int col = 3;
char val = '\0';
void printBoard(char A[][col])
{
	cout << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << A[i][j] << "   ";
		}
		cout << endl;
	}
}
bool cellFree(char A[][col], int r, int c)
{
	if(r < rows && r >= 0 && c < col && c >= 0)
	{
		if(A[r][c] == '0')
		{
			return true;
		}
	}
	return false;
}
bool setCell(char A[][col], int r, int c)
{
	if(cellFree(A, r, c) == 1)
	{
		A[r][c] = val;
		return true;
	}
	return false;
}
void getInputAndSetCell(char A[][col])
{
	int r = 0;
	int c = 0;
	
	cout << "Enter row no. ";
	cin >> r;
	cout << "Enter column no. ";
	cin >> c;
	
	while(setCell(A, r, c) == 0)
	{
		cout << "\nWrong position. Enter again.\n";
		cout << "Enter row no. ";
		cin >> r;
		cout << "Enter column no. ";
		cin >> c;
	}
}
bool rowSame(char A[][col], int r)
{
	if(r < rows && r >= 0)
	{
		if(A[r][0] == 'X' || A[r][0] == 'O')
		{
			for(int i = 1; i < col; i++)
			{
				if(A[r][i] != A[r][i-1])
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
bool columnSame(char A[][col], int c)
{
	if(c < col && c >= 0)
	{
		if(A[0][c] == 'X' || A[0][c] == 'O')
		{
			for(int i = 1; i < rows; i++)
			{
				if(A[i][c] != A[i-1][c])
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
bool primaryDiagonalSame(char A[][col])
{
	if(A[0][0] == 'X' || A[0][0] == 'O')
	{
		for(int i = 1; i < rows; i++)
		{
			if(A[i-1][i-1] != A[i][i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool secondaryDiagonalSame(char A[][col])
{
	if(A[0][col-1] == 'X' || A[0][col-1] == 'O')
	{
		for(int i = 1; i < rows; i++)
		{
			if(A[i][col-1-i] != A[i-1][col-1-(i-1)])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool anythingSame(char A[][col])
{
	for(int i = 0; i < rows; i++)
	{
		if(rowSame(A, i) || columnSame(A, i))
		{
			return true;
		}
	}
	
	if(primaryDiagonalSame(A) || secondaryDiagonalSame(A))
	{
		return true;
	}
	
	return false;
}

void play(char A[][col])
{
	for(int i = 1; i <= rows*col; i++)
	{
		if(i % 2 != 0)
		{
			printBoard(A);
			cout << "Player 1's turn:-" << endl;
			val = 'X';
		}
		else
		{
			printBoard(A);
			cout << "Player 2's turn:-" << endl;
			val = 'Y';
		}
		
		getInputAndSetCell(A);
		
		if(anythingSame(A) == 1)
		{
			cout << "GAME OVER!" << endl;
			printBoard(A);
			break;
		}
		else
		{
			if(i == rows*col)
			{
				cout << "It's a TIE!";
				printBoard(A);
				break;
			}
		}
	}
	
}




int main()
{
	char grid[rows][col] = {'0','0','0','0','0','0','0','0','0'};
	
	play(grid);
	return 0;
}




















