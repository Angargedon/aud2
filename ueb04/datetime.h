#ifndef DATETIME_H
#define DATETIME_H

int isLeapYear(int year);

int isDateValid(sDate date);

int getDateFromString(char *in, sDate *date);

int getDate(char *prompt, sDate **date);

void printDate(sDate *date);

#endif