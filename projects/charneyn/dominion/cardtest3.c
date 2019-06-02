#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "Village"

int main() 
{
    int seed = 1000;
    int flag = 0;
    int numPlayer = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("Testing %s card:\n", TESTCARD);

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    testG.hand[thisPlayer][testG.handCount[thisPlayer]] = village;
    testG.handCount[thisPlayer]++;

    cardEffect(village, 0, 0, 0, &testG, testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], 0);
    
    //Tests that player draws exactly one card
    if (G.handCount[thisPlayer] + 1 == testG.handCount[thisPlayer]){
        printf("Test passed. Player drew one card.\n");
    }
    else{
        printf("Test failed. Player did not draw the correct number of cards.\n");
        flag = 1;
    }

    //Tests that player gains exactly 2 actions
    if (G.numActions + 2 == testG.numActions){
        printf("Test passed. Player gained 2 actions.\n");
    }
    else{
        printf("Test failed. Player gained %d actions.\n", testG.numActions);
        flag = 1;
    }

    if(flag == 0){
        printf("All tests passed.\n\n");
    }
    else{
        printf("At lest one test failed.\n\n");
    }

    return 0;
}
