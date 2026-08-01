#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"
#include "list.h"

static int cmpTName(sTeam *t1, sTeam *t2){
    return strcmp(t1->teamName, t2->teamName);
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

void freeOnePlayer(sPlayer *player){
    free(player->name);
    if(player->birthday) free(player->birthday);
}

void freeOneTeam(sTeam *team){
    if (team == NULL)
        return;
    free(team->teamName);
    if(team->trainerName) free(team->trainerName);
    int i;
    for(i = 0; i < team->playerAmount; i++)
        freeOnePlayer(team->player + i);
    free(team);
}

void createPlayer(sTeam *team){
    //if(newPlayer){
        if(team->playerAmount >= MAXPLAYER){
            printf("\nMaximale Spielerzahl erreicht.");
            waitForEnter();
            return;
        }

        int check = 0;
        if(getText("Spielername: ", 50, 0, &(team->player[team->playerAmount].name)))
            if(getDate("Geburtstag(tt.mm.jjjj): ", &(team->player[team->playerAmount].birthday)))
                if(getNumber("Trikotnummer: ", 1, 99, &(team->player[team->playerAmount].playernumber)))
                    if(getNumber("Anzahl der Tore: ", 0, 0,&(team->player[team->playerAmount].goals)))
                        check = 1;
        if(check == 1){
            enter(1);
            printf("Spieler erstellt.");
            team->playerAmount++;
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
    sTeam *newTeam = calloc(1, sizeof(sTeam));

    if(newTeam){
        while(check == 1){
            check = getText("Teamname: ", 50, 0, &(newTeam->teamName));
            check = getText("Trainername: ", 50, 1, &(newTeam->trainerName));
            newTeam->playerAmount = 0;
            if(askYesOrNo("Spieler hinzufuegen?[j/n]: ")){
                int yn = 1;
                do{
                    createPlayer(newTeam);
                    if(newTeam->playerAmount < MAXPLAYER)
                        yn = askYesOrNo("Weiteren Spieler hinzufuegen?[j/n]: ");
                    else
                        yn = 0;
                }while(yn == 1);
            }
            check = 2;
        }
        if(check == 2){
            insertInDList(newTeam, cmpTName);
            enter(1);
            printf("Team erstellt..");
            waitForEnter();
        }
        else if(check == 0){
            enter(1);
            printf("Das alles war ein Fehlschlag..");
            waitForEnter();
        }
    }
}

void deleteTeam(){
    sTeam *tmp = first;

    if(tmp == NULL){
        printf("\nKeine Teams vorhanden..");
        waitForEnter();
    }
    else{
        int i;
        int in = 0;

        do{
            tmp = first;
            i = 0;
            printf("\nWahelen Sie ein Team zum loeschen aus(0 zum abbrechen):");
            while(tmp != NULL){
                printf("\n%i. %s", i+1, tmp->teamName);
                tmp = tmp->next;
                i++;
            }
            printf("\n\nIhre Wahl: ");
            scanf("%i", &in);
            clearBuffer();
        }while(in < 0 || in > i);
        if(in == 0)
            return;
        else{
            tmp = first;
            for(i = 1; i<in; i++)
                tmp = tmp->next;
            freeOneTeam(removeFromDList(tmp, cmpTName));
        }
    }

}

void searchPlayer(){
    printf("\nTeam suchen..\n");
    waitForEnter();
}

void sortTeams(){
    clearScreen();
    char *menu[5] = {"Nach Name sortieren", "Nach Geburtstag sortieren", "Nach Spielernummer sortieren", "Nach Anzahl der Tore sortieren", "Abbrechen"};
    struct sT *tmp = first;

    switch(getMenu("Sortieren", menu,5)){
        case 1:
            while(tmp != NULL){
                quickSort(tmp->player, tmp->playerAmount, cmpName);
                tmp = tmp->next;
            }
            break;
        case 2:
            while(tmp != NULL){
                quickSort(tmp->player, tmp->playerAmount, cmpDate);
                tmp = tmp->next;
            }
            break;
        case 3:
            while(tmp != NULL){
                quickSort(tmp->player, tmp->playerAmount, cmpNum);
                tmp = tmp->next;
            }
             break;
        case 4:
            while(tmp != NULL){
                quickSort(tmp->player, tmp->playerAmount, cmpGoal);
                tmp = tmp->next;
            }
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
    sTeam *tmp = first;
    printf("\nTeam auflisten..\n");
    if(first != NULL){
        while(tmp != NULL){
            listOneTeam(tmp);
            tmp = tmp->next;
        }
        printf("\nEingabetaste druecken..");
    }
    else printf("\nKeine Teams eingetragen..");
    waitForEnter();
}

void freeTeams(){
    sTeam *tmp = first;

    while(tmp != NULL){
        freeOneTeam(removeFromDList(tmp, cmpTName));
        tmp = first;
    }
}