#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "draw.h"
#include "restore.h"
#include "sort.h"

void draw(player* first,deck* getpile,deck* discardpile,status* gamestatus,FILE* logfile){
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    int flag=0;
    if(getpile->numberofcards<=0){
        restore(getpile,discardpile,logfile);
    }
    if(discardpile->pile[0].rank!=2&&discardpile->pile[0].rank!=3){
        if(gamestatus->flagattackuseful==0){
            if(getpile->numberofcards-gamestatus->flagattackuseful-1<=0){
                restore(getpile,discardpile,logfile);
            }
            first->cardsathand++;getpile->numberofcards--;
            if(flag==0){
                for(int f=first->cardsathand-1;f>0;f--){
                first->in_hand[f]=first->in_hand[f-1];        
            } 
            first->in_hand[0]=getpile->pile[0]; 
            printf("Player%d draws:%s %s\n",first->id,suit[first->in_hand[0].suit-1],rank[first->in_hand[0].rank-2]);
			fprintf(logfile,"Player%d draws:%s %s\n",first->id,suit[first->in_hand[0].suit-1],rank[first->in_hand[0].rank-2]);
            for(int r=0;r<getpile->numberofcards-1;r++){
                getpile->pile[r]=getpile->pile[r+1];
                } 
            } 
        }
        else{
            if(getpile->numberofcards-gamestatus->flagattackuseful<=0){
                restore(getpile,discardpile,logfile);
            }
            first->cardsathand+=gamestatus->flagattackuseful;
            getpile->numberofcards-=gamestatus->flagattackuseful;
            if(flag==0){
            for(int oo=first->cardsathand-1;oo>=gamestatus->flagattackuseful-1;oo--){
                first->in_hand[oo]=first->in_hand[oo-gamestatus->flagattackuseful];
            }
            printf("Player%d draws:",first->id);
			fprintf(logfile,"Player%d draws:",first->id);
            for(int o=0;o<gamestatus->flagattackuseful;o++){
                first->in_hand[o]=getpile->pile[o];
                printf("%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);
				fprintf(logfile,"%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);

            }
            printf("\n");
			fprintf(logfile,"\n");
            for(int qq=0;qq<getpile->numberofcards-1;qq++){
                getpile->pile[qq]=getpile->pile[qq+1];
            }
        }

        }
    }              
    if(discardpile->pile[0].rank==2||discardpile->pile[0].rank==3){
        if(gamestatus->flagattackuseful==0){
            gamestatus->flagattackuseful=1;
            if(getpile->numberofcards-gamestatus->flagattackuseful<=0){
                restore(getpile,discardpile,logfile);
            }
            first->cardsathand+=gamestatus->flagattackuseful;
            getpile->numberofcards-=gamestatus->flagattackuseful;
            if(flag==0){
            for(int oo=first->cardsathand-1;oo>=gamestatus->flagattackuseful-1;oo--){
                first->in_hand[oo]=first->in_hand[oo-gamestatus->flagattackuseful];
            }
            printf("Player%d draws:",first->id);
			fprintf(logfile,"Player%d draws:",first->id);
            for(int o=0;o<gamestatus->flagattackuseful;o++){
                first->in_hand[o]=getpile->pile[o];
                printf("%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);
				fprintf(logfile,"%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);
            }
            printf("\n");
			fprintf(logfile,"\n");
            for(int qq=0;qq<getpile->numberofcards-1;qq++){
                getpile->pile[qq]=getpile->pile[qq+1];
            }
        }
        }
        else{
            if(getpile->numberofcards-gamestatus->flagattackuseful<=0){
                restore(getpile,discardpile,logfile);
            }
           first->cardsathand+=gamestatus->flagattackuseful;
           getpile->numberofcards-=gamestatus->flagattackuseful;
            for(int oo=first->cardsathand-1;oo>=gamestatus->flagattackuseful;oo--){
                first->in_hand[oo]=first->in_hand[oo-gamestatus->flagattackuseful];
            }
            printf("Player%d draws:",first->id);
			fprintf(logfile,"Player%d draws:",first->id);
            for(int o=0;o<gamestatus->flagattackuseful;o++){
                first->in_hand[o]=getpile->pile[o];
                printf("%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);
				fprintf(logfile,"%s %s,",suit[first->in_hand[o].suit-1],rank[first->in_hand[o].rank-2]);
            }
            printf("\n");
			fprintf(logfile,"\n");
            for(int qq=0;qq<getpile->numberofcards-gamestatus->flagattackuseful;qq++){
                getpile->pile[qq]=getpile->pile[qq+gamestatus->flagattackuseful];
            } 
        }     
    }
    printf("Player%d cards:",first->id);
	fprintf(logfile,"Player%d cards:",first->id);
        sort(first);
        for(int h=0;h<first->cardsathand;h++){
           printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
		   fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
    }
    printf("\n");
	fprintf(logfile,"\n");
}