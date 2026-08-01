#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"


void createPlayer(){

    //if(newPlayer){
        int check = 0;
        if(getText("Spielername: ", 50, 0, &(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].name)))
            if(getDate("Geburtstag(tt.mm.jjjj): ", &(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].birthday)))
                if(getNumber("Trikotnummer: ", 1, 99, &(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].playernumber)))
                    if(getNumber("Anzahl der Tore: ", 0, 0,&(Teams[Teamcounter].player[Teams[Teamcounter].playerAmount].goals)))
                        check = 1;
        if(check == 1){
            enter(1);
            printf("Spieler erstellt.");
            Teams[Teamcounter].playerAmount++;
        }
        else{
            enter(1);
            printf("Fehlgeschlagen.");
            waitForEnter();
        }
    //}
    //else printf("Speichern fehlgeschlagen. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
    //waitForEnter();
}


void createTeam(){
    int check = 1;
    
    while(check == 1){
        check = getText("Teamname: ", 50, 0, &(Teams[Teamcounter].teamName));
        check = getText("Trainername: ", 50, 1, &(Teams[Teamcounter].trainerName));
        Teams[Teamcounter].playerAmount = 0;
        if(askYesOrNo("Spieler hinzufuegen?[j/n]: ")){
            int yn = 1;
            do{
                createPlayer();
                yn = askYesOrNo("Weiteren Spieler hinzufuegen?[j/n]: ");
            }while(yn == 1);
        }
        check = 2;
    }
    if(check == 2){
        enter(1);
        Teamcounter++;
        printf("Team erstellt..");
        waitForEnter();
    }
    else if(check == 0){
        enter(1);
        printf("Das alles war ein Fehlschlag..");
        waitForEnter();
    }
        
    
}

void deleteTeam(){
    printf("\nTeam loeschen..\n");
    waitForEnter();
}

void searchPlayer(){
    printf("\nTeam suchen..\n");
    waitForEnter();
}

static int cmpName(sPlayer *p1, sPlayer *p2){
    return strcmp(p1->name, p2->name);
}

static int cmpDate(sPlayer *d1, sPlayer *d2){
    if(d1->birthday == NULL && d2->birthday == NULL)
        return 0;
    if(d1->birthday == NULL)
        return -1;
    if(d2->birthday == NULL)
        return 1;
    else if(d1->birthday->Year-d2->birthday->Year == 0){
        if(d1->birthday->Month-d2->birthday->Month == 0)
            return d1->birthday->Day-d2->birthday->Day;
        else return d1->birthday->Month-d2->birthday->Month;
    }
    else return d1->birthday->Year-d2->birthday->Year;
}

static int cmpNum(sPlayer *p1, sPlayer *p2){
    if(p1->playernumber-p2->playernumber == 0)
        return cmpDate(p1, p2);
    else
        return p1->playernumber-p2->playernumber;
}

static int cmpGoal(sPlayer *p1, sPlayer *p2){
    if(p1->goals-p2->goals == 0)
        return cmpName(p1, p2);
    else
        return p1->goals-p2->goals;
}

void sortTeams(){
    clearScreen();
    char *menu[5] = {"Nach Name sortieren", "Nach Geburtstag sortieren", "Nach Spielernummer sortieren", "Nach Anzahl der Tore sortieren", "Abbrechen"};
    int i;

    switch(getMenu("Sortieren", menu,5)){
        case 1:
            for(i=0;i<Teamcounter;i++)
                quickSort(Teams[i].player, Teams[i].playerAmount, cmpName);
            break;
        case 2:
            for(i=0;i<Teamcounter;i++)
                quickSort(Teams[i].player, Teams[i].playerAmount, cmpDate);
            break;
        case 3:
            for(i=0;i<Teamcounter;i++)
                quickSort(Teams[i].player, Teams[i].playerAmount, cmpNum);
             break;
        case 4:
            for(i=0;i<Teamcounter;i++)
                quickSort(Teams[i].player, Teams[i].playerAmount, cmpGoal);
            break;
        case 5:
            break;
    }


}

void listOnePlayer(sPlayer *player){
    printLine('-', 75);
    enter(1);
    printf("%s(", player->name);
    printf("%i, ", player->playernumber);
    if(player->birthday) printDate(player->birthday);
    else printf("<Geburtstag unbekannt>");
    printf(", %i)", player->goals);
    enter(1);
}

void listOneTeam(sTeam *team){
    enter(1);
    printLine('=', 75);
    printf("\nTeam\n");
    printf("Name: %s", team->teamName);
    enter(1);
    printf("Trainer: ");
    if(team->trainerName) printf("%s", team->trainerName);
    else printf("<unbekannt>");
    printf("\nSpieler:");
    if(team->playerAmount > 0){
        enter(1);
        int i;
        for(i = 0; i < team->playerAmount; i++) listOnePlayer(&(team->player[i]));
    }
}

void listTeams(){
    printf("\nTeam auflisten..\n");
    if(Teamcounter > 0){
        int i;
        for(i = 0; i < Teamcounter; i++) listOneTeam(&Teams[i]);
        printf("\nEingabetaste druecken..");
    }
    else printf("\nKeine Teams eingetragen..");
    waitForEnter();
}

void freeOnePlayer(sPlayer *player){
    free(player->name);
    if(player->birthday) free(player->birthday);
}

void freeOneTeam(sTeam *team){
    free(team->teamName);
    if(team->trainerName) free(team->trainerName);
    int i;
    for(i = 0; i < Teams->playerAmount; i++) freeOnePlayer(Teams->player + i);
}

void freeTeams(){
    if(Teamcounter < 0){
        int i;
        for(i = 0; i < Teamcounter; i++) freeOneTeam(&(Teams[i]));
    }
}