#include "save.h";

// return 0 if successful
int savePlayer(int size, int xCoord, int yCoord, int energy, int whiffles)
{
	// file variables
	char * USER = "Save_Player_TeamG.txt";
	FILE * fileUser = fopen(USER,"w");
	// check if file can be opened
	if(fileUser == NULL)
	{
		printf("Error opening %s\n", USER);
		return 0;
	}
	// write player data to file
	fprintf(fileUser, "%s\n%s\n%s\n", size, xCoord, yCoord);
	fprintf(fileUser, "%s\n%s\n", energy, whiffles);
	
	return fclose(fileUser);
}

// helper function for saveInventory below
// return 0 if successful
/*
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
			name = "Binoculars";
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
}*/
// return 0 if successful
int saveInventory(int * bag, int length)
{
	// file variables
	char * BAG = "Save_Inventory_TeamG.txt";
	FILE * fileBag = fopen(BAG,"w");
	//int success = 0;
	// check if file can be opened
	if(fileBag == NULL)
	{
		printf("Error opening %s\n", BAG);
		return 1;
	}
	// cleared file for new write
	//fclose(fileBag);
	// write items in inventory to file
	for(int i = 0; i < length; ++i)
	{
		//success += saveI_help(BAG, i, bag[i]);
		fprintf(fileBag, "%d\n", bag[i]);
	}
	return fclose(fileBag);
	//return success;
}

// return 0 if successful
int saveMap(int size, char * cellData)
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
	// write cell data block to map save file
	fprintf(fileMap, "%d\n%s", size, cellData);
	
	return fclose(fileMap);
}

// update map file with new visible cells and used items
// return 0 if successful - inProgress
int updateMap()
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

// load save files with original map file
int loadSave()
{
	// hardcode mape file name
	FILE * fileMap = fopen("map.txt","r");
	char line[101];
	char size[11];
	char * xCoord;
	char * yCoord;
	char energy[11];
	char whiffles[11];
	int * inventory[11];
	// use a strcat to hold the bottom half of original file to save as map file
	// each line in map save file has format x,y,1/0,#,item name
	char cellInfo[101];
	// check if file can be read
	if(fileMap == NULL)
	{
		printf("Error opening map file.");
		return 0;
	}
	// parse file assuming correct formatting followed - no error checking
	// savePlayer file
	fgets(line, 101, fileMap); 		// Map file title
	fgets(size, 11, fileMap); 		// Map dimension
	fgets(line, 101, fileMap); 		// Map file format break
	fgets(line, 101, fileMap); 		// Player coordinates - split below
	xCoord = strtok(line, ",");
	yCoord = strtok(NULL, ",");
	fgets(energy, 11, fileMap);		// Player energy
	fgets(whiffles, 11, fileMap);	// Player whiffles
	// end savePlayer file
	// saveInventory file - hardcode switch statement using strcmp
	fgets(line, 101, fileMap);
	while(strchr(line,'#') == NULL)
	{
		if(strcmp(line,"Hatchet") == 0)
		{
			++inventory[0];
		}
		else if(strcmp(line,"Axe") == 0)
		{
			++inventory[1];
		}
		else if(strcmp(line,"Chainsaw") == 0)
		{
			++inventory[2];
		}
		else if(strcmp(line,"Chisel") == 0)
		{
			++inventory[3];
		}
		else if(strcmp(line,"Sledge") == 0)
		{
			++inventory[4];
		}
		else if(strcmp(line,"Jackhammer") == 0)
		{
			++inventory[5];
		}
		else if(strcmp(line,"Machete") == 0)
		{
			++inventory[6];
		}
		else if(strcmp(line,"Shears") == 0)
		{
			++inventory[7];
		}
		else if(strcmp(line,"Binoculars") == 0)
		{
			++inventory[8];
		}
		else if(strcmp(line,"Pretty Rock") == 0)
		{
			++inventory[9];
		}
		else // group all unknown items
		{
			++inventory[10];
		}
	}
	// end saveInventory - line contains '#'
	// saveMap file
	fgets(cellInfo, 101, fileMap); // hold first cell's properties
	fgets(line, 101, fileMap);
	while(line != EOF)
	{
		strcat(cellInfo,line);
	}
	fclose(fileMap);
	// finish reading from original file
	// write to save files
	savePlayer(atoi(size),atoi(xCoord),atoi(yCoord),atoi(energy),atoi(whiffles));
	saveInventory(inventory,11);
	saveMap(atoi(size),cellInfo);
}