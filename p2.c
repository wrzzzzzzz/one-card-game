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
#include "restore.h"

void p2(FILE* logfile,int n,int c,int d,int r){
    int flagcontinue=0;
    int i=0;
    deck discardpile;
    deck getpile;
    player *firsty=NULL;
	player *ultimate=NULL;
	player *temp=NULL;player* temp2=NULL;

    status *gamestatus;
    gamestatus=(status*)malloc(sizeof(status));
    gamestatus->flagcoun=2;//default:odd numbers
    gamestatus->flagskip=4;//default:5
    gamestatus->flagattackuseful=0;//sum up the attacks useful
    //initialize status

    getpile.numberofcards=52*d;
    getpile.pile=(card*)malloc((unsigned long long)52*(unsigned long long)d*sizeof(card));
    discardpile.pile=(card*)malloc((unsigned long long)52*(unsigned long long)d*sizeof(card));
    discardpile.numberofcards=0;

    firsty=circle(n,firsty);
    printf("\n########################\n#                      #\n# Welcome to One Card! #\n#                      #\n########################\n");
	fprintf(logfile,"\n########################\n#                      #\n# Welcome to One Card! #\n#                      #\n########################\n");
    //getchar();printf("\n");
    printf("\n---- Initial setup ----\nNumber of rounds: %d\nNumber of decks: %d\nNumber of players: %d",r,d,n);
	fprintf(logfile,"\n---- Initial setup ----\nNumber of rounds: %d\nNumber of decks: %d\nNumber of players: %d",r,d,n);
    //getchar();printf("\n");
    printf("\n\nShuffling cards...\nShuffle result:\n");
	fprintf(logfile,"\n\nShuffling cards...\nShuffle result:\n");
    init_then_shuffle(&getpile,d,logfile);
    //getchar();printf("\n");
    for(int round=0;round<r; round++){
		printf("\n\nDealing cards...\n");
		fprintf(logfile,"\n\nDealing cards...\n");
        deal_cards(&getpile,&discardpile,c,d,n,firsty,logfile);
        //getchar();printf("\n");
        printf("\nDetermining the playing order...\n");
		fprintf(logfile,"\nDetermining the playing order...\n");
        firsty=decide_the_first(firsty,n,&getpile,&discardpile,logfile);
        printf("The game will start with player%d\n\n",firsty->id);
		fprintf(logfile,"The game will start with player%d\n\n",firsty->id);
        //getchar();printf("\n");
        for(int i=discardpile.numberofcards;i>0;i--){
            discardpile.pile[i]=discardpile.pile[i-1];
        }
        discardpile.pile[0]=getpile.pile[0];
        discardpile.numberofcards++;getpile.numberofcards--;
        for(int u=0;u<getpile.numberofcards;u++){
            getpile.pile[u]=getpile.pile[u+1];
        }
        player* first=firsty;
		printf("----Round%d starts----\n",round+1);
		fprintf(logfile,"----Round%d starts----\n",round+1);
        while(flagcontinue==0){
            play_cards(&getpile,&discardpile,first,gamestatus,i,logfile);
            if(gamestatus->flagcoun%2!=0){
                if(gamestatus->flagskip==5){
                    first=first->prev->prev;
                    gamestatus->flagskip=4;
                }
                else{
                first=first->prev;
                }           
            }
            else if(gamestatus->flagskip==5){
                first=first->next->next;
                gamestatus->flagskip=4;
            }
            else{
            first=first->next;  
            }
            player* firstyy=first;
            for(int y=0;y<n;y++){
                if(first->cardsathand==0){
                    flagcontinue=1;
                    printf("Player %d wins the round!\n\n",first->id);
					fprintf(logfile,"Player %d wins the round!\n\n",first->id);
                    break;  
                }
                first=first->next;
            }
            first=firstyy;
            i++;
        }
        for(int i=0;i<n;i++){
			first->scorethistime=-first->cardsathand;
            first->score-=(first->cardsathand);
            first=first->next;
        }
        for(int j=0;j<n;j++){
            discardpile.numberofcards+=first->cardsathand;
            for(int i=discardpile.numberofcards-1;i>=first->cardsathand;i--){
                discardpile.pile[i]=discardpile.pile[i-first->cardsathand];
            }
            for(int i=0;i<first->cardsathand;i++){
                discardpile.pile[i]=first->in_hand[i];
            }
            first->cardsathand=0;
            first=first->next;
        }
        flagcontinue=0;
        printf("---- Stats ----\nRound %d result:\n",round+1);
		fprintf(logfile,"---- Stats ----\nRound %d result:\n",round+1);
		for(int p=0;p<n;p++){
			printf("Player%d: %d, total: %d\n",first->id,first->scorethistime,first->score);
			fprintf(logfile,"Player%d: %d, total: %d\n",first->id,first->scorethistime,first->score);
			first=first->next;
		}
		printf("Round %d ends.\n",round+1);
		fprintf(logfile,"Round %d ends.\n",round+1);
		ultimate=first;
		temp=ultimate;
    }
	printf("\n---- Final game result ----\n");
	fprintf(logfile,"\n---- Final game result ----\n");
	for(int p=0;p<n;p++){
		if(ultimate->score>temp->score){
			temp=ultimate;			
		}
		ultimate=ultimate->next;
		temp2=temp;
	}
	ultimate=temp2;
	printf("The final winner is player%d!\n",ultimate->id);
	fprintf(logfile,"The final winner is player%d!\n",ultimate->id);
    free(getpile.pile);
    free(discardpile.pile);
    for(int y=0;y<n;y++){
        firsty=firsty->next;
        free(firsty);
    }
    free(gamestatus);
}


