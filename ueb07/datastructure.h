#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXPLAYER 23
#define MAXINDEX 307

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

typedef struct sLE{
    sTeam *tData;
    sPlayer *pData;
    struct sLE *next;
}sListElement;

typedef struct{
    sListElement *first;
    sListElement *last;
}sHashTableElement;

extern sHashTableElement playerIndex[];
extern int Teamcounter;
extern sTeam *first;
extern sTeam *last;

#endif