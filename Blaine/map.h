#ifndef _MAP
#define _MAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell {
	int xCoord, yCoord;
	char terrain;
	char item[14];
	int isVisible;
};

//creates a cell, constructor essentially, but because C doesn't have constructors, i need to define it outside of the struct
struct cell makeCell(int x, int y, const char* visibility, char land, const char* inItem) {
	struct cell retVal;

	retVal.xCoord = x;
	retVal.yCoord = y;
	retVal.isVisible = atoi(visibility);

	strcpy(retVal.item, inItem);

	return retVal;
}

struct map {
	int dimensions;
	struct cell** cells;
};

//allocates memory for the map, then initializes all cells to be empty and invisible
void initializeMap(int size, struct map* inMap) {
	inMap->dimensions = size;

	inMap->cells = malloc(size * sizeof(struct cell*));

	for (int i = 0; i < size; ++i)
		inMap->cells[i] = malloc(size * sizeof(struct cell));

	for(int x = 0; x < size; ++x)
		for (int y = 0; y < size; ++y) {
			struct cell temp = makeCell(x, y, "0", '0' , "None");
			inMap->cells[x][y] = temp;
		}
}

//VERY IMPORTANT!
//MUST BE CALLED TO PREVENT MEMORY LEAKS. DO NOT CALL MAKEMAP WITHOUT CALLING DEALLOCATE MAP BEFORE RETURNING IN MAIN.
//TECHNICALLY THE MEMORY IS FREED AFTER THE PROGRAM TERMINATES, BUT IT'S STILL BAD PRACTICE!
void deallocateMap(int size, struct map* inMap) {
	for (int i = 0; i < size; ++i)
		free(inMap->cells[i]);

	free(inMap->cells);
}

//debug function to validate all files end up in the right spot
void printMap(int size, struct map* inMap) {
	for (int x = 0; x < size; ++x) {
		for (int y = 0; y < size; ++y){
			printf("%d,", inMap->cells[x][y].xCoord);
			printf("%d,", inMap->cells[x][y].yCoord);
			printf("%d,", inMap->cells[x][y].isVisible);
			printf("%c,", inMap->cells[x][y].terrain);
			printf("%s,    ", inMap->cells[x][y].item);
		}
		printf("\n");
	}
}

//main parsing routine to load in a map
struct map makeMap(char* filename) {
	struct map retMap;
	FILE* inFile;
	inFile = fopen(filename, "r");
	char line[64];
	int lineCount = 0, delimitersSeen = 0;

	//do operations line by line
	while (fgets(line, sizeof(line), inFile)) {
		//we don't care about the first line, just the second and then after the #'s
		if (lineCount == 0) {
			lineCount++;
			continue;
		}
		//dimensions line
		if (lineCount == 1) {
			++lineCount;
            //convert the cstring to its integer value, we get the map dimensions
			int dimensions = atoi(line);

			initializeMap(dimensions, &retMap);
            continue;
        }
        //check if we hit a delimiter, if we do, iterate the count then keep going
		if (line[0] == '#') {
			delimitersSeen++;
			continue;
		}

		//once we see two delimiter lines, we know we're at explicitly mentioned map cells
		if (delimitersSeen == 2) {
			char* tmp = strtok(line, ",");
			int fieldCount = 0;
			struct cell temp;
			
			while (tmp != NULL) {
				switch (fieldCount) {
				case 0:
					//xCoord
					temp.xCoord = atoi(tmp);
					fieldCount++;
					tmp = strtok(NULL, ",");
					continue;
				case 1:
					//yCoord
					temp.yCoord = atoi(tmp);
					fieldCount++;
					tmp = strtok(NULL, ",");
					continue;
				case 2:
					//visibility
					temp.isVisible = atoi(tmp);
					fieldCount++;
					tmp = strtok(NULL, ",");
					continue;
				case 3:
					//terrain
					temp.terrain = tmp[0];
					fieldCount++;
					tmp = strtok(NULL, ",");
					continue;
				case 4:
					//item
					strcpy(temp.item, tmp);
					fieldCount++;
					tmp = strtok(NULL, ",");
					continue;
				case 5:
					break;
				}//end switch
			}//end parsing while

			//push the newly made cell to the array
			retMap.cells[temp.xCoord][temp.yCoord] = temp;
		}//end if for delimiter lines = 2
	}

    fclose(inFile);
	return retMap;
}

#endif 
