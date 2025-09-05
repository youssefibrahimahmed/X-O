#include <iostream>
using namespace std;// 0   1   2   
char xo[5][3] = { {'1','2','3'}, //0
					 {' ',' ',' '}, //1
					 {'4','5','6'}, //2
					 {' ',' ',' '}, //3
					 {'7','8','9'} };//4    
// function for drawing the game:
void draw_board()
{
	for (int h = 1; h <= 3; h += 2)
	{
		for (int k = 0; k < 3; k++)
		{
			xo[h][k] = '-';
		}
	}
	for (size_t i = 0; i < 5; i++)
	{

		for (size_t j = 0; j < 3; j++)
		{
			if (i % 2 == 1)
			{
				cout << "---";
			}
			else cout << " " << xo[i][j] << " ";
			if (j < 2)
				cout << "|";
		}
		cout << endl;
	}
}
//function for cases of winning:
int checkwinner(char xo[5][3])
{
	for (size_t i = 0; i < 5; i += 2) //التحقق من الصفوف
	{
		if (xo[i][0] == xo[i][1] && xo[i][1] == xo[i][2])
		{
			if (xo[i][0] == 'x' || xo[i][0] == 'X') return 1;
			else if (xo[i][0] == 'o' || xo[i][0] == 'O') return 2;
		}
	}
	for (size_t i = 0; i < 3; i++) //التحقق من الاعمده
	{
		if (xo[0][i] == xo[2][i] && xo[2][i] == xo[4][i])
		{
			if (xo[0][i] == 'x' || xo[0][i] == 'X') return 1;
			else if (xo[0][i] == 'o' || xo[0][i] == 'O') return 2;
		}
	}
	//التحقق من الاقطار
	if (xo[0][0] == xo[2][1] && xo[2][1] == xo[4][2])
	{
		if (xo[0][0] == 'x' || xo[0][0] == 'X') return 1;
		else if (xo[0][0] == 'o' || xo[0][0] == 'O') return 2;
	}
	if (xo[0][2] == xo[2][1] && xo[2][1] == xo[4][0])
	{
		if (xo[0][2] == 'x' || xo[0][2] == 'X') return 1;
		if (xo[0][2] == 'o' || xo[0][2] == 'O') return 2;
	}
}
//function if the cells ended 
int drawingcase(char xo[5][3])
{
	int count = 0;
	for (size_t i = 0; i < 5; i += 2)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (!isdigit(xo[i][j]))
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	draw_board();
	cout << " Let's go! " << "\n" << endl;

	while (true) {
		int p1, y = 0, z = 0;
	returnhere:
		cout << "player 1 choose a number" << endl;

		cin >> p1;
		//في حالة اختيار رقم غير موجود بالشبكة
		if (p1 <= 0 || p1 > 9)
		{
			cout << "*========*" << endl;
			cout << " CHOOSE ANOTHER NUMBER ,PLZ" << endl; goto returnhere;
		}
		//في حالة اختيار رقم مش فاضي
		int f = 1;
		for (size_t s = 0; s < 5; s += 2)
		{
			for (size_t c = 0; c < 3; c++)
			{
				if (p1 == f && !isdigit(xo[s][c]))
				{
					cout << "*========*" << endl;
					cout << "CURRENT CELL IS BUSY : CHOOSE ANOTHER ONE" << "\n";
					goto returnhere;
				}
				f++;
			}
		}
		if (p1 < 4)
		{
			y = 0; z = p1 - 1;
			xo[y][z] = 'X';
		}
		else if (p1 < 7 && p1>3)
		{
			y = 2; z = p1 - 4;
			xo[y][z] = 'X';
		}
		else if (p1 < 10 && p1>6)
		{
			y = 4; z = p1 - 7;
			xo[y][z] = 'X';
		}
		{
			system("cls");
		}
		draw_board();
		int result = checkwinner(xo);
		if (result == 1)
		{
			cout << "*========*" << endl;
			cout << "P1 IS THE WINNER";
			return 0;
		}
		int counter = drawingcase(xo);
		if (counter == 9)
		{
			cout << "*========*" << endl;
			cout << "GAME OVER";
			return 0;
		}
		int p2, a = 0, b = 0;
	Returnhere:
		cout << "player 2 choose a number" << endl;
		cin >> p2;
		if (p2 <= 0 || p2 > 9) { cout << " CHOOSE ANOTHER NUMBER ,PLZ" << endl; goto Returnhere; }
		int o = 1;
		for (size_t m = 0; m < 5; m += 2)
		{
			for (size_t n = 0; n < 3; n++)
			{
				if (p2 == o && !isdigit(xo[m][n]))

				{
					cout << "CURRENT CELL IS BUSY : CHOOSE ANOTHER ONE" << "\n";
					goto Returnhere;
				}
				o++;
			}
		}
		if (p2 < 4)
		{
			a = 0; b = p2 - 1;
			xo[a][b] = 'O';
		}
		else if (p2 < 7 && p2>3)
		{
			a = 2; b = p2 - 4;
			xo[a][b] = 'O';
		}
		else if (p2 < 10 && p2>6)
		{
			a = 4; b = p2 - 7;
			xo[a][b] = 'O';
		}
		{
			system("cls");
		}
		draw_board();
		result = checkwinner(xo);
		if (result == 2)
		{
			cout << "===================" << endl;
			cout << "P2 IS THE WINNER";
			return 0;
		}
		counter = drawingcase(xo);
		if (counter == 9)
		{
			cout << "GAME OVER";
			return 0;
		}
	}
}

