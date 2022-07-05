#include "prompt.h"
#include "headers.h"

void prompt(char* a){
    char x[100];
    int len = gethostname(x, 25);
    
    if(a != NULL){
        printf("<%s:~%s> ",x,a);
    }
    else
    {
        printf("<%s:~> ",x);
    }
    
}
