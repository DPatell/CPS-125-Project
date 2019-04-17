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

typedef struct lakes {

    char name[6];
    double average;
    double summerAverage;
    double hotest;
    double coldest;
    double swim;
    double frozen;
} LAKES;

void indvidualAverage (TEMPS *t, int size) {
    
    int i;
    double average[6], total[6];
    
    for(i = 0 ; i < size ; i++) {
        total[0] += t[i].sup;
        total[1] += t[i].mich;
        total[2] += t[i].huron;
        total[3] += t[i].erie;
        total[4] += t[i].ont;
        total[5] += t[i].clr;
    }
    
    for(i = 0; i < 6; i++) {
        average[i] = total[i] / size;
        printf("The average temp of lake blank is: %5.2lf\n", average[i]);
    }
}

void indvidualAverageSummer (TEMPS *t) {
    
    int i, j, summerStartDay = 172, summerEndDay = 265;
    double temp, average[6] = {0}, total[6] = {0};
    
    for(i = summerStartDay ; i < summerEndDay ; i++) {
        total[0] += t[i].sup;
        total[1] += t[i].mich;
        total[2] += t[i].huron;
        total[3] += t[i].erie;
        total[4] += t[i].ont;
        total[5] += t[i].clr;
    }

    for(i = 0; i < 6; i++) {
        average[i] = total[i] / (summerEndDay - summerStartDay);
      //  printf("The average summer temp is: %lf\n", average[i]);
    }

    for(i = 0; i < 6; i++) {
        for(j = i+1; j < 6; j++) {
            if (average[i] < average[j]) {
                temp = average[i];
                average[i] = average[j];
                average[j] = temp;
            }
        }
    }

    for(i = 0; i < 6; i++) {
        printf("%5.2lf\n", average[i]);
    }
}

void swimOkay (TEMPS *t, int size) {
    int i,j;
    double swim[6] = {0};

    for (i = 0; i < 6; i++) {
        for (j = 0; j < size; j++) {
            if(t[j].sup > 20) {
                swim[0]++;               
            }

            if(t[j].mich > 20) {
                swim[1]++;               
            }

            if(t[j].huron > 20) {
                swim[2]++;               
            }

            if(t[j].erie > 20) {
                swim[3]++;               
            }

            if(t[j].ont > 20) {
                swim[4]++;               
            }

            if(t[j].clr > 20) {
                swim[5]++;               
            }
        }
    
    }
}

void IsFrozen (TEMPS *t, int size) {
    int i,j;
    double frozen[6] = {0};

    for (j = 0; j < size; j++) {
        if(t[j].sup < 0) {
            frozen[0]++;               
        }

        if(t[j].mich < 0) {
            frozen[1]++;               
        }

        if(t[j].huron < 0) {
            frozen[2]++;               
        }

        if(t[j].erie < 0) {
            frozen[3]++;               
        }

        if(t[j].ont < 0) {
            frozen[4]++;               
        }

        if(t[j].clr < 0) {
            frozen[5]++;               
        }
    }
    
    
}



#endif



//Header File

//
//  functions.h
//  Cps125
//
//  Created by Dhaval Patel on 2019-03-26.
//  Copyright © 2019 Dhaval Patel. All rights reserved.
//
/*
#ifndef FUNCTIONS
#define FUNCTIONS

#include <stdio.h>
#include <stdlib.h>

//#define length(x) (sizeof(x) / sizeof((x)[0]))

// Structure holding data for each lake for a specific day of the year

typedef struct temps {
    int year;
    int day;
    double sup;
    double mich;
    double huron;
    double erie;
    double ont;
    double clr;
} TEMPS;

//Structure for the averages of the lakes

typedef struct average {
    char name[10];
    double average;
} AVG;

typedef struct lake {
    char name[10];
    int day;
    double temp;
} LAKE;

double indvidualAverage(TEMPS *t, int size, AVG *average) {

    int i;
    double total_avg, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0;

    for (i = 0; i < size; i++) {
        total1 += t[i].sup;
        total2 += t[i].mich;
        total3 += t[i].huron;
        total4 += t[i].erie;
        total5 += t[i].ont;
        total6 += t[i].clr;
    }

    average[0].average = total1 / size;
    printf("The average temp of lake sup is: %5.2lf\n", average[0].average);
    average[1].average = total2 / size;
    printf("The average temp of lake mich is: %5.2lf\n", average[1].average);
    average[2].average = total3 / size;
    printf("The average temp of lake huron is: %5.2lf\n", average[2].average);
    average[3].average = total4 / size;
    printf("The average temp of lake erie is: %5.2lf\n", average[3].average);
    average[4].average = total5 / size;
    printf("The average temp of lake ont is: %5.2lf\n", average[4].average);
    average[5].average = total6 / size;
    printf("The average temp of lake clr is: %5.2lf\n", average[5].average);
    total_avg = (total1 + total2 + total3 + total4 + total5 + total6) / (365 * 6);
    printf("The total average of the lakes is %5.2lf\n", total_avg);

    return total_avg;
}

//finds the warmest average temperature of the lakes

void warmest_avg(AVG *average) {

    int i = 0;
    AVG warmest;
    warmest.average = average[0].average;
    strcpy(warmest.name, average[i].name);

    for (i = 1; i < 6; i++) {
        if (warmest.average < average[i].average) {
            warmest.average = average[i].average;
            strcpy(warmest.name, average[i].name);
        }
    }

    printf("\nThe warmest lake is %s", warmest.name);
}

//finds the coldest average temperature of the lakes

void coldest_avg(AVG *average) {

    int i = 0;
    AVG coldest;
    coldest.average = average[0].average;
    strcpy(coldest.name, average[i].name);

    for (i = 1; i < 6; i++) {

        if (coldest.average > average[i].average) {
            coldest.average = average[i].average;
            strcpy(coldest.name, average[i].name);
        }
    }

    printf("\nThe coldest lake is %s", coldest.name);
}

//Checks if the lake is above or below the average

void check_average(double total_avg, AVG *average) {

    int i = 0;

    printf("\n");
    for (i = 0; i < 6; i++) {
        if (average[i].average < total_avg)
            printf("\nLake %s is colder than the average", average[i].name);
        else
            printf("\nLake %s is warmer than the average", average[i].name);
    }
}

//finds the warmest day

void warmest_day(TEMPS *t, double *warmest) {

    int i = 0;
    int month = 0;
    LAKE lake[6];
    LAKE warmest_lake;
    warmest_lake.temp = t[0].sup;

    printf("\n");
    //The name of all the lakes
    strcpy(lake[0].name, "Superior");
    strcpy(lake[1].name, "Michigan");
    strcpy(lake[2].name, "Huron");
    strcpy(lake[3].name, "Erie");
    strcpy(lake[4].name, "Ontario");
    strcpy(lake[5].name, "St. Clair");

    //first temperatures of the lakes
    lake[0].temp = t[0].sup;
    lake[1].temp = t[0].mich;
    lake[2].temp = t[0].huron;
    lake[3].temp = t[0].erie;
    lake[4].temp = t[0].ont;
    lake[5].temp = t[0].clr;

    for (i = 0; i < 6; i++) {
        warmest[i] = lake[i].temp;
    }

    //sets each lake to the first day
    for (i = 0; i < 6; i++)
        lake[i].day = 1;

    //finds the warmest temperature and day of each lake
    for (i = 0; i < 365; i++) {
        if (warmest[0] < t[i].sup) {
            warmest[0] = t[i].sup;
            lake[0].day = i + 1;
        }
        if (warmest[1] < t[i].mich) {
            warmest[1] = t[i].mich;
            lake[1].day = i + 1;
        }
        if (warmest[2] < t[i].huron) {
            warmest[2] = t[i].huron;
            lake[2].day = i + 1;
        }
        if (warmest[3] < t[i].erie) {
            warmest[3] = t[i].erie;
            lake[3].day = i + 1;
        }
        if (warmest[4] < t[i].ont) {
            warmest[4] = t[i].ont;
            lake[4].day = i + 1;
        }
        if (warmest[5] < t[i].clr) {
            warmest[5] = t[i].clr;
            lake[5].day = i + 1;
        }
    }

    printf("Warmest Temperature of each lake:\n");
    //finds the warmest temperature and day
    for (i = 0; i < 6; i++) {
        month = date_format(&lake[i].day);
        printf("\nLake %s with a temperature of %5.2lf on %d/%d", lake[i].name, warmest[i], lake[i].day, month);
    }
}

//finds the coldest day

void coldest_day(TEMPS *t, double *coldest) {

    int i = 0;
    int month = 0;
    LAKE lake[6];
    LAKE coldest_lake;
    coldest_lake.temp = t[0].sup;

    printf("\n");
    //The name of all the lakes
    strcpy(lake[0].name, "Superior");
    strcpy(lake[1].name, "Michigan");
    strcpy(lake[2].name, "Huron");
    strcpy(lake[3].name, "Erie");
    strcpy(lake[4].name, "Ontario");
    strcpy(lake[5].name, "St. Clair");

    //first temperatures of the lakes
    lake[0].temp = t[0].sup;
    lake[1].temp = t[0].mich;
    lake[2].temp = t[0].huron;
    lake[3].temp = t[0].erie;
    lake[4].temp = t[0].ont;
    lake[5].temp = t[0].clr;

    for (i = 0; i < 6; i++) {
        coldest[i] = lake[i].temp;
    }

    //sets each lake to the first day
    for (i = 0; i < 6; i++)
        lake[i].day = 1;

    //finds the coldest temperature and day of each lake
    for (i = 0; i < 365; i++) {
        if (coldest[0] > t[i].sup) {
            coldest[0] = t[i].sup;
            lake[0].day = i + 1;
        }
        if (coldest[1] > t[i].mich) {
            coldest[1] = t[i].mich;
            lake[1].day = i + 1;
        }
        if (coldest[2] > t[i].huron) {
            coldest[2] = t[i].huron;
            lake[2].day = i + 1;
        }
        if (coldest[3] > t[i].erie) {
            coldest[3] = t[i].erie;
            lake[3].day = i + 1;
        }
        if (coldest[4] > t[i].ont) {
            coldest[4] = t[i].ont;
            lake[4].day = i + 1;
        }
        if (coldest[5] > t[i].clr) {
            coldest[5] = t[i].clr;
            lake[5].day = i + 1;
        }
    }

    printf("Coldest Temperature of each lake:\n");
    //finds the warmest temperature and day
    for (i = 0; i < 6; i++) {
        month = date_format(&lake[i].day);
        printf("\nLake %s with a temperature of %5.2lf on %d/%d", lake[i].name, coldest[i], lake[i].day, month);
    }
}

//finds the warmest lake

void warmest_lake(TEMPS *t, double *warmest) {

    int i = 0;
    int month = 0;
    LAKE lake[6];
    LAKE warmest_lake;
    warmest_lake.temp = t[0].sup;

    printf("\n");
    //The name of all the lakes
    strcpy(lake[0].name, "Superior");
    strcpy(lake[1].name, "Michigan");
    strcpy(lake[2].name, "Huron");
    strcpy(lake[3].name, "Erie");
    strcpy(lake[4].name, "Ontario");
    strcpy(lake[5].name, "St. Clair");

    //first temperatures of the lakes
    lake[0].temp = t[0].sup;
    lake[1].temp = t[0].mich;
    lake[2].temp = t[0].huron;
    lake[3].temp = t[0].erie;
    lake[4].temp = t[0].ont;
    lake[5].temp = t[0].clr;

    for (i = 0; i < 6; i++) {
        warmest[i] = lake[i].temp;
    }

    //sets each lake to the first day
    for (i = 0; i < 6; i++)
        lake[i].day = 1;

    //finds the warmest temperature and day of each lake
    for (i = 0; i < 365; i++) {
        if (warmest[0] < t[i].sup) {
            warmest[0] = t[i].sup;
            lake[0].day = i + 1;
        }
        if (warmest[1] < t[i].mich) {
            warmest[1] = t[i].mich;
            lake[1].day = i + 1;
        }
        if (warmest[2] < t[i].huron) {
            warmest[2] = t[i].huron;
            lake[2].day = i + 1;
        }
        if (warmest[3] < t[i].erie) {
            warmest[3] = t[i].erie;
            lake[3].day = i + 1;
        }
        if (warmest[4] < t[i].ont) {
            warmest[4] = t[i].ont;
            lake[4].day = i + 1;
        }
        if (warmest[5] < t[i].clr) {
            warmest[5] = t[i].clr;
            lake[5].day = i + 1;
        }
    }

    //finds the warmest lake, temperature and day
    for (i = 0; i < 6; i++) {
        if (warmest_lake.temp < warmest[i]) {
            warmest_lake.temp = warmest[i];
            strcpy(warmest_lake.name, lake[i].name);
            warmest_lake.day = lake[i].day;
        }
    }

    month = date_format(&warmest_lake.day);

    printf("\nThe warmest Lake is %s with a temperature of %5.2lf on %d/%d", warmest_lake.name, warmest_lake.temp, warmest_lake.day, month);
}

//finds the coldest lake

void coldest_lake(TEMPS *t, double *coldest) {

    int i = 0;
    int month = 0;
    LAKE lake[6];
    LAKE coldest_lake;
    coldest_lake.temp = t[0].sup;

    printf("\n");
    //The name of all the lakes
    strcpy(lake[0].name, "Superior");
    strcpy(lake[1].name, "Michigan");
    strcpy(lake[2].name, "Huron");
    strcpy(lake[3].name, "Erie");
    strcpy(lake[4].name, "Ontario");
    strcpy(lake[5].name, "St. Clair");

    //first temperatures of the lakes
    lake[0].temp = t[0].sup;
    lake[1].temp = t[0].mich;
    lake[2].temp = t[0].huron;
    lake[3].temp = t[0].erie;
    lake[4].temp = t[0].ont;
    lake[5].temp = t[0].clr;

    for (i = 0; i < 6; i++) {
        coldest[i] = lake[i].temp;
    }

    //sets each lake to the first day
    for (i = 0; i < 6; i++)
        lake[i].day = 1;

    //finds the coldest temperature and day of each lake
    for (i = 0; i < 365; i++) {
        if (coldest[0] > t[i].sup) {
            coldest[0] = t[i].sup;
            lake[0].day = i + 1;
        }
        if (coldest[1] > t[i].mich) {
            coldest[1] = t[i].mich;
            lake[1].day = i + 1;
        }
        if (coldest[2] > t[i].huron) {
            coldest[2] = t[i].huron;
            lake[2].day = i + 1;
        }
        if (coldest[3] > t[i].erie) {
            coldest[3] = t[i].erie;
            lake[3].day = i + 1;
        }
        if (coldest[4] > t[i].ont) {
            coldest[4] = t[i].ont;
            lake[4].day = i + 1;
        }
        if (coldest[5] > t[i].clr) {
            coldest[5] = t[i].clr;
            lake[5].day = i + 1;
        }
    }

    //finds the coldest lake, temperature and day
    for (i = 0; i < 6; i++) {
        if (coldest_lake.temp > coldest[i]) {
            coldest_lake.temp = coldest[i];
            strcpy(coldest_lake.name, lake[i].name);
            coldest_lake.day = lake[i].day;
        }
    }

    month = date_format(&coldest_lake.day);

    printf("\nThe coldest Lake is %s with a temperature of %5.2lf on %d/%d", coldest_lake.name, coldest_lake.temp, coldest_lake.day, month);
}

//puts an integer number of days into a month and day format

int date_format(int *days) {

    int i = 1, month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (i = 1; i <= 12; i++) {
        if (*days > month[i - 1])
            *days -= month[i - 1];
        else
            break;
    }
    return i;
}

void free_Mem(FILE *data, TEMPS *t) {
    fclose(data);
    free(t);
}

#endif

*/


//Main File

//
//  main.c
//  Cps125
//
//  Created by Dhaval Patel on 2019-03-26.
//  Copyright © 2019 Dhaval Patel. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main () {
    
    int i = 0, max = 2;
    double total_avg;
    double warmest[6] = {0};
    double coldest[6] = {0};
    FILE *data;
    TEMPS *t = (TEMPS *)malloc(sizeof(TEMPS));
    AVG avg[6];
            
    strcpy(avg[0].name, "Superior");
    strcpy(avg[1].name, "Michigan");
    strcpy(avg[2].name, "Huron");
    strcpy(avg[3].name, "Erie");
    strcpy(avg[4].name, "Ontario");
    strcpy(avg[5].name, "St. Clair");
    
    data = fopen("data", "r");
    
    if ( data == NULL) {
        printf("file could not be opened\n");
        return 1;
    }
    while (1) {
       if (feof(data)) break;
        
        fscanf(data, "%d%3d%lf%lf%lf%lf%lf%lf", &t[i].year, &t[i].day, &t[i].sup, &t[i].mich, &t[i].huron, &t[i].erie, &t[i].ont, &t[i].clr);
//        printf("%3d  %d  %3d  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf\n", i, t[i].year, t[i].day, t[i].sup, t[i].mich, t[i].huron, t[i].erie, t[i].ont, t[i].clr);
        
        if (i == (max-2) ) {
            t = (TEMPS *)realloc(t, max * sizeof(TEMPS));
            max++;
        }
        i++;
    }
    
    total_avg = indvidualAverage(t, (i+1),avg);
    warmest_avg(avg);
    coldest_avg(avg);
    check_average(total_avg, avg);
    warmest_day(t,warmest);
    coldest_day(t,coldest);
    warmest_lake(t,warmest);
    coldest_lake(t,coldest);
    free_Mem(data, t);
    
    return 0;
}
*/
