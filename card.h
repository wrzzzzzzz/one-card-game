#ifndef CARD_H
#define CARD_H
typedef struct _card{
    int rank;
    int suit;
}card;

typedef struct _deck{
    card *pile;//place to store cards
    int numberofcards;
}deck;
#endif
