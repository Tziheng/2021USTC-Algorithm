#include <string.h>

int c[1024][1024] ;
char b[1024][1024] ;

int x,y;
char *X,*Y;

void deliver(int *xt,int *yt,int (**ct)[1024],char (**bt)[1024],char **Xt,char **Yt){
    *xt = x;
    *yt = y;
    *ct = c;
    *bt = b;
    *Xt = X;
    *Yt = Y;
}

int Dynamic(char *strX,int X_length,char *strY,int Y_length){
    x = X_length;X = strX - 1;
    y = Y_length;Y = strY - 1;
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
                b[i][j] = 1;
            }
        }
    }
    return c[x][y];
}
