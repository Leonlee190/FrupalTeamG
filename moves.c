#include "moves.h"

void dir_move(char input, int *fx, int *fy, struct player hero){

	if(input == 'N' || input == 'w' || input == 'W'){
        if(hero.y < (hero.max - 1)){
            *fx = hero.x;
            *fy = hero.y + 1;
            --hero.energy;
        }
        else if(hero.y == (hero.max - 1)){
            *fx = hero.x;
            *fy = 0;
            --hero.energy;
        }
    }

    else if(input == 'S' || input == 's'){
        if(hero.y > 0){
            *fx = hero.x;
            *fy = hero.y - 1;
            --hero.energy;
        }
        else if(hero.y == 0){
            *fx = hero.x;
            *fy = (hero.max - 1);
            --hero.energy;
        }
    }

    else if(input == 'E' || input == 'd' || input == 'D'){
        if(hero.x < (hero.max - 1)){
            *fy = hero.y;
            *fx = hero.x + 1;
            --hero.energy;
        }
        else if(hero.x == (hero.max - 1)){
            *fy = hero.y;
            *fx = 0;
            --hero.energy;
        }
    }

    else if(input == 'W' || input == 'a' || input == 'A'){
        if(hero.x > 0){
            *fy = hero.y;
            *fx = hero.x - 1;
            --hero.energy;
        }
        else if(hero.x == 0){
            *fy = hero.y;
            *fx = (hero.max - 1);
            --hero.energy;
        }
    }

    else{
        *fx = hero.x;
        *fy = hero.y;
        --hero.energy;
    }
}

void obs_check(int x, int y, struct map q){
	struct player z = load();
	
	--z.energy;
	
	if(q.cells[x][y].terrain == 0){
		printf("Walking through a Meadow<br><br>");
		z.x = x;
		z.y = y;
		save(z);
	}
	
	else if(q.cells[x][y].terrain == 1){
		printf("Walking through a Forest<br><br>");
		z.x = x;
		z.y = y;
		save(z);
	}
	
	else if(q.cells[x][y].terrain == 2){
		printf("Can't walk on Water<br><br>");
		save(z);
	}
	
	else if(q.cells[x][y].terrain == 3){
		printf("Can't walk through Walls<br><br>");
		save(z);
	}
	
	else if(q.cells[x][y].terrain == 4){
		printf("Walking through a Bog, lost two energy<br><br>");
		z.x = x;
		z.y = y;
		--z.energy;
		save(z);
	}
	
	else if(q.cells[x][y].terrain == 5){
		printf("Walking through a Swamp, lost two energy<br><br>");
		z.x = x;
		z.y = y;
		--z.energy;
		save(z);
	}
}
