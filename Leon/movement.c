#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>

char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    int MAXx = 128, MAXy = 128;
    int Currentx = 127, Currenty = 127;
    int Energy = 10;

    cgi = cgiInit();

    strcpy(getting, cgiGetValue(cgi, "dir")); 

    input = getting[0];

    if(input == 'N'){
        if(Currenty < (MAXy - 1)){
            ++Currenty;
            --Energy;
        }
        else if(Currenty == (MAXy - 1)){
            Currenty = 0;
            --Energy;
        }
    }

    else if(input == 'S'){
        if(Currenty > 0){
            --Currenty;
            --Energy;
        }
        else if(Currenty == 0){
            Currenty = (MAXy - 1);
            --Energy;
        }
    }

    else if(input == 'E'){
        if(Currentx < (MAXx - 1)){
            ++Currentx;
            --Energy;
        }
        else if(Currentx == (MAXx - 1)){
            Currentx = 0;
            --Energy;
        }
    }

    else if(input == 'W'){
        if(Currentx > 0){
            --Currentx;
            --Energy;
        }
        else if(Currentx == 0){
            Currentx = (MAXx - 1);
            --Energy;
        }
    }

    else{
        Currentx = Currentx;
        Currenty = Currenty;
        --Energy;
    }

    printf("Cordinate<br>X: %d<br>Y: %d<br>Energy: %d\n\n", Currentx, Currenty, Energy);

    return 0;
}
