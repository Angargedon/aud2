#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"

void savePlayer(FILE *file, sPlayer *player){
    fprintf(file, "  <Player>\n   <Name>%s</Name>\n", player->name);
    if(player->birthday) fprintf(file, "   <Birthday>%02i.%02i.%04i</Birthday>\n", player->birthday->Day, player->birthday->Month, player->birthday->Year);
    fprintf(file, "   <TricotNr>%i</TricotNr>\n", player->playernumber);
    fprintf(file, "   <Goals>%i</Goals>\n", player->goals);
    fprintf(file, "  </Player>\n");
}

void saveTeam(FILE *file, sTeam *team){
    int i;

    fprintf(file," <Team>\n  <Name>%s</Name>\n", team->teamName);
    if(team->trainerName) fprintf(file, "  <Trainer>%s</Trainer>\n", team->trainerName);
    for(i = 0; i < (team->playerAmount); i++) savePlayer(file, &(team->player[i]));
    fprintf(file, " </Team>\n");
}

void save(){
    FILE *file = fopen("teams.xml", "wt");
    int i;

    if(file){
        if(Teamcounter > 0){
            fprintf(file, "<Data>\n");
            for(i = 0; i < Teamcounter; i++) 
                saveTeam(file, &(Teams[i]));
            fprintf(file, "</Data>");
        }
        fclose(file);
    }
    else{
        enter(1);
        printf("Datei konnte nicht geoeffnet werden. Mach mal richtige..");
        waitForEnter();
    }
}

int loadPlayer(FILE *loadFile){
    char row[101];
    char *startRow;
    unsigned len;

    
    do{
        fscanf(loadFile, "%100[^\n\r]", row);
        fclearBuffer(loadFile);
        startRow = row;

        while(*startRow == ' ' || *startRow == 9) startRow++;

        if(strncmp(startRow, "<Name>", 6) == 0){
            len = strlen(startRow + 6) - 7;
            if(len > 1000) len = 0;
            

            if(strncmp(startRow + 6 + len, "</Name>", 7) == 0){
                Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].name = calloc(len+1, sizeof(char));

                if(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].name) strncpy(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].name, startRow+6, len);
                else return 0;
            }
        }
        if(strncmp(startRow, "<Birthday>", 10) == 0){
            len = strlen(startRow + 10) - 11;
            if(len > 1000) len = 0;

            if(strncmp(startRow + 10 + len, "</Birthday>", 11) == 0){
                Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].birthday = malloc(sizeof(sDate));
                if(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].birthday) getDateFromString(startRow + 10, Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].birthday);
            }
        }
        if(strncmp(startRow, "<TricotNr>", 10) == 0){
            len = strlen(startRow + 10) - 11;
            if(len > 1000) len = 0;

            if(strncmp(startRow + 10 + len, "</TricotNr>", 11) == 0){
                Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].playernumber = atoi(startRow+10);
            }
        }
        if(strncmp(startRow, "<Goals>", 7) == 0){
            len = strlen(startRow + 7) - 8;
            if(len > 1000) len = 0;

            if(strncmp(startRow + 7 + len, "</Goals>", 8) == 0){
                Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].goals = atoi(startRow+7);
            }
        }
        if(feof(loadFile)) break;
    }while(strncmp(startRow, "</Player>", 9) != 0);
    return 1;
}

int loadTeam(FILE *loadFile){
    char row[101];
    char *startRow;
    Teams[Teamcounter].playerAmount = 0;
    unsigned len;

    do{
        fscanf(loadFile, "%100[^\n\r]", row);
        fclearBuffer(loadFile);
        startRow = row;

        while(*startRow == ' ' || *startRow == 9) startRow++;

        if(strncmp(startRow, "<Name>", 6) == 0){
            len = strlen(startRow + 6) - 7;

            if(len == 0) return 0;

            if(strncmp(startRow + 6 + len, "</Name>", 7) == 0){
                Teams[Teamcounter].teamName = calloc(len+1, sizeof(char));

                if(Teams[Teamcounter].teamName) 
                    strncpy(Teams[Teamcounter].teamName, startRow+6, len);
                else{
                    printf("\nKein Speicher fuer Name");
                    return 0;
                }
            }
        }
        if(strncmp(startRow, "<Trainer>", 9) == 0){
            len = strlen(startRow + 9) - 10;
            if(len > 1000) len = 0;
            
            if(strncmp(startRow + 9 + len, "</Trainer>", 10) == 0){
                Teams[Teamcounter].trainerName = calloc(len+1, sizeof(char));
                if(Teams[Teamcounter].trainerName) 
                    strncpy(Teams[Teamcounter].trainerName, startRow+9, len);
            }
        }
        if((strncmp(startRow, "<Player>", 8) == 0)){
            if(Teams[Teamcounter].playerAmount <= MAXPLAYER){
                if(loadPlayer(loadFile))
                    Teams[Teamcounter].playerAmount++;
                else{
                    printf("Teamindex %i Spielerindex %i: Laden fehlgeschagen.", Teamcounter, Teams[Teamcounter].playerAmount);
                    continue;
                }
            }
            else{
                printf("\nTeamindex %i: Maximale Spielerzahl ueberschritten", Teamcounter);
                continue;
            }
        }

        if(feof(loadFile)) break;
    }while(strncmp(startRow, "</Team>", 7) != 0);
    return 1;
}


void load(){
    FILE *file  = fopen("teams.xml", "rt"); //wofur steht "rt"?

    if(file){
        char row[101];
        char *startRow;

        do{
            fscanf(file, "%100[^\n\r]", row);
            fclearBuffer(file);
            startRow = row;

            while(*startRow == ' ' || *startRow == 9) startRow++;

            if(strncmp(startRow, "<Team>", 6) == 0){
                if(Teamcounter <= MAXTEAMS){
                    if(loadTeam(file)) Teamcounter++;
                    else printf("\nTeamindex %i: Laden Fehlgeschlagen.", Teamcounter);
                }
                else{
                    printf("\nMaximale Anzahl der Teams ueberschritten. :(");
                    waitForEnter();
                    fclose(file);
                    return;
                }
            }
            if(feof(file)) break;
        }while(strncmp(startRow, "</Data>", 7) != 0);

        fclose(file);
        enter(1);
    }
    else{
        printf("\nDatei konnte nicht aufgemacht werden.");
    }
}