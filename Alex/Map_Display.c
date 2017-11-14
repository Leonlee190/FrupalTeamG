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

const int PLAYER_X = 2;
const int PLAYER_Y = 1;

void main(void){
    printf("Content-Type: text/html;charset=us-ascii\n\n");
    struct map gameMap = makeMap("alex_test_map.txt");
    /*
    printf("<form action='https://web.cecs.pdx.edu/~masonal/FrupalTeamG/Alex/Display.cgi'>");
    printf("    <input type='submit' value='run cgi'>");
    printf("</form>");
    */
    setVisible(PLAYER_X, PLAYER_Y, gameMap);
    drawMap(gameMap);
}


/*  Set the visibility of the p
 *  Input:
 *      int playerX:        The X coordinate of the player on the map
 *      int playerY:        The Y coordinate of the player on the map
 *      struct map updMap:  The map generated from a file 
 */
void setVisible(int playerX, int playerY, struct map updMap){
    for(int i = playerX - 1; i <= playerX + 1; ++i){
        for(int j = playerY - 1; j <= playerY + 1; ++j){
            updMap.cells[i][j].isVisible = 1;
        }
    }
}


/*  Generate and output the html for displaying the map
 *  Input:
 *      struct map updMap: The map generated from a file 
 */
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
    printf("            margin-top:-32px;\n");
    printf("            position:relative;\n");
    printf("            width:32px;\n");
    printf("            height:32px;\n");
    printf("            outline:none !important;\n");
    printf("            float:left;\n");
    printf("            z-index:2;}\n");
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
    printf("            margin-top:-32px;\n");
    printf("            position:relative;\n");
    printf("            z-index:3;}\n");
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
                if(updMap.cells[i][j].isVisible == 0){
                    printf("fog.gif'>");
                }
                else{
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
                    //Draw the objects on top of the terrain
                    drawObjects(i, j, updMap);
                    //Draw the player character if they are on this cell on z-index 3
                    if(comparePlayerToCoor(i, j)){
                        printf("\t\t\t<div class='cell'><img id='player' src='assets/player.png'></div>\n");
                    }
                }
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


/*  Determines if the player is at this location on the map
 *  Input:
 *      cellX:  An X coordinate from the map
 *      cellY:  A Y coordinate from the map
 *  Output:
 *      true:   The player's coordinates match cellX and cellY
 *      false:  The player's coordinates do not match cellX and cellY
 */
bool comparePlayerToCoor(int cellX, int cellY){
    //STUB
    bool here = false;
    if(cellX == PLAYER_X && cellY == PLAYER_Y)
        here = true;
    return here;
}



/*  Draws the objects of the map on top of the terrain
 *  Input:
 *      i:  [FILL] 
 *      j:  [FILL]
 *  Output:
 *      N/A
 */
void drawObjects(int i, int j, struct map updMap){
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
                                   printf("bush.png'>");
                                   break;
                               }
                        case 3:{   //Draw a power bar
                                   printf("powerbar.png'>");
                                   break;
                               }
                        case 4:{   //Draw a Type 1 Treasure Chest
                                   printf("chest1.png'>");
                                   break;
                               }
                        case 5:{   //Draw a Type 2 Treasure Chest
                                   printf("chest2.png'>");
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
}
