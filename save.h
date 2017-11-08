#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
using namespace std;

int savePlayer(int xCoord, int yCoord, int energy, int whiffles);
int saveI_help(char * fName, int itemName, int itemNum);
int saveInventory(int * bag, int length);
int saveMap();