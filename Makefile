all: main

main: main.c deal_cards.c draw.c init_then_shuffle.c p2.c play_cards.c playerbegin.c restore.c sort.c
	gcc main.c deal_cards.c draw.c init_then_shuffle.c p2.c play_cards.c playerbegin.c restore.c sort.c -o main -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c11

clean:
	rm -f main