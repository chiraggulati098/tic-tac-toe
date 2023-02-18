#include<stdio.h>
#include<string.h>

int check_win_condition(char b[10])	// check win condition here
{
	if (b[1] == b[2] && b[2] == b[3])	{
		if (b[2] == 'X')
                        return 1;	// return 1 if player 1 wins
                else if (b[2] == 'O')
                        return 0;	// return 0 of player 2 wins
	}

	else if (b[4] == b[5] && b[5] == b[6])       {
                if (b[5] == 'X')
                        return 1;
                else if (b[5] == 'O')
                        return 0;
        }

	else if (b[7]==b[8] && b[8]==b[9])   {
                if (b[8] == 'X')
                        return 1;
                else if (b[8] == 'O')
                        return 0;
        }

	else if (b[1]==b[4] && b[4]==b[7])	{
		if (b[4] == 'X')
			return 1;
		else if (b[4] == 'O')
			return 0;
	}

	else if (b[2]==b[5] && b[5]==b[8])	{
		if (b[5] == 'X')
			return 1;
		else if (b[5] == 'O')
			return 0;
	}
	
	else if (b[3] == b[6] && b[6] == b[9])       {
                if (b[6] == 'X')
                        return 1;
                else if (b[6] == 'O')
                        return 0;
        }

        else if (b[1]==b[5] && b[5]==b[9])   {
                if (b[5] == 'X')
                        return 1;
                else if (b[5] == 'O')
                        return 0;
        }

        else if (b[3]==b[5] && b[5]==b[7])      {
                if (b[5] == 'X')
                        return 1;
                else if (b[5] == 'O')
                        return 0;
        }

	else if (b[1]!=' ' && b[2]!=' ' && b[3]!=' ' && b[4]!=' ' && b[5]!=' ' && b[6]!=' ' && b[7]!=' ' && b[8]!=' ' && b[9]!=' ')	{
		return -1;	// return -1 if it is a draw
	}

	return 2;	// return 2 if game continues
}

void input_block_x(char board_input[10],char name_string[30])	// let a player input a cell
{
	int n;
	char mark = 'X';
	invalid_cell_x:
	puts(name_string);
	printf("choose the cell: ");
	scanf("%d",&n);
	if (n < 0)	{
		printf("enter a correct cell number\n");
		goto invalid_cell_x;
	}
	else if (n > 9)	{
		printf("enter a correct cell number\n");
		goto invalid_cell_x;
	}
	else if (board_input[n] != ' ')	{
		printf("this cell is already taken. Go again.\n");
		goto invalid_cell_x;
	}
	else if (board_input[n] == ' ')	{
		board_input[n] = mark;
	}
}

void input_block_o(char board_input[10],char name_string[30])	// let a player input a cell
{
	int n;
	char mark = 'O';
	invalid_cell_o:
	puts(name_string);
	printf("choose the cell: ");
	scanf("%d",&n);
	if (n < 0)	{
		printf("enter a correct cell number\n");
		goto invalid_cell_o;
	}
	else if (n > 9)	{
		printf("enter a correct cell number\n");
		goto invalid_cell_o;
	}
	else if (board_input[n] != ' ')	{
		printf("this cell is already taken. Go again.\n");
		goto invalid_cell_o;
	}
	else if (board_input[n] == ' ')	{
		board_input[n] = mark;
	}
}

void show_board(char board_look[10])	// this is here to show what the board looks like
{
	printf("\n\n  %c  |  %c  |  %c",board_look[1],board_look[2],board_look[3]);
	printf("\n-----------------");
	printf("\n  %c  |  %c  |  %c",board_look[4],board_look[5],board_look[6]);
	printf("\n-----------------");
	printf("\n  %c  |  %c  |  %c\n\n\n",board_look[7],board_look[8],board_look[9]);
}

void input_names(char xname[30], char yname[30])	// change gets to fgets in the longer scale
{
	printf("\nenter player 1 name: ");
	fgets(xname,30,stdin);
	printf("enter player 2 name: ");
	fgets(yname,30,stdin);
}

void display_rules()	// input actual rules later
{
	printf("2 PLAYER TIC-TAC-TOE\n\nHow the game works:\n1. Enter a number from 1 to 9 to enter your mark on the playing board.\n2. The first player to have his sign in a line wins.\n");
}

int run_game()	// main game code
{
	char p1name[30],p2name[30];	// player names as strings
	char p1sign = 'X',p2sign = 'O';	// player sign - X or O
	char playing_board[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},board_cell_num[10] = {'0','1','2','3','4','5','6','7','8','9'};	// board to play and show cell number
	int win_condition = -2,number_of_turns = 0;
	display_rules();
	input_names(p1name,p2name);
	show_board(board_cell_num);
	game_loop:
	number_of_turns ++;
	if (number_of_turns % 2 != 0)
		input_block_x(playing_board,p1name);
	else
		input_block_o(playing_board,p2name);
	show_board(playing_board);
	win_condition = check_win_condition(playing_board);
	if (win_condition == 0)	{
		printf("%s WINS\n\n",p2name);
		return 0;
	}
	else if (win_condition == 1)	{
		printf("%s WINS\n\n",p1name);
		return 0;
	}
	else if (win_condition == -1)	{
		printf("it's a DRAW\n\n");
		return 0;
	}
	goto game_loop;
}

int main()
{
	run_game();
	return 0;
}
