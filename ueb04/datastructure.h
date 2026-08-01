#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXPLAYER 23
#define MAXTEAMS 10

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

typedef struct{
    char *teamName;
    char *trainerName;
    int playerAmount;
    sPlayer player[MAXPLAYER];
}sTeam;

extern int Teamcounter;
extern sTeam Teams[];

#endif