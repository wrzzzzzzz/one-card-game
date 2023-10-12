#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "restore.h"
#include "sort.h"

void deal_cards(deck* getpile,deck* discardpile,int c,int d,int n,player *firsty,FILE* logfile){
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    player *first;
    first=firsty;
    if(getpile->numberofcards-n*c<=0){
            restore(getpile,discardpile,logfile);
        }
    for(int g=0;g<n;g++){
        first->in_hand=(card*)malloc((unsigned long long)52*(unsigned long long)d*sizeof(card));
        printf("Player %d:",first->id);
		fprintf(logfile,"Player %d:",first->id);
        for(int y=0;y<c;y++){
            first->in_hand[y]=getpile->pile[0];
            getpile->numberofcards--;
            for(int w=0;w<getpile->numberofcards-1;w++){
                getpile->pile[w]=getpile->pile[w+1];              
            }
            sort(first);
            first->cardsathand++;
        }
        for(int v=0;v<c;v++){
            printf("%s %s, ",suit[first->in_hand[v].suit-1],rank[first->in_hand[v].rank-2]);
			fprintf(logfile,"%s %s, ",suit[first->in_hand[v].suit-1],rank[first->in_hand[v].rank-2]);
        }
        printf("\n");
		fprintf(logfile,"\n");
        first=first->next;       
    }
    first=firsty;
}