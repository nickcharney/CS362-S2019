#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "Adventurer"

int main() 
{
    int i;
    int seed = 1000;
    int flag = 0;
    int numPlayer = 2;
    int thisPlayer = 0;
    int newCard1, newCard2;
    int testCount = 0;
    int controlCount = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("Testing %s card:\n", TESTCARD);

    initializeGame(numPlayer, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    testG.hand[thisPlayer][testG.handCount[thisPlayer]] = adventurer;
    testG.handCount[thisPlayer]++;

    //Tests that Adventurer draws 2 treasure cards
    cardEffect(adventurer, 0, 0, 0, &testG, testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], 0);

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
       newCard1 = testG.hand[thisPlayer][i];
       if (newCard1 == copper || newCard1 == silver || newCard1 == gold){
          testCount++;
       }
    }
    for (i = 0; i < G.handCount[thisPlayer]; i++) {
       newCard2 = G.hand[thisPlayer][i];
       if (newCard2 == copper || newCard2 == silver || newCard2 == gold){
          controlCount++;
       }
    }
    if ((testCount - controlCount) > 0 && (testCount - controlCount) < 3){
       printf("Test passed. Exactly 2 treasure cards were drawn.\n");
    }
    else{
      printf("Test failed. %d treasure cards were drawn.\n", (testCount - controlCount));
      flag = 1;
    }

    //Tests that the new treasure cards were added to the player's hand
    if (G.handCount[thisPlayer] < testG.handCount[thisPlayer]){
       printf("Test passed. Drwan cards were added to test hand.\n");
    }
    else{
      printf("Test failed. No additional cards were added to test hand.\n");
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
