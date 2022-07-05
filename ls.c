#include "ls.h"
#include "headers.h"

void listt(const char *dirname,int x){
    DIR *dir;
    struct dirent *ent;
    char y[100][100];
    int k=0;
    if ((dir = opendir (dirname)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
           strcpy(y[k],ent->d_name);
           k++;
        }
        closedir (dir);
    }
    else
    {
        printf("\nDirectory not found\n");
    }
    
    if (x==1){
        for(int i=0;i<k;i++){
        if (strcmp(y[i],".")!=0 && strcmp(y[i],"..")!=0)
        {
            printf("%s\n",y[i]);
        }
    }
    }
    else if (x==0)
    {
      for(int i=0;i<k;i++){
        if (strcmp(y[i],".")!=0 && strcmp(y[i],"..")!=0 && y[i][0]!='.')
        {
            printf("%s\n",y[i]);
        }
      }  
    }
    
}
