#include "card.h"
#include "player.h"
#include "restore.h"
#ifndef DEAL_CARDS_H
#define DEAL_CARDS_H
void deal_cards(deck* getpile,deck* discardpile,int c,int d,int n,player *firsty,FILE* logfile);
#endif