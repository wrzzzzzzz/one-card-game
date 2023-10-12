#ifndef PLAYERBEGIN_H
#define PLAYERBEGIN_H
player* circle(int n,player* firsty);
player* decide_the_first(player* firsty,int n,deck* getpile,deck* discardpile,FILE* logfile);
typedef struct _status{
    int flagcoun;
    int flagskip;
    int flagattackuseful;
}status;
#endif
