#ifndef TEAMS_H
#define TEAMS_H
#include "datastructure.h"

/*Prints input-calls to create a team and includes it in the datastructure.*/
void createTeam();

/*Prints a list of teams with numeric input to be deleted.*/
void deleteTeam();

void searchPlayer();

/*User gets to choose by which factor the players of a team gets sorted.*/
void sortTeams();

/*Prints a list with each team and players.*/
void listOneTeam(sTeam *);
void listTeams();

/*Frees the allocated data. Recommended at end of program or in similar function.*/
void freeTeams();

#endif