#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 365
#define length(x) (sizeof(x) / sizeof((x)[0]))

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
    
    char name[7];
    int day;
    int month;
    int swim;
    int frozen;
    double average;
    double summerAverage;
    double winterAverage;
    double warmest;
    double coldest;
} LAKES;

void date_format(LAKES *l, int len);
double part1 (TEMPS *t, LAKES *l,int num);
void part2 (TEMPS *t, LAKES *l, double totalAvg);
void part3 (TEMPS *t, LAKES *l, LAKES *warm, LAKES *cold, int len);
void part4 (TEMPS *t, LAKES *l, LAKES *warm, LAKES *cold);
void part5 (TEMPS *t, LAKES *l);
void part6 (TEMPS *t, LAKES *l);
void part7 (TEMPS *t, LAKES *l);
void part8 (TEMPS *t, LAKES *l);

int main () {
    
    int i = 0, len;
    double totalAvg;
    
    FILE *data;
    TEMPS t[size];
    LAKES l[6], warm[6], cold[6];
    
    strcpy(l[0].name, "Sup.");
    strcpy(l[1].name, "Mich.");
    strcpy(l[2].name, "Huron");
    strcpy(l[3].name, "Erie");
    strcpy(l[4].name, "Ont.");
    strcpy(l[5].name, "St.Clr");
    
    data = fopen("data.dat", "r");
    
    if ( data == NULL) {
        printf("file could not be opened\n");
        return 1;
    }
    while (1) {
        
        if (feof(data)) break;
        
        fscanf(data, "%d%3d%lf%lf%lf%lf%lf%lf", &t[i].year, &t[i].day, &t[i].sup, &t[i].mich, &t[i].huron, &t[i].erie, &t[i].ont, &t[i].clr);
        // printf("%d  %3d  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf\n", t[i].year, t[i].day, t[i].sup, t[i].mich, t[i].huron, t[i].erie, t[i].ont, t[i].clr);
        i++;
    }

    fclose(data);
    
    len = length(l);
    
    printf("Question 1\n");
    totalAvg = part1(t, l, size);

    printf("Question 2\n");
    part2(t, l, totalAvg);

    printf("Question 3\n");
    part3(t, l, warm, cold, len);

    printf("Question 4\n");
    part4(t, l, warm, cold);

    printf("Question 5\n");
    part5(t, l);

    printf("Question 6\n");
    part6(t, l);

    printf("Question 7\n");
    part7(t, l);

    printf("Question 8\n");
    part8(t, l);
    
    return 0;
}

void date_format(LAKES *l, int len) {
    
    int i = 0, j = 0, mth,  month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, days;
    
    while(i < len) {
        days = l[i].day;
        mth = 1;
        for (j = 0; j < 12; j++) {
            
            if (days > month[j]){
                days -= month[j];
                mth++;
            }
        }
        
        l[i].day = days;
        l[i].month = mth;
        i++;
    }
}

double part1 (TEMPS *t, LAKES *l,  int num) {
    
    int i;
    double total[6] = {0}, sum = 0, totalAvg;
    
    for(i = 0 ; i < size ; i++) {
        total[0] += t[i].sup;
        total[1] += t[i].mich;
        total[2] += t[i].huron;
        total[3] += t[i].erie;
        total[4] += t[i].ont;
        total[5] += t[i].clr;
    }
    
    for(i = 0; i < 6; i++) {
        l[i].average = total[i] / num;
        sum += total[i];
        printf("The average temp of lake %6s is: %5.2lf degrees Celsius\n", l[i].name, l[i].average);
    }
    totalAvg = sum / (365 * 6);
    printf("\nThe average temp of all lakes is: %5.2lf degrees Celsius\n\n", totalAvg);
    
    return totalAvg;
}

void part2 (TEMPS *t, LAKES *l, double totalAvg) {
    int i = 0;
    LAKES warmest , coldest;
    warmest.average = l[0].average;
    strcpy(warmest.name, l[0].name);
    
    coldest.average = l[0].average;
    strcpy(coldest.name, l[0].name);
    
    for (i = 0; i < 6; i++) {
        if (warmest.average < l[i].average) {
            warmest.average = l[i].average;
            strcpy(warmest.name, l[i].name);
        }
    }
    
    printf("Lake %s has the warmest average temperature: %5.2lf \n", warmest.name, warmest.average);
    
    for (i = 0; i < 6; i++) {
        if (coldest.average > l[i].average) {
            coldest.average = l[i].average;
            strcpy(coldest.name, l[i].name);
        }
    }
    
    printf("Lake %s has the coldest average temperature: %5.2lf \n\n", coldest.name, coldest.average);
    
    for (i = 0; i < 6; i++) {
        if (l[i].average < totalAvg)
            printf("Lake %6s is below than the average temp of all the lakes\n", l[i].name);
        else
            printf("Lake %6s is above than the average temp of all the lakes\n", l[i].name);
    }

    printf("\n");
    
}

void part3 (TEMPS *t, LAKES *l, LAKES *warm, LAKES *cold, int len) {
    
    int i = 0;
    
    for (i = 0; i < 6; i++) {
        l[i].day = 1;
    }
    
    l[0].warmest = t[0].sup;
    l[1].warmest = t[0].mich;
    l[2].warmest = t[0].huron;
    l[3].warmest = t[0].erie;
    l[4].warmest = t[0].ont;
    l[5].warmest = t[0].clr;
    
    for (i = 0; i < 365; i++) {
        if (l[0].warmest < t[i].sup) {
            l[0].warmest = t[i].sup;
            l[0].day = i + 1;
        }
        if (l[1].warmest < t[i].mich) {
            l[1].warmest = t[i].mich;
            l[1].day = i + 1;
        }
        if (l[2].warmest < t[i].huron) {
            l[2].warmest = t[i].huron;
            l[2].day = i + 1;
        }
        if (l[3].warmest < t[i].erie) {
            l[3].warmest = t[i].erie;
            l[3].day = i + 1;
        }
        if (l[4].warmest < t[i].ont) {
            l[4].warmest = t[i].ont;
            l[4].day = i + 1;
        }
        if (l[5].warmest < t[i].clr) {
            l[5].warmest = t[i].clr;
            l[5].day = i + 1;
        }
    }
    
    for(i = 0; i < 6; i++) {
        warm[i].day = l[i].day;
    }
    
    date_format(l, len);
    for(i = 0; i < 6; i++) {
        printf("For Lake %6s on %d/%d the temperature was the warmest: %5.2lf \n", l[i].name, l[i].day, l[i].month, l[i].warmest);
    }
    
    printf("\n");
    for (i = 0; i < 6; i++) {
        l[i].day = 1;
    }
    
    l[0].coldest = t[0].sup;
    l[1].coldest = t[0].mich;
    l[2].coldest = t[0].huron;
    l[3].coldest = t[0].erie;
    l[4].coldest = t[0].ont;
    l[5].coldest = t[0].clr;
    
    for (i = 0; i < 365; i++) {
        if (l[0].coldest > t[i].sup) {
            l[0].coldest = t[i].sup;
            l[0].day = i + 1;
        }
        if (l[1].coldest > t[i].mich) {
            l[1].coldest = t[i].mich;
            l[1].day = i + 1;
        }
        if (l[2].coldest > t[i].huron) {
            l[2].coldest = t[i].huron;
            l[2].day = i + 1;
        }
        if (l[3].coldest > t[i].erie) {
            l[3].coldest = t[i].erie;
            l[3].day = i + 1;
        }
        if (l[4].coldest > t[i].ont) {
            l[4].coldest = t[i].ont;
            l[4].day = i + 1;
        }
        if (l[5].coldest > t[i].clr) {
            l[5].coldest = t[i].clr;
            l[5].day = i + 1;
        }
    }
    
    for(i = 0; i < 6; i++) {
        cold[i].day = l[i].day;
    }
    
    date_format(l, len);
    for(i = 0; i < 6; i++) {
        printf("For Lake %6s on %d/%d the temperature was the coldest: %5.2lf \n", l[i].name, l[i].day, l[i].month, l[i].coldest);
    }
    
    printf("\n");
}

void part4 (TEMPS *t, LAKES *l, LAKES *warm, LAKES *cold) {
    
    int i = 0, len;
    LAKES warmest[1], coldest[1];
    
    warmest[0].warmest = l[0].warmest;
    strcpy(warmest[0].name, l[0].name);
    
    coldest[0].coldest = l[0].coldest;
    strcpy(coldest[0].name, l[0].name);
    
    for (i = 0; i < 6; i++) {
        if (warmest[0].warmest < l[i].warmest) {
            warmest[0].warmest = l[i].warmest;
            strcpy(warmest[0].name, l[i].name);
            warmest[0].day  = warm[i].day;
        }
    }
    
    len = length(warmest);
    date_format(warmest, len);
    
    printf("\nLake %s has the warmest temp of all the lakes on %d/%d: %5.2lf degrees Celsius\n", warmest[0].name, warmest[0].day, warmest[0].month, warmest[0].warmest);
    
    for (i = 0; i < 6; i++) {
        if (coldest[0].coldest > l[i].coldest) {
            coldest[0].coldest = l[i].coldest;
            strcpy(coldest[0].name, l[i].name);
            coldest[0].day = cold[i].day;
        }
    }
    
    len = length(coldest);
    date_format(coldest, len);
    
    printf("Lake %s has the coldest temp of all the lakes on %d/%d: %5.2lf degrees Celsius\n", coldest[0].name, coldest[0].day, coldest[0].month, coldest[0].coldest);
    printf("\n");
}

void part5 (TEMPS *t, LAKES *l) {
    
    int i, j, summerStart = 172, summerEnd = 265;
    double total[6] = {0};
    LAKES tem[6], temp;
    
    for(i = summerStart ; i < summerEnd ; i++) {
        total[0] += t[i].sup;
        total[1] += t[i].mich;
        total[2] += t[i].huron;
        total[3] += t[i].erie;
        total[4] += t[i].ont;
        total[5] += t[i].clr;
    }

    for (i = 0; i < 6; i++) {
        tem[i].summerAverage = total[i] / (summerEnd - summerStart);
        strcpy(tem[i].name, l[i].name);
    }

    for(i = 0; i < 6; i++) {
        for(j = i+1; j < 6; j++) {
            if (tem[i].summerAverage < tem[j].summerAverage) {
                temp.summerAverage = tem[i].summerAverage;
                strcpy(temp.name, tem[i].name);
                tem[i].summerAverage = tem[j].summerAverage;
                strcpy(tem[i].name, tem[j].name);
                tem[j].summerAverage = temp.summerAverage;
                strcpy(tem[j].name, temp.name);
            }
        }
    }
    
    for(i = 0; i < 6; i++) {
        printf("The average summer temp of lake %6s is: %5.2lf degrees Celsius\n", tem[i].name, tem[i].summerAverage);
    }
    printf("The order of the averages in the summer are the same as the averages of the  entire year\n\n");
}

void part6 (TEMPS *t, LAKES *l) {
    
    int i, j;
    double total[6] = {0};
    LAKES tem[6], temp;
    
    for(i = 1 ; i <= 365 ; i++) {
        if ((i >= 1 && i <= 79) || (i >= 355 && i <= 365)) {
            total[0] += t[i - 1].sup;
            total[1] += t[i - 1].mich;
            total[2] += t[i - 1].huron;
            total[3] += t[i - 1].erie;
            total[4] += t[i - 1].ont;
            total[5] += t[i - 1].clr;
        }
    }

    for (i = 0; i < 6; i++) {
        tem[i].winterAverage = total[i] / (79 + (365-355));
        strcpy(tem[i].name, l[i].name);
    }

    for(i = 0; i < 6; i++) {
        for(j = i+1; j < 6; j++) {
            if (tem[i].winterAverage < tem[j].winterAverage) {
                temp.winterAverage = tem[i].winterAverage;
                strcpy(temp.name, tem[i].name);
                tem[i].winterAverage = tem[j].winterAverage;
                strcpy(tem[i].name, tem[j].name);
                tem[j].winterAverage = temp.winterAverage;
                strcpy(tem[j].name, temp.name);
            }
        }
    }
    
    for(i = 0; i < 6; i++) {
        printf("The average winter temp of lake %6s is: %5.2lf degrees Celsius\n", tem[i].name, tem[i].winterAverage);
    }
    printf("The order of the averages in the winter are not the same as the averages of the  entire year\n\n");
}

void part7 (TEMPS *t, LAKES *l) {

    int i, j, swim[6] = {0};
    
    for (j = 0; j < size; j++) {
        if(t[j].sup >= 20) {
            swim[0]++;               
        }

        if(t[j].mich >= 20) {
            swim[1]++;               
        }

        if(t[j].huron >= 20) {
            swim[2]++;               
        }

        if(t[j].erie >= 20) {
            swim[3]++;               
        }

        if(t[j].ont >= 20) {
            swim[4]++;               
        }

        if(t[j].clr >= 20) {
            swim[5]++;               
        }
    }

    for(i = 0; i < 6; i++) {
        printf("The number of days the you can swim in Lake %6s is: %d\n", l[i].name, swim[i]);
    }

    printf("\n");
        
}

void part8 (TEMPS *t, LAKES *l) {

    int i, j, frozen[6] = {0};

    for (j = 0; j < size; j++) {
        if(t[j].sup <= 0) {
            frozen[0]++;               
        }

        if(t[j].mich <= 0) {
            frozen[1]++;               
        }

        if(t[j].huron <= 0) {
            frozen[2]++;               
        }

        if(t[j].erie <= 0) {
            frozen[3]++;               
        }

        if(t[j].ont <= 0) {
            frozen[4]++;               
        }

        if(t[j].clr <= 0) {
            frozen[5]++;               
        }
    }

    for(i = 0; i < 6; i++) {
            printf("The number of days that Lake %6s is frozen is: %d\n", l[i].name, frozen[i]);
        }

}