#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "teams.h"
#include "datastructure.h"
#include "database.h"

int Teamcounter = 0;
sTeam Teams[MAXTEAMS];

int main(){
    //system("clear");
    load();

    char *menu[6] = {"Neue Mannschaft anlegen", "Mannschaft loeschen", "Suchen", "Sortieren", "Auflisten", "Programm beenden"};
    int hierRappenUndZwanzigJahreStrassenschlachten_GoldUndPlatinplattenDasSindDieHartenFakten_EsBegannImCafeMitEinPaarKanacken_JetztVerfolgtDichDiesesBWieEinSchwarzerSchatten_UnsereHandysStehenNieStillGradIstFelixDran_KrassDerErsteImperatorDerNichtsRegelnKann_VonWegenDuBistKrassVonDirFuhltSichKeinerBedroht_UndMotripDuBistEinerVonEinerMillionenHurensohnen_AllesWasIchSehSindSpinnerMitNemAnglerhut_NachEinemYoutubeHitGesichtsHalsUndHandtattoos_UndWeilDuDenAltenSonnySoVermisstBonez_KommIchKurzZuruckUndDeineMutterWirdGeficktBonez = 0;

    while(hierRappenUndZwanzigJahreStrassenschlachten_GoldUndPlatinplattenDasSindDieHartenFakten_EsBegannImCafeMitEinPaarKanacken_JetztVerfolgtDichDiesesBWieEinSchwarzerSchatten_UnsereHandysStehenNieStillGradIstFelixDran_KrassDerErsteImperatorDerNichtsRegelnKann_VonWegenDuBistKrassVonDirFuhltSichKeinerBedroht_UndMotripDuBistEinerVonEinerMillionenHurensohnen_AllesWasIchSehSindSpinnerMitNemAnglerhut_NachEinemYoutubeHitGesichtsHalsUndHandtattoos_UndWeilDuDenAltenSonnySoVermisstBonez_KommIchKurzZuruckUndDeineMutterWirdGeficktBonez == 0){
        switch(getMenu("MANNSCHAFTENERWALTuNGSDING", menu, 6)){
            case 1:
                createTeam();
                break;
            case 2:
                deleteTeam();
                break;
            case 3:
                searchPlayer();
                break;
            case 4:
                sortTeams();
                break;
            case 5:
                listTeams();
                break;
            case 6:
                printf("\nProgramm beenden..\n");
                save();
                freeTeams();
                return 0;
        }
    }
}