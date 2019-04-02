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

double indvidualAverage (TEMPS *t, int size, double average[]) {
    
    int i;
    double total_avg, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0;
    
    for(i = 0 ; i < size ; i++) {
        total1 += t[i].sup;
        total2 += t[i].mich;
        total3 += t[i].huron;
        total4 += t[i].erie;
        total5 += t[i].ont;
        total6 += t[i].clr;
    }
    
    average[0] = total1 / size;
    printf("The average temp of lake sup is: %5.2lf\n", average[0]);
    average[1] = total2 / size;
    printf("The average temp of lake mich is: %5.2lf\n", average[1]);
    average[2] = total3 / size;
    printf("The average temp of lake huron is: %5.2lf\n", average[2]);
    average[3] = total4 / size;
    printf("The average temp of lake erie is: %5.2lf\n", average[3]);
    average[4] = total5 / size;
    printf("The average temp of lake ont is: %5.2lf\n", average[4]);
    average[5] = total6 / size;
    printf("The average temp of lake clr is: %5.2lf\n", average[5]);
    total_avg = (total1 + total2 + total3 + total4 + total5 + total6) / 6;
    
    return total_avg;
}

void warmest(double average[])
{
    int i = 0,lake = 0;
    double warmest = average[0];
    
    for(i = 1; i < 6; i++)
    {
        if(warmest<average[i])
        {
            warmest = average[i];
            lake = i;
        }
    }
    
    if(lake == 0)
        printf("\nThe warmest lake is Superior");
    else if(lake == 1)
        printf("\nThe warmest lake is Michigan");
    else if(lake == 2)
        printf("\nThe warmest lake is Huron");
    else if(lake == 3)
        printf("\nThe warmest lake is Erie");
    else if(lake == 4)
        printf("\nThe warmest lake is Ontario");
    else if(lake == 5)
        printf("\nThe warmest lake is St. Clair");
        
}

void free_Mem(FILE *data, TEMPS *t) {
    fclose(data);
    free(t);
}

#endif
