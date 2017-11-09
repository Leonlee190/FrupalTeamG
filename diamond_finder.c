#include "diamond_finder.h"
/*
returns a 1 if on the diamond, 0 if not
input from the movement.c file, hopefully
x = x value of the player
y = y value of the player
*/
int onDiamond(int x, int y)
{
	FILE * map_file = fopen("Save_MapCells_TeamG.txt", 'r');
	//Pull info on Royal Diamonds into these variables.
	char buffer[255]; //input buffer from the file
	
	x_diamond;
	y_diamond;
	if(x == x_gem && y == y_gem) return 1; //return a success if the x and y variables match with the Diamonds 
	return 0; //auto return a failure state if they do not match.
}