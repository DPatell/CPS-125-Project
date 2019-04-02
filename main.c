//
//  main.c
//  Cps125
//
//  Created by Dhaval Patel on 2019-03-26.
//  Copyright © 2019 Dhaval Patel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main () {
    
    int i = 0, max = 2;
    FILE *data;
    TEMPS *t = (TEMPS *)malloc(sizeof(TEMPS));
    
    data = fopen("data.dat", "r");
    
    if ( data == NULL) {
        printf("file could not be opened\n");
        return 1;
    }
    while (1) {
       if (feof(data)) break;
        
        fscanf(data, "%d%3d%lf%lf%lf%lf%lf%lf", &t[i].year, &t[i].day, &t[i].sup, &t[i].mich, &t[i].huron, &t[i].erie, &t[i].ont, &t[i].clr);
        printf("%3d  %d  %3d  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf  %5.2lf\n", i, t[i].year, t[i].day, t[i].sup, t[i].mich, t[i].huron, t[i].erie, t[i].ont, t[i].clr);
        
        if (i == (max-2) ) {
            t = (TEMPS *)realloc(t, max * sizeof(TEMPS));
            max++;
        }
        i++;
    }
    
    indvidualAverage(t, (i+1));
    warmest(average);
    free_Mem(data, t);
    
    return 0;
}
