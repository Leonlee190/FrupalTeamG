#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadSave();
int savePlayer(int size, int xCoord, int yCoord, int energy, int whiffles);
int saveI_help(char * fName, int itemName, int itemNum);
int saveInventory(int * bag, int length);
int saveMap(int size, char * cellData);
int updateMap();