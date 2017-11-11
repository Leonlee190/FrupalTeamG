#include "map.h"

int main(void) {
	struct map myMap = makeMap("map.txt");
    
    //printMap(myMap.dimensions, myMap);
    deallocateMap(myMap.dimensions, myMap);
	
	return 0;
}
