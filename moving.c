#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include <time.h>
#include "player.h"
#include "map.h"

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

    if(input == 'N' || input == 'w' || input == 'W'){
        if(hero.y < (hero.max - 1)){
            fx = hero.x;
            fy = hero.y + 1;
            --hero.energy;
        }
        else if(hero.y == (hero.max - 1)){
            fx = hero.x;
            fy = 0;
            --hero.energy;
        }
    }

    else if(input == 'S' || input == 's'){
        if(hero.y > 0){
            fx = hero.x;
            fy = hero.y - 1;
            --hero.energy;
        }
        else if(hero.y == 0){
            fx = hero.x;
            fy = (hero.max - 1);
            --hero.energy;
        }
    }

    else if(input == 'E' || input == 'd' || input == 'D'){
        if(hero.x < (hero.max - 1)){
            fy = hero.y;
            fx = hero.x + 1;
            --hero.energy;
        }
        else if(hero.x == (hero.max - 1)){
            fy = hero.y;
            fx = 0;
            --hero.energy;
        }
    }

    else if(input == 'W' || input == 'a' || input == 'A'){
        if(hero.x > 0){
            fy = hero.y;
            fx = hero.x - 1;
            --hero.energy;
        }
        else if(hero.x == 0){
            fy = hero.y;
            fx = (hero.max - 1);
            --hero.energy;
        }
    }

    else{
        fx = hero.x;
        fy = hero.y;
        --hero.energy;
    }
	
	hero.x = fx;
	hero.y = fy;
	
	save(hero);

    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", hero.x, hero.y, hero.energy, hero.whiffles);
    printf("<br><br>Map Location: %d", place.cells[hero.x][hero.y].terrain);

    return 0;
}
