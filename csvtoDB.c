#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "extchk.h"
#include "makeTable.h"
#include "addData.h"
#define LSIZ 128 
#define RSIZ 2000
int main(int argc, char *argv[])
{
    //printf(".........");
    /*=============FILE READING VARIABLES=========================*/
    char line[RSIZ][LSIZ];
    int i = 0;
    int tot = 0;
    char *word;
    int wlen;
    /*=============FILE READING VARIABLES=========================*/
    if (argc < 4)
    {        
        printf("Source File CSV and Destination DB required\n");
        exit(1);
    }
    char *src;
    char *dest;
    char s[30],d[30],tName[30];
    src = argv[1];
    dest = argv[2];
    strncpy(s,argv[1],30);
    strncpy(d ,argv[2],30);
    strncpy(tName ,argv[3],30); 
    chk(src,dest);
/*=================================FILE READ ==============================*/

FILE *f = fopen(s,"r");
while(fgets(line[i], LSIZ,f)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    printf("%d",tot);
    //craete Table using Header and first line data  
    for(i = 0; i < 1; i++)
    {
       chkwd(line[i],line[i+1],d,tName);   
    }
      for(i = 1; i < tot; i++)
    {
       addDataDB(line[i],d,tName);
    }
    
/*=================================FILE READ ==============================*/
    return 0;
}
