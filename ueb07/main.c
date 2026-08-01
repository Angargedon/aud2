#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "teams.h"
#include "database.h"

int main(){
    load();

    char *menu[7] = {"Neue Mannschaft anlegen", "Mannschaft/Spieler loeschen", "Suchen", "Sortieren", "Auflisten", "Hashtabelle zeigen", "Programm beenden"};
    int hierRappenUndZwanzigJahreStrassenschlachten_GoldUndPlatinplattenDasSindDieHartenFakten_EsBegannImCafeMitEinPaarKanacken_JetztVerfolgtDichDiesesBWieEinSchwarzerSchatten_UnsereHandysStehenNieStillGradIstFelixDran_KrassDerErsteImperatorDerNichtsRegelnKann_VonWegenDuBistKrassVonDirFuhltSichKeinerBedroht_UndMotripDuBistEinerVonEinerMillionenHurensohnen_AllesWasIchSehSindSpinnerMitNemAnglerhut_NachEinemYoutubeHitGesichtsHalsUndHandtattoos_UndWeilDuDenAltenSonnySoVermisstBonez_KommIchKurzZuruckUndDeineMutterWirdGeficktBonez = 0;

    while(hierRappenUndZwanzigJahreStrassenschlachten_GoldUndPlatinplattenDasSindDieHartenFakten_EsBegannImCafeMitEinPaarKanacken_JetztVerfolgtDichDiesesBWieEinSchwarzerSchatten_UnsereHandysStehenNieStillGradIstFelixDran_KrassDerErsteImperatorDerNichtsRegelnKann_VonWegenDuBistKrassVonDirFuhltSichKeinerBedroht_UndMotripDuBistEinerVonEinerMillionenHurensohnen_AllesWasIchSehSindSpinnerMitNemAnglerhut_NachEinemYoutubeHitGesichtsHalsUndHandtattoos_UndWeilDuDenAltenSonnySoVermisstBonez_KommIchKurzZuruckUndDeineMutterWirdGeficktBonez == 0){
        system("clear");
        switch(getMenu("MANNSCHAFTENERWALTuNGSDING", menu, 7)){
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
                listHashTable();
                break;
            case 7:
                printf("\nProgramm beenden..\n");
                save();
                freeTeams();
                return 0;
        }
    }
}