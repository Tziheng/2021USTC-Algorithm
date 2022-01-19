#ifndef __DEFINE_H__
#define __DEFINE_H__

#define TMAX 5000
#define PMAX 200

#define FILENAME_INPUT "../input/4_1_input.txt"
#define FILENAME_OUTPUT  "../output/result.txt"
#define FILENAME_TIME "../output/time.txt"

typedef struct OPT{
    int pi[PMAX];
    int n;          // 匹配成功个数 
    int sta[PMAX];  // 匹配成功起始位置
}OPT;

extern OPT opt;


#endif