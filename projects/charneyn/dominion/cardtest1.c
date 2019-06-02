#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "Smithy"

int main() 
{
    int seed = 1000;
    int flag = 0;
    int numPlayer = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("Testing %s card:\n", TESTCARD );

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    testG.hand[thisPlayer][testG.handCount[thisPlayer]] = smithy;
    testG.handCount[thisPlayer]++;

    // Tests that Smithy draws 3 cards
    cardEffect(smithy, 0, 0, 0, &testG, testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], 0);

    if (G.handCount[thisPlayer] + 3 == testG.handCount[thisPlayer]){
        printf("Test passed. Player drew 3 new cards.\n");
    }
    else{
        printf("Test failed. Player drew %d new cards.\n", (testG.handCount[thisPlayer]) - (G.handCount[thisPlayer]));
        flag = 1;
    }

  if(flag == 0){
    printf("All tests passed.\n\n");
  }
  else{
    printf("At least one test failed.\n\n");
  }

    return 0;
}
