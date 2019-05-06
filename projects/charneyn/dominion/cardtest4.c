#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "Council Room"

int main() 
{
    int i;
    int seed = 1000;
    int flag = 0;
    int numPlayer = 4;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("Testing %s card:\n", TESTCARD);

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    testG.hand[thisPlayer][testG.handCount[thisPlayer]] = council_room;
    testG.handCount[thisPlayer]++;

    cardEffect(council_room, 0, 0, 0, &testG, testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], 0);

    //Tests that player 1 draws 4 cards.
    if (G.handCount[thisPlayer] + 4 == testG.handCount[thisPlayer]){
        printf("Test passed. Player 1 drew 4 cards.\n");
    }
    else{
        printf("Test failed. Player 1 drew %d cards.\n", (testG.handCount[thisPlayer]) - (G.handCount[thisPlayer]));
        flag = 1;
    }

    //Tests that player 1 gains 1 buy
    if (G.numBuys + 1 == testG.numBuys){
        printf("Test passed. Player 1 gained 1 buy.\n");
    }
    else{
        printf("Test failed. Player 1 gained %d buys.\n", testG.numBuys);
        flag = 1;
    }

    //Tests that other players gain 1 card
    for (i = 1; i < numPlayer; i++){
        if (G.handCount[i] + 1 == testG.handCount[i]){
            printf("Test passed. Player %d drew 1 card.\n", (i + 1));
        }
        else{
            printf("Test failed. Player %d did not draw 1 card.\n", (i + 1));
            flag = 1;
        }
    }

  if(flag == 0){
    printf("All tests passed.\n\n");
  }
  else{
    printf("At least one test failed.\n\n");
  }

    return 0;
}
