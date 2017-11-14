#include "save.c"

int main(void)
{
	printf("Enter main");
	loadSave();
	printf("Finish loadSave");
	struct map m = makeMap("Save_MapCells_TeamG.txt");
	updateMap(1,3,1,&m);
	printMap(5,&m);
	deallocateMap(5,&m);
	return 0;
}
