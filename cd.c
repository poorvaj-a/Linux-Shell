#include "cd.h"
#include "headers.h"


char* count(char* b,char* q){
    int a = strlen(b);
    for (int i = 0; i < a; i++)
    {
        q[i]=' ';
    }
    char* t = strtok(q,"  \t");
    return t;
    
}
  
char* cd(char* x,char* an,int h,int in){
    char* p = strtok(x, "  \t");
    int c=0;
    char y[50][50];
    char* q;
    while(p!=NULL){
        strcpy(y[c], p);
        c++;
        p = strtok(NULL, "  \t");
    }
    char s[1024];
    char str[1024];
    if (c==1+h)
    {
        for (int i = 0; i < in; i++)
        {
            chdir(an);
        }
        return NULL; }
    
    else if(c==2+h){ 
        if (y[1+h][0]=='~'){
            chdir(an);
            return NULL;
        }
        else if (y[1+h][0]=='-'){
            for (int i = 0; i < in; i++)
            {
                printf("%s\n",getcwd(s,100));
            }
            return NULL; }
            else if (y[1+h][0]=='.' && y[1+h][1]=='.'){
            for (int i = 0; i < in; i++)
            {
                chdir(y[1+h]);
                if(chdir(y[1+h])==-1){
            printf("cd: %s: No such file or directory\n", y[1]);
            return NULL;
            exit(1);
        }    }
            q = getcwd(str, 100);
            if (strcmp(str,an)==0){
                return NULL;
            }
            else{
            return q; 
            }
            exit(1);
        }
        else
        {   for (int i = 0; i < in; i++)
        {
            chdir(y[1+h]);
            if(chdir(y[1+h])==-1){
            printf("cd: %s: No such file or directory\n", y[1]);
            return NULL;
            exit(0);
        }
        }
            getcwd(s, 100); 
            if (strcmp(s,an)==0){
                return NULL;
            }
            else{           
                q = count(an,s);
                return q;
            }
            exit(0);
        }       
    }
    else if(c==3+h){
        if(chdir(y[1+h])==-1){
            printf("cd: %s: No such file or directory\n", y[1]);
            return NULL;
        }
        else{
        printf("cd: Too many arguments\n");
        return NULL;
        }
    }
}
