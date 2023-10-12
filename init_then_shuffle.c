#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"

void init_then_shuffle(deck* getpile,int d,FILE* logfile){//initialize decks
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    getpile->numberofcards=52*d;
    int t;
    int kind1[4]={1,2,3,4};
    int kind2[13]={2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int x=0;x<52*d;x++){
        getpile->pile[x].suit=kind1[((int)floor(x/13))%4];
        getpile->pile[x].rank=kind2[x%13];
    }
    card temp1;
    srand((unsigned int)time(NULL));
    for(int j=0;j<52*d;j++){
        t=rand()%(52*d);
        temp1=getpile->pile[t];   
        getpile->pile[t]=getpile->pile[j];
        getpile->pile[j]=temp1; 
    }
    for(int j=0;j<52*d;j++){
    printf("%s%s ", suit[getpile->pile[j].suit-1], rank[getpile->pile[j].rank-2]);
	fprintf(logfile,"%s%s ", suit[getpile->pile[j].suit-1], rank[getpile->pile[j].rank-2]);
    }
}