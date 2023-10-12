#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "player.h"

void sort(player* first){
    card temp3;
    for(int g=0;g<first->cardsathand;g++){
        for(int nn=g+1;nn<first->cardsathand;nn++){
            if(first->in_hand[g].suit>first->in_hand[nn].suit){
                temp3=first->in_hand[nn];
                first->in_hand[nn]=first->in_hand[g];
                first->in_hand[g]=temp3;
            }
            else if(first->in_hand[g].suit==first->in_hand[nn].suit){
                if(first->in_hand[g].rank>first->in_hand[nn].rank){
                temp3=first->in_hand[nn];
                first->in_hand[nn]=first->in_hand[g];
                first->in_hand[g]=temp3;
                }
            }
        }
    }
}