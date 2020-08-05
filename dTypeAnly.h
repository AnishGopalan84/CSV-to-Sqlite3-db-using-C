#include<stdio.h>
#include<string.h>
int txtChk(int ,int);
int floatcnt =0;
int negCount =0;
int Array[12] ={45,46,48,49,50,51,52,53,54,55,56,57};
const int aLen = 12;
int dType = 0;
char *dataType(char *input)
{
    //Integer ,real,text    
    char * var;
    var = input;
    char *str[3] ={"TEXT","INTEGER","REAL"};    
    int len;
    int chr;
    len = strlen(var);
    for (int i = 0;i < len;i++)
    {
        chr = (int)var[i];             
        dType = txtChk(chr,dType);
        if (dType == 0)
        {
              floatcnt =0;
            negCount =0;
            break;
        }
    }    
    
    if (dType > 0)
    {
            if(floatcnt > 1 || negCount > 1)
            {                
                dType = 0;
                
            }
            else if (floatcnt == 1 || negCount == 1)
            {
                dType = 2;
            }
            floatcnt =0;
            negCount =0;
    }

    return str[dType];
}

int txtChk(int x,int type){
    dType = 0;
for (int j = 0 ; j < aLen; j++)
{    if(x == Array[j])
        {
           if (x == 46)
            {
                floatcnt = floatcnt+1;
            }
            if (x == 45 && j ==0)
            {
                negCount = negCount + 1;
            }
            if (x == 45 && j > 0)
            {
                dType = 0;
                return dType;
                break;
            }
            
            dType = 1; 
break;
        }
}
        
 return dType;
}

// 46,48,49,50,51,52,53,54,55,56,57//