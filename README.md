# Author: Ruizhe

# basic information

This is a one_card game, the rule is similar to UNO, and it runs in auto mode. users can type in -h or --help to see how to start the game.

# operations

You can follow the following steps when compiling and running.

First, in the command line, type in the word "make" to compile.

Then, type in ”./main“ Following it, type in the things according to the hints learned from help.

Or you may type nothing at all and press enter. The program will run itself with default values.

# files

1. main.c

   The main function that receives command line arguments and calls the function related to game.

   Also,  the logfile is defined in it and called by the functions.

   The getopt is learned in the lab and I refer to the example written by Jiache Zhang TA. Later I revised it into getopt_long.

2. card.h & player.h

   Define the card structure and player structure

3. deal_cards.c & deal_cards.h

   Function that deals the cards to the players when starting a round and its header file.

4. draw.c & draw.h

   Function that let the player draw cards when not being able to play one and its header file.

5. init_then_shuffle.c & init_then_shuffle.h

   The function that initializes decks of cards and shuffle them and its header file. Inside the .c file, the shuffling part is reused if restore is needed later.

6. p2.c & p2.h

   A function that dispatches several game related functions and its header file. It also does most of the initializing work.

7. play_cards.c & play_cards.h

   The function that allows players to play a card(if applicable) according to certain conditions and its header file.

8. playerbegin.c & playerbegin.h

   Create a linkedlist to place the players and decide the first player according to the extra card given to each of them. Together with its header file.

9. restore.c & restore.h

   When the getpile is exhausted, this function throws all the cards in the discardpile into the getpile and shuffles it. Together with its header file.

10. sort.c & sort.h

    After dealing the cards or a player draws a card, this function lets the player place his cards in a certain order. Together with its header file.

11. Makefile

    The file that helps do the compiling work. I refer to the example given by TAs in the announcement.

12. Changelog

    Keeps track of the progress.

13. README

    

    

    

    

    

    











