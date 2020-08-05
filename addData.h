#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sqlite3.h>
//#include"typeDataAnly.h"
int addDataDB(char * line,char *d,char *tName)
{
char *arr[3]={"'%s'","'%d'","'%f'"};
char *ext;
char line1[500];
char *tData[15];
char *typeData[15];
char qMark[100];
char tableDataVar[500];
strncpy(line1,line,500);
int i = 0;
char query[1000];
char pQry[1000];
sprintf(qMark,"INSERT INTO '%s' VALUES(NULL,",tName);
// insert into Cust values('%s','%s'),custname,
ext = strtok(line1,",");
    while (ext != NULL)
    {
            
        tData[i] = ext;
        strncat(qMark,"'",1),
        strncat(qMark,tData[i],strlen(tData[i]));
        strncat(qMark,"',",2),        
        ext = strtok (NULL, ",");       
        i++;   
    }
    qMark[strlen(qMark)-1] = 0;
    strncat(qMark,")",1);
    sprintf(query,qMark);
    *qMark ='\0';

    //printf("%s",query);
    
  

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
if(sqlite3_step(stmt) != SQLITE_DONE)
{
    //perror(sqlite3_system_errno);
}

sqlite3_finalize(stmt);

sqlite3_close(db);

//===================================Make Table==========================================//

}