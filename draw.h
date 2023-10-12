#include "card.h"
#include "player.h"
#include "playerbegin.h"
#include "restore.h"
#include "sort.h"
#ifndef DRAW_H
#define DRAW_H
void draw(player* first,deck* getpile,deck* discardpile,status* gamestatus,FILE* logfile);
#endif