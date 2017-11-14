#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include "moves.h"

char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    struct map place = makeMap("map.txt"); 
    struct player hero = load();
    int fx = 0, fy = 0;

    cgi = cgiInit();

    strcpy(getting, cgiGetValue(cgi, "dir")); 

    input = getting[0];

    dir_move(input, &fx, &fy, hero);

    obs_check(fx, fy, place);

    hero = load();

    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", hero.x, hero.y, hero.energy, hero.whiffles);
    printf("<br>Item: %s", place.cells[hero.x][hero.y].item);

    deallocateMap(hero.max, &place);

    return 0;
}
