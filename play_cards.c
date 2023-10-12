#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "draw.h"
#include "playerbegin.h"

void play_cards(deck* getpile,deck* discardpile,player *first,status *gamestatus,int i,FILE* logfile){
    char suit[100][100]={"Spades","Hearts","Diamonds","Clubs"};
    char rank[150][150]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    int flag=0;
    if(i==0){
        printf("First card:%s %s\n",suit[discardpile->pile[0].suit-1],rank[discardpile->pile[0].rank-2]);
		fprintf(logfile,"First card:%s %s\n",suit[discardpile->pile[0].suit-1],rank[discardpile->pile[0].rank-2]);
    }
    if(discardpile->pile[0].rank==2||discardpile->pile[0].rank==3){
         if(i==0){
            gamestatus->flagattackuseful+=discardpile->pile[0].rank;
        }
        for(int h=0;h<first->cardsathand;h++){
            if(gamestatus->flagattackuseful==0){
                 if(first->in_hand[h].rank==discardpile->pile[0].rank||first->in_hand[h].suit==discardpile->pile[0].suit){
                        if(first->in_hand[h].rank==11){
                            gamestatus->flagskip=5;
                        }
                        if(first->in_hand[h].rank==12){
                            gamestatus->flagcoun+=1;
                        }
                        if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                            gamestatus->flagattackuseful+=first->in_hand[h].rank; 
                        }
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        }
                        printf("Player%d cards:",first->id); 
						fprintf(logfile,"Player%d cards:",first->id);
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s, ",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s, ",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;  
                    }
                }
            else{          
                if(first->in_hand[h].suit==discardpile->pile[0].suit){               
                    if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);  
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        gamestatus->flagattackuseful+=first->in_hand[h].rank; 
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];//first->inhand[h] = first->inhand[h+1];        
                        }
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id); 
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						}
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;
                    }
                    else if(first->in_hand[h].rank==7){ 
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
                        fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
						first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        } 
                        gamestatus->flagattackuseful=0;
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id);
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
                        //getchar();printf("\n");
                        break;                        
                    }
                    else if(first->in_hand[h].rank==11){
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);  
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        } 
                        gamestatus->flagskip=5;
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id); 
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;                       
                    }
                    else if(first->in_hand[h].rank==12){
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
                        fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
						first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        } 
                        gamestatus->flagcoun+=1;
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id); 
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break; 
                    }
                }
            }            
        }
    }
    else if(discardpile->pile[0].rank==11){
        if(i==0){
            flag=1;
            gamestatus->flagskip=4;
        }
        else{
            if(gamestatus->flagattackuseful!=0){
                draw(first,getpile,discardpile,gamestatus,logfile);gamestatus->flagattackuseful=0;flag=1;
            } 
            else{
                for(int h=0;h<first->cardsathand;h++){
                    if(first->in_hand[h].rank==discardpile->pile[0].rank||first->in_hand[h].suit==discardpile->pile[0].suit){
                        if(first->in_hand[h].rank==11){
                            gamestatus->flagskip=5;
                        }
                        if(first->in_hand[h].rank==12){
                            gamestatus->flagcoun+=1;
                        }
                        if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                            gamestatus->flagattackuseful+=first->in_hand[h].rank; 
                        }
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        }
                        printf("Player%d cards:",first->id); 
						fprintf(logfile,"Player%d cards:",first->id);
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;  
                    }
                } 
            }
        }
    }
    else if(discardpile->pile[0].rank==12){
        if(i==0){
            flag=1;
            gamestatus->flagcoun+=1;
            for(int h=0;h<first->cardsathand;h++){
                if(first->in_hand[h].rank==discardpile->pile[0].rank||first->in_hand[h].suit==discardpile->pile[0].suit){
                        if(first->in_hand[h].rank==11){
                            gamestatus->flagskip=5;
                        }
                        if(first->in_hand[h].rank==12){
                            gamestatus->flagcoun+=1;
                        }
                        if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                            gamestatus->flagattackuseful+=first->in_hand[h].rank; 
                        }
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
                        fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]); 
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        } 
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id);
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;  
                }
            }
        }
        else{
             if(gamestatus->flagattackuseful!=0){
                    draw(first,getpile,discardpile,gamestatus,logfile);gamestatus->flagattackuseful=0;flag=1;
                }
            else{
                for(int h=0;h<first->cardsathand;h++){ 
                    if(first->in_hand[h].rank==discardpile->pile[0].rank||first->in_hand[h].suit==discardpile->pile[0].suit){
                        if(first->in_hand[h].rank==11){
                            gamestatus->flagskip=5;
                        }
                        if(first->in_hand[h].rank==12){
                            gamestatus->flagcoun+=1;
                        }
                        if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                            gamestatus->flagattackuseful+=first->in_hand[h].rank;               
                        }
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        } 
                        printf("Player%d cards:",first->id); 
						fprintf(logfile,"Player%d cards:",first->id); 
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;  
                    }
                }
            }
        } 
    }
    else if(discardpile->pile[0].rank!=2&&discardpile->pile[0].rank!=3&&discardpile->pile[0].rank!=11&&discardpile->pile[0].rank!=12){
            for(int h=0;h<first->cardsathand;h++){
                if(first->in_hand[h].rank==discardpile->pile[0].rank||first->in_hand[h].suit==discardpile->pile[0].suit){
                        if(first->in_hand[h].rank==11){
                            gamestatus->flagskip=5;
                        }
                        if(first->in_hand[h].rank==12){
                            gamestatus->flagcoun+=1;
                        }
                        if(first->in_hand[h].rank==2||first->in_hand[h].rank==3){
                            gamestatus->flagattackuseful+=first->in_hand[h].rank;
                        }
                        flag=1;
                        printf("Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
						fprintf(logfile,"Player%d plays:%s %s\n",first->id,suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        first->cardsathand--;discardpile->numberofcards++;
                        for(int r=discardpile->numberofcards-1;r>=1;r--){
                            discardpile->pile[r]=discardpile->pile[r-1];                   
                        }
                        discardpile->pile[0]=first->in_hand[h];
                        for(int f=h;f<first->cardsathand;f++){
                            first->in_hand[f]=first->in_hand[f+1];        
                        }
                        printf("Player%d cards:",first->id);
						fprintf(logfile,"Player%d cards:",first->id);
                        for(int h=0;h<first->cardsathand;h++){
                            printf("%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
							fprintf(logfile,"%s %s,",suit[first->in_hand[h].suit-1],rank[first->in_hand[h].rank-2]);
                        }
                        printf("\n");
						fprintf(logfile,"\n");
                        //getchar();printf("\n");
                        break;  
                }
            } 
        }
    if(flag==0){draw(first,getpile,discardpile,gamestatus,logfile);gamestatus->flagattackuseful=0;}        
}    