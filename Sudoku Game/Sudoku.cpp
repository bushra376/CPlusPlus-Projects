// SUDOKU GAME
#include<iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include<fstream>
#include<cstring>

using namespace std;

void game_generator (const int[][9]);
bool game_finish (int[][9]);
bool move_check (int[][9] , int, int, int);
void function_row0_gen (int[][9]);
bool check_function_row (int [][9], const int);
void function_row1_gen (int [][9]);
void function_row2_gen (int[][9]);
void function_row3_gen (int[][9]);
void function_row4_gen (int[][9]);
void function_row5_gen (int[][9]);
void function_row6_gen (int[][9]);
void function_row7_gen (int[][9]);
void function_row8_gen (int[][9]);

int main()
{
	int ans_check,ch_move,spaces=0,space_check;
	const int size = 9;
	int arr [size][size];	// THE MAIN SEQUENCE STORED IN IT
	int arr_copy [size][size];
	
	srand(time(0));
//***************************************************************	WRITING THE MAIN MENU
	char str[400];
	ifstream myfile("mainmenu.txt");
	int start;

	if (myfile.is_open())
	{
		while(!myfile.eof())
		{
				myfile.getline(str, 400,7);
				cout<<str;
		}
	}
	cout<<endl;
	myfile.close();
	cin>>start;
	system("cls");
	if (start ==1)
	{

		//***************************************************************8

			function_row0_gen (arr);	// GENERATING ROW 0

		//***************************************************************	
			function_row1_gen (arr);	// GENERATING ROW 1

			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 1
			{
				ans_check = check_function_row (arr, 1);
		
				if (ans_check == 1)
					break;

				function_row1_gen (arr);
			}
		//***************************************************************
			function_row2_gen (arr);	// GENERATING ROW 2

			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 2
			{
				ans_check = check_function_row (arr, 2);
		
				if (ans_check == 1)
					break;

				function_row2_gen (arr);
			}
		// *****************************************************************
			function_row3_gen (arr);	// GENERATING ROW 3

			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 3
			{
				ans_check = check_function_row (arr, 3);
		
				if (ans_check == 1)
					break;

				function_row3_gen (arr);
			}
		//******************************************************************
			function_row4_gen (arr);	// GENERATES ROW 4

			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 4
			{
				ans_check = check_function_row (arr, 4);
		
				if (ans_check == 1)
					break;

				function_row4_gen (arr);
			}
		//*******************************************************************
			function_row5_gen (arr);	// GENERATES ROW 5

			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 5
			{
				ans_check = check_function_row (arr, 5);
		
				if (ans_check == 1)
					break;

				function_row5_gen (arr);
			}

		// *******************************************************************
			function_row6_gen (arr);	// GENERATES ROW 6
	
			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 6
			{
				ans_check = check_function_row (arr, 6);
		
				if (ans_check == 1)
					break;

				function_row6_gen (arr);
			}

		// *******************************************************************

			function_row7_gen (arr);	// GENERATES ROW 7
	
			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 7
			{
				ans_check = check_function_row (arr, 7);
		
				if (ans_check == 1)
					break;

				function_row7_gen (arr);
			}

		// *******************************************************************

			function_row8_gen (arr);	// GENERATES ROW 8
	
			while(1)	// LOOPS UNTIL RIGHT SEQUENCE ACHIEVED FOR ROW 8
			{
				ans_check = check_function_row (arr, 8);
		
				if (ans_check == 1)
					break;

				function_row8_gen (arr);
			}

		// *******************************************************************
		// MAKING A COPY OF ARRAY
			for (int z=0; z<size; z++)
			{
				for (int y=0; y<size; y++)
				{
					arr_copy[z][y] = arr [z][y];
				}
			}
		// MAKING SOME BLANK SPACE ON BOARD
			while (spaces<=30)
			{
				arr_copy [1 + rand() % 9][1 + rand() % 9] = 0;
				spaces++;
			}
			int row,column,turn;
		// PRINTS THE SEQUENCE WITH BLANKS ON THE BOARD
			system("cls");
			game_generator (arr_copy);
		// STARTING THE GAME *************************************************************
			while(1)
			{

				while (1)
				{
					cout<<"ENTER THE ROW: ";
					cin>>row;
					cout<<"ENTER THE COLUMN: ";
					cin>>column;
					cout<<"ENTER THE NUMBER YOU WANT TO PLACE: ";
					cin>>turn;
					cout<<endl;

					ch_move = move_check (arr_copy, row, column, turn);
					if (ch_move == 0)
					{
						continue;
					}
					else
					{
						arr_copy[row][column] = turn;
						system("cls");
						game_generator (arr_copy);
						cout<<"\tYOU HAVE GUESSED THE RIGHT PLACEMENT OF THE NUMBER"<<endl;
						cout<<"\tMAKE YOUR NEXT MOVE"<<endl;
						break;
					}
				}
				space_check = game_finish (arr_copy);
		
				if (space_check == 1)
				{
					system("cls");
					game_generator (arr_copy);
					cout<<"CONGRATULATIONS!!!! YOU HAVE GUESSED ALL THE RIGHT NUMBERS & HAVE"<<endl<<" PLACED THEM CORRECTLY AT THEIR PLACES"<<endl;
					cout<<"GAME OVER !!!!!!"<<endl;
					break;
				}

			}
	}
			return 0;
}
void game_generator (const int arr_gen [][9])
{
	cout<<"COLUMN:"<<setw(7)<<"0"<<setw(4)<<"1"<<setw(4)<<"2"<<setw(9)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(9)<<"6"<<setw(4)<<"7"<<setw(4)<<"8"<<endl;
	cout<<"           _______________________________________________"<<endl;
	
	cout<<"ROW 0 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [0][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [0][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [0][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [0][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 1 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [1][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [1][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [1][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [1][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 2 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [2][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [2][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [2][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [2][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;
	
	cout<<setw(12)<<"|"<<setw(46)<<"|"<<endl;

	cout<<setw(24)<<"|____________"<<setw(17)<<"_____________"<<setw(17)<<"____________|"<<endl;

	cout<<"ROW 3 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [3][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [3][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [3][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [3][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 4 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [4][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [4][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [4][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [4][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 5 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [5][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [5][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [5][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [5][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<setw(12)<<"|"<<setw(46)<<"|"<<endl;

	cout<<setw(24)<<"|____________"<<setw(17)<<"_____________"<<setw(17)<<"____________|"<<endl;

	cout<<"ROW 6 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [6][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [6][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [6][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [6][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 7 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [7][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [7][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [7][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [7][8]<<setw(2)<<"|"<<endl;
	cout<<setw(24)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<setw(17)<<"|___|___|___|"<<endl;

	cout<<"ROW 8 >>"<<setw(4)<<"|"<<setw(2)<<arr_gen [8][0]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][1]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][2]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [8][3]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][4]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][5]<<setw(2)<<"|"<<setw(5)<<"|"<<setw(2)<<arr_gen [8][6]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][7]<<setw(2)<<"|"<<setw(2)<<arr_gen [8][8]<<setw(2)<<"|"<<endl;
	cout<<setw(58)<<"|___|___|___|____|___|___|___|____|___|___|___|"<<endl;
	cout<<endl;
	

}

// FUNCTION GENERATING ROW 0
void function_row0_gen (int arr_row0_gen[][9])
{
	int n=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,x;
	while (n<9)
	{
		x = 1 + (rand() % 9);
		if (x==1)
		{
			a++;
			if(a>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		
		if (x==2)
		{
			b++;
			if(b>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		} 
		if (x==3)
		{
			c++;
			if(c>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==4)
		{
			d++;
			if(d>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==5)
		{
			e++;
			if(e>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==6)
		{
			f++;
			if(f>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==7)
		{
			g++;
			if(g>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==8)
		{
			h++;
			if(h>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
		if (x==9)
		{
			j++;
			if(j>1)
				continue;
			arr_row0_gen [0][n]= x;
			n++;
		}
	}
}

// FUNCTION GENERATING ROW 1
void function_row1_gen (int arr_row1_gen[][9])
{
	
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2]) ) || ((n==1 || 4 || 7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || 5 || 8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n== 0 || n==3 || n==6) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2]) ) || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				 if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
			if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
			if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6)) && ( x != arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] &&  x != arr_row1_gen[0][n+2])  || ((n==1 || n==4 || n==7 ) && (x!= arr_row1_gen [0][n] && x!= arr_row1_gen [0][n+1] && x!= arr_row1_gen[0][n-1]) ) || ((n==2 || n==5 || n==8) && (x!= arr_row1_gen [0][n] &&  x!=arr_row1_gen [0][n-1] && x!= arr_row1_gen[0][n-2]) ))
				{
					arr_row1_gen [1][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION CHECKING
bool check_function_row (int arr1[][9], const int row_size)
{
	int sum_row =0;
	
	for (int y=0; y<9; y++)
	{
		sum_row += arr1[row_size][y] ;
	}
	
	if (sum_row == 45)
		return true;
	else return false;
}

// FUNCTION TO GENERATE ROW 2
void function_row2_gen (int arr_row2_gen[][9])
{
	
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] &&  x != arr_row2_gen[0][n+2]) && ( x != arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] &&  x != arr_row2_gen[1][n+2]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row2_gen [0][n] && x!= arr_row2_gen [0][n+1] && x!= arr_row2_gen[0][n-1]) && (x!= arr_row2_gen [1][n] && x!= arr_row2_gen [1][n+1] && x!= arr_row2_gen[1][n-1]) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row2_gen [0][n] &&  x!=arr_row2_gen [0][n-1] && x!= arr_row2_gen[0][n-2]) && (x!= arr_row2_gen [1][n] &&  x!=arr_row2_gen [1][n-1] && x!= arr_row2_gen[1][n-2]) ))
				{
					arr_row2_gen [2][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}

// FUNCTION TO GENERATE ROW 3
void function_row3_gen (int arr_row3_gen[][9])
{
	
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (x!= arr_row3_gen[0][n] && x!= arr_row3_gen[1][n] && x!= arr_row3_gen[2][n])
				{
					arr_row3_gen [3][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION TO GENERATE ROW 4
void function_row4_gen (int arr_row4_gen[][9])
{
	
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] &&  x != arr_row4_gen[3][n+2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row4_gen [3][n] && x!= arr_row4_gen [3][n+1] && x!= arr_row4_gen[3][n-1]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row4_gen [3][n] &&  x!=arr_row4_gen [3][n-1] && x!= arr_row4_gen[3][n-2]) && ( x!= arr_row4_gen[0][n] && x!= arr_row4_gen[1][n] && x!= arr_row4_gen[2][n] && x!= arr_row4_gen[3][n] ) ))
				{
					arr_row4_gen [4][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION TO GENERATE ROW 5
void function_row5_gen (int arr_row5_gen[][9])
{
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] &&  x != arr_row5_gen[3][n+2]) && ( x != arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] &&  x != arr_row5_gen[4][n+2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row5_gen [3][n] && x!= arr_row5_gen [3][n+1] && x!= arr_row5_gen[3][n-1]) && (x!= arr_row5_gen [4][n] && x!= arr_row5_gen [4][n+1] && x!= arr_row5_gen[4][n-1]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row5_gen [3][n] &&  x!=arr_row5_gen [3][n-1] && x!= arr_row5_gen[3][n-2]) && (x!= arr_row5_gen [4][n] &&  x!=arr_row5_gen [4][n-1] && x!= arr_row5_gen[4][n-2]) && ( x!= arr_row5_gen[0][n] && x!= arr_row5_gen[1][n] && x!= arr_row5_gen[2][n] && x!= arr_row5_gen[3][n] && x!= arr_row5_gen[4][n] ) ))
				{
					arr_row5_gen [5][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION GENERATES ROW 6
void function_row6_gen (int arr_row6_gen[][9])
{
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<1000 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if(x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if(x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (x!= arr_row6_gen[0][n] && x!= arr_row6_gen[1][n] && x!= arr_row6_gen[2][n] && x!= arr_row6_gen[3][n] && x!= arr_row6_gen[4][n] && x!= arr_row6_gen[5][n])
				{
					arr_row6_gen [6][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION GENERATES ROW 7
void function_row7_gen (int arr_row7_gen[][9])
{
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] &&  x != arr_row7_gen[6][n+2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row7_gen [6][n] && x!= arr_row7_gen [6][n+1] && x!= arr_row7_gen[6][n-1]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row7_gen [6][n] &&  x!=arr_row7_gen [6][n-1] && x!= arr_row7_gen[6][n-2]) && ( x!= arr_row7_gen[0][n] && x!= arr_row7_gen[1][n] && x!= arr_row7_gen[2][n] && x!= arr_row7_gen[3][n] && x!= arr_row7_gen[4][n] && x!= arr_row7_gen[5][n] && x!= arr_row7_gen[6][n] ) ))
				{
					arr_row7_gen [7][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION GENERATES ROW 8
void function_row8_gen (int arr_row8_gen[][9])
{
	int	a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,n=0,x;
	for (int z=0; z<100 ; z++)	
	{	
		while (n<9)
		{
			x = 1 + (rand() % 9);
			if (x==1)
			{
				
				if(a>=1)
					break ;

				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					a++;
					n++;
				}
			}
			
			if (x==2)
			{
				
				if(b>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					b++;
				}
			} 
			if (x==3)
			{
				
				if(c>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					c++;
				}
			}
			if (x==4)
			{
				
				if(d>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					d++;
				}
			}
			if (x==5)
			{
				
				if(e>=1)
					break;
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					e++;
				}
			}
			if (x==6)
			{
				
				if(f>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					f++;
				}
			}
			if (x==7)
			{
				
				if(g>=1)
					break;
			
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					g++;
				}
			}
			if (x==8)
			{
				
				if(h>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					h++;
				}
			}
			if (x==9)
			{
				
				if(j>=1)
					break;
				
				if (((n==0 || n==3 || n==6) && ( x != arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] &&  x != arr_row8_gen[6][n+2]) && ( x != arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] &&  x != arr_row8_gen[7][n+2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n]) ) || ((n==1 ||n== 4 ||n== 7 ) && (x!= arr_row8_gen [6][n] && x!= arr_row8_gen [6][n+1] && x!= arr_row8_gen[6][n-1]) && (x!= arr_row8_gen [7][n] && x!= arr_row8_gen [7][n+1] && x!= arr_row8_gen[7][n-1]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ) || ((n==2 ||n== 5 ||n== 8) && (x!= arr_row8_gen [6][n] &&  x!=arr_row8_gen [6][n-1] && x!= arr_row8_gen[6][n-2]) && (x!= arr_row8_gen [7][n] &&  x!=arr_row8_gen [7][n-1] && x!= arr_row8_gen[7][n-2]) && ( x!= arr_row8_gen[0][n] && x!= arr_row8_gen[1][n] && x!= arr_row8_gen[2][n] && x!= arr_row8_gen[3][n] && x!= arr_row8_gen[4][n] && x!= arr_row8_gen[5][n] && x!= arr_row8_gen[6][n] && x!= arr_row8_gen[7][n] ) ))
				{
					arr_row8_gen [8][n]= x;
					n++;
					j++;
				}
			}
		}		
	}
}
// FUNCTION CHECKING THE PLAYERS TURN
bool move_check (int arr_copy_1[][9] ,int row_1 ,int column_1, int turn_1)
{
	for ( int w=0; w<9; w++)
	{
		if (((column_1==0 || column_1==3 || column_1==6) && (row_1==0 || row_1 ==3 || row_1==6) && ( arr_copy_1 [(row_1) +1][(column_1) + 1] == turn_1 || arr_copy_1[row_1 +1][column_1 + 2] == turn_1 || arr_copy_1[row_1 + 2][column_1 + 1] == turn_1 || arr_copy_1[row_1 + 2][column_1 + 2] == turn_1)) ||	// checks rows & columns 0, 3 & 6
			((column_1==1 || column_1==4 || column_1==7) && (row_1==1 || row_1 ==4 || row_1==7) && ( arr_copy_1 [(row_1) +1][(column_1) + 1] == turn_1 || arr_copy_1[row_1 +1][column_1 - 1] == turn_1 || arr_copy_1[row_1 - 1][column_1 + 1] == turn_1 || arr_copy_1[row_1 + 2][column_1 - 1] == turn_1)) ||	// checks rows & columns 1, 4 & 7
			((column_1==2 || column_1==5 || column_1==8) && (row_1==2 || row_1 ==5 || row_1==8) && ( arr_copy_1 [(row_1) -1][(column_1) - 1] == turn_1 || arr_copy_1[row_1 -1][column_1 - 2] == turn_1 || arr_copy_1[row_1 - 2][column_1 - 1] == turn_1 || arr_copy_1[row_1 - 2][column_1 - 2] == turn_1)))		// checks rows & columns 2, 5 & 8
		{
			cout<<"INVALID MOVE. THAT NUMBER IS ALREADY PRESENT IN THE 3X3 BOX. THINK A LITTLE HARDER"<<endl;
			return false;
		}
		if (turn_1 < 1 || turn_1 > 9)
		{
			cout<<"INVALID MOVE. PLEASE CHOOSE A NUMBER FROM 1 TO 9"<<endl;
			return false;
		}
		if (arr_copy_1[row_1][column_1] !=0 )
		{
			cout<<"INVALID MOVE. PLACE YOUR NUMBER IN THE BOX WHICH CONTAINS A ZERO"<<endl;
			return false;
		}
		if (arr_copy_1[row_1][w] == turn_1)
		{
			cout<<"THAT NUMBER IS ALREADY PRESENT IN THE ROW. PLEASE MAKE ANOTHER MOVE"<<endl;
			return false;
		}
		if (arr_copy_1[w][column_1] == turn_1 )
		{
			cout<<"THAT NUMBER IS ALREADY PRESENT IN THE COLUMN. PLEASE MAKE ANOTHER MOVE"<<endl;
			return false;
		}

	}
	return true;
}
// FUNCTION TO CHECK IF ALL SPACES FILLED
bool game_finish (int arr_check[][9])
{
	for (int r=0; r<9;r++)
	{
		for(int q=0; q<9; q++)
		{
			if (arr_check [r][q] == 0)
				return false;

		}
	}
	 return true;
}



