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

        printf("Random Tests: Adventurer Card");
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
		int opponentHand = g->handCount[1] = rand() % MAX_HAND;
		int opponentsDeck = g->deckCount[1] = rand() % MAX_DECK;
		int coinCount = 0;
		int j; 
	
		for(j = 0 ; j < g->handCount[player]; j++){
			if((g->hand[player][j] == copper) || (g->hand[player][j] == silver) || (g->hand[player][j] == gold)){
				coinCount--;
			}
		}

		cardEffect(adventurer, 0, 0, 0, g, 0, 0);
	
		for(j = 0 ; j < g->handCount[player]; j++){
			if((g->hand[player][j] == copper) || (g->hand[player][j] == silver) || (g->hand[player][j] == gold)){
				coinCount++;
			}
		}

		if(coinCount > 0 && (initialHand + 1) == g->handCount[player] && opponentHand == g->handCount[1] && opponentsDeck == g->deckCount[1]){
			testSuccess++;
		}
		else{
			testFail++;
		}
		free(g);
	}
	printf("\nOut of %d games, adventurer was played successfully %d times and unsuccessfully %d times.\n\n", tests, testSuccess, testFail);

	return 0;
}
