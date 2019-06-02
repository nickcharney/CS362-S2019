#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

#define FUNC "whoseTurn"
#define NUM_TURNS 5

int main()
{
   int i;
   int turn = 0;
   int result = 0;
   int flag = 0;
   struct gameState G;

   printf("Testing %s():\n", FUNC);

   //Checks for "whoseTurn" match for NUM_TURNS times
   for (i = 0; i < NUM_TURNS; i++){
      G.whoseTurn = turn;
      result = whoseTurn(&G);

      if (result == turn){
         printf("Test #%d passed. Expected turn matches whoseTurn().\n", i + 1);
      }
      else{
         printf("Test %d failed. Expected turn: %d, whoseTurn(): %d\n", i + 1, turn, result);
         flag = 1;
      }
      turn++;
   }

   if (flag == 0){
      printf("All tests passed.\n\n");
   }
   else{
      printf("At least one test failed.\n\n");
   }

   return 0;
}
