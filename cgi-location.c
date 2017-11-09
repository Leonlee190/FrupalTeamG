//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <cgi.h>
//s_cgi *cgi;
//char x_var[4];
//char y_var[4];
//int x_gem = 127;
//int y_gem = 127;

//simple comparison that checks for if line input is the location of the diamonds.

/* void main(void)
{
	cgi = cgiInit();
	strcpy(x_var, cgiGetValue(cgi, "x_char"));
	strcpy(y_var, cgiGetValue(cgi, "y_char"));
	int x = atoi(x_var);
	int y = atoi(y_var);
	printf("Content-Type: text/plain;charset=us-ascii\n\n");
	if(x_gem == x && y_gem == y)
	{	
		printf("You have reached the Royal Diamonds!");
	}
	else
	{
		printf("There isn't anything here...");
	}
} */

//Actual Code Starts Here
#idndef _GEM
#define _GEM
#include <stdio.h>
#include <stdlib.h>

/*
int pull_info_player(int x_play, int y_play);
int pull_info_diamond(int x_gem, int y_gem);
int onDiamond(int gem_x, int gem_y, int user_x, int user_y)