#include <time.h>
clock_t timeStart, timeEnd;
void startTiming() {
    timeStart = clock();
}
void endTiming() {
    timeEnd = clock();
}
int timeCost() {
    return timeEnd - timeStart;
}