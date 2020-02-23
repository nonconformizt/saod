#include <iostream>
#include <ctime>
#ifndef TIMER
#define TIMER

namespace saod
{

int runningTime;

void startTimer()
{
    runningTime = clock();
}

void endTimer()
{
    runningTime = (clock() - runningTime) / (CLOCKS_PER_SEC / 1000000);
}

std::string getMicroseconds()
{
    return std::to_string(runningTime);
}



}
#endif