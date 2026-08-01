#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.h"

int isLeapYear(int year){ //Jahr % 4 == 0 AND Jahr % 100 != 0) OR (Jahr % 400 == 0
    if(((year % 4) == 0) && (((year % 100) != 0) || ((year % 100) == 0))) return 1;
    else return 0;
}

int isDateValid(sDate date){
    int isDay = 0;

    if(date.Month > 0 && date.Month < 13){
        switch (date.Month){
        case 4: case 6: case 9: case 11:
            isDay = 31;
            break;
        case 2:
            if(isLeapYear(date.Year)) isDay = 29;
            else isDay = 28;
            break;
        default:
            isDay = 31;
            break;
        }
        return(date.Day > 0) && (date.Day <= isDay);
    }
    else return 0;
}

int getDateFromString(char in[20], sDate *date){
    char read[20];
    int count = 0;
    int j= 0;
    
    for(int i = 0; count < 3; i++){
        if((in[i] != '.') && (in[i] != '\0')){
             read[j] = in[i];
             read[j+1] = '\0';
             j++;
            }
        else{
            if(count == 0) date->Day = atoi(read);
            else if(count == 1) date->Month = atoi(read);
            else if(count == 2) date->Year = atoi(read);

            j = 0;
            count++;
        }
    }
    return isDateValid(*date);
}

int getDate(char *prompt, sDate **date){
    char in[20];
    sDate tmp;
    int check = 0;

    //if(date == NULL) return 0;

    do{
        printf("%s", prompt);
        *in = '\0';
        scanf("%19[^\n]", in);
        clearBuffer();
        if (*in == '\0'){
            *date = NULL;
            break;
        }
        check = getDateFromString(in, &tmp);
    }while((check != 1));

    if(check){
        *date = malloc(sizeof(sDate));
        if (*date)
            **date = tmp;
    }

    return 1;
}

void printDate(sDate *date){
    printf("%02i.%02i.%04i", date->Day, date->Month, date->Year);
}