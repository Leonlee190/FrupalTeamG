#include "save.h"

// return 0 if successful
int savePlayer(int MAX, int xCoord, int yCoord, int energy, int whiffles)
{
	// file variables
	FILE * fileUser = fopen("Save_Player_TeamG.txt","w");
	
	// write player data to file
	fprintf(fileUser, "%d\n%d\n%d\n%d\n%d", MAX, xCoord, yCoord, energy, whiffles);
	
	return fclose(fileUser);
}

// helper function for saveInventory below
// return 0 if successful
int saveI_help(char * fName, int itemName, int itemNum)
{
	// local variable to append to file
	char * name = NULL;
	FILE * fileBag = fopen(fName,"a");
	// check if file can be opened
	if(fileBag == NULL)
	{
		printf("Error opening %s\n", fName);
		return 1;
	}
	
	// hardcode item names to array values
	switch(itemName)
	{
		case 0:
			name = "Hatchet";
			break;
		case 1:
			name = "Axe";
			break;
		case 2:
			name = "Chainsaw";
			break;
		case 3:
			name = "Chisel";
			break;
		case 4:
			name = "Sledge";
			break;
		case 5:
			name = "Jackhammer";
			break;
		case 6:
			name = "Machete";
			break;
		case 7:
			name = "Shears";
			break;
		case 8:
			name = "Royal Diamonds";
			break;
		case 9:
			name = "Pretty Rock";
			break;
	}
	// write item name # times to file
	for(int i = 0; i<itemNum; ++i)
	{
		fprintf(fileBag, "%s\n", name);
	}
	
	return fclose(fileBag);
}

// return 0 if successful
int saveInventory(int * bag, int length)
{
	// file variables
	char * BAG = "Save_Inventory_TeamG.txt";
	FILE * fileBag = fopen(BAG,"w");
	int success = 0;
	
	// check if file can be opened
	if(fileBag == NULL)
	{
		printf("Error opening %s\n", BAG);
		return 1;
	}
	// cleared file for new write
	fclose(fileBag);
	
	// write items in inventory to file
	for(int i = 0; i < length; ++i)
	{
		success += saveI_help(BAG, i, bag[i]);
	}
	
	return success;
}

// return 0 if successful
int saveMap()
{
	// file variables
	char * MAP = "Save_MapCells_TeamG.txt";
	FILE * fileMap = fopen(MAP,"w");
	
	// check if file can be opened
	if(fileMap == NULL)
	{
		printf("Error opening %s\n", MAP);
		return 0;
	}
	
	return fclose(fileMap);
}
