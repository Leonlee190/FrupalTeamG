#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//deleted these library because C can't recognize iostream, fstream, namespace std;
//#include <iostream>
//#include <fstream>
//using namespace std;

int savePlayer(int MAX, int xCoord, int yCoord, int energy, int whiffles);
int saveI_help(char * fName, int itemName, int itemNum);
int saveInventory(int * bag, int length);
int saveMap();
