#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include <time.h>

char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    srand(time(NULL));
    int terrain = rand() % 6;

    int MAX;
    int cx, cy, fx, fy;
    int energy, whiffles;
    int avail = 1;

    FILE *fp;
    int i = 0, k = 0;
    char getter[10];
    char single;

    fp = fopen("Save_Player_TeamG.txt", "r");

    single = fgetc(fp);

    while(single != EOF){
        while(single != '\n'){
            getter[i] = single;
            single = fgetc(fp);
            ++i;
        }
        getter[i] = '\0';

        i = 0;

        if(k == 0)
            MAX = atoi(getter);
        else if(k == 1)
            cx = atoi(getter);
        else if(k == 2)
            cy = atoi(getter);
        else if(k == 3)
            energy = atoi(getter);
        else if(k == 4)
            whiffles = atoi(getter);
        single = fgetc(fp);
        ++k;
    }

    fclose(fp);

    cgi = cgiInit();

    strcpy(getting, cgiGetValue(cgi, "dir")); 

    input = getting[0];

    if(input == 'N' || input == 'w' || input == 'W'){
        if(cy < (MAX - 1)){
            fx = cx;
            fy = cy + 1;
            --energy;
        }
        else if(cy == (MAX - 1)){
            fx = cx;
            fy = 0;
            --energy;
        }
    }

    else if(input == 'S' || input == 's'){
        if(cy > 0){
            fx = cx;
            fy = cy - 1;
            --energy;
        }
        else if(cy == 0){
            fx = cx;
            fy = (MAX - 1);
            --energy;
        }
    }

    else if(input == 'E' || input == 'd' || input == 'D'){
        if(cx < (MAX - 1)){
            fy = cy;
            fx = cx + 1;
            --energy;
        }
        else if(cx == (MAX - 1)){
            fy = cy;
            fx = 0;
            --energy;
        }
    }

    else if(input == 'W' || input == 'a' || input == 'A'){
        if(cx > 0){
            fy = cy;
            fx = cx - 1;
            --energy;
        }
        else if(cx == 0){
            fy = cy;
            fx = (MAX - 1);
            --energy;
        }
    }

    else{
        fx = cx;
        fy = cy;
        --energy;
    }

    if(terrain == 0){
        printf("<br>Walking through Meadow<br><br>");
        avail = 1;
    }

    if(terrain == 1){
        printf("<br>Walking through Forrest<br><br>");
        avail = 1;
    }

    if(terrain == 2){
        printf("<br>Can't walk on water...<br><br>");
        avail = 0;
    }

    if(terrain == 3){
        printf("<br>Can't walk through walls...<br><br>");
        avail = 0;
    }

    if(terrain == 4){
        printf("<br>Walked through bog so lost additional energy<br><br>");
        avail = 1;
        --energy;
    }

    if(terrain == 5){
        printf("<br>Walked through swamp so lost additional energy<br><br>");
        avail = 1;
        --energy;
    }

    if(avail){
        cx = fx;
        cy = fy;
    }

    else if(!avail){
        cx = cx;
        cy = cy;
    }

    fp = fopen("Save_Player_TeamG.txt", "w");
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n", MAX, cx, cy, energy, whiffles);
    fclose(fp);

    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", cx, cy, energy, whiffles);

    return 0;
}
