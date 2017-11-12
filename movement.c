#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>

char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    int MAX;
    int cx, cy;
    int energy;
    int whiffles;

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

    if(input == 'N'){
        if(cy < (MAX - 1)){
            ++cy;
            --energy;
        }
        else if(cy == (MAX - 1)){
            cy = 0;
            --energy;
        }
    }

    else if(input == 'S'){
        if(cy > 0){
            --cy;
            --energy;
        }
        else if(cy == 0){
            cy = (MAX - 1);
            --energy;
        }
    }

    else if(input == 'E'){
        if(cx < (MAX - 1)){
            ++cx;
            --energy;
        }
        else if(cx == (MAX - 1)){
            cx = 0;
            --energy;
        }
    }

    else if(input == 'W'){
        if(cx > 0){
            --cx;
            --energy;
        }
        else if(cx == 0){
            cx = (MAX - 1);
            --energy;
        }
    }

    else{
        cx = cx;
        cy = cy;
        --energy;
    }

    fp = fopen("Save_Player_TeamG.txt", "w");
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n", MAX, cx, cy, energy, whiffles);
    fclose(fp);

    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", cx, cy, energy, whiffles);

    return 0;
}
