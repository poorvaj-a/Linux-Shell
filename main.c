#include "prompt.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "cd.h"
#include "ls.h"

int main(){
    char a[100];
    char b[100]; char y11[50][50];
    char* z = ""; char* zz1;
    char an[1024];
    getcwd(an, 100);
    
    while (1){
        prompt(z);
        gets(a);
        char y[50][50]; char y0[50][50];
        strcpy(b,a); 
        int c=0; int c0;
        char b0[150];
        char* p = strtok(b, ";");

        while(p!=NULL){
        strcpy(y0[c], p);
        strcpy(y11[c], y0[c]);
        c++;
        p = strtok(NULL, ";");
        }
    for(int i=0; i<c; i++){
     zz1 = strtok(y11[i], "  \t");
        c0 = 0;
        while(zz1!=NULL){
            strcpy(y[c0], zz1);
            c0++;
            zz1 = strtok(NULL, "  \t");
        }

        if(strcmp(y[0], "repeat")==0){
        int in = y[1][0] - '0';
        if(strcmp(y[2],"echo")==0){
                for (int i = 0; i < in; i++){
                    echo(y0[i],2);
                }
            }
        else if(strcmp(y[2],"cd")==0){
                z = cd(y0[i],an,2,in);
            }
        else if(strcmp(y[2],"pwd")==0){
                char s[1024];
                for (int i = 0; i < in; i++)
        {
                printf("%s\n", getcwd(s, 100));
            }
            }
        else if(strcmp(y[2],"ls")==0){
            for (int i = 0; i < in; i++){
                if (c==3){
                listt(".",0);
            }
            else if (c==4){
            if (strcmp(y[3],"-a")==0)
            {
                listt(".",1);
            }
            else if (strcmp(y[3],"~")==0)
            {
                char *homedir = getenv("HOME");
                listt(homedir,0);
            }            
            else{
                listt(y[3],0);
            }}
            else if (c==3){
            if (strcmp(y[3],"-a")==0){
                if (strcmp(y[4],"~")==0){
                    char *homedir = getenv("HOME");
                    listt(homedir,1);
                } 
                else{
                listt(y[4],1);
                }}
            else if (strcmp(y[4],"-a")==0)
            {
                if (strcmp(y[3],"~")==0){
                    char *homedir = getenv("HOME");
                    listt(homedir,1);
                } 
                else{
                listt(y[3],1);
                }
            }
            else{
                for (int i = 1; i < c; i++)
                {
                    printf("%s:\n", y[i]);
                    listt(y[i],0);
                    printf("\n");
                }
                
            }
        }
        else{
            if (strcmp(y[3],"-a")==0)            {
                for (int i = 2; i < c; i++){
                    printf("%s:\n", y[i]);
                    listt(y[i],1);
                    printf("\n");
                }}
            else{
                for (int i = 1; i < c; i++)
                {
                    printf("%s:\n", y[i]);
                    listt(y[i],0);
                    printf("\n");
                }               
    }  
} 
    }  }                  
    else{
      pid_t child; int hy=0; int hy1=0;
           int cstatus;  // child exit status
           pid_t c;  // child process id returned by wait()
           char* args[c0-1]; char* args2[c0-1];
        for (int i = 0; i < in; i++)
        {   
        for(int i=2; i<c0; i++){
            args[hy] = y[i];
            args2[hy1] = y[i];
            hy++;  hy1++;
        }
        args[c0-2] = NULL;  args2[c0-2] = NULL; // args[c0-1] = NULL;
        
        if ((child = fork()) == 0){
            if (args2[c0-3][0]=='&'){
                args2[c0-3] = NULL;
            }
                execvp(args[0], args);            
            printf("Error: %s not found\n", args[0]);
            exit(1);
        }
        else{
            if (child == (pid_t)-1){
                printf("Error: fork() failed\n"); 
                exit(1);
            }
            else{
                if (args[c0-3][0]=='&'){
                    continue;
                }
                else{
                    waitpid(child,&cstatus,WUNTRACED);
                }
    } } } } } 
    else if(strcmp(y[0],"echo")==0){
        echo(y0[i],0);
    }
    else if(strcmp(y[0],"cd")==0){
       z = cd(y0[i],an,0,1);
    }
    else if(strcmp(y[0],"pwd")==0){
        char s[1024];
        printf("%s\n", getcwd(s, 100));
    }
    else if(strcmp(y[0],"ls")==0){
        if (c==1)
        {
            listt(".",0);
        }
        else if (c==2){
            if (strcmp(y[1],"-a")==0)
            {
                listt(".",1);
            }
            else if (strcmp(y[1],"~")==0)
            {
                char *homedir = getenv("HOME");
                listt(homedir,0);
            }            
            else{
                listt(y[1],0);
            }
        }
        else if (c==3)
        {
            if (strcmp(y[1],"-a")==0){
                if (strcmp(y[2],"~")==0){
                    char *homedir = getenv("HOME");
                    listt(homedir,1);
                } 
                else{
                listt(y[2],1);
                }
            }
            else if (strcmp(y[2],"-a")==0)
            {
                if (strcmp(y[1],"~")==0){
                    char *homedir = getenv("HOME");
                    listt(homedir,1);
                } 
                else{
                listt(y[1],1);
                }  }
            else{
                for (int i = 1; i < c; i++)
                {
                    printf("%s:\n", y[i]);
                    listt(y[i],0);
                    printf("\n");
                }  }   }
        else{
            if (strcmp(y[1],"-a")==0){
                for (int i = 2; i < c; i++){
                    printf("%s:\n", y[i]);
                    listt(y[i],1);
                    printf("\n");
                } }
            else{
                for (int i = 1; i < c; i++){
                    printf("%s:\n", y[i]);
                    listt(y[i],0);
                    printf("\n");
                }  }  
} }            
    else{  
           pid_t child;
           int cstatus;  // child exit status
           pid_t c12;  // child process id returned by wait()
           char* args[c0+1]; char* args2[c0+1];
        
        for(int i=0; i<c0; i++){
            args[i] = y[i];
            args2[i] = y[i];
        }
        args[c0] = NULL; args2[c0] = NULL;
  if ((child = fork()) == 0){
            if (args2[c0-1][0]=='&'){
                args2[c0-1] = NULL;
            }
            execvp(args2[0], args2);
            printf("Error: %s not found\n", args[0]);
            exit(1);
        }      
        else{
            if (child == (pid_t)-1){
                printf("Error: fork() failed\n"); 
                exit(1);
            }
            else{    
                if (args[c0-1][0]=='&'){
               break;
            }   
            else{                
               waitpid(child,&cstatus,WUNTRACED);
            }   }                    
    }  }      }
} return 0; }
