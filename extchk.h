#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int chk(char *source,char *destination)
{
char *ext;
char *ext1;
char *csvExt[2];
    char *dbExt[2];
    int i =0;
    ext = strtok(source,".");
    while (ext != NULL)
    {
        csvExt[i] = ext;
        ext = strtok (NULL, ",:");
        i++;        
    }
    if (strncmp(csvExt[1],"csv",3) == 0 && strlen(csvExt[1]) == 3)
    {
    }
    else
    {
        printf("Wrong Csv Extension\n");
        exit(1);
    }
    i =0;
    ext1 = strtok(destination,".");
    while (ext1 != NULL)
    {        
        dbExt[i] = ext1;
        ext1 = strtok (NULL, ",:");
        i++;       
    }
    //printf("%d\n",strlen(dbExt[1]));
    if (strncmp(dbExt[1],"db",2) == 0 && strlen(dbExt[1]) == 2)
    {
    }
    else
    {
        printf("Wrong DB Extension\n");
        exit(1);
    }
    return 0;
}