#include "file.h"
#include "set.h"
int Algorithm(int (*r)[MAXNUM] , int n){
    for( int i = 0 ; i < n ; ++i){
        MakeSet(node(i));
        for( int j = 0 ; j < i; ++j)
            if(r[i][j]) Union(node(i),node(j));
    }
    int rst = 0;
    for(int i = 0 ; i < n; ++i)
        if(node(i) == node(i)->par) rst++;
    return rst;
        
}