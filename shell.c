#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void aaa(char **c,char *d){
int j;
for(j=0;j<19;j++)
         {
           c[j] = strsep(&d," ");
           if(c[j] == NULL) break;
       }
}
int main()
  {
     int i,j;char *c[5];//c[0]="ls";c[1]="\0";//c[2]="\0";
      char d[20];
    while(1)
    {

      printf("new_shell @:\n");
		fgets(d,20,stdin);
        if(d[strlen(d)-1] == '\n') {
            d[strlen(d)-1] = '\0';
        }
         aaa(c,d);
        //printf("ok");
        if(strcmp(c[0],"exit") == 0)
    {
        printf("Exit!\n");
        exit(0);
    }

      pid_t p=fork();

       if(p==0)
       {
         //printf("ok");
         execvp(c[0],c);
          exit(0);
       }

       else{wait(NULL);}
    }

    return 0;
 }
