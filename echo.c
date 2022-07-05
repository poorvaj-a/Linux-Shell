#include "headers.h"

void echo(char *x,int k){
    char y[50][50];
    char* p = strtok(x, "  \t");
    int c=0;
    while(p!=NULL){
        strcpy(y[c], p);
        c++;
        p = strtok(NULL, "  \t");
    }
    for (int i=c-1; i >=1+k; i--) {
     strcat(y[i], " ");
     if (i != c-1) 
     {
         strcat(y[i], y[i+1]);
     }
   }
   printf("%s\n", y[1+k]);
    
};
