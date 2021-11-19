#include "algorithm.h"

/*
c[i][j] means LCS of X[i-1] & Y[j-1]
            0                        i = 0 || j = 0
c[i][j] =   c[i-1][j-1] + 1          X[i] = Y[j]
            max(c[i][j-1],c[i-1][j]) X[i] != Y[j]
*/
int c[1024][1024] ;
char b[1024][1024] ;
char o[1024] = "";

/*
X[1,2,3,...,x],Y[1,2,3,...,y]
*/
int x,y;
char *X,*Y;

void OPToutput(int m,int n,void (*prt)(char s[])){
    if(m == 0 || n == 0){
        prt(o+1);
        return;
    }
    int t = c[m][n];
    while(c[m][n] == t && t > 0){
        for(int i = n; c[m][i] == t ; --i){
            if(b[m][i] == 0){
                o[t] = X[m];
                OPToutput(m-1,i-1,prt);
            }
        }
        m--;
    }
}

int Dynamic(char *strX,int X_length,char *strY,int Y_length){
    x = X_length;X = strX - 1;
    y = Y_length;Y = strY - 1;
    memset(o,0,sizeof(o));
    for(int i = 1; i <= x; ++i){
        for(int j = 1; j <= y; ++j){
            if(X[i] == Y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
    prt2file_d(c[x][y]);
    OPToutput(x,y,prt2file_s);
    return c[x][y];
}
