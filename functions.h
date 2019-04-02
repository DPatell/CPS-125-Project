//
//  functions.h
//  Cps125
//
//  Created by Dhaval Patel on 2019-03-26.
//  Copyright © 2019 Dhaval Patel. All rights reserved.
//

#ifndef FUNCTIONS
#define FUNCTIONS

#include <stdio.h>
#include <stdlib.h>

//#define length(x) (sizeof(x) / sizeof((x)[0]))

// Structure holding data for each lake for a specific day of the year
typedef struct  temps {
    
    int year;
    int day;
    double sup;
    double mich;
    double huron;
    double erie;
    double ont;
    double clr;
} TEMPS;

// Function that reads the data from the file and stores it into a dynamic array of structures
/*
 void readData() {
 
 }
 */


void indvidualAverage (TEMPS *t, int size) {
    
    int i;
    double average, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0;
    
    for(i = 0 ; i < size ; i++) {
        total1 += t[i].sup;
        total2 += t[i].mich;
        total3 += t[i].huron;
        total4 += t[i].erie;
        total5 += t[i].ont;
        total6 += t[i].clr;
    }
    average = total1 / size;
    printf("The average temp of lake sup is: %5.2lf\n", average);
    average = total2 / size;
    printf("The average temp of lake mich is: %5.2lf\n", average);
    average = total3 / size;
    printf("The average temp of lake huron is: %5.2lf\n", average);
    average = total4 / size;
    printf("The average temp of lake erie is: %5.2lf\n", average);
    average = total5 / size;
    printf("The average temp of lake ont is: %5.2lf\n", average);
    average = total6 / size;
    printf("The average temp of lake clr is: %5.2lf\n", average);
}

void free_Mem(FILE *data, TEMPS *t) {
    fclose(data);
    free(t);
}


#endif
