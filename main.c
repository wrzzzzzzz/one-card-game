#include <stdio.h>
#include <math.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "deal_cards.h"
#include "draw.h"
#include "init_then_shuffle.h"
#include "play_cards.h"
#include "playerbegin.h"
#include "p2.h"

int main(int argc, char* argv[])
{
    int opt;
	char* filename = "onecard.log";
    int option_index = 0;
    char *string ="hl:n:c:d:r:a";
    int n=4;int c=5;int d=2;int r=1;
    static struct option long_options[] =
    {  
        {"help",no_argument,NULL,'h'},
        {"log",required_argument, NULL, 'l'},
        {"player-number",required_argument,NULL,'n'},
        {"initial-cards",required_argument,NULL,'c'},
        {"decks",required_argument,NULL,'d'},
        {"rounds",required_argument,NULL,'r'},
        {"auto",no_argument,NULL,'a'},
    }; 
    while((opt=getopt_long(argc,argv,string,long_options,&option_index))!=-1)
    {
        switch (opt)
        {
        case 'h':
           printf("-h|--help print this help message\n--log filename write the logs in filename (default: onecard.log)\n-n n|--player-number=n n players, n must be larger than 2 (default: 4)\n-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)\n-d d|--decks=d use d decks 52 cards each, d must be at least 2 (default: 2)\n-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)\n-a|--auto run in demo mode\n");
           return 0;
           break;
		case 'l':
			filename=optarg;
			break;
        case 'n':
           n=atoi(optarg);
           if(n>2){
           printf("%d players\n",atoi(optarg));
           }
           else{
               n=4;
               printf("%d players\n",n);
           }
           break;
        case 'c':
            c=atoi(optarg);
            if(c>=2){
            printf("Deal %d cards per player.\n",atoi(optarg));
            }
            else{
                c=5;
                printf("Deal %d cards per player.\n",c);
            }
            break;
        case 'd':
            d=atoi(optarg);
            if(d>=2){
            printf("The game uses %d decks 52 cards each.\n",atoi(optarg));
            }
            else{
                d=2;
                printf("The game uses %d decks 52 cards each.\n",d);
            }
            break;
        case 'r':
            r=atoi(optarg);
            if(r>=1){
            printf("Play %d rounds.\n",atoi(optarg));
            }
            else{
                r=1;
                printf("Play %d rounds.\n",r);
            }
            break;
        case 'a':
           printf("Run in demo mode.\n");
           break;
        default:       
           break;
        }
    }
	FILE* logfile;
	logfile=fopen(filename,"w+");
    p2(logfile,n,c,d,r);
	fclose(logfile);
}

