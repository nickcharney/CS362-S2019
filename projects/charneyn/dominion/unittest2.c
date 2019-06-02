#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

#define FUNC_TEST "drawCard"

int main()
{
   int flag = 0;
   int seed = 1000;
   int numPlayer = 2;
   int thisPlayer = 0;
   struct gameState G, testG;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   printf("Testing %s():\n", FUNC_TEST);

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    drawCard(thisPlayer, &testG);
  
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1){
	printf("Test passed. Player drew a card.\n");
    }
    else{
	printf("Test failed. Player drew %d cards.\n", (testG.handCount[thisPlayer]) - (G.handCount[thisPlayer]));
	flag = 1;
    }

   if (flag == 0){
      printf("All tests passed.\n\n");
   }
   else{
      printf("At least one test failed.\n\n");
   }

   return 0;
}

