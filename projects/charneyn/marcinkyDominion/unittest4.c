#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

#define FUNC "shuffle"

int main()
{
   int flag = 0;
   int seed = 1000;
   int numPlayer = 2;
   int thisPlayer = 0;
   struct gameState G, testG;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   printf("Testing %s():\n", FUNC);

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    shuffle(thisPlayer, &testG);
    
    //Tests that deckCount doesn't change during shuffle()
    if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]){
        printf("Test passed. The player's deck size was unchanged during the shuffle.\n");
    }
    else{
        printf("Test failed. The player's deck size was changed during the shuffle.\n");
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
