#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sqlite3.h>
#include "dTypeAnly.h"
int chkwd(char *line, char *dataT,char *d,char *tName)
{
char *ext;
char *extD;
char line1[500];
char line2[500];
char *tHead[15];
char *tDataType[15];
char *dataTypeVar[15];
strncpy(line1,line,500);
strncpy(line2,dataT,500);
//printf("%s\n",line1);
//printf("%s\n",line2);
int i = 0;
char query[1000];
char pQry[1000];
sprintf(query,"CREATE TABLE IF NOT EXISTS '%s' (id INTEGER PRIMARY KEY ",tName);
ext = strtok(line1,",");
//
    while (ext != NULL)
    {
       // printf("%s\n",ext);
        strncat(query,pQry,strlen(pQry));
        tHead[i] = ext;
        ext = strtok (NULL, ",");       
        i++;    
    }
  
    int j = 0;
    extD = strtok(line2,",");
    while (extD != NULL)
    {
        tDataType[j] = extD;
        extD = strtok (NULL, ",");       
        j++; 

    }
    for (int g = 0;g < 12;g++)
    {
        dataTypeVar[g] = dataType(tDataType[g]);
        sprintf(pQry,",%s %s",tHead[g],dataTypeVar[g]);
        strncat(query,pQry,sizeof(pQry));
    }
    sprintf(pQry," );");
    strncat(query,pQry,strlen(pQry));
//===================================Make Table==========================================//
//CONNECT TO DB
sqlite3 *db;
if(sqlite3_open(d,&db))
{
    printf("Cant open DataBase::\n");
    exit(1);
}
//prepare Excecute
sqlite3_stmt *stmt;
sqlite3_prepare(db,query,strlen(query),&stmt,NULL);
sqlite3_step(stmt);
sqlite3_close(db);
//===================================Make Table==========================================//
}