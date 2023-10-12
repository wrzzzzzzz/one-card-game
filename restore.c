#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "deal_cards.h"
#include "draw.h"
#include "init_then_shuffle.h"
#include "play_cards.h"
#include "playerbegin.h"

void restore(deck* getpile,deck* discardpile,FILE* logfile){
    printf("Getpile exhausted; start restoring. \n");
	fprintf(logfile,"Getpile exhausted; start restoring. \n");
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    getpile->numberofcards+=discardpile->numberofcards;
    for(int w=getpile->numberofcards-1;w>=discardpile->numberofcards;w--){
        getpile->pile[w]=getpile->pile[w-discardpile->numberofcards];
    }
    for(int u=0;u<discardpile->numberofcards;u++){
        getpile->pile[u]=discardpile->pile[u];
    }
    discardpile->numberofcards=0;
    card tempa;
    srand((unsigned int)time(NULL));
    for(int j=0;j<getpile->numberofcards;j++){
        int t=rand()%(getpile->numberofcards);
        tempa=getpile->pile[t];   
        getpile->pile[t]=getpile->pile[j];
        getpile->pile[j]=tempa; 
    }
    for(int j=0;j<getpile->numberofcards;j++){
    printf("%s%s ", suit[getpile->pile[j].suit-1], rank[getpile->pile[j].rank-2]);
	fprintf(logfile,"%s%s ", suit[getpile->pile[j].suit-1], rank[getpile->pile[j].rank-2]);
    }
	printf("\n");
	fprintf(logfile,"\n");
}
