#ifndef __DEFINE_H__
#define __DEFINE_H__

#define TMAX 5000
#define PMAX 200

#define FILENAME_INPUT "../input/4_2_input.txt"
#define FILENAME_OUTPUT  "../output/result.txt"
#define FILENAME_TIME "../output/time.txt"
#define FILENAME_DQ "d q.txt"

typedef struct OPT{
    int i;          // 第i组d p
    int f[4];       // 命中次数(含伪命中与真命中)
    int n;          // 匹配成功个数 (真命中)
    int sta[PMAX];  // 匹配成功起始位置
}OPT;

extern OPT opt;


#endif