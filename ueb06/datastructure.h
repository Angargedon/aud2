#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXPLAYER 23

typedef struct{
    int Day;
    int Month;
    int Year;
}sDate;

typedef struct{
    char *name;
    sDate *birthday;
    int playernumber;
    int goals;
}sPlayer;

typedef struct sT{
    char *teamName;
    char *trainerName;
    int playerAmount;
    sPlayer player[MAXPLAYER];
    struct sT *prev;
    struct sT *next;
}sTeam;

extern int Teamcounter;
extern sTeam *first;
extern sTeam *last;

#endif