#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "playerbegin.h"
#include "restore.h"
player* circle(int n,player* firsty){
    player *prev=NULL;
    player *current;
    for(int i=0;i<n;i++){
        current=(player*)malloc(sizeof(player));
        current->id=i+1;
        current->score=0;
        current->cardsathand=0;
        current->prev=prev;
        if(i==0){
            firsty=current;//save the place of the first player         
        }
        prev=current;      
    }
    firsty->prev=prev;
    for(int j=0;j<n;j++){
        current->prev->next=current;
        current=current->prev;
    }
    return firsty;
}

player* decide_the_first(player* firsty,int n,deck* getpile,deck* discardpile,FILE* logfile){
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    player* first;
    first=firsty;
    int temp0=0;int temp=0;
    player* tempy=first;
    if(getpile->numberofcards-n<=0){
        restore(getpile,discardpile,logfile);
    }
    for(int p=0;p<n;p++){
        first->extra=getpile->pile[0];
        getpile->numberofcards--;
        for(int w=0;w<getpile->numberofcards;w++){
                getpile->pile[w]=getpile->pile[w+1];              
        }
        first=first->next;
    }
    for(int p=0;p<n;p++){
        if(first->extra.suit>temp0){
            tempy=first;
            temp0=first->extra.suit;
            temp=first->extra.rank;
        }
        else if(first->extra.suit==temp0){
            if(first->extra.rank>temp){
                tempy=first;
                temp=first->extra.rank; 
            }
        }
        printf("Player%d: %s %s\n",first->id,suit[first->extra.suit-1],rank[first->extra.rank-2]);
		fprintf(logfile,"Player%d: %s %s\n",first->id,suit[first->extra.suit-1],rank[first->extra.rank-2]);
        first=first->next; 
    }
    first=tempy;
    discardpile->numberofcards+=n;
    for(int w=discardpile->numberofcards-1;w>n-1;w--){
        discardpile->pile[w]=discardpile->pile[w-n];
    }
    for(int q=0;q<n;q++){
    discardpile->pile[q]=first->extra;
    first=first->next;
    }  
    return first;
}