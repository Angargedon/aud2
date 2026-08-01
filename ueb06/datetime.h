#ifndef DATETIME_H
#define DATETIME_H

/*Checks if parameter is a leap-year*/
int isLeapYear(int year);

/*Checks if date is valid, including if 29th of february is possible in given year*/
int isDateValid(sDate date);

/*Reads given date in dd.mm.yyyy-format from a string and turns it into data for 'datastructure.h' before checking if date is even valid.*/
int getDateFromString(char *in, sDate *date);

/*Prints prompt and expects a date to be given in dd.mm.yyyy-format. Turns it into data for 'datastructure.h' afterwards.*/
int getDate(char *prompt, sDate **date);

/*Prints date from 'datastructure.h' in dd.mm.yyyy-format*/
void printDate(sDate *date);

#endif