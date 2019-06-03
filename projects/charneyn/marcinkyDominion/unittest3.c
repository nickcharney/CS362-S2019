#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

#define FUNC "discardCard"

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

    discardCard(mine, thisPlayer, &testG, 0);
    
    //Tests that the player's hand decremented
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] - 1){
        printf("Test passed. Player discarded a card.\n");
    }
    else{
        printf("Test failed. Player discarded %d cards.\n", (G.handCount[thisPlayer]) - (testG.handCount[thisPlayer]));
        flag = 1;
    }

    //Tests that the player's played card count incremented
    if(testG.playedCardCount == G.playedCardCount + 1){
        printf("Test passed. Player's played card count increased by 1.\n");
    }
    else{
        printf("Test failed. Player's played card count increased by %d\n", (G.playedCardCount - testG.playedCardCount));
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

