#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cgi.h>

s_cgi *cgi;
char x_var[4]; //no reasonable reason for 1000+ tile map
char y_var[4];
int x_gem = 127;
int y_gem = 127;

//simple comparison that sends out the damn info

void main(void)
{
	cgi = cgiInit();
	//test commit line
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
}