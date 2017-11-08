#include <stdio.h>
//#include <cgi.h>
#include <string.h>

enum item{hatchet = 0, axe = 1, chainsaw = 2, chisel = 3, sledge = 4,
  jackhammer = 5, machete = 6, shears = 7};

int inventory[8];

void displayInventory()
{
  printf("Content-Type: text/plain;charset=us-ascii\n\n");
  printf("Hatchets - 15Wh(%d)\n", inventory[hatchet]);
  printf("Axes - 30Wh(%d)\n", inventory[axe]);
  printf("Chainsaws - 60Wh(%d)\n", inventory[chainsaw]);
  printf("Chisels - 5Wh(%d)\n", inventory[chisel]);
  printf("Sledges - 25Wh(%d)\n", inventory[sledge]);
  printf("Jackhammers - 100Wh(%d)\n", inventory[jackhammer]);
  printf("Machetes - 25Wh(%d)\n", inventory[machete]);
  printf("Shears - 35Wh(%d)\n", inventory[shears]);
  return 0;
}

int main(void)
{
  
}
