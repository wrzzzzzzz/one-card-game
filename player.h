#ifndef PLAYER_H
#define PLAYER_H
typedef struct _player{
    int id;
    int score;
	int scorethistime;
    int cardsathand;//number of cards in a person's hand
    card *in_hand;//store each person's cards in an array
    card extra;
    struct _player *next;
    struct _player *prev;
}player;
#endif
