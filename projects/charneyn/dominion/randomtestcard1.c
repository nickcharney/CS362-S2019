#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main (){
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
        int testSuccess = 0;
        int testFail = 0;
        int tests = 100;
        int i;
        srand(time(NULL));

        printf("Random Tests: Council Room Card");

        for(i = 0; i < tests; i++){
                int player = 0;
                int num_players = rand() % 4 + 1;
                int seed = rand();
                struct gameState *g = malloc(sizeof(struct gameState));

                initializeGame(num_players, k, seed, g);

                g->deckCount[player] = rand() % MAX_DECK;
                g->discardCount[player] = rand() % MAX_DECK;
                g->handCount[player] = rand() % MAX_HAND;
                int initialHand = g->handCount[player];
                g->handCount[1] = rand() % MAX_HAND;
		int opponentHand = g->handCount[1];
                int initialNumBuys = g->numBuys;

                cardEffect(council_room, 0, 0, 0, g, 0, 0);

		if (initialHand + 3 == g->handCount[player] && initialNumBuys + 1 == g->numBuys && opponentHand + 1 == g->handCount[1]){
			testSuccess++;
		}
		else{
			testFail++;
		}
                free(g);
        }
        printf("\nOut of %d games, council room was played successfully %d times and unsuccessfully %d times.\n\n", tests, testSuccess, testFail);
        return 0;
}
