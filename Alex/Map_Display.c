/*
 * CS300: Frupal Project
 * Team G
 * Written by: Alexander Mason
 * File: Map_Display.c
 */

#include "Map_Display.h"

char name[20];
s_cgi *cgi;     //Define a pointer of type s_cgi, call it cgi

    //Whether a space should be visible. 
    //Default set to not-visible

    //A terrain ID indicating what type of terrain the map cell is:
    //0=meadow, 1=forest, 2=water, 3=wall, 4=bog, 5=swamp
    //Default set to meadow

    //A content string indicating what is on this map cell:
    //Tree, Boulder, Blackberry Bushes, Power Bar, Type 1 Treasure Chest
    //Type 2 Treasure Chest, Royal Diamonds, Clue, Hatchet, Axe, Chainsaw
    //Chisel, Sledge, Jackhammer, Machete, Shears, Binoculars, None
    //Default set to None

void main(void){
    printf("Content-Type: text/html;charset=us-ascii\n\n");
    struct map gameMap = makeMap("alex_test_map.txt");
    /*
    printf("<form action='https://web.cecs.pdx.edu/~masonal/FrupalTeamG/Alex/Display.cgi'>");
    printf("    <input type='submit' value='run cgi'>");
    printf("</form>");
    */
    drawMap(gameMap);
}

//Generate the map
void drawMap(struct map updMap){
    printf("<html>\n");
    printf("<head>\n");
    printf("    <style>\n");
    printf("        .map{\n");
    printf("            position:relative;\n");
    printf("            width:%d;\n", updMap.dimensions * 32);
    printf("            height:%d;\n", updMap.dimensions * 32);
    printf("            background-color:saddlebrown;\n");
    printf("            border:8px solid black;\n");
    printf("            margin:auto;}\n");
    printf("        .cell{\n");
    printf("            text-align:center;\n");
    printf("            width:32px;\n");
    printf("            height:32px;\n");
    printf("            color:white;\n");
    printf("            float:left;\n");
    printf("            outline:none !important;}\n");
    printf("        .object{\n");
    printf("            position:relative;\n");
    printf("            width:32px;\n");
    printf("            height:32px;\n");
    printf("            outline:none !important;\n");
    printf("            float:left;\n");
    printf("            z-index:3;}\n");
    printf("        .terrain{\n");
    printf("            position:relative;\n");
    printf("            width:32px;\n");
    printf("            height:32px;\n");
    printf("            outline:none !important;\n");
    printf("            float:left;\n");
    printf("            z-index:1;}\n");
   // printf("            left:0;\n");
   // printf("            right:0;\n");
   // printf("            position:relative;}\n");
    printf("        #player{\n");
    printf("            position:relative;}\n");
    printf("    </style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("    <div>\n");
    printf("        <div class='map'>\n");
    //Draw each individual cell
    if(updMap.cells[0] != NULL){
        for(int i = 0; i < updMap.dimensions; ++i){
            for(int j = 0; j < updMap.dimensions; ++j){
                printf("\t\t\t<div class='cell'><img class='terrain' src='assets/");
                /*
                if(updMap.cells[i][j].isVisible == 0){
                    printf("fog.gif'>");
                }
                else{
                */
                //Draw the underlying terrain on z-index 1
                    switch(updMap.cells[i][j].terrain){
                        case 0:{   //Draw a meadow tile
                                   printf("meadow.png'>");
                                   break;
                               }
                        case 1:{   //Draw a forest tile
                                   printf("forest.jpg'>");
                                   break;
                               }
                        case 2:{   //Draw a water tile
                                   printf("water.jpg'>");
                                   break;
                               }
                        case 3:{   //Draw a wall tile 
                                   printf("wall.jpg'>");
                                   break;
                               }
                        case 4:{   //Draw a bog tile
                                   printf("bog.png'>");
                                   break;
                               }
                        case 5:{   //Draw a swamp tile
                                   printf("swamp.png'>");
                                   break;
                               }
                        default:
                               break;
                    }
                //Draw the object on top of the terrain on z-index 2
                printf("<img class='object' src='assets/");
                    switch(updMap.cells[i][j].terrain){
                        case 0:{   //Draw no object 
                                   printf("tree.png'>");
                                   break;
                               }
                        case 1:{   //Draw a tree
                                   printf("tree.png'>");
                                   break;
                               }
                        case 2:{   //Draw a black berry bush
                                   printf("diamond.png'>");
                                   break;
                               }
                        case 3:{   //Draw a power bar
                                   printf("tree.png'>");
                                   break;
                               }
                        case 4:{   //Draw a Type 1 Treasure Chest
                                   printf("tree.png'>");
                                   break;
                               }
                        case 5:{   //Draw a Type 2 Treasure Chest
                                   printf("tree.png'>");
                                   break;
                               }
                        case 6:{   //Draw the royal diamonds
                                   printf("diamond.png'>");
                                   break;
                               }
                        case 7:{   //Draw a clue
                                   printf("clue.png'>");
                                   break;
                               }
                        default:
                               break;
                    }
                //Draw the player character if they are on this cell
                /*
                if(
                printf("\t\t\t<div class='cell'><img id='player' src='assets/");
                */
                //}
                printf("</div>\n");
            }
        }
    }
    else{
        printf("\n\nTHE MAP IS NOT THERE\n\n");
    }
    printf("        </div>"); 
    printf("    </div>"); 
    printf("</body>"); 
    printf("</html>");
}
